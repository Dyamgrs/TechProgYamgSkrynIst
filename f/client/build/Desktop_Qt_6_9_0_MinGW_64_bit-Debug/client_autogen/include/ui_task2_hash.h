/********************************************************************************
** Form generated from reading UI file 'task2_hash.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK2_HASH_H
#define UI_TASK2_HASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task2_hash
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *inputLineEdit;
    QPushButton *calculateButton;
    QLabel *resultLabel;
    QPushButton *backButton;

    void setupUi(QWidget *task2_hash)
    {
        if (task2_hash->objectName().isEmpty())
            task2_hash->setObjectName("task2_hash");
        task2_hash->resize(400, 300);
        verticalLayout = new QVBoxLayout(task2_hash);
        verticalLayout->setObjectName("verticalLayout");
        inputLineEdit = new QLineEdit(task2_hash);
        inputLineEdit->setObjectName("inputLineEdit");

        verticalLayout->addWidget(inputLineEdit);

        calculateButton = new QPushButton(task2_hash);
        calculateButton->setObjectName("calculateButton");

        verticalLayout->addWidget(calculateButton);

        resultLabel = new QLabel(task2_hash);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(resultLabel);

        backButton = new QPushButton(task2_hash);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);


        retranslateUi(task2_hash);

        QMetaObject::connectSlotsByName(task2_hash);
    } // setupUi

    void retranslateUi(QWidget *task2_hash)
    {
        task2_hash->setWindowTitle(QCoreApplication::translate("task2_hash", "Form", nullptr));
        inputLineEdit->setPlaceholderText(QCoreApplication::translate("task2_hash", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202...", nullptr));
        calculateButton->setText(QCoreApplication::translate("task2_hash", "Calculate Hash", nullptr));
        resultLabel->setText(QCoreApplication::translate("task2_hash", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        backButton->setText(QCoreApplication::translate("task2_hash", "Back to Main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task2_hash: public Ui_task2_hash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK2_HASH_H
