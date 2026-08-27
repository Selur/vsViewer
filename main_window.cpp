#include "main_window.h"

#include "common-src/settings/settings_manager.h"
#include "common-src/vapoursynth/vs_script_library.h"
#include "common-src/vapoursynth/vapoursynth_script_processor.h"
#include "common-src/helpers.h"
#include "common-src/ipc_defines.h"

#include "vapoursynth/vapoursynth_plugins_manager.h"
#include "preview/preview_dialog.h"
#include "settings/settings_dialog.h"
#include "frame_consumers/benchmark_dialog.h"
#include "frame_consumers/encode_dialog.h"
#include "script_templates/templates_dialog.h"
#include "job_server_watcher_socket.h"
#include "ipc/LocalSocketIpcClient.h"
#include "ipc/LocalSocketIpcServer.h"

#include <QCoreApplication>
#include <QSettings>
#include <QByteArray>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QMoveEvent>
#include <QResizeEvent>
#include <QSocketNotifier>
#include <QToolTip>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QStandardPaths>
#include <QStringList>
#include <QFileInfo>
#include <QDir>
#include <QFontDatabase>
#include <QResource>
#include <QDesktopServices>
#include <QUrl>
#include <QDateTime>
#include <QTimer>
#include <QThread>

//==============================================================================

// Crop specs travel both on the command line (--crop) and inside IPC messages.
static const int CROP_SPEC_FIELDS = 5;
static const char CROP_SPEC_FORM[] = "<on|off>#<left>#<right>#<top>#<bottom>";

//==============================================================================

MainWindow::MainWindow(SettingsManager *settings)
  : QMainWindow(), m_pSettingsManager(settings), m_pVapourSynthPluginsManager(nullptr), m_pVSScriptLibrary(nullptr),
    m_pActionNewScript(nullptr), m_pActionOpenScript(nullptr), m_pActionSaveScript(nullptr), m_pActionSaveScriptAs(nullptr),
    m_pActionTemplates(nullptr), m_pActionSettings(nullptr), m_pActionPreview(nullptr), m_pActionCheckScript(nullptr),
    m_pActionBenchmark(nullptr), m_pActionEncode(nullptr), m_pActionEnqueueEncodeJob(nullptr), m_pActionJobs(nullptr),
    m_pActionExit(nullptr), m_pActionAbout(nullptr), m_settableActionsList(), m_pMenuRecentScripts(nullptr), m_pPreviewDialog(nullptr),
    m_pSettingsDialog(nullptr), m_pBenchmarkDialog(nullptr), m_pEncodeDialog(nullptr), m_pTemplatesDialog(nullptr), m_scriptFilePath(),
    m_lastSavedText(), m_pJobServerWatcherSocket(nullptr), m_pGeometrySaveTimer(nullptr), m_pReloadTextTimer(nullptr), m_ipcClient(nullptr),
    m_ipcClientThread(nullptr), m_ipcServer(nullptr), m_hideMainWindow(false)
{
  loadFonts();

  m_ui.setupUi(this);

  setWindowIcon(QIcon(":vsviewer.ico"));

  if (m_pSettingsManager->inDarkMode()) {
    // qDarkStyle is not bundled, so this normally fails - append, never replace, and do not nag
    QFile styleSheetDark(":/dark/style.qss");
    if (styleSheetDark.open(QFile::ReadOnly | QFile::Text)) {
      qApp->setStyleSheet(qApp->styleSheet() + QString::fromUtf8(styleSheetDark.readAll()));
    }
    // With the current impl of the timeline slider
    // we have to relaunch anyway
    QPalette newPal(qApp->palette());
    newPal.setColor(QPalette::Base, QColor(0, 0, 0));
    newPal.setColor(QPalette::Highlight, QColor(128, 128, 128));
    newPal.setColor(QPalette::Dark, QColor(192, 192, 192));
    newPal.setColor(QPalette::Text, QColor(64, 192, 0));
    qApp->setPalette(newPal);
  }
#ifdef Q_OS_WIN
  else
    qApp->setStyle("fusion");
#endif
  m_pSettingsDialog = new SettingsDialog(m_pSettingsManager, nullptr);

  connect(m_pSettingsDialog, SIGNAL(signalSettingsChanged()), this, SLOT(slotSettingsChanged()));

  m_pVSScriptLibrary = new VSScriptLibrary(m_pSettingsManager, this);

  connect(m_pVSScriptLibrary, SIGNAL(signalWriteLogMessage(int, const QString &)), this, SLOT(slotWriteLogMessage(int, const QString &)));

  m_pVapourSynthPluginsManager = new VapourSynthPluginsManager(m_pSettingsManager, m_pVSScriptLibrary->getVSAPI(), this);
  VSPluginsList vsPluginsList = m_pVapourSynthPluginsManager->pluginsList();

  m_ui.scriptEdit->setPluginsList(vsPluginsList);
  m_ui.scriptEdit->setSettingsManager(m_pSettingsManager);

  connect(m_ui.scriptEdit, SIGNAL(textChanged()), this, SLOT(slotEditorTextChanged()));
  connect(m_ui.scriptEdit, SIGNAL(modificationChanged(bool)), this, SLOT(slotChangeWindowTitle()));
  connect(m_ui.scriptEdit, SIGNAL(signalScriptFileDropped(const QString &, bool *)), this,
          SLOT(slotScriptFileDropped(const QString &, bool *)));

  m_ui.logView->setName("main_log");
  m_ui.logView->setSettingsManager(m_pSettingsManager);
  m_ui.logView->loadSettings();

  m_pPreviewDialog =
    new PreviewDialog(m_pSettingsManager, m_pVSScriptLibrary);

  connect(m_pPreviewDialog,
    SIGNAL(signalWriteLogMessage(int, const QString &)),
    this, SLOT(slotWriteLogMessage(int, const QString &)));
  connect(m_pPreviewDialog,
    SIGNAL(signalPasteIntoScriptAtNewLine(const QString &)),
    this, SLOT(slotInsertTextIntoScriptAtNewLine(const QString &)));
  connect(m_pPreviewDialog,
    SIGNAL(signalPasteIntoScriptAtCursor(const QString &)),
    this, SLOT(slotInsertTextIntoScriptAtCursor(const QString &)));
  connect(m_pSettingsDialog, SIGNAL(signalSettingsChanged()),
    m_pPreviewDialog, SLOT(slotSettingsChanged()));

  m_pBenchmarkDialog = new ScriptBenchmarkDialog(m_pSettingsManager, m_pVSScriptLibrary);
  connect(m_pBenchmarkDialog, SIGNAL(signalWriteLogMessage(int, const QString &)), this, SLOT(slotWriteLogMessage(int, const QString &)));

  m_pEncodeDialog = new EncodeDialog(m_pSettingsManager, m_pVSScriptLibrary);
  connect(m_pEncodeDialog, SIGNAL(signalWriteLogMessage(const QString &, const QString &)), this,
          SLOT(slotWriteLogMessage(const QString &, const QString &)));

  m_pTemplatesDialog = new TemplatesDialog(m_pSettingsManager);
  m_pTemplatesDialog->setPluginsList(vsPluginsList);

  connect(m_pTemplatesDialog, SIGNAL(signalPasteCodeSnippet(const QString &)), this,
          SLOT(slotInsertTextIntoScriptAtNewLine(const QString &)));

  m_orphanQObjects = {(QObject **)&m_pPreviewDialog, (QObject **)&m_pSettingsDialog, (QObject **)&m_pBenchmarkDialog,
                      (QObject **)&m_pEncodeDialog, (QObject **)&m_pTemplatesDialog};

  m_pJobServerWatcherSocket = new JobServerWatcherSocket(this);
  connect(m_pJobServerWatcherSocket, SIGNAL(signalWriteLogMessage(const QString &, const QString &)), this,
          SLOT(slotWriteLogMessage(const QString &, const QString &)));

  m_pGeometrySaveTimer = new QTimer(this);
  m_pGeometrySaveTimer->setInterval(DEFAULT_WINDOW_GEOMETRY_SAVE_DELAY);
  connect(m_pGeometrySaveTimer, &QTimer::timeout, this, &MainWindow::slotSaveGeometry);

  m_pReloadTextTimer = new QTimer(this);
  m_pReloadTextTimer->setInterval(500);
  connect(m_pReloadTextTimer, &QTimer::timeout, this, &MainWindow::slotReloadTextFromDisk);

  createActionsAndMenus();

  slotChangeWindowTitle();

  m_windowGeometry = m_pSettingsManager->getMainWindowGeometry();
  if (!m_windowGeometry.isEmpty()) restoreGeometry(m_windowGeometry);

  if (m_pSettingsManager->getMainWindowMaximized()) showMaximized();

  loadStartUpScript();

  if (m_pSettingsManager->getReloadScriptFromDisk()) m_pReloadTextTimer->start();
}

