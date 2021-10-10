/********************************************************************************
** Form generated from reading UI file 'script_status_bar_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPT_STATUS_BAR_WIDGET_H
#define UI_SCRIPT_STATUS_BAR_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptStatusBarWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *colorPickerWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *colorPickerIconLabel;
    QLabel *colorPickerLabel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *scriptProcessonInfoPanel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *scriptProcessorQueueIconLabel;
    QLabel *scriptProcessorQueueLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *videoInfoLabel;

    void setupUi(QWidget *ScriptStatusBarWidget)
    {
        if (ScriptStatusBarWidget->objectName().isEmpty())
            ScriptStatusBarWidget->setObjectName(QString::fromUtf8("ScriptStatusBarWidget"));
        ScriptStatusBarWidget->resize(674, 67);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScriptStatusBarWidget->sizePolicy().hasHeightForWidth());
        ScriptStatusBarWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ScriptStatusBarWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        colorPickerWidget = new QWidget(ScriptStatusBarWidget);
        colorPickerWidget->setObjectName(QString::fromUtf8("colorPickerWidget"));
        horizontalLayout = new QHBoxLayout(colorPickerWidget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        colorPickerIconLabel = new QLabel(colorPickerWidget);
        colorPickerIconLabel->setObjectName(QString::fromUtf8("colorPickerIconLabel"));

        horizontalLayout->addWidget(colorPickerIconLabel);

        colorPickerLabel = new QLabel(colorPickerWidget);
        colorPickerLabel->setObjectName(QString::fromUtf8("colorPickerLabel"));

        horizontalLayout->addWidget(colorPickerLabel);

        horizontalSpacer_2 = new QSpacerItem(486, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(colorPickerWidget);

        scriptProcessonInfoPanel = new QWidget(ScriptStatusBarWidget);
        scriptProcessonInfoPanel->setObjectName(QString::fromUtf8("scriptProcessonInfoPanel"));
        horizontalLayout_2 = new QHBoxLayout(scriptProcessonInfoPanel);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scriptProcessorQueueIconLabel = new QLabel(scriptProcessonInfoPanel);
        scriptProcessorQueueIconLabel->setObjectName(QString::fromUtf8("scriptProcessorQueueIconLabel"));

        horizontalLayout_2->addWidget(scriptProcessorQueueIconLabel);

        scriptProcessorQueueLabel = new QLabel(scriptProcessonInfoPanel);
        scriptProcessorQueueLabel->setObjectName(QString::fromUtf8("scriptProcessorQueueLabel"));

        horizontalLayout_2->addWidget(scriptProcessorQueueLabel);

        horizontalSpacer = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(scriptProcessonInfoPanel);

        videoInfoLabel = new QLabel(ScriptStatusBarWidget);
        videoInfoLabel->setObjectName(QString::fromUtf8("videoInfoLabel"));
        videoInfoLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(videoInfoLabel);


        retranslateUi(ScriptStatusBarWidget);

        QMetaObject::connectSlotsByName(ScriptStatusBarWidget);
    } // setupUi

    void retranslateUi(QWidget *ScriptStatusBarWidget)
    {
        ScriptStatusBarWidget->setWindowTitle(QCoreApplication::translate("ScriptStatusBarWidget", "Form", nullptr));
        colorPickerIconLabel->setText(QCoreApplication::translate("ScriptStatusBarWidget", "colorPickerIconLabel", nullptr));
        colorPickerLabel->setText(QCoreApplication::translate("ScriptStatusBarWidget", "colorPickerLabel", nullptr));
        scriptProcessorQueueIconLabel->setText(QCoreApplication::translate("ScriptStatusBarWidget", "scriptProcessorQueueIconLabel", nullptr));
        scriptProcessorQueueLabel->setText(QCoreApplication::translate("ScriptStatusBarWidget", "scriptProcessorQueueLabel", nullptr));
        videoInfoLabel->setText(QCoreApplication::translate("ScriptStatusBarWidget", "videoInfoLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScriptStatusBarWidget: public Ui_ScriptStatusBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPT_STATUS_BAR_WIDGET_H
