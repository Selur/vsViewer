/********************************************************************************
** Form generated from reading UI file 'preview_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEW_DIALOG_H
#define UI_PREVIEW_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "common-src/timeline_slider/timeline_slider.h"
#include "preview/preview_area.h"

QT_BEGIN_NAMESPACE

class Ui_PreviewDialog
{
public:
    QVBoxLayout *mainLayout;
    PreviewArea *previewArea;
    QWidget *toolBar;
    QHBoxLayout *horizontalLayout;
    QToolButton *timeLineCheckButton;
    QSpinBox *frameNumberSpinBox;
    QLabel *frameStatusLabel;
    TimeLineSlider *frameNumberSlider;
    QToolButton *frameToClipboardButton;
    QToolButton *saveSnapshotButton;
    QToolButton *advancedSettingsButton;
    QToolButton *cropCheckButton;
    QToolButton *zoomCheckButton;
    QWidget *zoomPanel;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *zoomModeComboBox;
    QDoubleSpinBox *zoomRatioSpinBox;
    QComboBox *scaleModeComboBox;
    QToolButton *colorPickerButton;
    QWidget *timeLinePanel;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *playButton;
    QLabel *label;
    QComboBox *playFpsLimitModeComboBox;
    QDoubleSpinBox *playFpsLimitSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *goToPreviousBookmarkButton;
    QToolButton *bookmarkCurrentFrameButton;
    QToolButton *unbookmarkCurrentFrameButton;
    QToolButton *loadChaptersButton;
    QToolButton *clearBookmarksButton;
    QToolButton *goToNextBookmarkButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *timeLineModeLabel;
    QComboBox *timeLineModeComboBox;
    QLabel *stepLabel;
    QTimeEdit *timeStepEdit;
    QToolButton *timeStepBackButton;
    QToolButton *timeStepForwardButton;
    QWidget *cropPanel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *cropModeLabel;
    QComboBox *cropModeComboBox;
    QLabel *cropLeftLabel;
    QSpinBox *cropLeftSpinBox;
    QLabel *cropTopLabel;
    QSpinBox *cropTopSpinBox;
    QLabel *cropWidthLabel;
    QSpinBox *cropWidthSpinBox;
    QLabel *cropHeightLabel;
    QSpinBox *cropHeightSpinBox;
    QLabel *cropRightLabel;
    QSpinBox *cropRightSpinBox;
    QLabel *cropBottomLabel;
    QSpinBox *cropBottomSpinBox;
    QLabel *cropZoomLabel;
    QSpinBox *cropZoomRatioSpinBox;
    QToolButton *cropPasteToScriptButton;

    void setupUi(QDialog *PreviewDialog)
    {
        if (PreviewDialog->objectName().isEmpty())
            PreviewDialog->setObjectName(QString::fromUtf8("PreviewDialog"));
        PreviewDialog->resize(933, 652);
        mainLayout = new QVBoxLayout(PreviewDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        previewArea = new PreviewArea(PreviewDialog);
        previewArea->setObjectName(QString::fromUtf8("previewArea"));

        mainLayout->addWidget(previewArea);

        toolBar = new QWidget(PreviewDialog);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(toolBar);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        timeLineCheckButton = new QToolButton(toolBar);
        timeLineCheckButton->setObjectName(QString::fromUtf8("timeLineCheckButton"));
        timeLineCheckButton->setCheckable(true);

        horizontalLayout->addWidget(timeLineCheckButton);

        frameNumberSpinBox = new QSpinBox(toolBar);
        frameNumberSpinBox->setObjectName(QString::fromUtf8("frameNumberSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frameNumberSpinBox->sizePolicy().hasHeightForWidth());
        frameNumberSpinBox->setSizePolicy(sizePolicy1);
        frameNumberSpinBox->setKeyboardTracking(false);
        frameNumberSpinBox->setMaximum(999999999);

        horizontalLayout->addWidget(frameNumberSpinBox);

        frameStatusLabel = new QLabel(toolBar);
        frameStatusLabel->setObjectName(QString::fromUtf8("frameStatusLabel"));
        frameStatusLabel->setMinimumSize(QSize(16, 0));

        horizontalLayout->addWidget(frameStatusLabel);

        frameNumberSlider = new TimeLineSlider(toolBar);
        frameNumberSlider->setObjectName(QString::fromUtf8("frameNumberSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameNumberSlider->sizePolicy().hasHeightForWidth());
        frameNumberSlider->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(frameNumberSlider);

        frameToClipboardButton = new QToolButton(toolBar);
        frameToClipboardButton->setObjectName(QString::fromUtf8("frameToClipboardButton"));

        horizontalLayout->addWidget(frameToClipboardButton);

        saveSnapshotButton = new QToolButton(toolBar);
        saveSnapshotButton->setObjectName(QString::fromUtf8("saveSnapshotButton"));

        horizontalLayout->addWidget(saveSnapshotButton);

        advancedSettingsButton = new QToolButton(toolBar);
        advancedSettingsButton->setObjectName(QString::fromUtf8("advancedSettingsButton"));

        horizontalLayout->addWidget(advancedSettingsButton);

        cropCheckButton = new QToolButton(toolBar);
        cropCheckButton->setObjectName(QString::fromUtf8("cropCheckButton"));
        cropCheckButton->setCheckable(true);

        horizontalLayout->addWidget(cropCheckButton);

        zoomCheckButton = new QToolButton(toolBar);
        zoomCheckButton->setObjectName(QString::fromUtf8("zoomCheckButton"));
        zoomCheckButton->setCheckable(true);
        zoomCheckButton->setChecked(true);

        horizontalLayout->addWidget(zoomCheckButton);

        zoomPanel = new QWidget(toolBar);
        zoomPanel->setObjectName(QString::fromUtf8("zoomPanel"));
        horizontalLayout_2 = new QHBoxLayout(zoomPanel);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        zoomModeComboBox = new QComboBox(zoomPanel);
        zoomModeComboBox->setObjectName(QString::fromUtf8("zoomModeComboBox"));
        sizePolicy1.setHeightForWidth(zoomModeComboBox->sizePolicy().hasHeightForWidth());
        zoomModeComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(zoomModeComboBox);

        zoomRatioSpinBox = new QDoubleSpinBox(zoomPanel);
        zoomRatioSpinBox->setObjectName(QString::fromUtf8("zoomRatioSpinBox"));
        zoomRatioSpinBox->setKeyboardTracking(false);
        zoomRatioSpinBox->setMinimum(0.010000000000000);
        zoomRatioSpinBox->setMaximum(1024.000000000000000);
        zoomRatioSpinBox->setValue(2.000000000000000);

        horizontalLayout_2->addWidget(zoomRatioSpinBox);

        scaleModeComboBox = new QComboBox(zoomPanel);
        scaleModeComboBox->setObjectName(QString::fromUtf8("scaleModeComboBox"));

        horizontalLayout_2->addWidget(scaleModeComboBox);


        horizontalLayout->addWidget(zoomPanel);

        colorPickerButton = new QToolButton(toolBar);
        colorPickerButton->setObjectName(QString::fromUtf8("colorPickerButton"));

        horizontalLayout->addWidget(colorPickerButton);

        colorPickerButton->raise();
        frameNumberSlider->raise();
        frameToClipboardButton->raise();
        saveSnapshotButton->raise();
        advancedSettingsButton->raise();
        cropCheckButton->raise();
        zoomCheckButton->raise();
        zoomPanel->raise();
        timeLineCheckButton->raise();
        frameNumberSpinBox->raise();
        frameStatusLabel->raise();

        mainLayout->addWidget(toolBar);

        timeLinePanel = new QWidget(PreviewDialog);
        timeLinePanel->setObjectName(QString::fromUtf8("timeLinePanel"));
        horizontalLayout_4 = new QHBoxLayout(timeLinePanel);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        playButton = new QToolButton(timeLinePanel);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        horizontalLayout_4->addWidget(playButton);

        label = new QLabel(timeLinePanel);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        playFpsLimitModeComboBox = new QComboBox(timeLinePanel);
        playFpsLimitModeComboBox->setObjectName(QString::fromUtf8("playFpsLimitModeComboBox"));

        horizontalLayout_4->addWidget(playFpsLimitModeComboBox);

        playFpsLimitSpinBox = new QDoubleSpinBox(timeLinePanel);
        playFpsLimitSpinBox->setObjectName(QString::fromUtf8("playFpsLimitSpinBox"));
        playFpsLimitSpinBox->setDecimals(5);
        playFpsLimitSpinBox->setMaximum(100000.000000000000000);
        playFpsLimitSpinBox->setValue(23.999990000000000);

        horizontalLayout_4->addWidget(playFpsLimitSpinBox);

        horizontalSpacer_2 = new QSpacerItem(571, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        goToPreviousBookmarkButton = new QToolButton(timeLinePanel);
        goToPreviousBookmarkButton->setObjectName(QString::fromUtf8("goToPreviousBookmarkButton"));

        horizontalLayout_4->addWidget(goToPreviousBookmarkButton);

        bookmarkCurrentFrameButton = new QToolButton(timeLinePanel);
        bookmarkCurrentFrameButton->setObjectName(QString::fromUtf8("bookmarkCurrentFrameButton"));

        horizontalLayout_4->addWidget(bookmarkCurrentFrameButton);

        unbookmarkCurrentFrameButton = new QToolButton(timeLinePanel);
        unbookmarkCurrentFrameButton->setObjectName(QString::fromUtf8("unbookmarkCurrentFrameButton"));

        horizontalLayout_4->addWidget(unbookmarkCurrentFrameButton);

        loadChaptersButton = new QToolButton(timeLinePanel);
        loadChaptersButton->setObjectName(QString::fromUtf8("loadChaptersButton"));

        horizontalLayout_4->addWidget(loadChaptersButton);

        clearBookmarksButton = new QToolButton(timeLinePanel);
        clearBookmarksButton->setObjectName(QString::fromUtf8("clearBookmarksButton"));

        horizontalLayout_4->addWidget(clearBookmarksButton);

        goToNextBookmarkButton = new QToolButton(timeLinePanel);
        goToNextBookmarkButton->setObjectName(QString::fromUtf8("goToNextBookmarkButton"));

        horizontalLayout_4->addWidget(goToNextBookmarkButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        timeLineModeLabel = new QLabel(timeLinePanel);
        timeLineModeLabel->setObjectName(QString::fromUtf8("timeLineModeLabel"));
        timeLineModeLabel->setMargin(2);

        horizontalLayout_4->addWidget(timeLineModeLabel);

        timeLineModeComboBox = new QComboBox(timeLinePanel);
        timeLineModeComboBox->setObjectName(QString::fromUtf8("timeLineModeComboBox"));
        sizePolicy1.setHeightForWidth(timeLineModeComboBox->sizePolicy().hasHeightForWidth());
        timeLineModeComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(timeLineModeComboBox);

        stepLabel = new QLabel(timeLinePanel);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));
        stepLabel->setMargin(2);

        horizontalLayout_4->addWidget(stepLabel);

        timeStepEdit = new QTimeEdit(timeLinePanel);
        timeStepEdit->setObjectName(QString::fromUtf8("timeStepEdit"));

        horizontalLayout_4->addWidget(timeStepEdit);

        timeStepBackButton = new QToolButton(timeLinePanel);
        timeStepBackButton->setObjectName(QString::fromUtf8("timeStepBackButton"));

        horizontalLayout_4->addWidget(timeStepBackButton);

        timeStepForwardButton = new QToolButton(timeLinePanel);
        timeStepForwardButton->setObjectName(QString::fromUtf8("timeStepForwardButton"));

        horizontalLayout_4->addWidget(timeStepForwardButton);

        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(11, 1);

        mainLayout->addWidget(timeLinePanel);

        cropPanel = new QWidget(PreviewDialog);
        cropPanel->setObjectName(QString::fromUtf8("cropPanel"));
        horizontalLayout_3 = new QHBoxLayout(cropPanel);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cropModeLabel = new QLabel(cropPanel);
        cropModeLabel->setObjectName(QString::fromUtf8("cropModeLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cropModeLabel->sizePolicy().hasHeightForWidth());
        cropModeLabel->setSizePolicy(sizePolicy3);
        cropModeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropModeLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropModeLabel);

        cropModeComboBox = new QComboBox(cropPanel);
        cropModeComboBox->setObjectName(QString::fromUtf8("cropModeComboBox"));

        horizontalLayout_3->addWidget(cropModeComboBox);

        cropLeftLabel = new QLabel(cropPanel);
        cropLeftLabel->setObjectName(QString::fromUtf8("cropLeftLabel"));
        sizePolicy3.setHeightForWidth(cropLeftLabel->sizePolicy().hasHeightForWidth());
        cropLeftLabel->setSizePolicy(sizePolicy3);
        cropLeftLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropLeftLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropLeftLabel);

        cropLeftSpinBox = new QSpinBox(cropPanel);
        cropLeftSpinBox->setObjectName(QString::fromUtf8("cropLeftSpinBox"));
        cropLeftSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropLeftSpinBox);

        cropTopLabel = new QLabel(cropPanel);
        cropTopLabel->setObjectName(QString::fromUtf8("cropTopLabel"));
        sizePolicy3.setHeightForWidth(cropTopLabel->sizePolicy().hasHeightForWidth());
        cropTopLabel->setSizePolicy(sizePolicy3);
        cropTopLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropTopLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropTopLabel);

        cropTopSpinBox = new QSpinBox(cropPanel);
        cropTopSpinBox->setObjectName(QString::fromUtf8("cropTopSpinBox"));
        cropTopSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropTopSpinBox);

        cropWidthLabel = new QLabel(cropPanel);
        cropWidthLabel->setObjectName(QString::fromUtf8("cropWidthLabel"));
        sizePolicy3.setHeightForWidth(cropWidthLabel->sizePolicy().hasHeightForWidth());
        cropWidthLabel->setSizePolicy(sizePolicy3);
        cropWidthLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropWidthLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropWidthLabel);

        cropWidthSpinBox = new QSpinBox(cropPanel);
        cropWidthSpinBox->setObjectName(QString::fromUtf8("cropWidthSpinBox"));
        cropWidthSpinBox->setKeyboardTracking(false);
        cropWidthSpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(cropWidthSpinBox);

        cropHeightLabel = new QLabel(cropPanel);
        cropHeightLabel->setObjectName(QString::fromUtf8("cropHeightLabel"));
        sizePolicy3.setHeightForWidth(cropHeightLabel->sizePolicy().hasHeightForWidth());
        cropHeightLabel->setSizePolicy(sizePolicy3);
        cropHeightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropHeightLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropHeightLabel);

        cropHeightSpinBox = new QSpinBox(cropPanel);
        cropHeightSpinBox->setObjectName(QString::fromUtf8("cropHeightSpinBox"));
        cropHeightSpinBox->setKeyboardTracking(false);
        cropHeightSpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(cropHeightSpinBox);

        cropRightLabel = new QLabel(cropPanel);
        cropRightLabel->setObjectName(QString::fromUtf8("cropRightLabel"));
        sizePolicy3.setHeightForWidth(cropRightLabel->sizePolicy().hasHeightForWidth());
        cropRightLabel->setSizePolicy(sizePolicy3);
        cropRightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropRightLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropRightLabel);

        cropRightSpinBox = new QSpinBox(cropPanel);
        cropRightSpinBox->setObjectName(QString::fromUtf8("cropRightSpinBox"));
        cropRightSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropRightSpinBox);

        cropBottomLabel = new QLabel(cropPanel);
        cropBottomLabel->setObjectName(QString::fromUtf8("cropBottomLabel"));
        sizePolicy3.setHeightForWidth(cropBottomLabel->sizePolicy().hasHeightForWidth());
        cropBottomLabel->setSizePolicy(sizePolicy3);
        cropBottomLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropBottomLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropBottomLabel);

        cropBottomSpinBox = new QSpinBox(cropPanel);
        cropBottomSpinBox->setObjectName(QString::fromUtf8("cropBottomSpinBox"));
        cropBottomSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropBottomSpinBox);

        cropZoomLabel = new QLabel(cropPanel);
        cropZoomLabel->setObjectName(QString::fromUtf8("cropZoomLabel"));
        sizePolicy3.setHeightForWidth(cropZoomLabel->sizePolicy().hasHeightForWidth());
        cropZoomLabel->setSizePolicy(sizePolicy3);
        cropZoomLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropZoomLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropZoomLabel);

        cropZoomRatioSpinBox = new QSpinBox(cropPanel);
        cropZoomRatioSpinBox->setObjectName(QString::fromUtf8("cropZoomRatioSpinBox"));
        cropZoomRatioSpinBox->setKeyboardTracking(false);
        cropZoomRatioSpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(cropZoomRatioSpinBox);

        cropPasteToScriptButton = new QToolButton(cropPanel);
        cropPasteToScriptButton->setObjectName(QString::fromUtf8("cropPasteToScriptButton"));

        horizontalLayout_3->addWidget(cropPasteToScriptButton);


        mainLayout->addWidget(cropPanel);

        toolBar->raise();
        previewArea->raise();
        cropPanel->raise();
        timeLinePanel->raise();

        retranslateUi(PreviewDialog);

        QMetaObject::connectSlotsByName(PreviewDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewDialog)
    {
        PreviewDialog->setWindowTitle(QCoreApplication::translate("PreviewDialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        timeLineCheckButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Timeline", nullptr));
#endif // QT_CONFIG(tooltip)
        frameStatusLabel->setText(QString());
#if QT_CONFIG(tooltip)
        frameToClipboardButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Copy frame to clipboard", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        saveSnapshotButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Save snapshot", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        advancedSettingsButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Preview Advanced Settings", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cropCheckButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Crop assistant", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        zoomCheckButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Zoom", nullptr));
#endif // QT_CONFIG(tooltip)
        zoomRatioSpinBox->setPrefix(QCoreApplication::translate("PreviewDialog", "x", nullptr));
#if QT_CONFIG(tooltip)
        colorPickerButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Color picker", nullptr));
#endif // QT_CONFIG(tooltip)
        colorPickerButton->setText(QString());
        playButton->setText(QString());
        label->setText(QCoreApplication::translate("PreviewDialog", "FPS limit mode:", nullptr));
        goToPreviousBookmarkButton->setText(QString());
        loadChaptersButton->setText(QString());
        timeLineModeLabel->setText(QCoreApplication::translate("PreviewDialog", "Timeline display mode:", nullptr));
        stepLabel->setText(QCoreApplication::translate("PreviewDialog", "Step:", nullptr));
        timeStepEdit->setDisplayFormat(QCoreApplication::translate("PreviewDialog", "H:mm:ss.zzz", nullptr));
#if QT_CONFIG(tooltip)
        timeStepBackButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Step back", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        timeStepForwardButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Step forward", nullptr));
#endif // QT_CONFIG(tooltip)
        cropModeLabel->setText(QCoreApplication::translate("PreviewDialog", "Crop mode:", nullptr));
        cropLeftLabel->setText(QCoreApplication::translate("PreviewDialog", "Left:", nullptr));
        cropTopLabel->setText(QCoreApplication::translate("PreviewDialog", "Top:", nullptr));
        cropWidthLabel->setText(QCoreApplication::translate("PreviewDialog", "Width:", nullptr));
        cropHeightLabel->setText(QCoreApplication::translate("PreviewDialog", "Height:", nullptr));
        cropRightLabel->setText(QCoreApplication::translate("PreviewDialog", "Right:", nullptr));
        cropBottomLabel->setText(QCoreApplication::translate("PreviewDialog", "Bottom:", nullptr));
        cropZoomLabel->setText(QCoreApplication::translate("PreviewDialog", "Zoom:", nullptr));
        cropZoomRatioSpinBox->setPrefix(QCoreApplication::translate("PreviewDialog", "x", nullptr));
#if QT_CONFIG(tooltip)
        cropPasteToScriptButton->setToolTip(QCoreApplication::translate("PreviewDialog", "Paste into script", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class PreviewDialog: public Ui_PreviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEW_DIALOG_H
