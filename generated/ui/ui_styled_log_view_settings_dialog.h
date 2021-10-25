/********************************************************************************
** Form generated from reading UI file 'styled_log_view_settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLED_LOG_VIEW_SETTINGS_DIALOG_H
#define UI_STYLED_LOG_VIEW_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StyledLogViewSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *stylesView;
    QLabel *fontLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *fontButton;
    QPushButton *textColorButton;
    QPushButton *backgroundColorButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *StyledLogViewSettingsDialog)
    {
        if (StyledLogViewSettingsDialog->objectName().isEmpty())
            StyledLogViewSettingsDialog->setObjectName(QStringLiteral("StyledLogViewSettingsDialog"));
        StyledLogViewSettingsDialog->resize(306, 497);
        verticalLayout = new QVBoxLayout(StyledLogViewSettingsDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        stylesView = new QTableView(StyledLogViewSettingsDialog);
        stylesView->setObjectName(QStringLiteral("stylesView"));
        stylesView->setAlternatingRowColors(true);
        stylesView->setSelectionMode(QAbstractItemView::SingleSelection);
        stylesView->setSelectionBehavior(QAbstractItemView::SelectRows);
        stylesView->horizontalHeader()->setVisible(false);
        stylesView->horizontalHeader()->setStretchLastSection(true);
        stylesView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(stylesView);

        fontLabel = new QLabel(StyledLogViewSettingsDialog);
        fontLabel->setObjectName(QStringLiteral("fontLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fontLabel->sizePolicy().hasHeightForWidth());
        fontLabel->setSizePolicy(sizePolicy);
        fontLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(fontLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fontButton = new QPushButton(StyledLogViewSettingsDialog);
        fontButton->setObjectName(QStringLiteral("fontButton"));

        horizontalLayout_2->addWidget(fontButton);

        textColorButton = new QPushButton(StyledLogViewSettingsDialog);
        textColorButton->setObjectName(QStringLiteral("textColorButton"));

        horizontalLayout_2->addWidget(textColorButton);

        backgroundColorButton = new QPushButton(StyledLogViewSettingsDialog);
        backgroundColorButton->setObjectName(QStringLiteral("backgroundColorButton"));

        horizontalLayout_2->addWidget(backgroundColorButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(StyledLogViewSettingsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        applyButton = new QPushButton(StyledLogViewSettingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);

        cancelButton = new QPushButton(StyledLogViewSettingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(StyledLogViewSettingsDialog);

        cancelButton->setDefault(true);


        QMetaObject::connectSlotsByName(StyledLogViewSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *StyledLogViewSettingsDialog)
    {
        StyledLogViewSettingsDialog->setWindowTitle(QApplication::translate("StyledLogViewSettingsDialog", "Log settings", Q_NULLPTR));
        fontLabel->setText(QString());
        fontButton->setText(QApplication::translate("StyledLogViewSettingsDialog", "Font", Q_NULLPTR));
        textColorButton->setText(QApplication::translate("StyledLogViewSettingsDialog", "Text color", Q_NULLPTR));
        backgroundColorButton->setText(QApplication::translate("StyledLogViewSettingsDialog", "Background color", Q_NULLPTR));
        okButton->setText(QApplication::translate("StyledLogViewSettingsDialog", "OK", Q_NULLPTR));
        applyButton->setText(QApplication::translate("StyledLogViewSettingsDialog", "Apply", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("StyledLogViewSettingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StyledLogViewSettingsDialog: public Ui_StyledLogViewSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLED_LOG_VIEW_SETTINGS_DIALOG_H