// END OF MainWindow::MainWindow()
//==============================================================================

MainWindow::~MainWindow()
{
  if(m_pGeometrySaveTimer->isActive())
  {
    m_pGeometrySaveTimer->stop();
    slotSaveGeometry();
  }

  qInstallMessageHandler(0);

  // stop the client thread first: it deletes the client, so m_ipcClient dangles after this
  if (m_ipcClientThread != nullptr) {
    m_ipcClientThread->quit();
    if (!m_ipcClientThread->wait(5000)) {
      m_ipcClientThread->terminate();
      m_ipcClientThread->wait(1000);
    }
    m_ipcClient = nullptr;
  }

  destroyOrphanQObjects();
}

// END OF MainWindow::~MainWindow()
//==============================================================================

void MainWindow::slotWriteLogMessage(int a_messageType,
  const QString & a_message)
{
  QString style = vsMessageTypeToStyleName(a_messageType);
  slotWriteLogMessage(a_message, style);
}

// END OF void MainWindow::slotWriteLogMessage(int a_messageType,
//		const QString & a_message)
//==============================================================================

void MainWindow::slotWriteLogMessage(const QString & a_message,
  const QString & a_style)
{
  m_ui.logView->addEntry(a_message, a_style);

  this->ipcSend(a_message);

  QString fatalTypes[] = {LOG_STYLE_VS_FATAL, LOG_STYLE_QT_FATAL};
  if(!vsedit::contains(fatalTypes, a_style))
    return;

  QDateTime now = QDateTime::currentDateTime();
  QString timeString = now.toString("hh:mm:ss.zzz");
  QString dateString = now.toString("yyyy-MM-dd");
  QString caption = QObject::tr("VapourSynth Editor fatal error!");
  QString fullMessage = dateString + QString(" ") + timeString +
    QString("\n") + caption + QString("\n") + a_message;

    QString tempPath =
    QStandardPaths::writableLocation(QStandardPaths::TempLocation);
  if(tempPath.isEmpty())
  {
    this->ipcSend(fullMessage);

    QMessageBox::critical(nullptr, caption, fullMessage);
    return;
  }

  QString filePath = tempPath + QString("/") +
    QString("VapourSynth-Editor-crashlog-") + dateString + QString("-") +
    timeString.replace(':', '-') + QString(".html");

  bool saved = m_ui.logView->saveHtml(filePath);
  if(!saved)
  {
    this->ipcSend(fullMessage);

    QMessageBox::critical(nullptr, caption, fullMessage);
    return;
  }

  QUrl fileUrl = QUrl::fromLocalFile(filePath);
  QDesktopServices::openUrl(fileUrl);
}

