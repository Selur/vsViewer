/********************************************************************************
** Form generated from reading UI file 'preview_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEW_DIALOG_H
#define UI_PREVIEW_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            PreviewDialog->setObjectName(QStringLiteral("PreviewDialog"));
        PreviewDialog->resize(933, 652);
        mainLayout = new QVBoxLayout(PreviewDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        previewArea = new PreviewArea(PreviewDialog);
        previewArea->setObjectName(QStringLiteral("previewArea"));

        mainLayout->addWidget(previewArea);

        toolBar = new QWidget(PreviewDialog);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(toolBar);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        timeLineCheckButton = new QToolButton(toolBar);
        timeLineCheckButton->setObjectName(QStringLiteral("timeLineCheckButton"));
        timeLineCheckButton->setCheckable(true);

        horizontalLayout->addWidget(timeLineCheckButton);

        frameNumberSpinBox = new QSpinBox(toolBar);
        frameNumberSpinBox->setObjectName(QStringLiteral("frameNumberSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frameNumberSpinBox->sizePolicy().hasHeightForWidth());
        frameNumberSpinBox->setSizePolicy(sizePolicy1);
        frameNumberSpinBox->setKeyboardTracking(false);
        frameNumberSpinBox->setMaximum(999999999);

        horizontalLayout->addWidget(frameNumberSpinBox);

        frameStatusLabel = new QLabel(toolBar);
        frameStatusLabel->setObjectName(QStringLiteral("frameStatusLabel"));
        frameStatusLabel->setMinimumSize(QSize(16, 0));

        horizontalLayout->addWidget(frameStatusLabel);

        frameNumberSlider = new TimeLineSlider(toolBar);
        frameNumberSlider->setObjectName(QStringLiteral("frameNumberSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameNumberSlider->sizePolicy().hasHeightForWidth());
        frameNumberSlider->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(frameNumberSlider);

        frameToClipboardButton = new QToolButton(toolBar);
        frameToClipboardButton->setObjectName(QStringLiteral("frameToClipboardButton"));

        horizontalLayout->addWidget(frameToClipboardButton);

        saveSnapshotButton = new QToolButton(toolBar);
        saveSnapshotButton->setObjectName(QStringLiteral("saveSnapshotButton"));

        horizontalLayout->addWidget(saveSnapshotButton);

        advancedSettingsButton = new QToolButton(toolBar);
        advancedSettingsButton->setObjectName(QStringLiteral("advancedSettingsButton"));

        horizontalLayout->addWidget(advancedSettingsButton);

        cropCheckButton = new QToolButton(toolBar);
        cropCheckButton->setObjectName(QStringLiteral("cropCheckButton"));
        cropCheckButton->setCheckable(true);

        horizontalLayout->addWidget(cropCheckButton);

        zoomCheckButton = new QToolButton(toolBar);
        zoomCheckButton->setObjectName(QStringLiteral("zoomCheckButton"));
        zoomCheckButton->setCheckable(true);
        zoomCheckButton->setChecked(true);

        horizontalLayout->addWidget(zoomCheckButton);

        zoomPanel = new QWidget(toolBar);
        zoomPanel->setObjectName(QStringLiteral("zoomPanel"));
        horizontalLayout_2 = new QHBoxLayout(zoomPanel);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        zoomModeComboBox = new QComboBox(zoomPanel);
        zoomModeComboBox->setObjectName(QStringLiteral("zoomModeComboBox"));
        sizePolicy1.setHeightForWidth(zoomModeComboBox->sizePolicy().hasHeightForWidth());
        zoomModeComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(zoomModeComboBox);

        zoomRatioSpinBox = new QDoubleSpinBox(zoomPanel);
        zoomRatioSpinBox->setObjectName(QStringLiteral("zoomRatioSpinBox"));
        zoomRatioSpinBox->setKeyboardTracking(false);
        zoomRatioSpinBox->setMinimum(0.01);
        zoomRatioSpinBox->setMaximum(1024);
        zoomRatioSpinBox->setValue(2);

        horizontalLayout_2->addWidget(zoomRatioSpinBox);

        scaleModeComboBox = new QComboBox(zoomPanel);
        scaleModeComboBox->setObjectName(QStringLiteral("scaleModeComboBox"));

        horizontalLayout_2->addWidget(scaleModeComboBox);


        horizontalLayout->addWidget(zoomPanel);

        colorPickerButton = new QToolButton(toolBar);
        colorPickerButton->setObjectName(QStringLiteral("colorPickerButton"));

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
        timeLinePanel->setObjectName(QStringLiteral("timeLinePanel"));
        horizontalLayout_4 = new QHBoxLayout(timeLinePanel);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        playButton = new QToolButton(timeLinePanel);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout_4->addWidget(playButton);

        label = new QLabel(timeLinePanel);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        playFpsLimitModeComboBox = new QComboBox(timeLinePanel);
        playFpsLimitModeComboBox->setObjectName(QStringLiteral("playFpsLimitModeComboBox"));

        horizontalLayout_4->addWidget(playFpsLimitModeComboBox);

        playFpsLimitSpinBox = new QDoubleSpinBox(timeLinePanel);
        playFpsLimitSpinBox->setObjectName(QStringLiteral("playFpsLimitSpinBox"));
        playFpsLimitSpinBox->setDecimals(5);
        playFpsLimitSpinBox->setMaximum(100000);
        playFpsLimitSpinBox->setValue(24);

        horizontalLayout_4->addWidget(playFpsLimitSpinBox);

        horizontalSpacer_2 = new QSpacerItem(571, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        goToPreviousBookmarkButton = new QToolButton(timeLinePanel);
        goToPreviousBookmarkButton->setObjectName(QStringLiteral("goToPreviousBookmarkButton"));

        horizontalLayout_4->addWidget(goToPreviousBookmarkButton);

        bookmarkCurrentFrameButton = new QToolButton(timeLinePanel);
        bookmarkCurrentFrameButton->setObjectName(QStringLiteral("bookmarkCurrentFrameButton"));

        horizontalLayout_4->addWidget(bookmarkCurrentFrameButton);

        unbookmarkCurrentFrameButton = new QToolButton(timeLinePanel);
        unbookmarkCurrentFrameButton->setObjectName(QStringLiteral("unbookmarkCurrentFrameButton"));

        horizontalLayout_4->addWidget(unbookmarkCurrentFrameButton);

        loadChaptersButton = new QToolButton(timeLinePanel);
        loadChaptersButton->setObjectName(QStringLiteral("loadChaptersButton"));

        horizontalLayout_4->addWidget(loadChaptersButton);

        clearBookmarksButton = new QToolButton(timeLinePanel);
        clearBookmarksButton->setObjectName(QStringLiteral("clearBookmarksButton"));

        horizontalLayout_4->addWidget(clearBookmarksButton);

        goToNextBookmarkButton = new QToolButton(timeLinePanel);
        goToNextBookmarkButton->setObjectName(QStringLiteral("goToNextBookmarkButton"));

        horizontalLayout_4->addWidget(goToNextBookmarkButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        timeLineModeLabel = new QLabel(timeLinePanel);
        timeLineModeLabel->setObjectName(QStringLiteral("timeLineModeLabel"));
        timeLineModeLabel->setMargin(2);

        horizontalLayout_4->addWidget(timeLineModeLabel);

        timeLineModeComboBox = new QComboBox(timeLinePanel);
        timeLineModeComboBox->setObjectName(QStringLiteral("timeLineModeComboBox"));
        sizePolicy1.setHeightForWidth(timeLineModeComboBox->sizePolicy().hasHeightForWidth());
        timeLineModeComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(timeLineModeComboBox);

        stepLabel = new QLabel(timeLinePanel);
        stepLabel->setObjectName(QStringLiteral("stepLabel"));
        stepLabel->setMargin(2);

        horizontalLayout_4->addWidget(stepLabel);

        timeStepEdit = new QTimeEdit(timeLinePanel);
        timeStepEdit->setObjectName(QStringLiteral("timeStepEdit"));

        horizontalLayout_4->addWidget(timeStepEdit);

        timeStepBackButton = new QToolButton(timeLinePanel);
        timeStepBackButton->setObjectName(QStringLiteral("timeStepBackButton"));

        horizontalLayout_4->addWidget(timeStepBackButton);

        timeStepForwardButton = new QToolButton(timeLinePanel);
        timeStepForwardButton->setObjectName(QStringLiteral("timeStepForwardButton"));

        horizontalLayout_4->addWidget(timeStepForwardButton);

        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(11, 1);

        mainLayout->addWidget(timeLinePanel);

        cropPanel = new QWidget(PreviewDialog);
        cropPanel->setObjectName(QStringLiteral("cropPanel"));
        horizontalLayout_3 = new QHBoxLayout(cropPanel);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cropModeLabel = new QLabel(cropPanel);
        cropModeLabel->setObjectName(QStringLiteral("cropModeLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cropModeLabel->sizePolicy().hasHeightForWidth());
        cropModeLabel->setSizePolicy(sizePolicy3);
        cropModeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropModeLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropModeLabel);

        cropModeComboBox = new QComboBox(cropPanel);
        cropModeComboBox->setObjectName(QStringLiteral("cropModeComboBox"));

        horizontalLayout_3->addWidget(cropModeComboBox);

        cropLeftLabel = new QLabel(cropPanel);
        cropLeftLabel->setObjectName(QStringLiteral("cropLeftLabel"));
        sizePolicy3.setHeightForWidth(cropLeftLabel->sizePolicy().hasHeightForWidth());
        cropLeftLabel->setSizePolicy(sizePolicy3);
        cropLeftLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropLeftLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropLeftLabel);

        cropLeftSpinBox = new QSpinBox(cropPanel);
        cropLeftSpinBox->setObjectName(QStringLiteral("cropLeftSpinBox"));
        cropLeftSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropLeftSpinBox);

        cropTopLabel = new QLabel(cropPanel);
        cropTopLabel->setObjectName(QStringLiteral("cropTopLabel"));
        sizePolicy3.setHeightForWidth(cropTopLabel->sizePolicy().hasHeightForWidth());
        cropTopLabel->setSizePolicy(sizePolicy3);
        cropTopLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropTopLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropTopLabel);

        cropTopSpinBox = new QSpinBox(cropPanel);
        cropTopSpinBox->setObjectName(QStringLiteral("cropTopSpinBox"));
        cropTopSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropTopSpinBox);

        cropWidthLabel = new QLabel(cropPanel);
        cropWidthLabel->setObjectName(QStringLiteral("cropWidthLabel"));
        sizePolicy3.setHeightForWidth(cropWidthLabel->sizePolicy().hasHeightForWidth());
        cropWidthLabel->setSizePolicy(sizePolicy3);
        cropWidthLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropWidthLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropWidthLabel);

        cropWidthSpinBox = new QSpinBox(cropPanel);
        cropWidthSpinBox->setObjectName(QStringLiteral("cropWidthSpinBox"));
        cropWidthSpinBox->setKeyboardTracking(false);
        cropWidthSpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(cropWidthSpinBox);

        cropHeightLabel = new QLabel(cropPanel);
        cropHeightLabel->setObjectName(QStringLiteral("cropHeightLabel"));
        sizePolicy3.setHeightForWidth(cropHeightLabel->sizePolicy().hasHeightForWidth());
        cropHeightLabel->setSizePolicy(sizePolicy3);
        cropHeightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropHeightLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropHeightLabel);

        cropHeightSpinBox = new QSpinBox(cropPanel);
        cropHeightSpinBox->setObjectName(QStringLiteral("cropHeightSpinBox"));
        cropHeightSpinBox->setKeyboardTracking(false);
        cropHeightSpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(cropHeightSpinBox);

        cropRightLabel = new QLabel(cropPanel);
        cropRightLabel->setObjectName(QStringLiteral("cropRightLabel"));
        sizePolicy3.setHeightForWidth(cropRightLabel->sizePolicy().hasHeightForWidth());
        cropRightLabel->setSizePolicy(sizePolicy3);
        cropRightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropRightLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropRightLabel);

        cropRightSpinBox = new QSpinBox(cropPanel);
        cropRightSpinBox->setObjectName(QStringLiteral("cropRightSpinBox"));
        cropRightSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropRightSpinBox);

        cropBottomLabel = new QLabel(cropPanel);
        cropBottomLabel->setObjectName(QStringLiteral("cropBottomLabel"));
        sizePolicy3.setHeightForWidth(cropBottomLabel->sizePolicy().hasHeightForWidth());
        cropBottomLabel->setSizePolicy(sizePolicy3);
        cropBottomLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropBottomLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropBottomLabel);

        cropBottomSpinBox = new QSpinBox(cropPanel);
        cropBottomSpinBox->setObjectName(QStringLiteral("cropBottomSpinBox"));
        cropBottomSpinBox->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(cropBottomSpinBox);

        cropZoomLabel = new QLabel(cropPanel);
        cropZoomLabel->setObjectName(QStringLiteral("cropZoomLabel"));
        sizePolicy3.setHeightForWidth(cropZoomLabel->sizePolicy().hasHeightForWidth());
        cropZoomLabel->setSizePolicy(sizePolicy3);
        cropZoomLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cropZoomLabel->setMargin(4);

        horizontalLayout_3->addWidget(cropZoomLabel);

        cropZoomRatioSpinBox = new QSpinBox(cropPanel);
        cropZoomRatioSpinBox->setObjectName(QStringLiteral("cropZoomRatioSpinBox"));
        cropZoomRatioSpinBox->setKeyboardTracking(false);
        cropZoomRatioSpinBox->setMinimum(1);

        horizontalLayout_3->addWidget(cropZoomRatioSpinBox);

        cropPasteToScriptButton = new QToolButton(cropPanel);
        cropPasteToScriptButton->setObjectName(QStringLiteral("cropPasteToScriptButton"));

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
        PreviewDialog->setWindowTitle(QApplication::translate("PreviewDialog", "Dialog", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        timeLineCheckButton->setToolTip(QApplication::translate("PreviewDialog", "Timeline", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        frameStatusLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        frameToClipboardButton->setToolTip(QApplication::translate("PreviewDialog", "Copy frame to clipboard", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        saveSnapshotButton->setToolTip(QApplication::translate("PreviewDialog", "Save snapshot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        advancedSettingsButton->setToolTip(QApplication::translate("PreviewDialog", "Preview Advanced Settings", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cropCheckButton->setToolTip(QApplication::translate("PreviewDialog", "Crop assistant", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        zoomCheckButton->setToolTip(QApplication::translate("PreviewDialog", "Zoom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        zoomRatioSpinBox->setPrefix(QApplication::translate("PreviewDialog", "x", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        colorPickerButton->setToolTip(QApplication::translate("PreviewDialog", "Color picker", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        colorPickerButton->setText(QString());
        playButton->setText(QString());
        label->setText(QApplication::translate("PreviewDialog", "FPS limit mode:", Q_NULLPTR));
        goToPreviousBookmarkButton->setText(QString());
        loadChaptersButton->setText(QString());
        timeLineModeLabel->setText(QApplication::translate("PreviewDialog", "Timeline display mode:", Q_NULLPTR));
        stepLabel->setText(QApplication::translate("PreviewDialog", "Step:", Q_NULLPTR));
        timeStepEdit->setDisplayFormat(QApplication::translate("PreviewDialog", "H:mm:ss.zzz", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        timeStepBackButton->setToolTip(QApplication::translate("PreviewDialog", "Step back", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        timeStepForwardButton->setToolTip(QApplication::translate("PreviewDialog", "Step forward", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cropModeLabel->setText(QApplication::translate("PreviewDialog", "Crop mode:", Q_NULLPTR));
        cropLeftLabel->setText(QApplication::translate("PreviewDialog", "Left:", Q_NULLPTR));
        cropTopLabel->setText(QApplication::translate("PreviewDialog", "Top:", Q_NULLPTR));
        cropWidthLabel->setText(QApplication::translate("PreviewDialog", "Width:", Q_NULLPTR));
        cropHeightLabel->setText(QApplication::translate("PreviewDialog", "Height:", Q_NULLPTR));
        cropRightLabel->setText(QApplication::translate("PreviewDialog", "Right:", Q_NULLPTR));
        cropBottomLabel->setText(QApplication::translate("PreviewDialog", "Bottom:", Q_NULLPTR));
        cropZoomLabel->setText(QApplication::translate("PreviewDialog", "Zoom:", Q_NULLPTR));
        cropZoomRatioSpinBox->setPrefix(QApplication::translate("PreviewDialog", "x", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cropPasteToScriptButton->setToolTip(QApplication::translate("PreviewDialog", "Paste into script", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class PreviewDialog: public Ui_PreviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEW_DIALOG_H
