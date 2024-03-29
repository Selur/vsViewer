/********************************************************************************
** Form generated from reading UI file 'preview_advanced_settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEW_ADVANCED_SETTINGS_DIALOG_H
#define UI_PREVIEW_ADVANCED_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PreviewAdvancedSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *yuvMatrixCoefficientsComboBox;
    QComboBox *chromaPlacementComboBox;
    QComboBox *chromaResamplingFilterComboBox;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *bicubicFilterParameterCSpinBox;
    QDoubleSpinBox *bicubicFilterParameterBSpinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *applyButton;
    QPushButton *resetToDefaultButton;
    QPushButton *cancelButton;
    QSpinBox *lanczosFilterTapsSpinBox;

    void setupUi(QDialog *PreviewAdvancedSettingsDialog)
    {
        if (PreviewAdvancedSettingsDialog->objectName().isEmpty())
            PreviewAdvancedSettingsDialog->setObjectName(QStringLiteral("PreviewAdvancedSettingsDialog"));
        PreviewAdvancedSettingsDialog->resize(364, 181);
        gridLayout = new QGridLayout(PreviewAdvancedSettingsDialog);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        label_4 = new QLabel(PreviewAdvancedSettingsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        yuvMatrixCoefficientsComboBox = new QComboBox(PreviewAdvancedSettingsDialog);
        yuvMatrixCoefficientsComboBox->setObjectName(QStringLiteral("yuvMatrixCoefficientsComboBox"));

        gridLayout->addWidget(yuvMatrixCoefficientsComboBox, 0, 1, 1, 1);

        chromaPlacementComboBox = new QComboBox(PreviewAdvancedSettingsDialog);
        chromaPlacementComboBox->setObjectName(QStringLiteral("chromaPlacementComboBox"));

        gridLayout->addWidget(chromaPlacementComboBox, 2, 1, 1, 1);

        chromaResamplingFilterComboBox = new QComboBox(PreviewAdvancedSettingsDialog);
        chromaResamplingFilterComboBox->setObjectName(QStringLiteral("chromaResamplingFilterComboBox"));

        gridLayout->addWidget(chromaResamplingFilterComboBox, 1, 1, 1, 1);

        label_2 = new QLabel(PreviewAdvancedSettingsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(PreviewAdvancedSettingsDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(PreviewAdvancedSettingsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(PreviewAdvancedSettingsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_5 = new QLabel(PreviewAdvancedSettingsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        bicubicFilterParameterCSpinBox = new QDoubleSpinBox(PreviewAdvancedSettingsDialog);
        bicubicFilterParameterCSpinBox->setObjectName(QStringLiteral("bicubicFilterParameterCSpinBox"));
        bicubicFilterParameterCSpinBox->setDecimals(6);
        bicubicFilterParameterCSpinBox->setMinimum(-100000);
        bicubicFilterParameterCSpinBox->setMaximum(100000);
        bicubicFilterParameterCSpinBox->setSingleStep(1e-6);
        bicubicFilterParameterCSpinBox->setValue(0.333333);

        gridLayout->addWidget(bicubicFilterParameterCSpinBox, 4, 1, 1, 1);

        bicubicFilterParameterBSpinBox = new QDoubleSpinBox(PreviewAdvancedSettingsDialog);
        bicubicFilterParameterBSpinBox->setObjectName(QStringLiteral("bicubicFilterParameterBSpinBox"));
        bicubicFilterParameterBSpinBox->setDecimals(6);
        bicubicFilterParameterBSpinBox->setMinimum(-100000);
        bicubicFilterParameterBSpinBox->setMaximum(100000);
        bicubicFilterParameterBSpinBox->setSingleStep(1e-6);
        bicubicFilterParameterBSpinBox->setValue(0.333333);

        gridLayout->addWidget(bicubicFilterParameterBSpinBox, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(PreviewAdvancedSettingsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setAutoDefault(true);

        horizontalLayout->addWidget(okButton);

        applyButton = new QPushButton(PreviewAdvancedSettingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);

        resetToDefaultButton = new QPushButton(PreviewAdvancedSettingsDialog);
        resetToDefaultButton->setObjectName(QStringLiteral("resetToDefaultButton"));

        horizontalLayout->addWidget(resetToDefaultButton);

        cancelButton = new QPushButton(PreviewAdvancedSettingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        lanczosFilterTapsSpinBox = new QSpinBox(PreviewAdvancedSettingsDialog);
        lanczosFilterTapsSpinBox->setObjectName(QStringLiteral("lanczosFilterTapsSpinBox"));
        lanczosFilterTapsSpinBox->setMinimum(2);
        lanczosFilterTapsSpinBox->setMaximum(4096);
        lanczosFilterTapsSpinBox->setValue(3);

        gridLayout->addWidget(lanczosFilterTapsSpinBox, 5, 1, 1, 1);


        retranslateUi(PreviewAdvancedSettingsDialog);

        QMetaObject::connectSlotsByName(PreviewAdvancedSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewAdvancedSettingsDialog)
    {
        PreviewAdvancedSettingsDialog->setWindowTitle(QApplication::translate("PreviewAdvancedSettingsDialog", "Preview Advanced Settings", Q_NULLPTR));
        label_4->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Bicubic filter parameter b:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Chroma resampling filter:", Q_NULLPTR));
        label->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Y'CbCr / Y'UV matrix coefficients:", Q_NULLPTR));
        label_3->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Chroma placement:", Q_NULLPTR));
        label_6->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Lanczos filter taps:", Q_NULLPTR));
        label_5->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Bicubic filter parameter c:", Q_NULLPTR));
        okButton->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "OK", Q_NULLPTR));
        applyButton->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Apply", Q_NULLPTR));
        resetToDefaultButton->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Reset to default", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("PreviewAdvancedSettingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PreviewAdvancedSettingsDialog: public Ui_PreviewAdvancedSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEW_ADVANCED_SETTINGS_DIALOG_H