// END OF void MainWindow::slotWriteLogMessage(const QString & a_message,
//		const QString & a_style);
//==============================================================================

void MainWindow::slotInsertTextIntoScriptAtNewLine(const QString & a_text)
{
  m_ui.scriptEdit->slotInsertTextAtNewLine(a_text);
}

// END OF void MainWindow::slotInsertTextIntoScriptAtNewLine(
//		const QString & a_text)
//==============================================================================

void MainWindow::slotInsertTextIntoScriptAtCursor(const QString & a_text)
{
  m_ui.scriptEdit->insertPlainText(a_text);
}

// END OF void MainWindow::slotInsertTextIntoScriptAtCursor(
//		const QString & a_text)
//==============================================================================

void MainWindow::closeEvent(QCloseEvent * a_pEvent)
{
  if(!safeToCloseFile())
  {
    a_pEvent->ignore();
    return;
  }

  destroyOrphanQObjects();

  QMainWindow::closeEvent(a_pEvent);
}

// END OF void MainWindow::closeEvent(QCloseEvent * a_pEvent)
//==============================================================================

void MainWindow::moveEvent(QMoveEvent * a_pEvent)
{
  QMainWindow::moveEvent(a_pEvent);
  saveGeometryDelayed();
}

// END OF void MainWindow::moveEvent(QMoveEvent * a_pEvent)
//==============================================================================

void MainWindow::resizeEvent(QResizeEvent * a_pEvent)
{
  QMainWindow::resizeEvent(a_pEvent);
  saveGeometryDelayed();
}

// END OF void MainWindow::resizeEvent(QResizeEvent * a_pEvent)
//==============================================================================

void MainWindow::changeEvent(QEvent * a_pEvent)
{
  if(a_pEvent->type() == QEvent::WindowStateChange)
  {
    if(isMaximized())
      m_pSettingsManager->setMainWindowMaximized(true);
    else
      m_pSettingsManager->setMainWindowMaximized(false);
  }
  QMainWindow::changeEvent(a_pEvent);
}

// END OF void MainWindow::changeEvent(QEvent * a_pEvent)
//==============================================================================

void MainWindow::slotNewScript()
{
  if(!safeToCloseFile())
    return;

  QString newScriptTemplate = m_pSettingsManager->getNewScriptTemplate();

  m_scriptFilePath.clear();
  m_lastSavedText = newScriptTemplate;
  m_ui.scriptEdit->setPlainText(newScriptTemplate);
  m_ui.scriptEdit->moveCursor(QTextCursor::End);
  m_ui.scriptEdit->setModified(true);

  m_pBenchmarkDialog->resetSavedRange();
}

// END OF void MainWindow::slotNewScript()
//==============================================================================

bool MainWindow::slotSaveScript()
{
  if(!m_ui.scriptEdit->isModified())
    return false;

  if(m_scriptFilePath.isEmpty())
  {
    slotSaveScriptAs();
    return false;
  }

  return saveScriptToFile(m_scriptFilePath);
}

// END OF bool MainWindow::slotSaveScript()
//==============================================================================

bool MainWindow::slotSaveScriptAs()
{
  QString offeredFilePath = m_scriptFilePath;
  if(offeredFilePath.isEmpty())
  {
    QFileInfo fileInfo(m_pSettingsManager->getLastUsedPath());
    offeredFilePath = fileInfo.absoluteDir().path() +
      tr("/Untitled.vpy");
  }

  QString filePath = QFileDialog::getSaveFileName(this,
    tr("Save VapourSynth script"), offeredFilePath,
    tr("VapourSynth script (*.vpy);;All files (*)"));

  if(!filePath.isEmpty())
  {
    bool success = saveScriptToFile(filePath);

    // Copy bookmarks
    if((!success) || offeredFilePath.isEmpty())
      return success;
    QFile::copy(offeredFilePath + TIMELINE_BOOKMARKS_FILE_SUFFIX,
      filePath + TIMELINE_BOOKMARKS_FILE_SUFFIX);
  }

  return false;
}

// END OF bool MainWindow::slotSaveScriptAs()
//==============================================================================

bool MainWindow::slotOpenScript()
{
  if(!safeToCloseFile())
    return false;

  QFileInfo fileInfo(m_pSettingsManager->getLastUsedPath());
  QString offeredPath = fileInfo.absoluteDir().path();

  QString filePath = QFileDialog::getOpenFileName(this,
    tr("Open VapourSynth script"), offeredPath,
    tr("VapourSynth script (*.vpy);;All files (*)"));

  return loadScriptFromFile(filePath);
}

// END OF bool MainWindow::slotOpenScript()
//==============================================================================

void MainWindow::slotTemplates()
{
  m_pTemplatesDialog->call();
}

// END OF void MainWindow::slotTemplates()
//==============================================================================

