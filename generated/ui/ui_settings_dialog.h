/********************************************************************************
** Form generated from reading UI file 'settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_DIALOG_H
#define UI_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(512, 665);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        settingsTabWidget = new QTabWidget(SettingsDialog);
        settingsTabWidget->setObjectName(QString::fromUtf8("settingsTabWidget"));
        commonSettingsTab = new QWidget();
        commonSettingsTab->setObjectName(QString::fromUtf8("commonSettingsTab"));
        verticalLayout_2 = new QVBoxLayout(commonSettingsTab);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        autoLoadLastScriptCheckBox = new QCheckBox(commonSettingsTab);
        autoLoadLastScriptCheckBox->setObjectName(QString::fromUtf8("autoLoadLastScriptCheckBox"));
        autoLoadLastScriptCheckBox->setChecked(true);

        verticalLayout_2->addWidget(autoLoadLastScriptCheckBox);

        promptToSaveChangesCheckBox = new QCheckBox(commonSettingsTab);
        promptToSaveChangesCheckBox->setObjectName(QString::fromUtf8("promptToSaveChangesCheckBox"));
        promptToSaveChangesCheckBox->setChecked(true);

        verticalLayout_2->addWidget(promptToSaveChangesCheckBox);

        recentFilesSettingsLayout = new QHBoxLayout();
        recentFilesSettingsLayout->setObjectName(QString::fromUtf8("recentFilesSettingsLayout"));
        maxRecentFilesLabel = new QLabel(commonSettingsTab);
        maxRecentFilesLabel->setObjectName(QString::fromUtf8("maxRecentFilesLabel"));

        recentFilesSettingsLayout->addWidget(maxRecentFilesLabel);

        maxRecentFilesSpinBox = new QSpinBox(commonSettingsTab);
        maxRecentFilesSpinBox->setObjectName(QString::fromUtf8("maxRecentFilesSpinBox"));
        maxRecentFilesSpinBox->setMinimum(1);
        maxRecentFilesSpinBox->setValue(10);

        recentFilesSettingsLayout->addWidget(maxRecentFilesSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        recentFilesSettingsLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(recentFilesSettingsLayout);

        autocompletionLayout = new QHBoxLayout();
        autocompletionLayout->setObjectName(QString::fromUtf8("autocompletionLayout"));
        charactersTypedToStartCompletionLabel = new QLabel(commonSettingsTab);
        charactersTypedToStartCompletionLabel->setObjectName(QString::fromUtf8("charactersTypedToStartCompletionLabel"));

        autocompletionLayout->addWidget(charactersTypedToStartCompletionLabel);

        charactersTypedToStartCompletionSpinBox = new QSpinBox(commonSettingsTab);
        charactersTypedToStartCompletionSpinBox->setObjectName(QString::fromUtf8("charactersTypedToStartCompletionSpinBox"));
        charactersTypedToStartCompletionSpinBox->setMinimum(0);
        charactersTypedToStartCompletionSpinBox->setMaximum(10);
        charactersTypedToStartCompletionSpinBox->setValue(2);

        autocompletionLayout->addWidget(charactersTypedToStartCompletionSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        autocompletionLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(autocompletionLayout);

        useSpacesAsTabCheckBox = new QCheckBox(commonSettingsTab);
        useSpacesAsTabCheckBox->setObjectName(QString::fromUtf8("useSpacesAsTabCheckBox"));

        verticalLayout_2->addWidget(useSpacesAsTabCheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacesInTabLabel = new QLabel(commonSettingsTab);
        spacesInTabLabel->setObjectName(QString::fromUtf8("spacesInTabLabel"));

        horizontalLayout->addWidget(spacesInTabLabel);

        spacesInTabSpinBox = new QSpinBox(commonSettingsTab);
        spacesInTabSpinBox->setObjectName(QString::fromUtf8("spacesInTabSpinBox"));
        spacesInTabSpinBox->setMinimum(1);
        spacesInTabSpinBox->setMaximum(80);
        spacesInTabSpinBox->setValue(4);

        horizontalLayout->addWidget(spacesInTabSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        highlightSelectionMatchesCheckBox = new QCheckBox(commonSettingsTab);
        highlightSelectionMatchesCheckBox->setObjectName(QString::fromUtf8("highlightSelectionMatchesCheckBox"));

        verticalLayout_2->addWidget(highlightSelectionMatchesCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        highlightSelectionMatchesMinLengthLabel = new QLabel(commonSettingsTab);
        highlightSelectionMatchesMinLengthLabel->setObjectName(QString::fromUtf8("highlightSelectionMatchesMinLengthLabel"));

        horizontalLayout_2->addWidget(highlightSelectionMatchesMinLengthLabel);

        highlightSelectionMatchesMinLengthSpinBox = new QSpinBox(commonSettingsTab);
        highlightSelectionMatchesMinLengthSpinBox->setObjectName(QString::fromUtf8("highlightSelectionMatchesMinLengthSpinBox"));
        highlightSelectionMatchesMinLengthSpinBox->setMaximum(80);
        highlightSelectionMatchesMinLengthSpinBox->setValue(3);

        horizontalLayout_2->addWidget(highlightSelectionMatchesMinLengthSpinBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        rememberLastPreviewFrameCheckBox = new QCheckBox(commonSettingsTab);
        rememberLastPreviewFrameCheckBox->setObjectName(QString::fromUtf8("rememberLastPreviewFrameCheckBox"));

        verticalLayout_2->addWidget(rememberLastPreviewFrameCheckBox);

        alwaysKeepCurrentFrameCheckBox = new QCheckBox(commonSettingsTab);
        alwaysKeepCurrentFrameCheckBox->setObjectName(QString::fromUtf8("alwaysKeepCurrentFrameCheckBox"));

        verticalLayout_2->addWidget(alwaysKeepCurrentFrameCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        snapshotCompressionLevelLabel = new QLabel(commonSettingsTab);
        snapshotCompressionLevelLabel->setObjectName(QString::fromUtf8("snapshotCompressionLevelLabel"));

        horizontalLayout_3->addWidget(snapshotCompressionLevelLabel);

        snapshotCompressionLevelSpinBox = new QSpinBox(commonSettingsTab);
        snapshotCompressionLevelSpinBox->setObjectName(QString::fromUtf8("snapshotCompressionLevelSpinBox"));
        snapshotCompressionLevelSpinBox->setMaximum(100);
        snapshotCompressionLevelSpinBox->setMinimum(0);
        snapshotCompressionLevelSpinBox->setValue(0);

        horizontalLayout_3->addWidget(snapshotCompressionLevelSpinBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        delimiter = new QFrame(commonSettingsTab);
        delimiter->setObjectName(QString::fromUtf8("delimiter"));
        delimiter->setFrameShape(QFrame::HLine);
        delimiter->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(delimiter);

        portableModeLabel = new QLabel(commonSettingsTab);
        portableModeLabel->setObjectName(QString::fromUtf8("portableModeLabel"));
        portableModeLabel->setWordWrap(true);

        verticalLayout_2->addWidget(portableModeLabel);

        portableModeCheckBox = new QCheckBox(commonSettingsTab);
        portableModeCheckBox->setObjectName(QString::fromUtf8("portableModeCheckBox"));

        verticalLayout_2->addWidget(portableModeCheckBox);

        verticalSpacer = new QSpacerItem(20, 171, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        settingsTabWidget->addTab(commonSettingsTab, QString());
        pathsSettingsTab = new QWidget();
        pathsSettingsTab->setObjectName(QString::fromUtf8("pathsSettingsTab"));
        verticalLayout_3 = new QVBoxLayout(pathsSettingsTab);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        vsLibraryPathsGroupBox = new QGroupBox(pathsSettingsTab);
        vsLibraryPathsGroupBox->setObjectName(QString::fromUtf8("vsLibraryPathsGroupBox"));
        gridLayout_2 = new QGridLayout(vsLibraryPathsGroupBox);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        vsLibraryPathsListWidget = new QListWidget(vsLibraryPathsGroupBox);
        vsLibraryPathsListWidget->setObjectName(QString::fromUtf8("vsLibraryPathsListWidget"));
        vsLibraryPathsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vsLibraryPathsListWidget->setAlternatingRowColors(true);
        vsLibraryPathsListWidget->setTextElideMode(Qt::ElideNone);

        gridLayout_2->addWidget(vsLibraryPathsListWidget, 0, 0, 3, 1);

        removeVSLibraryPathButton = new QToolButton(vsLibraryPathsGroupBox);
        removeVSLibraryPathButton->setObjectName(QString::fromUtf8("removeVSLibraryPathButton"));

        gridLayout_2->addWidget(removeVSLibraryPathButton, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 1, 1, 1);

        addVSLibraryPathButton = new QToolButton(vsLibraryPathsGroupBox);
        addVSLibraryPathButton->setObjectName(QString::fromUtf8("addVSLibraryPathButton"));

        gridLayout_2->addWidget(addVSLibraryPathButton, 2, 1, 1, 1);

        vsLibraryPathEdit = new QLineEdit(vsLibraryPathsGroupBox);
        vsLibraryPathEdit->setObjectName(QString::fromUtf8("vsLibraryPathEdit"));

        gridLayout_2->addWidget(vsLibraryPathEdit, 3, 0, 1, 1);

        selectVSLibraryPathButton = new QToolButton(vsLibraryPathsGroupBox);
        selectVSLibraryPathButton->setObjectName(QString::fromUtf8("selectVSLibraryPathButton"));

        gridLayout_2->addWidget(selectVSLibraryPathButton, 3, 1, 1, 1);


        verticalLayout_3->addWidget(vsLibraryPathsGroupBox);

        vsPluginsPathsGroupBox = new QGroupBox(pathsSettingsTab);
        vsPluginsPathsGroupBox->setObjectName(QString::fromUtf8("vsPluginsPathsGroupBox"));
        gridLayout = new QGridLayout(vsPluginsPathsGroupBox);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        vsPluginsPathsListWidget = new QListWidget(vsPluginsPathsGroupBox);
        vsPluginsPathsListWidget->setObjectName(QString::fromUtf8("vsPluginsPathsListWidget"));
        vsPluginsPathsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vsPluginsPathsListWidget->setAlternatingRowColors(true);
        vsPluginsPathsListWidget->setTextElideMode(Qt::ElideNone);

        gridLayout->addWidget(vsPluginsPathsListWidget, 0, 0, 3, 1);

        removeVSPluginsPathButton = new QToolButton(vsPluginsPathsGroupBox);
        removeVSPluginsPathButton->setObjectName(QString::fromUtf8("removeVSPluginsPathButton"));

        gridLayout->addWidget(removeVSPluginsPathButton, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        addVSPluginsPathButton = new QToolButton(vsPluginsPathsGroupBox);
        addVSPluginsPathButton->setObjectName(QString::fromUtf8("addVSPluginsPathButton"));

        gridLayout->addWidget(addVSPluginsPathButton, 2, 1, 1, 1);

        vsPluginsPathEdit = new QLineEdit(vsPluginsPathsGroupBox);
        vsPluginsPathEdit->setObjectName(QString::fromUtf8("vsPluginsPathEdit"));

        gridLayout->addWidget(vsPluginsPathEdit, 3, 0, 1, 1);

        selectVSPluginsPathButton = new QToolButton(vsPluginsPathsGroupBox);
        selectVSPluginsPathButton->setObjectName(QString::fromUtf8("selectVSPluginsPathButton"));

        gridLayout->addWidget(selectVSPluginsPathButton, 3, 1, 1, 1);


        verticalLayout_3->addWidget(vsPluginsPathsGroupBox);

        vsDocumentationPathsGroupBox = new QGroupBox(pathsSettingsTab);
        vsDocumentationPathsGroupBox->setObjectName(QString::fromUtf8("vsDocumentationPathsGroupBox"));
        gridLayout_3 = new QGridLayout(vsDocumentationPathsGroupBox);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        vsDocumentationPathsListWidget = new QListWidget(vsDocumentationPathsGroupBox);
        vsDocumentationPathsListWidget->setObjectName(QString::fromUtf8("vsDocumentationPathsListWidget"));
        vsDocumentationPathsListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vsDocumentationPathsListWidget->setAlternatingRowColors(true);
        vsDocumentationPathsListWidget->setTextElideMode(Qt::ElideNone);

        gridLayout_3->addWidget(vsDocumentationPathsListWidget, 0, 0, 3, 1);

        removeVSDocumentationPathButton = new QToolButton(vsDocumentationPathsGroupBox);
        removeVSDocumentationPathButton->setObjectName(QString::fromUtf8("removeVSDocumentationPathButton"));

        gridLayout_3->addWidget(removeVSDocumentationPathButton, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 124, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 1, 1, 1, 1);

        addVSDocumentationPathButton = new QToolButton(vsDocumentationPathsGroupBox);
        addVSDocumentationPathButton->setObjectName(QString::fromUtf8("addVSDocumentationPathButton"));

        gridLayout_3->addWidget(addVSDocumentationPathButton, 2, 1, 1, 1);

        vsDocumentationPathEdit = new QLineEdit(vsDocumentationPathsGroupBox);
        vsDocumentationPathEdit->setObjectName(QString::fromUtf8("vsDocumentationPathEdit"));

        gridLayout_3->addWidget(vsDocumentationPathEdit, 3, 0, 1, 1);

        selectVSDocumentationPathButton = new QToolButton(vsDocumentationPathsGroupBox);
        selectVSDocumentationPathButton->setObjectName(QString::fromUtf8("selectVSDocumentationPathButton"));

        gridLayout_3->addWidget(selectVSDocumentationPathButton, 3, 1, 1, 1);


        verticalLayout_3->addWidget(vsDocumentationPathsGroupBox);

        settingsTabWidget->addTab(pathsSettingsTab, QString());
        hotkeysSettingsTab = new QWidget();
        hotkeysSettingsTab->setObjectName(QString::fromUtf8("hotkeysSettingsTab"));
        verticalLayout_4 = new QVBoxLayout(hotkeysSettingsTab);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        hotkeysTable = new QTableView(hotkeysSettingsTab);
        hotkeysTable->setObjectName(QString::fromUtf8("hotkeysTable"));
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
        themeSettingsTab->setObjectName(QString::fromUtf8("themeSettingsTab"));
        themeSettingsTab->setContextMenuPolicy(Qt::PreventContextMenu);
        verticalLayout_5 = new QVBoxLayout(themeSettingsTab);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 6, 6, 6);
        themeElementsLabel = new QLabel(themeSettingsTab);
        themeElementsLabel->setObjectName(QString::fromUtf8("themeElementsLabel"));

        verticalLayout_5->addWidget(themeElementsLabel);

        themeElementsList = new QListView(themeSettingsTab);
        themeElementsList->setObjectName(QString::fromUtf8("themeElementsList"));
        themeElementsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        themeElementsList->setSelectionBehavior(QAbstractItemView::SelectRows);
        themeElementsList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        themeElementsList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        themeElementsList->setResizeMode(QListView::Adjust);

        verticalLayout_5->addWidget(themeElementsList);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        fontButton = new QPushButton(themeSettingsTab);
        fontButton->setObjectName(QString::fromUtf8("fontButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fontButton);

        fontLabel = new QLabel(themeSettingsTab);
        fontLabel->setObjectName(QString::fromUtf8("fontLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fontLabel->sizePolicy().hasHeightForWidth());
        fontLabel->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, fontLabel);

        colourButton = new QPushButton(themeSettingsTab);
        colourButton->setObjectName(QString::fromUtf8("colourButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, colourButton);

        colourFrame = new QFrame(themeSettingsTab);
        colourFrame->setObjectName(QString::fromUtf8("colourFrame"));
        colourFrame->setAutoFillBackground(true);
        colourFrame->setFrameShape(QFrame::Box);
        colourFrame->setFrameShadow(QFrame::Plain);

        formLayout->setWidget(1, QFormLayout::FieldRole, colourFrame);


        verticalLayout_5->addLayout(formLayout);

        settingsTabWidget->addTab(themeSettingsTab, QString());

        verticalLayout->addWidget(settingsTabWidget);

        decisionButtonsLayout = new QHBoxLayout();
        decisionButtonsLayout->setSpacing(2);
        decisionButtonsLayout->setObjectName(QString::fromUtf8("decisionButtonsLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        decisionButtonsLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(SettingsDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        decisionButtonsLayout->addWidget(okButton);

        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        decisionButtonsLayout->addWidget(applyButton);

        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        decisionButtonsLayout->addWidget(cancelButton);


        verticalLayout->addLayout(decisionButtonsLayout);


        retranslateUi(SettingsDialog);

        settingsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Settings - VapourSynth Editor", nullptr));
        autoLoadLastScriptCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Automatically load the last script", nullptr));
        promptToSaveChangesCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Prompt to save changes when closing script file", nullptr));
        maxRecentFilesLabel->setText(QCoreApplication::translate("SettingsDialog", "Limit the number of recent scripts in history to", nullptr));
        charactersTypedToStartCompletionLabel->setText(QCoreApplication::translate("SettingsDialog", "Characters typed to start autocompletion", nullptr));
        useSpacesAsTabCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Use spaces as Tab", nullptr));
        spacesInTabLabel->setText(QCoreApplication::translate("SettingsDialog", "Space characters in Tab", nullptr));
        highlightSelectionMatchesCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Highlight selection matches", nullptr));
        highlightSelectionMatchesMinLengthLabel->setText(QCoreApplication::translate("SettingsDialog", "Minimum legth to highlight", nullptr));
        rememberLastPreviewFrameCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Remember last previewed frame on exit", nullptr));
        alwaysKeepCurrentFrameCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Keep current frame when previewing different script", nullptr));
        snapshotCompressionLevelLabel->setText(QCoreApplication::translate("SettingsDialog", "PNG snapshot compression level (0 - 100 for size factor)", nullptr));
        portableModeLabel->setText(QCoreApplication::translate("SettingsDialog", "Portable mode means that editor stores its settings in the same folder with its executable. Editors determines if it is running in portable mode by looking for the configuration file in its folder. Please make sure you have the rights to write files in the editor's folder before you switch to this mode.", nullptr));
        portableModeCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Portable mode enabled", nullptr));
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(commonSettingsTab), QCoreApplication::translate("SettingsDialog", "Common", nullptr));
        vsLibraryPathsGroupBox->setTitle(QCoreApplication::translate("SettingsDialog", "VapourSynth library search paths", nullptr));
#if QT_CONFIG(tooltip)
        removeVSLibraryPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Remove VapourSynth library search path", nullptr));
#endif // QT_CONFIG(tooltip)
        removeVSLibraryPathButton->setText(QString());
#if QT_CONFIG(tooltip)
        addVSLibraryPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Add VapourSynth library search path", nullptr));
#endif // QT_CONFIG(tooltip)
        addVSLibraryPathButton->setText(QString());
#if QT_CONFIG(tooltip)
        selectVSLibraryPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Select path", nullptr));
#endif // QT_CONFIG(tooltip)
        selectVSLibraryPathButton->setText(QString());
        vsPluginsPathsGroupBox->setTitle(QCoreApplication::translate("SettingsDialog", "VapourSynth plugins paths", nullptr));
#if QT_CONFIG(tooltip)
        removeVSPluginsPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Remove VapourSynth plugins path", nullptr));
#endif // QT_CONFIG(tooltip)
        removeVSPluginsPathButton->setText(QString());
#if QT_CONFIG(tooltip)
        addVSPluginsPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Add VapourSynth plugins path", nullptr));
#endif // QT_CONFIG(tooltip)
        addVSPluginsPathButton->setText(QString());
#if QT_CONFIG(tooltip)
        selectVSPluginsPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Select path", nullptr));
#endif // QT_CONFIG(tooltip)
        selectVSPluginsPathButton->setText(QString());
        vsDocumentationPathsGroupBox->setTitle(QCoreApplication::translate("SettingsDialog", "Documentation paths", nullptr));
#if QT_CONFIG(tooltip)
        removeVSDocumentationPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Remove VapourSynth documentation path", nullptr));
#endif // QT_CONFIG(tooltip)
        removeVSDocumentationPathButton->setText(QString());
#if QT_CONFIG(tooltip)
        addVSDocumentationPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Add VapourSynth documentation path", nullptr));
#endif // QT_CONFIG(tooltip)
        addVSDocumentationPathButton->setText(QString());
#if QT_CONFIG(tooltip)
        selectVSDocumentationPathButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Select path", nullptr));
#endif // QT_CONFIG(tooltip)
        selectVSDocumentationPathButton->setText(QString());
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(pathsSettingsTab), QCoreApplication::translate("SettingsDialog", "Paths", nullptr));
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(hotkeysSettingsTab), QCoreApplication::translate("SettingsDialog", "Hotkeys", nullptr));
        themeElementsLabel->setText(QCoreApplication::translate("SettingsDialog", "Theme elements", nullptr));
        fontButton->setText(QCoreApplication::translate("SettingsDialog", "Font", nullptr));
        fontLabel->setText(QString());
        colourButton->setText(QCoreApplication::translate("SettingsDialog", "Colour", nullptr));
        settingsTabWidget->setTabText(settingsTabWidget->indexOf(themeSettingsTab), QCoreApplication::translate("SettingsDialog", "Theme", nullptr));
        okButton->setText(QCoreApplication::translate("SettingsDialog", "OK", nullptr));
        applyButton->setText(QCoreApplication::translate("SettingsDialog", "Apply", nullptr));
        cancelButton->setText(QCoreApplication::translate("SettingsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_DIALOG_H
