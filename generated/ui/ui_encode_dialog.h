/********************************************************************************
** Form generated from reading UI file 'encode_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCODE_DIALOG_H
#define UI_ENCODE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            EncodeDialog->setObjectName(QStringLiteral("EncodeDialog"));
        EncodeDialog->resize(677, 648);
        QIcon icon;
        icon.addFile(QStringLiteral(":/film_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        EncodeDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(EncodeDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        feedbackTextEdit = new VSEditorLog(EncodeDialog);
        feedbackTextEdit->setObjectName(QStringLiteral("feedbackTextEdit"));
        feedbackTextEdit->setReadOnly(true);
        feedbackTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(feedbackTextEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        encodingPresetLabel = new QLabel(EncodeDialog);
        encodingPresetLabel->setObjectName(QStringLiteral("encodingPresetLabel"));

        horizontalLayout_4->addWidget(encodingPresetLabel);

        encodingPresetComboBox = new QComboBox(EncodeDialog);
        encodingPresetComboBox->setObjectName(QStringLiteral("encodingPresetComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(encodingPresetComboBox->sizePolicy().hasHeightForWidth());
        encodingPresetComboBox->setSizePolicy(sizePolicy);
        encodingPresetComboBox->setEditable(true);
        encodingPresetComboBox->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_4->addWidget(encodingPresetComboBox);

        encodingPresetSaveButton = new QPushButton(EncodeDialog);
        encodingPresetSaveButton->setObjectName(QStringLiteral("encodingPresetSaveButton"));

        horizontalLayout_4->addWidget(encodingPresetSaveButton);

        encodingPresetDeleteButton = new QPushButton(EncodeDialog);
        encodingPresetDeleteButton->setObjectName(QStringLiteral("encodingPresetDeleteButton"));

        horizontalLayout_4->addWidget(encodingPresetDeleteButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(EncodeDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        headerTypeComboBox = new QComboBox(EncodeDialog);
        headerTypeComboBox->setObjectName(QStringLiteral("headerTypeComboBox"));
        headerTypeComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(headerTypeComboBox);

        label = new QLabel(EncodeDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        executablePathEdit = new QLineEdit(EncodeDialog);
        executablePathEdit->setObjectName(QStringLiteral("executablePathEdit"));

        horizontalLayout_2->addWidget(executablePathEdit);

        executableBrowseButton = new QToolButton(EncodeDialog);
        executableBrowseButton->setObjectName(QStringLiteral("executableBrowseButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        executableBrowseButton->setIcon(icon1);

        horizontalLayout_2->addWidget(executableBrowseButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(EncodeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        argumentsHelpButton = new QToolButton(EncodeDialog);
        argumentsHelpButton->setObjectName(QStringLiteral("argumentsHelpButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        argumentsHelpButton->setIcon(icon2);

        horizontalLayout_3->addWidget(argumentsHelpButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        argumentsTextEdit = new QPlainTextEdit(EncodeDialog);
        argumentsTextEdit->setObjectName(QStringLiteral("argumentsTextEdit"));

        verticalLayout->addWidget(argumentsTextEdit);

        metricsEdit = new QLineEdit(EncodeDialog);
        metricsEdit->setObjectName(QStringLiteral("metricsEdit"));
        metricsEdit->setReadOnly(true);

        verticalLayout->addWidget(metricsEdit);

        processingProgressBar = new QProgressBar(EncodeDialog);
        processingProgressBar->setObjectName(QStringLiteral("processingProgressBar"));
        processingProgressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(processingProgressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        framesLabel = new QLabel(EncodeDialog);
        framesLabel->setObjectName(QStringLiteral("framesLabel"));

        horizontalLayout->addWidget(framesLabel);

        fromFrameSpinBox = new QSpinBox(EncodeDialog);
        fromFrameSpinBox->setObjectName(QStringLiteral("fromFrameSpinBox"));

        horizontalLayout->addWidget(fromFrameSpinBox);

        toLabel = new QLabel(EncodeDialog);
        toLabel->setObjectName(QStringLiteral("toLabel"));

        horizontalLayout->addWidget(toLabel);

        toFrameSpinBox = new QSpinBox(EncodeDialog);
        toFrameSpinBox->setObjectName(QStringLiteral("toFrameSpinBox"));

        horizontalLayout->addWidget(toFrameSpinBox);

        wholeVideoButton = new QPushButton(EncodeDialog);
        wholeVideoButton->setObjectName(QStringLiteral("wholeVideoButton"));

        horizontalLayout->addWidget(wholeVideoButton);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startEncodeButton = new QPushButton(EncodeDialog);
        startEncodeButton->setObjectName(QStringLiteral("startEncodeButton"));

        horizontalLayout->addWidget(startEncodeButton);

        pauseEncodeButton = new QPushButton(EncodeDialog);
        pauseEncodeButton->setObjectName(QStringLiteral("pauseEncodeButton"));

        horizontalLayout->addWidget(pauseEncodeButton);

        abortEncodeButton = new QPushButton(EncodeDialog);
        abortEncodeButton->setObjectName(QStringLiteral("abortEncodeButton"));

        horizontalLayout->addWidget(abortEncodeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EncodeDialog);

        startEncodeButton->setDefault(true);


        QMetaObject::connectSlotsByName(EncodeDialog);
    } // setupUi

    void retranslateUi(QDialog *EncodeDialog)
    {
        EncodeDialog->setWindowTitle(QApplication::translate("EncodeDialog", "Encode video", Q_NULLPTR));
        encodingPresetLabel->setText(QApplication::translate("EncodeDialog", "Preset:", Q_NULLPTR));
        encodingPresetSaveButton->setText(QApplication::translate("EncodeDialog", "Save", Q_NULLPTR));
        encodingPresetDeleteButton->setText(QApplication::translate("EncodeDialog", "Delete", Q_NULLPTR));
        label_3->setText(QApplication::translate("EncodeDialog", "Header:", Q_NULLPTR));
        label->setText(QApplication::translate("EncodeDialog", "Executable:", Q_NULLPTR));
        executablePathEdit->setText(QString());
        executableBrowseButton->setText(QString());
        label_2->setText(QApplication::translate("EncodeDialog", "Arguments (newlines will be replaced with spaces):", Q_NULLPTR));
        argumentsHelpButton->setText(QString());
        argumentsTextEdit->setPlainText(QString());
        processingProgressBar->setFormat(QApplication::translate("EncodeDialog", "%v / %m", Q_NULLPTR));
        framesLabel->setText(QApplication::translate("EncodeDialog", "Frames:", Q_NULLPTR));
        toLabel->setText(QApplication::translate("EncodeDialog", "to", Q_NULLPTR));
        wholeVideoButton->setText(QApplication::translate("EncodeDialog", "Whole video", Q_NULLPTR));
        startEncodeButton->setText(QApplication::translate("EncodeDialog", "Start", Q_NULLPTR));
        pauseEncodeButton->setText(QApplication::translate("EncodeDialog", "Pause", Q_NULLPTR));
        abortEncodeButton->setText(QApplication::translate("EncodeDialog", "Abort", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EncodeDialog: public Ui_EncodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCODE_DIALOG_H