void MainWindow::slotPreview()
{
  if (m_pPreviewDialog->busy()) {
    QString message = tr(
      "Preview dialog appears busy processing "
      "frames. Please stop any active actions in the dialog and wait "
      "for script processor to finish processing.");
    m_ui.logView->addEntry(message, LOG_STYLE_WARNING);
    return;
  }

  m_pPreviewDialog->previewScript(m_ui.scriptEdit->text(), m_scriptFilePath);
}

// END OF void MainWindow::slotPreview()
//==============================================================================

void MainWindow::slotCheckScript()
{
  VapourSynthScriptProcessor tempProcessor(m_pSettingsManager, m_pVSScriptLibrary, this);

  const VSAPI *cpVSAPI = m_pVSScriptLibrary->getVSAPI();

  connect(&tempProcessor, SIGNAL(signalWriteLogMessage(int, const QString &)), this, SLOT(slotWriteLogMessage(int, const QString &)));

  bool correct = tempProcessor.initialize(m_ui.scriptEdit->text(), m_scriptFilePath, 0, ProcessReason::Check);
  if (correct) {
    VSNodeInfo info = tempProcessor.nodeInfo();
    QString message = tr(
                        "Script was successfully evaluated. "
                        "Output %1 info:\n")
                        .arg(info.isAudio() ? "audio" : "video");
    message += vsedit::nodeInfoString(info, cpVSAPI);
    m_ui.logView->addEntry(message, LOG_STYLE_POSITIVE);
  }
}

// END OF void MainWindow::slotCheckScript()
//==============================================================================

void MainWindow::slotBenchmark()
{
  if (m_pBenchmarkDialog->busy()) {
    QString message = tr(
      "Benchmark dialog appears busy processing "
      "frames. Please stop any active actions in the dialog and wait "
      "for script processor to finish processing.");
    m_ui.logView->addEntry(message, LOG_STYLE_WARNING);
    return;
  }

  m_pBenchmarkDialog->initialize(m_ui.scriptEdit->text(), m_scriptFilePath);
  m_pBenchmarkDialog->call();
}

// END OF void MainWindow::slotBenchmark()
//==============================================================================

void MainWindow::slotEncode()
{
  if (m_pEncodeDialog->busy()) {
    m_pEncodeDialog->showActive();
    return;
  }

  bool initialized = m_pEncodeDialog->initialize(m_ui.scriptEdit->text(), m_scriptFilePath);
  if (initialized) m_pEncodeDialog->showActive();
}

// END OF void MainWindow::slotEncode()
//==============================================================================

void MainWindow::slotEnqueueEncodeJob()
{
  if (m_scriptFilePath.isEmpty()) return;

  JobProperties properties;
  properties.type = JobType::EncodeScriptCLI;
  properties.scriptName = m_scriptFilePath;

  QByteArray message = vsedit::jsonMessage(WMSG_CLI_ENCODE_JOB, properties.toJson());
  m_pJobServerWatcherSocket->sendMessage(message);
}

// END OF void MainWindow::slotEnqueueEncodeJob()
//==============================================================================

void MainWindow::slotJobs()
{
  m_pJobServerWatcherSocket->sendMessage(WMSG_SHOW_WINDOW);
}

// END OF void MainWindow::slotJobs()
//==============================================================================

void MainWindow::slotAbout()
{
  QResource aboutResource(":readme");
  QByteArray aboutData((const char *)aboutResource.data(),
    aboutResource.size());
  QString aboutString = QString::fromUtf8(aboutData);
  QMessageBox::about(this, "VapourSynth Editor", aboutString);
}

// END OF void MainWindow::slotAbout()
//==============================================================================

void MainWindow::slotChangeWindowTitle()
{
  QString windowTitleText = QString::fromUtf8("VapourSynth Editor - ");

  if(m_scriptFilePath.isEmpty())
    windowTitleText += QString::fromUtf8("(Untitled)");
  else
    windowTitleText += m_scriptFilePath;

  if(m_ui.scriptEdit->isModified())
    windowTitleText += "*";

  setWindowTitle(windowTitleText);
}

// END OF void MainWindow::slotChangeWindowTitle()
//==============================================================================

void MainWindow::slotEditorTextChanged()
{
  bool textMatchesSaved = (m_lastSavedText == m_ui.scriptEdit->text());
  m_ui.scriptEdit->setModified(!textMatchesSaved);
  slotChangeWindowTitle();
}

// END OF void MainWindow::slotEditorTextChanged()
//==============================================================================

void MainWindow::slotOpenRecentScriptActionTriggered()
{
  QAction * pAction = qobject_cast<QAction *>(sender());
  if(pAction == nullptr)
    return;
  if(!safeToCloseFile())
    return;
  loadScriptFromFile(pAction->data().toString());
}

// END OF bool MainWindow::safeToCloseFile()
//==============================================================================

void MainWindow::slotSettingsChanged()
{
  QKeySequence hotkey;
  for (QAction *pAction : m_settableActionsList) {
    hotkey = m_pSettingsManager->getHotkey(pAction->data().toString());
    pAction->setShortcut(hotkey);
  }

  m_pVapourSynthPluginsManager->slotRefill(m_pVSScriptLibrary->getVSAPI());
  VSPluginsList vsPluginsList = m_pVapourSynthPluginsManager->pluginsList();
  m_ui.scriptEdit->setPluginsList(vsPluginsList);
  m_ui.scriptEdit->slotLoadSettings();
  m_pTemplatesDialog->setPluginsList(vsPluginsList);
  m_pTemplatesDialog->slotLoadSettings();

  if (m_pSettingsManager->getReloadScriptFromDisk())
    m_pReloadTextTimer->start(500);
  else
    m_pReloadTextTimer->stop();
}

