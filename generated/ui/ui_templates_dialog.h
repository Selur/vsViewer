/********************************************************************************
** Form generated from reading UI file 'templates_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATES_DIALOG_H
#define UI_TEMPLATES_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "script_editor/script_editor.h"

QT_BEGIN_NAMESPACE

class Ui_TemplatesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *templatesTabWidget;
    QWidget *codeSnippetsTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *snippetNameComboBox;
    QPushButton *snippetPasteIntoScriptButton;
    QPushButton *snippetSaveButton;
    QPushButton *snippetDeleteButton;
    ScriptEditor *snippetEdit;
    QWidget *newScriptTemplateTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *newScriptTemplateRevertButton;
    QPushButton *newScriptTemplateLoadDefaultButton;
    QPushButton *newScriptTemplateSaveButton;
    ScriptEditor *newScriptTemplateEdit;
    QWidget *fileDropTemplatesTab;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QTableView *dropFileCategoryView;
    QVBoxLayout *verticalLayout_4;
    QPushButton *saveDropFileCategoriesButton;
    QPushButton *revertDropFileCategoriesButton;
    QPushButton *addDropFileCategoryButton;
    QPushButton *deleteSelectedDropFileCategoryButton;
    QSpacerItem *verticalSpacer;
    QLabel *fileDropTemplatesInfoLabel;
    ScriptEditor *dropFileCategoryTemplateEdit;

    void setupUi(QDialog *TemplatesDialog)
    {
        if (TemplatesDialog->objectName().isEmpty())
            TemplatesDialog->setObjectName(QStringLiteral("TemplatesDialog"));
        TemplatesDialog->resize(770, 578);
        verticalLayout = new QVBoxLayout(TemplatesDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        templatesTabWidget = new QTabWidget(TemplatesDialog);
        templatesTabWidget->setObjectName(QStringLiteral("templatesTabWidget"));
        codeSnippetsTab = new QWidget();
        codeSnippetsTab->setObjectName(QStringLiteral("codeSnippetsTab"));
        verticalLayout_3 = new QVBoxLayout(codeSnippetsTab);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        snippetNameComboBox = new QComboBox(codeSnippetsTab);
        snippetNameComboBox->setObjectName(QStringLiteral("snippetNameComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(snippetNameComboBox->sizePolicy().hasHeightForWidth());
        snippetNameComboBox->setSizePolicy(sizePolicy);
        snippetNameComboBox->setEditable(true);
        snippetNameComboBox->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_2->addWidget(snippetNameComboBox);

        snippetPasteIntoScriptButton = new QPushButton(codeSnippetsTab);
        snippetPasteIntoScriptButton->setObjectName(QStringLiteral("snippetPasteIntoScriptButton"));

        horizontalLayout_2->addWidget(snippetPasteIntoScriptButton);

        snippetSaveButton = new QPushButton(codeSnippetsTab);
        snippetSaveButton->setObjectName(QStringLiteral("snippetSaveButton"));

        horizontalLayout_2->addWidget(snippetSaveButton);

        snippetDeleteButton = new QPushButton(codeSnippetsTab);
        snippetDeleteButton->setObjectName(QStringLiteral("snippetDeleteButton"));

        horizontalLayout_2->addWidget(snippetDeleteButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        snippetEdit = new ScriptEditor(codeSnippetsTab);
        snippetEdit->setObjectName(QStringLiteral("snippetEdit"));

        verticalLayout_3->addWidget(snippetEdit);

        templatesTabWidget->addTab(codeSnippetsTab, QString());
        newScriptTemplateTab = new QWidget();
        newScriptTemplateTab->setObjectName(QStringLiteral("newScriptTemplateTab"));
        verticalLayout_2 = new QVBoxLayout(newScriptTemplateTab);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(318, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        newScriptTemplateRevertButton = new QPushButton(newScriptTemplateTab);
        newScriptTemplateRevertButton->setObjectName(QStringLiteral("newScriptTemplateRevertButton"));

        horizontalLayout->addWidget(newScriptTemplateRevertButton);

        newScriptTemplateLoadDefaultButton = new QPushButton(newScriptTemplateTab);
        newScriptTemplateLoadDefaultButton->setObjectName(QStringLiteral("newScriptTemplateLoadDefaultButton"));

        horizontalLayout->addWidget(newScriptTemplateLoadDefaultButton);

        newScriptTemplateSaveButton = new QPushButton(newScriptTemplateTab);
        newScriptTemplateSaveButton->setObjectName(QStringLiteral("newScriptTemplateSaveButton"));

        horizontalLayout->addWidget(newScriptTemplateSaveButton);


        verticalLayout_2->addLayout(horizontalLayout);

        newScriptTemplateEdit = new ScriptEditor(newScriptTemplateTab);
        newScriptTemplateEdit->setObjectName(QStringLiteral("newScriptTemplateEdit"));

        verticalLayout_2->addWidget(newScriptTemplateEdit);

        templatesTabWidget->addTab(newScriptTemplateTab, QString());
        fileDropTemplatesTab = new QWidget();
        fileDropTemplatesTab->setObjectName(QStringLiteral("fileDropTemplatesTab"));
        verticalLayout_5 = new QVBoxLayout(fileDropTemplatesTab);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dropFileCategoryView = new QTableView(fileDropTemplatesTab);
        dropFileCategoryView->setObjectName(QStringLiteral("dropFileCategoryView"));
        dropFileCategoryView->setAlternatingRowColors(true);
        dropFileCategoryView->setSelectionMode(QAbstractItemView::SingleSelection);
        dropFileCategoryView->setSelectionBehavior(QAbstractItemView::SelectRows);
        dropFileCategoryView->setTextElideMode(Qt::ElideNone);
        dropFileCategoryView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        dropFileCategoryView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        dropFileCategoryView->horizontalHeader()->setHighlightSections(false);
        dropFileCategoryView->horizontalHeader()->setStretchLastSection(true);
        dropFileCategoryView->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(dropFileCategoryView);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        saveDropFileCategoriesButton = new QPushButton(fileDropTemplatesTab);
        saveDropFileCategoriesButton->setObjectName(QStringLiteral("saveDropFileCategoriesButton"));

        verticalLayout_4->addWidget(saveDropFileCategoriesButton);

        revertDropFileCategoriesButton = new QPushButton(fileDropTemplatesTab);
        revertDropFileCategoriesButton->setObjectName(QStringLiteral("revertDropFileCategoriesButton"));

        verticalLayout_4->addWidget(revertDropFileCategoriesButton);

        addDropFileCategoryButton = new QPushButton(fileDropTemplatesTab);
        addDropFileCategoryButton->setObjectName(QStringLiteral("addDropFileCategoryButton"));

        verticalLayout_4->addWidget(addDropFileCategoryButton);

        deleteSelectedDropFileCategoryButton = new QPushButton(fileDropTemplatesTab);
        deleteSelectedDropFileCategoryButton->setObjectName(QStringLiteral("deleteSelectedDropFileCategoryButton"));

        verticalLayout_4->addWidget(deleteSelectedDropFileCategoryButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        fileDropTemplatesInfoLabel = new QLabel(fileDropTemplatesTab);
        fileDropTemplatesInfoLabel->setObjectName(QStringLiteral("fileDropTemplatesInfoLabel"));
        fileDropTemplatesInfoLabel->setWordWrap(true);

        verticalLayout_5->addWidget(fileDropTemplatesInfoLabel);

        dropFileCategoryTemplateEdit = new ScriptEditor(fileDropTemplatesTab);
        dropFileCategoryTemplateEdit->setObjectName(QStringLiteral("dropFileCategoryTemplateEdit"));

        verticalLayout_5->addWidget(dropFileCategoryTemplateEdit);

        templatesTabWidget->addTab(fileDropTemplatesTab, QString());

        verticalLayout->addWidget(templatesTabWidget);


        retranslateUi(TemplatesDialog);

        templatesTabWidget->setCurrentIndex(0);
        snippetPasteIntoScriptButton->setDefault(true);


        QMetaObject::connectSlotsByName(TemplatesDialog);
    } // setupUi

    void retranslateUi(QDialog *TemplatesDialog)
    {
        TemplatesDialog->setWindowTitle(QApplication::translate("TemplatesDialog", "Script templates", Q_NULLPTR));
        snippetPasteIntoScriptButton->setText(QApplication::translate("TemplatesDialog", "Paste into script", Q_NULLPTR));
        snippetSaveButton->setText(QApplication::translate("TemplatesDialog", "Save", Q_NULLPTR));
        snippetDeleteButton->setText(QApplication::translate("TemplatesDialog", "Delete", Q_NULLPTR));
        templatesTabWidget->setTabText(templatesTabWidget->indexOf(codeSnippetsTab), QApplication::translate("TemplatesDialog", "Code snippets", Q_NULLPTR));
        newScriptTemplateRevertButton->setText(QApplication::translate("TemplatesDialog", "Revert", Q_NULLPTR));
        newScriptTemplateLoadDefaultButton->setText(QApplication::translate("TemplatesDialog", "Load default", Q_NULLPTR));
        newScriptTemplateSaveButton->setText(QApplication::translate("TemplatesDialog", "Save", Q_NULLPTR));
        templatesTabWidget->setTabText(templatesTabWidget->indexOf(newScriptTemplateTab), QApplication::translate("TemplatesDialog", "New script template", Q_NULLPTR));
        saveDropFileCategoriesButton->setText(QApplication::translate("TemplatesDialog", "Save all", Q_NULLPTR));
        revertDropFileCategoriesButton->setText(QApplication::translate("TemplatesDialog", "Revert", Q_NULLPTR));
        addDropFileCategoryButton->setText(QApplication::translate("TemplatesDialog", "Add", Q_NULLPTR));
        deleteSelectedDropFileCategoryButton->setText(QApplication::translate("TemplatesDialog", "Delete", Q_NULLPTR));
        fileDropTemplatesInfoLabel->setText(QApplication::translate("TemplatesDialog", "Write file name mask list as a list of wildcards, separated by semicolons without spaces.\n"
"In the template below use tokens: ", Q_NULLPTR));
        templatesTabWidget->setTabText(templatesTabWidget->indexOf(fileDropTemplatesTab), QApplication::translate("TemplatesDialog", "File drop templates", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TemplatesDialog: public Ui_TemplatesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATES_DIALOG_H
