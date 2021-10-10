/********************************************************************************
** Form generated from reading UI file 'encode_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCODE_DIALOG_H
#define UI_ENCODE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "common-src/log/vs_editor_log.h"

QT_BEGIN_NAMESPACE

class Ui_EncodeDialog
{
public:
    QVBoxLayout *verticalLayout;
    VSEditorLog *feedbackTextEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *encodingPresetLabel;
    QComboBox *encodingPresetComboBox;
    QPushButton *encodingPresetSaveButton;
    QPushButton *encodingPresetDeleteButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *headerTypeComboBox;
    QLabel *label;
    QLineEdit *executablePathEdit;
    QToolButton *executableBrowseButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QToolButton *argumentsHelpButton;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *argumentsTextEdit;
    QLineEdit *metricsEdit;
    QProgressBar *processingProgressBar;
    QHBoxLayout *horizontalLayout;
    QLabel *framesLabel;
    QSpinBox *fromFrameSpinBox;
    QLabel *toLabel;
    QSpinBox *toFrameSpinBox;
    QPushButton *wholeVideoButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *startEncodeButton;
    QPushButton *pauseEncodeButton;
    QPushButton *abortEncodeButton;

    void setupUi(QDialog *EncodeDialog)
    {
        if (EncodeDialog->objectName().isEmpty())
            EncodeDialog->setObjectName(QString::fromUtf8("EncodeDialog"));
        EncodeDialog->resize(677, 648);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/film_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        EncodeDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(EncodeDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        feedbackTextEdit = new VSEditorLog(EncodeDialog);
        feedbackTextEdit->setObjectName(QString::fromUtf8("feedbackTextEdit"));
        feedbackTextEdit->setReadOnly(true);
        feedbackTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(feedbackTextEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        encodingPresetLabel = new QLabel(EncodeDialog);
        encodingPresetLabel->setObjectName(QString::fromUtf8("encodingPresetLabel"));

        horizontalLayout_4->addWidget(encodingPresetLabel);

        encodingPresetComboBox = new QComboBox(EncodeDialog);
        encodingPresetComboBox->setObjectName(QString::fromUtf8("encodingPresetComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(encodingPresetComboBox->sizePolicy().hasHeightForWidth());
        encodingPresetComboBox->setSizePolicy(sizePolicy);
        encodingPresetComboBox->setEditable(true);
        encodingPresetComboBox->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_4->addWidget(encodingPresetComboBox);

        encodingPresetSaveButton = new QPushButton(EncodeDialog);
        encodingPresetSaveButton->setObjectName(QString::fromUtf8("encodingPresetSaveButton"));

        horizontalLayout_4->addWidget(encodingPresetSaveButton);

        encodingPresetDeleteButton = new QPushButton(EncodeDialog);
        encodingPresetDeleteButton->setObjectName(QString::fromUtf8("encodingPresetDeleteButton"));

        horizontalLayout_4->addWidget(encodingPresetDeleteButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(EncodeDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        headerTypeComboBox = new QComboBox(EncodeDialog);
        headerTypeComboBox->setObjectName(QString::fromUtf8("headerTypeComboBox"));
        headerTypeComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(headerTypeComboBox);

        label = new QLabel(EncodeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        executablePathEdit = new QLineEdit(EncodeDialog);
        executablePathEdit->setObjectName(QString::fromUtf8("executablePathEdit"));

        horizontalLayout_2->addWidget(executablePathEdit);

        executableBrowseButton = new QToolButton(EncodeDialog);
        executableBrowseButton->setObjectName(QString::fromUtf8("executableBrowseButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        executableBrowseButton->setIcon(icon1);

        horizontalLayout_2->addWidget(executableBrowseButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(EncodeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        argumentsHelpButton = new QToolButton(EncodeDialog);
        argumentsHelpButton->setObjectName(QString::fromUtf8("argumentsHelpButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        argumentsHelpButton->setIcon(icon2);

        horizontalLayout_3->addWidget(argumentsHelpButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        argumentsTextEdit = new QPlainTextEdit(EncodeDialog);
        argumentsTextEdit->setObjectName(QString::fromUtf8("argumentsTextEdit"));

        verticalLayout->addWidget(argumentsTextEdit);

        metricsEdit = new QLineEdit(EncodeDialog);
        metricsEdit->setObjectName(QString::fromUtf8("metricsEdit"));
        metricsEdit->setReadOnly(true);

        verticalLayout->addWidget(metricsEdit);

        processingProgressBar = new QProgressBar(EncodeDialog);
        processingProgressBar->setObjectName(QString::fromUtf8("processingProgressBar"));
        processingProgressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(processingProgressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        framesLabel = new QLabel(EncodeDialog);
        framesLabel->setObjectName(QString::fromUtf8("framesLabel"));

        horizontalLayout->addWidget(framesLabel);

        fromFrameSpinBox = new QSpinBox(EncodeDialog);
        fromFrameSpinBox->setObjectName(QString::fromUtf8("fromFrameSpinBox"));

        horizontalLayout->addWidget(fromFrameSpinBox);

        toLabel = new QLabel(EncodeDialog);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        horizontalLayout->addWidget(toLabel);

        toFrameSpinBox = new QSpinBox(EncodeDialog);
        toFrameSpinBox->setObjectName(QString::fromUtf8("toFrameSpinBox"));

        horizontalLayout->addWidget(toFrameSpinBox);

        wholeVideoButton = new QPushButton(EncodeDialog);
        wholeVideoButton->setObjectName(QString::fromUtf8("wholeVideoButton"));

        horizontalLayout->addWidget(wholeVideoButton);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startEncodeButton = new QPushButton(EncodeDialog);
        startEncodeButton->setObjectName(QString::fromUtf8("startEncodeButton"));

        horizontalLayout->addWidget(startEncodeButton);

        pauseEncodeButton = new QPushButton(EncodeDialog);
        pauseEncodeButton->setObjectName(QString::fromUtf8("pauseEncodeButton"));

        horizontalLayout->addWidget(pauseEncodeButton);

        abortEncodeButton = new QPushButton(EncodeDialog);
        abortEncodeButton->setObjectName(QString::fromUtf8("abortEncodeButton"));

        horizontalLayout->addWidget(abortEncodeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EncodeDialog);

        startEncodeButton->setDefault(true);


        QMetaObject::connectSlotsByName(EncodeDialog);
    } // setupUi

    void retranslateUi(QDialog *EncodeDialog)
    {
        EncodeDialog->setWindowTitle(QCoreApplication::translate("EncodeDialog", "Encode video", nullptr));
        encodingPresetLabel->setText(QCoreApplication::translate("EncodeDialog", "Preset:", nullptr));
        encodingPresetSaveButton->setText(QCoreApplication::translate("EncodeDialog", "Save", nullptr));
        encodingPresetDeleteButton->setText(QCoreApplication::translate("EncodeDialog", "Delete", nullptr));
        label_3->setText(QCoreApplication::translate("EncodeDialog", "Header:", nullptr));
        label->setText(QCoreApplication::translate("EncodeDialog", "Executable:", nullptr));
        executablePathEdit->setText(QString());
        executableBrowseButton->setText(QString());
        label_2->setText(QCoreApplication::translate("EncodeDialog", "Arguments (newlines will be replaced with spaces):", nullptr));
        argumentsHelpButton->setText(QString());
        argumentsTextEdit->setPlainText(QString());
        processingProgressBar->setFormat(QCoreApplication::translate("EncodeDialog", "%v / %m", nullptr));
        framesLabel->setText(QCoreApplication::translate("EncodeDialog", "Frames:", nullptr));
        toLabel->setText(QCoreApplication::translate("EncodeDialog", "to", nullptr));
        wholeVideoButton->setText(QCoreApplication::translate("EncodeDialog", "Whole video", nullptr));
        startEncodeButton->setText(QCoreApplication::translate("EncodeDialog", "Start", nullptr));
        pauseEncodeButton->setText(QCoreApplication::translate("EncodeDialog", "Pause", nullptr));
        abortEncodeButton->setText(QCoreApplication::translate("EncodeDialog", "Abort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EncodeDialog: public Ui_EncodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCODE_DIALOG_H