// END OF void MainWindow::slotSettingsChanged()
//==============================================================================

void MainWindow::slotScriptFileDropped(const QString & a_filePath,
  bool * a_pHandled)
{
  *a_pHandled = true;

  if(!safeToCloseFile())
    return;

  loadScriptFromFile(a_filePath);
}

// END OF void MainWindow::slotScriptFileDropped(const QString & a_filePath,
//		bool * a_pHandled)
//==============================================================================

void MainWindow::slotSaveGeometry()
{
  m_pGeometrySaveTimer->stop();
  m_pSettingsManager->setMainWindowGeometry(m_windowGeometry);
}
// void slotReloadTextFromDisk();
//==============================================================================

void MainWindow::slotReloadTextFromDisk()
{
  if (m_ui.scriptEdit->isModified()) return;

  if (m_scriptFilePath.isEmpty()) return;

  QFile scriptFile(m_scriptFilePath);
  bool loadSuccess = scriptFile.open(QIODevice::ReadOnly | QIODevice::Text);
  if (!loadSuccess) return;

  QByteArray utf8Script = scriptFile.readAll();
  QString scriptText = QString::fromUtf8(utf8Script);
  if (scriptText.isEmpty())  // To prevent an occasional bug?
    return;
  if (scriptText == m_ui.scriptEdit->text()) return;

  QPoint pos = m_ui.scriptEdit->cursorPosition();
  m_ui.scriptEdit->setPlainText(scriptText);
  m_ui.scriptEdit->setCursorPosition(pos);
  m_ui.scriptEdit->setModified(false);

  m_pBenchmarkDialog->resetSavedRange();
}

void MainWindow::createActionsAndMenus()
{
  struct ActionToCreate
  {
    QAction ** ppAction;
    const char * id;
    QObject * pObjectToConnect;
    const char * slotToConnect;
  };

  ActionToCreate actionsToCreate[] =
  {
    {&m_pActionNewScript, ACTION_ID_NEW_SCRIPT,
      this, SLOT(slotNewScript())},
    {&m_pActionOpenScript, ACTION_ID_OPEN_SCRIPT,
      this, SLOT(slotOpenScript())},
    {&m_pActionSaveScript, ACTION_ID_SAVE_SCRIPT,
      this, SLOT(slotSaveScript())},
    {&m_pActionSaveScriptAs, ACTION_ID_SAVE_SCRIPT_AS,
      this, SLOT(slotSaveScriptAs())},
    {&m_pActionExit, ACTION_ID_EXIT,
      this, SLOT(close())},
    {&m_pActionTemplates, ACTION_ID_TEMPLATES,
      this, SLOT(slotTemplates())},
    {&m_pActionSettings, ACTION_ID_SETTINGS,
      m_pSettingsDialog, SLOT(slotCall())},
    {&m_pActionPreview, ACTION_ID_PREVIEW,
      this, SLOT(slotPreview())},
    {&m_pActionCheckScript, ACTION_ID_CHECK_SCRIPT,
      this, SLOT(slotCheckScript())},
    {&m_pActionBenchmark, ACTION_ID_BENCHMARK,
      this, SLOT(slotBenchmark())},
    {&m_pActionEncode, ACTION_ID_CLI_ENCODE,
      this, SLOT(slotEncode())},
    {&m_pActionEnqueueEncodeJob, ACTION_ID_ENQUEUE_ENCODE_JOB,
      this, SLOT(slotEnqueueEncodeJob())},
    {&m_pActionJobs, ACTION_ID_JOBS,
      this, SLOT(slotJobs())},
    {&m_pActionAbout, ACTION_ID_ABOUT,
      this, SLOT(slotAbout())},
  };

  for(ActionToCreate & item : actionsToCreate)
  {
    QAction * pAction = m_pSettingsManager->createStandardAction(
      item.id, this);
    *item.ppAction = pAction;
    m_settableActionsList.push_back(pAction);
    connect(pAction, SIGNAL(triggered()),
      item.pObjectToConnect, item.slotToConnect);
  }

//------------------------------------------------------------------------------

  QMenu * pFileMenu = m_ui.menuBar->addMenu(tr("File"));
  pFileMenu->addAction(m_pActionNewScript);
  pFileMenu->addAction(m_pActionOpenScript);
  pFileMenu->addAction(m_pActionSaveScript);
  pFileMenu->addAction(m_pActionSaveScriptAs);
  pFileMenu->addSeparator();

  m_pMenuRecentScripts = new QMenu(tr("Recent scripts"), this);
  pFileMenu->addMenu(m_pMenuRecentScripts);
  fillRecentScriptsMenu();

  pFileMenu->addSeparator();
  pFileMenu->addAction(m_pActionExit);

//------------------------------------------------------------------------------

  QMenu * pEditMenu = m_ui.menuBar->addMenu(tr("Edit"));

  std::vector<QAction *> editorActions = m_ui.scriptEdit->actionsForMenu();
  for(QAction * pAction : editorActions)
    pEditMenu->addAction(pAction);

  pEditMenu->addSeparator();
  pEditMenu->addAction(m_pActionTemplates);
  pEditMenu->addAction(m_pActionSettings);

//------------------------------------------------------------------------------

  QMenu * pScriptMenu = m_ui.menuBar->addMenu(tr("Script"));
  pScriptMenu->addAction(m_pActionPreview);
  pScriptMenu->addAction(m_pActionCheckScript);
  pScriptMenu->addAction(m_pActionBenchmark);
  pScriptMenu->addAction(m_pActionEncode);
  pScriptMenu->addAction(m_pActionEnqueueEncodeJob);
  pScriptMenu->addAction(m_pActionJobs);

//------------------------------------------------------------------------------

  QMenu * pHelpMenu = m_ui.menuBar->addMenu(tr("Help"));
  pHelpMenu->addAction(m_pActionAbout);
}

