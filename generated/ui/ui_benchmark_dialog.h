/********************************************************************************
** Form generated from reading UI file 'benchmark_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENCHMARK_DIALOG_H
#define UI_BENCHMARK_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "common-src/log/vs_editor_log.h"

QT_BEGIN_NAMESPACE

class Ui_ScriptBenchmarkDialog
{
public:
    QVBoxLayout *verticalLayout;
    VSEditorLog *feedbackTextEdit;
    QLineEdit *metricsEdit;
    QProgressBar *processingProgressBar;
    QHBoxLayout *horizontalLayout;
    QLabel *framesLabel;
    QSpinBox *fromFrameSpinBox;
    QLabel *toLabel;
    QSpinBox *toFrameSpinBox;
    QPushButton *wholeVideoButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *startStopBenchmarkButton;

    void setupUi(QDialog *ScriptBenchmarkDialog)
    {
        if (ScriptBenchmarkDialog->objectName().isEmpty())
            ScriptBenchmarkDialog->setObjectName(QString::fromUtf8("ScriptBenchmarkDialog"));
        ScriptBenchmarkDialog->resize(400, 191);
        verticalLayout = new QVBoxLayout(ScriptBenchmarkDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        feedbackTextEdit = new VSEditorLog(ScriptBenchmarkDialog);
        feedbackTextEdit->setObjectName(QString::fromUtf8("feedbackTextEdit"));
        feedbackTextEdit->setReadOnly(true);
        feedbackTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(feedbackTextEdit);

        metricsEdit = new QLineEdit(ScriptBenchmarkDialog);
        metricsEdit->setObjectName(QString::fromUtf8("metricsEdit"));
        metricsEdit->setReadOnly(true);

        verticalLayout->addWidget(metricsEdit);

        processingProgressBar = new QProgressBar(ScriptBenchmarkDialog);
        processingProgressBar->setObjectName(QString::fromUtf8("processingProgressBar"));
        processingProgressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(processingProgressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        framesLabel = new QLabel(ScriptBenchmarkDialog);
        framesLabel->setObjectName(QString::fromUtf8("framesLabel"));

        horizontalLayout->addWidget(framesLabel);

        fromFrameSpinBox = new QSpinBox(ScriptBenchmarkDialog);
        fromFrameSpinBox->setObjectName(QString::fromUtf8("fromFrameSpinBox"));

        horizontalLayout->addWidget(fromFrameSpinBox);

        toLabel = new QLabel(ScriptBenchmarkDialog);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        horizontalLayout->addWidget(toLabel);

        toFrameSpinBox = new QSpinBox(ScriptBenchmarkDialog);
        toFrameSpinBox->setObjectName(QString::fromUtf8("toFrameSpinBox"));

        horizontalLayout->addWidget(toFrameSpinBox);

        wholeVideoButton = new QPushButton(ScriptBenchmarkDialog);
        wholeVideoButton->setObjectName(QString::fromUtf8("wholeVideoButton"));

        horizontalLayout->addWidget(wholeVideoButton);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startStopBenchmarkButton = new QPushButton(ScriptBenchmarkDialog);
        startStopBenchmarkButton->setObjectName(QString::fromUtf8("startStopBenchmarkButton"));

        horizontalLayout->addWidget(startStopBenchmarkButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ScriptBenchmarkDialog);

        startStopBenchmarkButton->setDefault(true);


        QMetaObject::connectSlotsByName(ScriptBenchmarkDialog);
    } // setupUi

    void retranslateUi(QDialog *ScriptBenchmarkDialog)
    {
        ScriptBenchmarkDialog->setWindowTitle(QCoreApplication::translate("ScriptBenchmarkDialog", "Script benchmark", nullptr));
        processingProgressBar->setFormat(QCoreApplication::translate("ScriptBenchmarkDialog", "%v / %m", nullptr));
        framesLabel->setText(QCoreApplication::translate("ScriptBenchmarkDialog", "Frames:", nullptr));
        toLabel->setText(QCoreApplication::translate("ScriptBenchmarkDialog", "to", nullptr));
        wholeVideoButton->setText(QCoreApplication::translate("ScriptBenchmarkDialog", "Whole video", nullptr));
        startStopBenchmarkButton->setText(QCoreApplication::translate("ScriptBenchmarkDialog", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScriptBenchmarkDialog: public Ui_ScriptBenchmarkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENCHMARK_DIALOG_H
