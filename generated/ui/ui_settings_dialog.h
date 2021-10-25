/********************************************************************************
** Form generated from reading UI file 'settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_DIALOG_H
#define UI_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *settingsTabWidget;
    QWidget *commonSettingsTab;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *autoLoadLastScriptCheckBox;
    QCheckBox *promptToSaveChangesCheckBox;
    QHBoxLayout *recentFilesSettingsLayout;
    QLabel *maxRecentFilesLabel;
    QSpinBox *maxRecentFilesSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *autocompletionLayout;
    QLabel *charactersTypedToStartCompletionLabel;
    QSpinBox *charactersTypedToStartCompletionSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *useSpacesAsTabCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *spacesInTabLabel;
    QSpinBox *spacesInTabSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *highlightSelectionMatchesCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *highlightSelectionMatchesMinLengthLabel;
    QSpinBox *highlightSelectionMatchesMinLengthSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *rememberLastPreviewFrameCheckBox;
    QCheckBox *alwaysKeepCurrentFrameCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *snapshotCompressionLevelLabel;
    QSpinBox *snapshotCompressionLevelSpinBox;
    QSpacerItem *horizontalSpacer_6;
    QFrame *delimiter;
    QLabel *portableModeLabel;
    QCheckBox *portableModeCheckBox;
    QSpacerItem *verticalSpacer;
    QWidget *pathsSettingsTab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *vsLibraryPathsGroupBox;
    QGridLayout *gridLayout_2;
    QListWidget *vsLibraryPathsListWidget;
    QToolButton *removeVSLibraryPathButton;
    QSpacerItem *verticalSpacer_3;
    QToolButton *addVSLibraryPathButton;
    QLineEdit *vsLibraryPathEdit;
    QToolButton *selectVSLibraryPathButton;
    QGroupBox *vsPluginsPathsGroupBox;
    QGridLayout *gridLayout;
    QListWidget *vsPluginsPathsListWidget;
    QToolButton *removeVSPluginsPathButton;
    QSpacerItem *verticalSpacer_2;
    QToolButton *addVSPluginsPathButton;
    QLineEdit *vsPluginsPathEdit;
    QToolButton *selectVSPluginsPathButton;
    QGroupBox *vsDocumentationPathsGroupBox;
    QGridLayout *gridLayout_3;
    QListWidget *vsDocumentationPathsListWidget;
    QToolButton *removeVSDocumentationPathButton;
    QSpacerItem *verticalSpacer_4;
    QToolButton *addVSDocumentationPathButton;
    QLineEdit *vsDocumentationPathEdit;
    QToolButton *selectVSDocumentationPathButton;
    QWidget *hotkeysSettingsTab;
    QVBoxLayout *verticalLayout_4;
    QTableView *hotkeysTable;
    QWidget *themeSettingsTab;
    QVBoxLayout *verticalLayout_5;
    QLabel *themeElementsLabel;
    QListView *themeElementsList;
    QFormLayout *formLayout;
    QPushButton *fontButton;
    QLabel *fontLabel;
    QPushButton *colourButton;
    QFrame *colourFrame;
    QHBoxLayout *decisionButtonsLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(512, 665);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        settingsTabWidget = new QTabWidget(SettingsDialog);
        settingsTabWidget->setObjectName(QStringLiteral("settingsTabWidget"));
        commonSettingsTab = new QWidget();
        commonSettingsTab->setObjectName(QStringLiteral("commonSettingsTab"));
        verticalLayout_2 = new QVBoxLayout(commonSettingsTab);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        autoLoadLastScriptCheckBox = new QCheckBox(commonSettingsTab);
        autoLoadLastScriptCheckBox->setObjectName(QStringLiteral("autoLoadLastScriptCheckBox"));
        autoLoadLastScriptCheckBox->setChecked(true);

        verticalLayout_2->addWidget(autoLoadLastScriptCheckBox);

        promptToSaveChangesCheckBox = new QCheckBox(commonSettingsTab);
        promptToSaveChangesCheckBox->setObjectName(QStringLiteral("promptToSaveChangesCheckBox"));
        promptToSaveChangesCheckBox->setChecked(true);

        verticalLayout_2->addWidget(promptToSaveChangesCheckBox);

        recentFilesSettingsLayout = new QHBoxLayout();
        recentFilesSettingsLayout->setObjectName(QStringLiteral("recentFilesSettingsLayout"));
        maxRecentFilesLabel = new QLabel(commonSettingsTab);
        maxRecentFilesLabel->setObjectName(QStringLiteral("maxRecentFilesLabel"));

        recentFilesSettingsLayout->addWidget(maxRecentFilesLabel);

        maxRecentFilesSpinBox = new QSpinBox(commonSettingsTab);
        maxRecentFilesSpinBox->setObjectName(QStringLiteral("maxRecentFilesSpinBox"));
        maxRecentFilesSpinBox->setMinimum(1);
        maxRecentFilesSpinBox->setValue(10);

        recentFilesSettingsLayout->addWidget(maxRecentFilesSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        recentFilesSettingsLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(recentFilesSettingsLayout);

        autocompletionLayout = new QHBoxLayout();
        autocompletionLayout->setObjectName(QStringLiteral("autocompletionLayout"));
        charactersTypedToStartCompletionLabel = new QLabel(commonSettingsTab);
        charactersTypedToStartCompletionLabel->setObjectName(QStringLiteral("charactersTypedToStartCompletionLabel"));

        autocompletionLayout->addWidget(charactersTypedToStartCompletionLabel);

        charactersTypedToStartCompletionSpinBox = new QSpinBox(commonSettingsTab);
        charactersTypedToStartCompletionSpinBox->setObjectName(QStringLiteral("charactersTypedToStartCompletionSpinBox"));
        charactersTypedToStartCompletionSpinBox->setMinimum(0);
        charactersTypedToStartCompletionSpinBox->setMaximum(10);
        charactersTypedToStartCompletionSpinBox->setValue(2);

        autocompletionLayout->addWidget(charactersTypedToStartCompletionSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        autocompletionLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(autocompletionLayout);

        useSpacesAsTabCheckBox = new QCheckBox(commonSettingsTab);
        useSpacesAsTabCheckBox->setObjectName(QStringLiteral("useSpacesAsTabCheckBox"));

        verticalLayout_2->addWidget(useSpacesAsTabCheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spacesInTabLabel = new QLabel(commonSettingsTab);
        spacesInTabLabel->setObjectName(QStringLiteral("spacesInTabLabel"));

        horizontalLayout->addWidget(spacesInTabLabel);

        spacesInTabSpinBox = new QSpinBox(commonSettingsTab);
        spacesInTabSpinBox->setObjectName(QStringLiteral("spacesInTabSpinBox"));
        spacesInTabSpinBox->setMinimum(1);
        spacesInTabSpinBox->setMaximum(80);
        spacesInTabSpinBox->setValue(4);

        horizontalLayout->addWidget(spacesInTabSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        highlightSelectionMatchesCheckBox = new QCheckBox(commonSettingsTab);
        highlightSelectionMatchesCheckBox->setObjectName(QStringLiteral("highlightSelectionMatchesCheckBox"));

        verticalLayout_2->addWidget(highlightSelectionMatchesCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        highlightSelectionMatchesMinLengthLabel = new QLabel(commonSettingsTab);
        highlightSelectionMatchesMinLengthLabel->setObjectName(QStringLiteral("highlightSelectionMatchesMinLengthLabel"));

        horizontalLayout_2->addWidget(highlightSelectionMatchesMinLengthLabel);

        highlightSelectionMatchesMinLengthSpinBox = new QSpinBox(commonSettingsTab);
        highlightSelectionMatchesMinLengthSpinBox->setObjectName(QStringLiteral("highlightSelectionMatchesMinLengthSpinBox"));
        highlightSelectionMatchesMinLengthSpinBox->setMaximum(80);
        highlightSelectionMatchesMinLengthSpinBox->setValue(3);

        horizontalLayout_2->addWidget(highlightSelectionMatchesMinLengthSpinBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        rememberLastPreviewFrameCheckBox = new QCheckBox(commonSettingsTab);
        rememberLastPreviewFrameCheckBox->setObjectName(QStringLiteral("rememberLastPreviewFrameCheckBox"));

        verticalLayout_2->addWidget(rememberLastPreviewFrameCheckBox);

        alwaysKeepCurrentFrameCheckBox = new QCheckBox(commonSettingsTab);
        alwaysKeepCurrentFrameCheckBox->setObjectName(QStringLiteral("alwaysKeepCurrentFrameCheckBox"));

        verticalLayout_2->addWidget(alwaysKeepCurrentFrameCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        snapshotCompressionLevelLabel = new QLabel(commonSettingsTab);
        snapshotCompressionLevelLabel->setObjectName(QStringLiteral("snapshotCompressionLevelLabel"));

        horizontalLayout_3->addWidget(snapshotCompressionLevelLabel);

        snapshotCompressionLevelSpinBox = new QSpinBox(commonSettingsTab);
        snapshotCompressionLevelSpinBox->setObjectName(QStringLiteral("snapshotCompressionLevelSpinBox"));
        snapshotCompressionLevelSpinBox->setMinimum(0);
        snapshotCompressionLevelSpinBox->setMaximum(100);
        snapshotCompressionLevelSpinBox->setValue(0);

        horizontalLayout_3->addWidget(snapshotCompressionLevelSpinBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        delimiter = new QFrame(commonSettingsTab);
        delimiter->setObjectName(QStringLiteral("delimiter"));
        delimiter->setFrameShape(QFrame::HLine);
        delimiter->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(delimiter);

        portableModeLabel = new QLabel(commonSettingsTab);
        portableModeLabel->setObjectName(QStringLiteral("portableModeLabel"));
        portableModeLabel->setWordWrap(true);

        verticalLayout_2->addWidget(portableModeLabel);

        portableModeCheckBox = new QCheckBox(commonSettingsTab);
        portableModeCheckBox->setObjectName(QStringLiteral("portableModeCheckBox"));

        verticalLayout_2->addWidget(portableModeCheckBox);

        verticalSpacer = new QSpacerItem(20, 171, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        settingsTabWidget->addTab(commonSettingsTab, QString());
        pathsSettingsTab = new QWidget();
        pathsSettingsTab->setObjectName(QStringLiteral("pathsSettingsTab"));
        verticalLayout_3 = new QVBoxLayout(pathsSettingsTab);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        vsLibraryPathsGroupBox = new QGroupBox(pathsSettingsTab);
        vsLibraryPathsGroupBox->setObjectName(QStringLiteral("vsLibraryPathsGroupBox"));
        gridLayout_2 = new QGridLayout(vsLibraryPathsGroupBox);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        vsLibraryPathsListWidget = new QListWidget(vsLibraryPathsGroupBox);
        vsLibraryPathsListWidget->setObjectName(QStringLiteral("vsLibraryPathsListWidget"));
        vsLibraryPathsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vsLibraryPathsListWidget->setAlternatingRowColors(true);
        vsLibraryPathsListWidget->setTextElideMode(Qt::ElideNone);

        gridLayout_2->addWidget(vsLibraryPathsListWidget, 0, 0, 3, 1);

        removeVSLibraryPathButton = new QToolButton(vsLibraryPathsGroupBox);
        removeVSLibraryPathButton->setObjectName(QStringLiteral("removeVSLibraryPathButton"));

        gridLayout_2->addWidget(removeVSLibraryPathButton, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 1, 1, 1);

        addVSLibraryPathButton = new QToolButton(vsLibraryPathsGroupBox);
        addVSLibraryPathButton->setObjectName(QStringLiteral("addVSLibraryPathButton"));

        gridLayout_2->addWidget(addVSLibraryPathButton, 2, 1, 1, 1);

        vsLibraryPathEdit = new QLineEdit(vsLibraryPathsGroupBox);
        vsLibraryPathEdit->setObjectName(QStringLiteral("vsLibraryPathEdit"));

        gridLayout_2->addWidget(vsLibraryPathEdit, 3, 0, 1, 1);

        selectVSLibraryPathButton = new QToolButton(vsLibraryPathsGroupBox);
        selectVSLibraryPathButton->setObjectName(QStringLiteral("selectVSLibraryPathButton"));

        gridLayout_2->addWidget(selectVSLibraryPathButton, 3, 1, 1, 1);


        verticalLayout_3->addWidget(vsLibraryPathsGroupBox);

        vsPluginsPathsGroupBox = new QGroupBox(pathsSettingsTab);
        vsPluginsPathsGroupBox->setObjectName(QStringLiteral("vsPluginsPathsGroupBox"));
        gridLayout = new QGridLayout(vsPluginsPathsGroupBox);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        vsPluginsPathsListWidget = new QListWidget(vsPluginsPathsGroupBox);
        vsPluginsPathsListWidget->setObjectName(QStringLiteral("vsPluginsPathsListWidget"));
        vsPluginsPathsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vsPluginsPathsListWidget->setAlternatingRowColors(true);
        vsPluginsPathsListWidget->setTextElideMode(Qt::ElideNone);

        gridLayout->addWidget(vsPluginsPathsListWidget, 0, 0, 3, 1);

        removeVSPluginsPathButton = new QToolButton(vsPluginsPathsGroupBox);
        removeVSPluginsPathButton->setObjectName(QStringLiteral("removeVSPluginsPathButton"));

        gridLayout->addWidget(removeVSPluginsPathButton, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        addVSPluginsPathButton = new QToolButton(vsPluginsPathsGroupBox);
        addVSPluginsPathButton->setObjectName(QStringLiteral("addVSPluginsPathButton"));

        gridLayout->addWidget(addVSPluginsPathButton, 2, 1, 1, 1);

        vsPluginsPathEdit = new QLineEdit(vsPluginsPathsGroupBox);
        vsPluginsPathEdit->setObjectName(QStringLiteral("vsPluginsPathEdit"));

        gridLayout->addWidget(vsPluginsPathEdit, 3, 0, 1, 1);

        selectVSPluginsPathButton = new QToolButton(vsPluginsPathsGroupBox);
        selectVSPluginsPathButton->setObjectName(QStringLiteral("selectVSPluginsPathButton"));

        gridLayout->addWidget(selectVSPluginsPathButton, 3, 1, 1, 1);


        verticalLayout_3->addWidget(vsPluginsPathsGroupBox);

        vsDocumentationPathsGroupBox = new QGroupBox(pathsSettingsTab);
        vsDocumentationPathsGroupBox->setObjectName(QStringLiteral("vsDocumentationPathsGroupBox"));
        gridLayout_3 = new QGridLayout(vsDocumentationPathsGroupBox);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        vsDocumentationPathsListWidget = new QListWidget(vsDocumentationPathsGroupBox);
        vsDocumentationPathsListWidget->setObjectName(QStringLiteral("vsDocumentationPathsListWidget"));
        vsDocumentationPathsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vsDocumentationPathsListWidget->setAlternatingRowColors(true);
        vsDocumentationPathsListWidget->setTextElideMode(Qt::ElideNone);

        gridLayout_3->addWidget(vsDocumentationPathsListWidget, 0, 0, 3, 1);

        removeVSDocumentationPathButton = new QToolButton(vsDocumentationPathsGroupBox);
        removeVSDocumentationPathButton->setObjectName(QStringLiteral("removeVSDocumentationPathButton"));

        gridLayout_3->addWidget(removeVSDocumentationPathButton, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 1, 1, 1, 1);

        addVSDocumentationPathButton = new QToolButton(vsDocumentationPathsGroupBox);
        addVSDocumentationPathButton->setObjectName(QStringLiteral("addVSDocumentationPathButton"));

        gridLayout_3->addWidget(addVSDocumentationPathButton, 2, 1, 1, 1);

        vsDocumentationPathEdit = new QLineEdit(vsDocumentationPathsGroupBox);
        vsDocumentationPathEdit->setObjectName(QStringLiteral("vsDocumentationPathEdit"));

        gridLayout_3->addWidget(vsDocumentationPathEdit, 3, 0, 1, 1);

        selectVSDocumentationPathButton = new QToolButton(vsDocumentationPathsGroupBox);
        selectVSDocumentationPathButton->setObjectName(QStringLiteral("selectVSDocumentationPathButton"));

        gridLayout_3->addWidget(selectVSDocumentationPathButton, 3, 1, 1, 1);


        verticalLayout_3->addWidget(vsDocumentationPathsGroupBox);

        settingsTabWidget->addTab(pathsSettingsTab, QString());
        hotkeysSettingsTab = new QWidget();
        hotkeysSettingsTab->setObjectName(QStringLiteral("hotkeysSettingsTab"));
        verticalLayout_4 = new QVBoxLayout(hotkeysSettingsTab);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        hotkeysTable = new QTableView(hotkeysSettingsTab);
        hotkeysTable->setObjectName(QStringLiteral("hotkeysTable"));
        hotkeysTable->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        hotkeysTable->setAlternatingRowColors(true);
        hotkeysTable->setSelectionMode(QAbstractItemView::SingleSelection);
        hotkeysTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        hotkeysTable->setTextElideMode(Qt::ElideNone);
        hotkeysTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        hotkeysTable->horizontalHeader()->setVisible(false);
        hotkeysTable->horizontalHeader()->setStretchLastSection(true);
        hotkeysTable->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(hotkeysTable);

        settingsTabWidget->addTab(hotkeysSettingsTab, QString());
        themeSettingsTab = new QWidget();
        themeSettingsTab->setObjectName(QStringLiteral("themeSettingsTab"));
        themeSettingsTab->setContextMenuPolicy(Qt::PreventContextMenu);
        verticalLayout_5 = new QVBoxLayout(themeSettingsTab);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 6, 6, 6);
        themeElementsLabel = new QLabel(themeSettingsTab);
        themeElementsLabel->setObjectName(QStringLiteral("themeElementsLabel"));

        verticalLayout_5->addWidget(themeElementsLabel);

        themeElementsList = new QListView(themeSettingsTab);
        themeElementsList->setObjectName(QStringLiteral("themeElementsList"));
        themeElementsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        themeElementsList->setSelectionBehavior(QAbstractItemView::SelectRows);
        themeElementsList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        themeElementsList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        themeElementsList->setResizeMode(QListView::Adjust);

        verticalLayout_5->addWidget(themeElementsList);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        fontButton = new QPushButton(themeSettingsTab);
        fontButton->setObjectName(QStringLiteral("fontButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fontButton);

        fontLabel = new QLabel(themeSettingsTab);
        fontLabel->setObjectName(QStringLiteral("fontLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fontLabel->sizePolicy().hasHeightForWidth());
        fontLabel->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, fontLabel);

        colourButton = new QPushButton(themeSettingsTab);
        colourButton->setObjectName(QStringLiteral("colourButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, colourButton);

        colourFrame = new QFrame(themeSettingsTab);
        colourFrame->setObjectName(QStringLiteral("colourFrame"));
        colourFrame->setAutoFillBackground(true);
        colourFrame->setFrameShape(QFrame::Box);
        colourFrame->setFrameShadow(QFrame::Plain);

        formLayout->setWidget(1, QFormLayout::FieldRole, colourFrame);


        verticalLayout_5->addLayout(formLayout);

        settingsTabWidget->addTab(themeSettingsTab, QString());

        verticalLayout->addWidget(settingsTabWidget);

        decisionButtonsLayout = new QHBoxLayout();
        decisionButtonsLayout->setSpacing(2);
        decisionButtonsLayout->setObjectName(QStringLiteral("decisionButtonsLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        decisionButtonsLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(SettingsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        decisionButtonsLayout->addWidget(okButton);

        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        decisionButtonsLayout->addWidget(applyButton);

        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        decisionButtonsLayout->addWidget(cancelButton);


        verticalLayout->addLayout(decisionButtonsLayout);


        retranslateUi(SettingsDialog);

        settingsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings - VapourSynth Editor", Q_NULLPTR));
        autoLoadLastScriptCheckBox->setText(QApplication::translate("SettingsDialog", "Automatically load the last script", Q_NULLPTR));
        promptToSaveChangesCheckBox->setText(QApplication::translate("SettingsDialog", "Prompt to save changes when closing script file", Q_NULLPTR));
        maxRecentFilesLabel->setText(QApplication::translate("SettingsDialog", "Limit the number of recent scripts in history to", Q_NULLPTR));
        charactersTypedToStartCompletionLabel->setText(QApplication::translate("SettingsDialog", "Characters typed to start autocompletion", Q_NULLPTR));
        useSpacesAsTabCheckBox->setText(QApplication::translate("SettingsDialog", "Use spaces as Tab", Q_NULLPTR));
        spacesInTabLabel->setText(QApplication::translate("SettingsDialog", "Space characters in Tab", Q_NULLPTR));
        highlightSelectionMatchesCheckBox->setText(QApplication::translate("SettingsDialog", "Highlight selection matches", Q_NULLPTR));
        highlightSelectionMatchesMinLengthLabel->setText(QApplication::translate("SettingsDialog", "Minimum legth to highlight", Q_NULLPTR));
        rememberLastPreviewFrameCheckBox->setText(QApplication::translate("SettingsDialog", "Remember last previewed frame on exit", Q_NULLPTR));
        alwaysKeepCurrentFrameCheckBox->setText(QApplication::translate("SettingsDialog", "Keep current frame when previewing different script", Q_NULLPTR));
        snapshotCompressionLevelLabel->setText(QApplication::translate("SettingsDialog", "PNG snapshot compression level (0-100 for size factor)", Q_NULLPTR));
        portableModeLabel->setText(QApplication::translate("SettingsDialog", "Portable mode means that editor stores its settings in the same folder with its executable. Editors determines if it is running in portable mode by looking for the configuration file in its folder. Please make sure you have the rights to write files in the editor's folder before you switch to this mode.", Q_NULLPTR));
        portableModeCheckBox->setText(QApplication::translate("SettingsDialog", "Portable mode enabled", Q_NULLPTR));
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(commonSettingsTab), QApplication::translate("SettingsDialog", "Common", Q_NULLPTR));
        vsLibraryPathsGroupBox->setTitle(QApplication::translate("SettingsDialog", "VapourSynth library search paths", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        removeVSLibraryPathButton->setToolTip(QApplication::translate("SettingsDialog", "Remove VapourSynth library search path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeVSLibraryPathButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        addVSLibraryPathButton->setToolTip(QApplication::translate("SettingsDialog", "Add VapourSynth library search path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addVSLibraryPathButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectVSLibraryPathButton->setToolTip(QApplication::translate("SettingsDialog", "Select path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        selectVSLibraryPathButton->setText(QString());
        vsPluginsPathsGroupBox->setTitle(QApplication::translate("SettingsDialog", "VapourSynth plugins paths", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        removeVSPluginsPathButton->setToolTip(QApplication::translate("SettingsDialog", "Remove VapourSynth plugins path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeVSPluginsPathButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        addVSPluginsPathButton->setToolTip(QApplication::translate("SettingsDialog", "Add VapourSynth plugins path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addVSPluginsPathButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectVSPluginsPathButton->setToolTip(QApplication::translate("SettingsDialog", "Select path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        selectVSPluginsPathButton->setText(QString());
        vsDocumentationPathsGroupBox->setTitle(QApplication::translate("SettingsDialog", "Documentation paths", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        removeVSDocumentationPathButton->setToolTip(QApplication::translate("SettingsDialog", "Remove VapourSynth documentation path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeVSDocumentationPathButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        addVSDocumentationPathButton->setToolTip(QApplication::translate("SettingsDialog", "Add VapourSynth documentation path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addVSDocumentationPathButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectVSDocumentationPathButton->setToolTip(QApplication::translate("SettingsDialog", "Select path", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        selectVSDocumentationPathButton->setText(QString());
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(pathsSettingsTab), QApplication::translate("SettingsDialog", "Paths", Q_NULLPTR));
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(hotkeysSettingsTab), QApplication::translate("SettingsDialog", "Hotkeys", Q_NULLPTR));
        themeElementsLabel->setText(QApplication::translate("SettingsDialog", "Theme elements", Q_NULLPTR));
        fontButton->setText(QApplication::translate("SettingsDialog", "Font", Q_NULLPTR));
        fontLabel->setText(QString());
        colourButton->setText(QApplication::translate("SettingsDialog", "Colour", Q_NULLPTR));
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(themeSettingsTab), QApplication::translate("SettingsDialog", "Theme", Q_NULLPTR));
        okButton->setText(QApplication::translate("SettingsDialog", "OK", Q_NULLPTR));
        applyButton->setText(QApplication::translate("SettingsDialog", "Apply", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SettingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_DIALOG_H
