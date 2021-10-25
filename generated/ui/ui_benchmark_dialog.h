/********************************************************************************
** Form generated from reading UI file 'benchmark_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENCHMARK_DIALOG_H
#define UI_BENCHMARK_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            ScriptBenchmarkDialog->setObjectName(QStringLiteral("ScriptBenchmarkDialog"));
        ScriptBenchmarkDialog->resize(400, 191);
        verticalLayout = new QVBoxLayout(ScriptBenchmarkDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        feedbackTextEdit = new VSEditorLog(ScriptBenchmarkDialog);
        feedbackTextEdit->setObjectName(QStringLiteral("feedbackTextEdit"));
        feedbackTextEdit->setReadOnly(true);
        feedbackTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(feedbackTextEdit);

        metricsEdit = new QLineEdit(ScriptBenchmarkDialog);
        metricsEdit->setObjectName(QStringLiteral("metricsEdit"));
        metricsEdit->setReadOnly(true);

        verticalLayout->addWidget(metricsEdit);

        processingProgressBar = new QProgressBar(ScriptBenchmarkDialog);
        processingProgressBar->setObjectName(QStringLiteral("processingProgressBar"));
        processingProgressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(processingProgressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        framesLabel = new QLabel(ScriptBenchmarkDialog);
        framesLabel->setObjectName(QStringLiteral("framesLabel"));

        horizontalLayout->addWidget(framesLabel);

        fromFrameSpinBox = new QSpinBox(ScriptBenchmarkDialog);
        fromFrameSpinBox->setObjectName(QStringLiteral("fromFrameSpinBox"));

        horizontalLayout->addWidget(fromFrameSpinBox);

        toLabel = new QLabel(ScriptBenchmarkDialog);
        toLabel->setObjectName(QStringLiteral("toLabel"));

        horizontalLayout->addWidget(toLabel);

        toFrameSpinBox = new QSpinBox(ScriptBenchmarkDialog);
        toFrameSpinBox->setObjectName(QStringLiteral("toFrameSpinBox"));

        horizontalLayout->addWidget(toFrameSpinBox);

        wholeVideoButton = new QPushButton(ScriptBenchmarkDialog);
        wholeVideoButton->setObjectName(QStringLiteral("wholeVideoButton"));

        horizontalLayout->addWidget(wholeVideoButton);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startStopBenchmarkButton = new QPushButton(ScriptBenchmarkDialog);
        startStopBenchmarkButton->setObjectName(QStringLiteral("startStopBenchmarkButton"));

        horizontalLayout->addWidget(startStopBenchmarkButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ScriptBenchmarkDialog);

        startStopBenchmarkButton->setDefault(true);


        QMetaObject::connectSlotsByName(ScriptBenchmarkDialog);
    } // setupUi

    void retranslateUi(QDialog *ScriptBenchmarkDialog)
    {
        ScriptBenchmarkDialog->setWindowTitle(QApplication::translate("ScriptBenchmarkDialog", "Script benchmark", Q_NULLPTR));
        processingProgressBar->setFormat(QApplication::translate("ScriptBenchmarkDialog", "%v / %m", Q_NULLPTR));
        framesLabel->setText(QApplication::translate("ScriptBenchmarkDialog", "Frames:", Q_NULLPTR));
        toLabel->setText(QApplication::translate("ScriptBenchmarkDialog", "to", Q_NULLPTR));
        wholeVideoButton->setText(QApplication::translate("ScriptBenchmarkDialog", "Whole video", Q_NULLPTR));
        startStopBenchmarkButton->setText(QApplication::translate("ScriptBenchmarkDialog", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScriptBenchmarkDialog: public Ui_ScriptBenchmarkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENCHMARK_DIALOG_H
