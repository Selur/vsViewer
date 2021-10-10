/********************************************************************************
** Form generated from reading UI file 'preview_advanced_settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEW_ADVANCED_SETTINGS_DIALOG_H
#define UI_PREVIEW_ADVANCED_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
            PreviewAdvancedSettingsDialog->setObjectName(QString::fromUtf8("PreviewAdvancedSettingsDialog"));
        PreviewAdvancedSettingsDialog->resize(364, 181);
        gridLayout = new QGridLayout(PreviewAdvancedSettingsDialog);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 6);
        label_4 = new QLabel(PreviewAdvancedSettingsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        yuvMatrixCoefficientsComboBox = new QComboBox(PreviewAdvancedSettingsDialog);
        yuvMatrixCoefficientsComboBox->setObjectName(QString::fromUtf8("yuvMatrixCoefficientsComboBox"));

        gridLayout->addWidget(yuvMatrixCoefficientsComboBox, 0, 1, 1, 1);

        chromaPlacementComboBox = new QComboBox(PreviewAdvancedSettingsDialog);
        chromaPlacementComboBox->setObjectName(QString::fromUtf8("chromaPlacementComboBox"));

        gridLayout->addWidget(chromaPlacementComboBox, 2, 1, 1, 1);

        chromaResamplingFilterComboBox = new QComboBox(PreviewAdvancedSettingsDialog);
        chromaResamplingFilterComboBox->setObjectName(QString::fromUtf8("chromaResamplingFilterComboBox"));

        gridLayout->addWidget(chromaResamplingFilterComboBox, 1, 1, 1, 1);

        label_2 = new QLabel(PreviewAdvancedSettingsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(PreviewAdvancedSettingsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(PreviewAdvancedSettingsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(PreviewAdvancedSettingsDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_5 = new QLabel(PreviewAdvancedSettingsDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        bicubicFilterParameterCSpinBox = new QDoubleSpinBox(PreviewAdvancedSettingsDialog);
        bicubicFilterParameterCSpinBox->setObjectName(QString::fromUtf8("bicubicFilterParameterCSpinBox"));
        bicubicFilterParameterCSpinBox->setDecimals(6);
        bicubicFilterParameterCSpinBox->setMinimum(-100000.000000000000000);
        bicubicFilterParameterCSpinBox->setMaximum(100000.000000000000000);
        bicubicFilterParameterCSpinBox->setSingleStep(0.000001000000000);
        bicubicFilterParameterCSpinBox->setValue(0.333333000000000);

        gridLayout->addWidget(bicubicFilterParameterCSpinBox, 4, 1, 1, 1);

        bicubicFilterParameterBSpinBox = new QDoubleSpinBox(PreviewAdvancedSettingsDialog);
        bicubicFilterParameterBSpinBox->setObjectName(QString::fromUtf8("bicubicFilterParameterBSpinBox"));
        bicubicFilterParameterBSpinBox->setDecimals(6);
        bicubicFilterParameterBSpinBox->setMinimum(-100000.000000000000000);
        bicubicFilterParameterBSpinBox->setMaximum(100000.000000000000000);
        bicubicFilterParameterBSpinBox->setSingleStep(0.000001000000000);
        bicubicFilterParameterBSpinBox->setValue(0.333333000000000);

        gridLayout->addWidget(bicubicFilterParameterBSpinBox, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(PreviewAdvancedSettingsDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(true);

        horizontalLayout->addWidget(okButton);

        applyButton = new QPushButton(PreviewAdvancedSettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout->addWidget(applyButton);

        resetToDefaultButton = new QPushButton(PreviewAdvancedSettingsDialog);
        resetToDefaultButton->setObjectName(QString::fromUtf8("resetToDefaultButton"));

        horizontalLayout->addWidget(resetToDefaultButton);

        cancelButton = new QPushButton(PreviewAdvancedSettingsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        lanczosFilterTapsSpinBox = new QSpinBox(PreviewAdvancedSettingsDialog);
        lanczosFilterTapsSpinBox->setObjectName(QString::fromUtf8("lanczosFilterTapsSpinBox"));
        lanczosFilterTapsSpinBox->setMinimum(2);
        lanczosFilterTapsSpinBox->setMaximum(4096);
        lanczosFilterTapsSpinBox->setValue(3);

        gridLayout->addWidget(lanczosFilterTapsSpinBox, 5, 1, 1, 1);


        retranslateUi(PreviewAdvancedSettingsDialog);

        QMetaObject::connectSlotsByName(PreviewAdvancedSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewAdvancedSettingsDialog)
    {
        PreviewAdvancedSettingsDialog->setWindowTitle(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Preview Advanced Settings", nullptr));
        label_4->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Bicubic filter parameter b:", nullptr));
        label_2->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Chroma resampling filter:", nullptr));
        label->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Y'CbCr / Y'UV matrix coefficients:", nullptr));
        label_3->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Chroma placement:", nullptr));
        label_6->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Lanczos filter taps:", nullptr));
        label_5->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Bicubic filter parameter c:", nullptr));
        okButton->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "OK", nullptr));
        applyButton->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Apply", nullptr));
        resetToDefaultButton->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Reset to default", nullptr));
        cancelButton->setText(QCoreApplication::translate("PreviewAdvancedSettingsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewAdvancedSettingsDialog: public Ui_PreviewAdvancedSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEW_ADVANCED_SETTINGS_DIALOG_H