// END OF void MainWindow::createActionsAndMenus()
//==============================================================================

void MainWindow::fillRecentScriptsMenu()
{
  m_pMenuRecentScripts->clear();
  QStringList recentSciptsList = m_pSettingsManager->getRecentFilesList();
  for(const QString & filePath : recentSciptsList)
  {
    QAction * pAction = new QAction(m_pMenuRecentScripts);
    pAction->setIconText(filePath);
    pAction->setData(filePath);
    m_pMenuRecentScripts->addAction(pAction);

    connect(pAction, SIGNAL(triggered()),
      this, SLOT(slotOpenRecentScriptActionTriggered()));
  }
}

// END OF void MainWindow::fillRecentScriptsMenu()
//==============================================================================

bool MainWindow::saveScriptToFile(const QString& a_filePath)
{
  if(a_filePath.isEmpty())
    return false;

  QFile scriptFile(a_filePath);
  bool openSuccess = scriptFile.open(QIODevice::WriteOnly | QIODevice::Text);
  if(!openSuccess)
  {
    QMessageBox::critical(this,
      QString::fromUtf8("File open error"),
      QString::fromUtf8("Failed to open the file ") + a_filePath +
      QString::fromUtf8("for writing!"));
    return false;
  }

  QByteArray utf8Script = m_ui.scriptEdit->text().toUtf8();
  qint64 writtenBytes = scriptFile.write(utf8Script);

  if(writtenBytes != utf8Script.size())
  {
    QMessageBox::critical(this,
      QString::fromUtf8("File write error"),
      QString::fromUtf8("Error while writing to the file ") + a_filePath);
    return false;
  }

  setCurrentScriptFilePath(a_filePath);
  m_lastSavedText = m_ui.scriptEdit->text();
  m_ui.scriptEdit->setModified(false);

  return true;
}

// END OF bool MainWindow::saveScriptToFile(const QString& a_filePath)
//==============================================================================

bool MainWindow::loadScriptFromFile(const QString& a_filePath, bool a_mayShowDialog)
{
  if(a_filePath.isEmpty())
    return false;

  QFile scriptFile(a_filePath);
  bool loadSuccess = scriptFile.open(QIODevice::ReadOnly | QIODevice::Text);
  if(!loadSuccess)
  {
    const QString message = tr("Failed to open the file %1.").arg(a_filePath);
    // a modal from the constructor is fatal, and one behind a hidden window blocks IPC (docs/issues.md #10)
    if(a_mayShowDialog)
      QMessageBox::critical(this, tr("File open error"), message);
    else
      slotWriteLogMessage(mtCritical, message);
    return false;
  }

  setCurrentScriptFilePath(a_filePath);
  QByteArray utf8Script = scriptFile.readAll();
  QString scriptText = QString::fromUtf8(utf8Script);
  m_lastSavedText = scriptText;
  m_ui.scriptEdit->setPlainText(scriptText);

  m_pBenchmarkDialog->resetSavedRange();

  return true;
}

// END OF bool MainWindow::loadScriptFromFile(const QString& a_filePath)
//==============================================================================

