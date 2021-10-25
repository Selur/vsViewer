/********************************************************************************
** Form generated from reading UI file 'script_status_bar_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPT_STATUS_BAR_WIDGET_H
#define UI_SCRIPT_STATUS_BAR_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            ScriptStatusBarWidget->setObjectName(QStringLiteral("ScriptStatusBarWidget"));
        ScriptStatusBarWidget->resize(674, 67);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScriptStatusBarWidget->sizePolicy().hasHeightForWidth());
        ScriptStatusBarWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ScriptStatusBarWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        colorPickerWidget = new QWidget(ScriptStatusBarWidget);
        colorPickerWidget->setObjectName(QStringLiteral("colorPickerWidget"));
        horizontalLayout = new QHBoxLayout(colorPickerWidget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        colorPickerIconLabel = new QLabel(colorPickerWidget);
        colorPickerIconLabel->setObjectName(QStringLiteral("colorPickerIconLabel"));

        horizontalLayout->addWidget(colorPickerIconLabel);

        colorPickerLabel = new QLabel(colorPickerWidget);
        colorPickerLabel->setObjectName(QStringLiteral("colorPickerLabel"));

        horizontalLayout->addWidget(colorPickerLabel);

        horizontalSpacer_2 = new QSpacerItem(486, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(colorPickerWidget);

        scriptProcessonInfoPanel = new QWidget(ScriptStatusBarWidget);
        scriptProcessonInfoPanel->setObjectName(QStringLiteral("scriptProcessonInfoPanel"));
        horizontalLayout_2 = new QHBoxLayout(scriptProcessonInfoPanel);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scriptProcessorQueueIconLabel = new QLabel(scriptProcessonInfoPanel);
        scriptProcessorQueueIconLabel->setObjectName(QStringLiteral("scriptProcessorQueueIconLabel"));

        horizontalLayout_2->addWidget(scriptProcessorQueueIconLabel);

        scriptProcessorQueueLabel = new QLabel(scriptProcessonInfoPanel);
        scriptProcessorQueueLabel->setObjectName(QStringLiteral("scriptProcessorQueueLabel"));

        horizontalLayout_2->addWidget(scriptProcessorQueueLabel);

        horizontalSpacer = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(scriptProcessonInfoPanel);

        videoInfoLabel = new QLabel(ScriptStatusBarWidget);
        videoInfoLabel->setObjectName(QStringLiteral("videoInfoLabel"));
        videoInfoLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(videoInfoLabel);


        retranslateUi(ScriptStatusBarWidget);

        QMetaObject::connectSlotsByName(ScriptStatusBarWidget);
    } // setupUi

    void retranslateUi(QWidget *ScriptStatusBarWidget)
    {
        ScriptStatusBarWidget->setWindowTitle(QApplication::translate("ScriptStatusBarWidget", "Form", Q_NULLPTR));
        colorPickerIconLabel->setText(QApplication::translate("ScriptStatusBarWidget", "colorPickerIconLabel", Q_NULLPTR));
        colorPickerLabel->setText(QApplication::translate("ScriptStatusBarWidget", "colorPickerLabel", Q_NULLPTR));
        scriptProcessorQueueIconLabel->setText(QApplication::translate("ScriptStatusBarWidget", "scriptProcessorQueueIconLabel", Q_NULLPTR));
        scriptProcessorQueueLabel->setText(QApplication::translate("ScriptStatusBarWidget", "scriptProcessorQueueLabel", Q_NULLPTR));
        videoInfoLabel->setText(QApplication::translate("ScriptStatusBarWidget", "videoInfoLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScriptStatusBarWidget: public Ui_ScriptStatusBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPT_STATUS_BAR_WIDGET_H
