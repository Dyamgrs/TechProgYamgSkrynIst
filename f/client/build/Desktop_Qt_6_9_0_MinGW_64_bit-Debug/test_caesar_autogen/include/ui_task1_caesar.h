/********************************************************************************
** Form generated from reading UI file 'task1_caesar.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_CAESAR_H
#define UI_TASK1_CAESAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task1_Caesar
{
public:
    QLabel *label_title;
    QLabel *label_shift;
    QSpinBox *spinBox_shift;
    QLabel *label_input;
    QPlainTextEdit *plainTextEdit_input;
    QLabel *label_output;
    QPlainTextEdit *plainTextEdit_output;
    QPushButton *pushButton_encrypt;
    QPushButton *pushButton_decrypt;
    QPushButton *pushButton_back;

    void setupUi(QWidget *Task1_Caesar)
    {
        if (Task1_Caesar->objectName().isEmpty())
            Task1_Caesar->setObjectName("Task1_Caesar");
        Task1_Caesar->resize(600, 400);
        Task1_Caesar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_title = new QLabel(Task1_Caesar);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(150, 20, 300, 40));
        label_title->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0);"));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_shift = new QLabel(Task1_Caesar);
        label_shift->setObjectName("label_shift");
        label_shift->setGeometry(QRect(50, 80, 60, 30));
        label_shift->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0)"));
        spinBox_shift = new QSpinBox(Task1_Caesar);
        spinBox_shift->setObjectName("spinBox_shift");
        spinBox_shift->setGeometry(QRect(120, 80, 30, 25));
        spinBox_shift->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0)"));
        spinBox_shift->setMinimum(1);
        spinBox_shift->setMaximum(25);
        spinBox_shift->setValue(3);
        label_input = new QLabel(Task1_Caesar);
        label_input->setObjectName("label_input");
        label_input->setGeometry(QRect(50, 130, 100, 30));
        label_input->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0)"));
        plainTextEdit_input = new QPlainTextEdit(Task1_Caesar);
        plainTextEdit_input->setObjectName("plainTextEdit_input");
        plainTextEdit_input->setGeometry(QRect(50, 160, 500, 100));
        label_output = new QLabel(Task1_Caesar);
        label_output->setObjectName("label_output");
        label_output->setGeometry(QRect(50, 270, 100, 30));
        label_output->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0)"));
        plainTextEdit_output = new QPlainTextEdit(Task1_Caesar);
        plainTextEdit_output->setObjectName("plainTextEdit_output");
        plainTextEdit_output->setGeometry(QRect(50, 300, 500, 60));
        plainTextEdit_output->setReadOnly(true);
        pushButton_encrypt = new QPushButton(Task1_Caesar);
        pushButton_encrypt->setObjectName("pushButton_encrypt");
        pushButton_encrypt->setGeometry(QRect(50, 370, 120, 30));
        pushButton_encrypt->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0);\n"
"background: rgb(255, 255, 127);"));
        pushButton_decrypt = new QPushButton(Task1_Caesar);
        pushButton_decrypt->setObjectName("pushButton_decrypt");
        pushButton_decrypt->setGeometry(QRect(200, 370, 120, 30));
        pushButton_decrypt->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0);\n"
"background: rgb(255, 255, 127);"));
        pushButton_back = new QPushButton(Task1_Caesar);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(350, 370, 200, 30));
        pushButton_back->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"color: rgb(0, 0, 0);\n"
"background: rgb(255, 255, 127);"));

        retranslateUi(Task1_Caesar);

        QMetaObject::connectSlotsByName(Task1_Caesar);
    } // setupUi

    void retranslateUi(QWidget *Task1_Caesar)
    {
        Task1_Caesar->setWindowTitle(QCoreApplication::translate("Task1_Caesar", "Caesar Cipher", nullptr));
        label_title->setText(QCoreApplication::translate("Task1_Caesar", "Caesar Cipher", nullptr));
        label_shift->setText(QCoreApplication::translate("Task1_Caesar", "Shift:", nullptr));
        label_input->setText(QCoreApplication::translate("Task1_Caesar", "Input Text:", nullptr));
        plainTextEdit_input->setPlaceholderText(QCoreApplication::translate("Task1_Caesar", "Enter text here...", nullptr));
        label_output->setText(QCoreApplication::translate("Task1_Caesar", "Output Text:", nullptr));
        plainTextEdit_output->setPlaceholderText(QCoreApplication::translate("Task1_Caesar", "Result will appear here...", nullptr));
        pushButton_encrypt->setText(QCoreApplication::translate("Task1_Caesar", "Encrypt", nullptr));
        pushButton_decrypt->setText(QCoreApplication::translate("Task1_Caesar", "Decrypt", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Task1_Caesar", "Back to Main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task1_Caesar: public Ui_Task1_Caesar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_CAESAR_H