bool MainWindow::safeToCloseFile()
{
  bool needPrompt = (m_pSettingsManager->getPromptToSaveChanges() &&
    m_ui.scriptEdit->isModified());

  if(!needPrompt)
    return true;

  QMessageBox::StandardButton choice = QMessageBox::NoButton;
  if(m_scriptFilePath.isEmpty())
  {
    choice = QMessageBox::question(this, tr("Save script?"),
      tr("Would you like to save your script before closing?"),
      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if(choice == QMessageBox::Yes)
    {
      bool saved = slotSaveScriptAs();
      if(!saved)
        return false;
    }
  }
  else
  {
    choice = QMessageBox::question(this, tr("Save script?"),
      tr("Would you like to save script \"%1\" before closing?")
      .arg(m_scriptFilePath),
      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if(choice == QMessageBox::Yes)
    {
      bool saved = slotSaveScript();
      if(!saved)
        return false;
    }
  }

  if(choice == QMessageBox::Cancel)
    return false;

  return true;
}

// END OF bool MainWindow::safeToCloseFile()
//==============================================================================

void MainWindow::setCurrentScriptFilePath(const QString & a_filePath)
{
  if(m_scriptFilePath == a_filePath)
    return;

  m_scriptFilePath = a_filePath;
  m_pSettingsManager->setLastUsedPath(a_filePath);
  slotChangeWindowTitle();
  fillRecentScriptsMenu();
}

// END OF void MainWindow::setCurrentScriptFilePath(const QString & a_filePath)
//==============================================================================

void MainWindow::ipcMessageReceived(const QString& message)
{
  QStringList typeAndValue = message.split("###");
  switch (typeAndValue.count()){
    case 3 :
      this->ipcCallMethod(typeAndValue.at(0).trimmed(), typeAndValue.at(1).trimmed(), typeAndValue.at(2).trimmed());
      break;
    case 2 :
      this->ipcCallMethod(typeAndValue.at(0).trimmed(), typeAndValue.at(1).trimmed(), QString());
      break;
    default :
      this->slotWriteLogMessage(mtDebug, tr("ignoring received message: %1").arg(message));
      break;
  }
}
bool MainWindow::hybridCustom(const QStringList& arguments)
{
  QString option, input, previewOnly, ipcID, remoteName;
  QStringList cropSettings, unknownOptions;
  int argc = arguments.count();
  bool usingHybrid = false;
  // every option takes one value, so it may not be the last argument (docs/issues.md #3)
  for (int i = 1; i < argc; ++i) {
    option = arguments.at(i);
    const bool hasValue = (i + 1 < argc);
    if (option == "--preview-only" && hasValue) {
      previewOnly = arguments.at(++i);
      usingHybrid = true;
    }
    else if (option == "--input" && hasValue) {
      input = arguments.at(++i);
      usingHybrid = true;
    }
    else if (option == "--listen" && hasValue) {
      const QString value = arguments.at(++i);
      if (ipcID.isEmpty()) ipcID = value; // first one wins, as before
      usingHybrid = true;
    }
    else if (option == "--listen-to" && hasValue) {
      const QString value = arguments.at(++i);
      if (remoteName.isEmpty()) remoteName = value; // first one wins, as before
      usingHybrid = true;
    }
    else if (option == "--crop" && hasValue) {
      cropSettings = arguments.at(++i).split("#");
      usingHybrid = true;
    }
    else if (option.startsWith("--")) {
      // reported after the loop, so the warning also reaches the parent over IPC
      unknownOptions.append(option);
    }
  }

  // built after the whole command line is read, so --listen/--listen-to work in either order (docs/issues.md #2)
  if (!ipcID.isEmpty() && m_ipcServer == nullptr) {
    m_ipcServer = new LocalSocketIpcServer(ipcID + "VSE", this);
    connect(m_ipcServer, SIGNAL(messageReceived(QString)), this,
        SLOT(ipcMessageReceived(QString)));
    connect(m_ipcServer, SIGNAL(signalWriteLogMessage(int, const QString &)), this,
        SLOT(slotWriteLogMessage(int, const QString &)));
  }
  if (!remoteName.isEmpty()) {
    if (ipcID.isEmpty()) {
      // the outbound name is id + remote name; without an id it would be a bare global name
      slotWriteLogMessage(mtWarning, tr("--listen-to needs --listen; ignoring --listen-to."));
    }
    else if (m_ipcClient == nullptr) {
      // own thread: connect blocks for seconds on a busy pipe (#5). No parent - moveToThread refuses one. No log connect (#1)
      m_ipcClientThread = new QThread(this);
      m_ipcClientThread->setObjectName("ipc-client");
      m_ipcClient = new LocalSocketIpcClient(ipcID + remoteName);
      m_ipcClient->moveToThread(m_ipcClientThread);
      // destroy the client on its own thread, where its socket lives
      connect(m_ipcClientThread, &QThread::finished, m_ipcClient, &QObject::deleteLater);
      m_ipcClientThread->start();
    }
  }

  for (const QString& unknown : unknownOptions) {
    slotWriteLogMessage(mtWarning, tr("Ignoring command line option \"%1\": "
                                      "unknown, or missing its value.").arg(unknown));
  }

  if (m_ipcServer != nullptr && !m_ipcServer->isListening()) {
    slotWriteLogMessage(mtCritical, tr("Could not listen on \"%1VSE\" (%2). "
                                       "Commands from the parent application will not arrive.")
                                      .arg(ipcID, m_ipcServer->errorString()));
  }

  if (usingHybrid) {
    // silently: a modal from the constructor is fatal (docs/issues.md #10)
    if (!input.isEmpty()) {
      loadScriptFromFile(input, false);
    } else if (previewOnly.endsWith(".vpy", Qt::CaseInsensitive)) {
      loadScriptFromFile(previewOnly, false);
      // --preview-only starts with cropping off unless an explicit --crop says otherwise
      if (cropSettings.isEmpty()) cropSettings = QString("off#0#0#0#0").split("#");
    }
    if(!checkHybridScript()) {
      return true;
    }
    slotPreview();

    // after slotPreview(), so an "on" crop has a video output to size itself against
    if (cropSettings.count() == CROP_SPEC_FIELDS) {
      if (!applyIpcCrop(cropSettings)) {
        slotWriteLogMessage(mtWarning, tr("Ignoring --crop: no video output to apply it to."));
      }
    } else if (!cropSettings.isEmpty()) {
      slotWriteLogMessage(mtWarning, tr("Ignoring --crop: expected %1.").arg(CROP_SPEC_FORM));
    }

    m_hideMainWindow = true;
  }

  return usingHybrid;
}

void MainWindow::show()
{
  if (m_hideMainWindow) {
    return;
  }
  if (!this->isVisible()) {
    QMainWindow::show();
  }
}

// END OF void MainWindow::ipcStartUpEtc(const QStringList& arguments)
//==============================================================================

void MainWindow::loadStartUpScript()
{
  slotNewScript();

  // runs from the constructor, so nothing here may raise a modal (docs/issues.md #10)
  QStringList argumentsList = QCoreApplication::arguments();
  if(argumentsList.size() > 1)
  {
    if (!hybridCustom(argumentsList)) {
      loadScriptFromFile(argumentsList.at(1), false);
    }
  } else if(m_pSettingsManager->getAutoLoadLastScript())
  {
    QString lastUsedPath = m_pSettingsManager->getLastUsedPath();
    if(!lastUsedPath.isEmpty())
      loadScriptFromFile(lastUsedPath, false);
  }
}

bool MainWindow::checkHybridScript()
{
  VapourSynthScriptProcessor tempProcessor(m_pSettingsManager,
    m_pVSScriptLibrary, this);

  const VSAPI *cpVSAPI = m_pVSScriptLibrary->getVSAPI();

  connect(&tempProcessor, SIGNAL(signalWriteLogMessage(int, const QString &)),
    this, SLOT(slotWriteLogMessage(int, const QString &)));

  bool correct = tempProcessor.initialize(m_ui.scriptEdit->text(), m_scriptFilePath, 0, ProcessReason::Check);
  if (correct) {
    VSNodeInfo info = tempProcessor.nodeInfo();
    QString message = tr(
                        "Script was successfully evaluated. "
                        "Output %1 info:\n")
                        .arg(info.isAudio() ? "audio" : "video");
    message += vsedit::nodeInfoString(info, cpVSAPI);
    m_ui.logView->addEntry(message, LOG_STYLE_POSITIVE);
  }
  return correct;
}

// no-op without an outbound channel: the two IPC directions are independent endpoints
void MainWindow::ipcSend(const QString& message)
{
  if (m_ipcClient == nullptr) {
    return;
  }
  // queued, never direct: the client is on another thread and may be blocked in connect
  QMetaObject::invokeMethod(m_ipcClient, "send_MessageToServer", Qt::QueuedConnection,
                            Q_ARG(QString, message));
}

// "<on|off>#<left>#<right>#<top>#<bottom>"; callers check the field count first
bool MainWindow::applyIpcCrop(const QStringList& fields)
{
  Q_ASSERT(fields.count() == CROP_SPEC_FIELDS);
  return m_pPreviewDialog->ipcAdjustCrop(fields.at(0), fields.at(1).toInt(), fields.at(2).toInt(),
                                         fields.at(3).toInt(), fields.at(4).toInt());
}

void MainWindow::ipcCallMethod(const QString& typ, const QString& value, const QString &optionString)
{
  // dispatched with or without an outbound client - it used to refuse (docs/issues.md #2)
  this->ipcSend(QString("%1 => %2").arg(typ).arg(value));
  if (typ == "changeTo") {
    int x = m_pPreviewDialog->getScrollX();
    int y = m_pPreviewDialog->getScrollY();
    // the socket is unauthenticated, so do not open an arbitrary path
    if (!value.endsWith(".vpy", Qt::CaseInsensitive)) {
      this->ipcSend(value + " is not a .vpy script!");
      return;
    }
    if (!QFile::exists(value)) {
      this->ipcSend(value + " doesn't exist!");
      return;
    }
    // silently: in Hybrid mode a modal behind the hidden window would block every further command
    if(!loadScriptFromFile(value, false)) {
      this->ipcSend(value + " couldn't be loaded(1)!");
      return;
    }
    if(!checkHybridScript()) {
      this->ipcSend(value + " couldn't be loaded(2)!");
      if (m_hideMainWindow) {
        m_hideMainWindow = false;
        this->show();
      }
      return;
    }
    slotPreview();
    if (!optionString.isEmpty() && x == 0 && y == 0) {
      // the script is loaded by now, so a bad crop is reported but does not fail the changeTo
      const QStringList options = optionString.split("#");
      if (options.count() != CROP_SPEC_FIELDS) {
        this->ipcSend(QString("ignoring crop option \"%1\": expected %2").arg(optionString, CROP_SPEC_FORM));
      }
      else if (!applyIpcCrop(options)) {
        this->ipcSend("ignoring crop option: no video output to apply it to!");
      }
    }
    if (!m_hideMainWindow) {
      m_hideMainWindow = true;
      this->hide();
    }
    return;
  }
  if (typ == "crop") {
    const QStringList options = value.split("#");
    if (options.count() != CROP_SPEC_FIELDS) {
      // at(1)..at(4) on a shorter list used to run straight off the end
      this->ipcSend(QString("crop expects %1, got \"%2\"!").arg(CROP_SPEC_FORM, value));
      return;
    }
    if (!applyIpcCrop(options)) {
      this->ipcSend("crop needs a video output to apply to!");
    }
    return;
  }
}
// END OF void MainWindow::ipcCallMethod(const QString& typ, const QString& value, const QString &optionString)

// END OF void MainWindow::loadStartUpScript()
//==============================================================================

void MainWindow::loadFonts()
{
  QResource digitalMiniFontResource(":/fonts/DigitalMini.ttf");
  QByteArray digitalMiniFontData((const char *)digitalMiniFontResource.data(),
    digitalMiniFontResource.size());
  QFontDatabase::addApplicationFontFromData(digitalMiniFontData);
}

// END OF void MainWindow::loadFonts()
//==============================================================================

void MainWindow::destroyOrphanQObjects()
{
  for(QObject ** ppObject : m_orphanQObjects)
  {
    if(!ppObject)
      continue;
    if(!*ppObject)
      continue;
    delete *ppObject;
    *ppObject = nullptr;
  }
}

// END OF void MainWindow::destroyOrphanQObjects()
//==============================================================================

void MainWindow::saveGeometryDelayed()
{
  QApplication::processEvents();
  if(!isMaximized())
  {
    m_windowGeometry = saveGeometry();
    m_pGeometrySaveTimer->start();
  }
}

// END OF void MainWindow::saveGeometryDelayed()
//==============================================================================

void MainWindow::reloadTexts()
{
  if(!loadScriptFromFile(m_scriptFilePath))
    m_ui.scriptEdit->setModified(true);
}

// END OF void MainWindow::reloadTexts()
//==============================================================================
