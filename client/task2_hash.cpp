#include "task2_hash.h"
#include "ui_task2_hash.h"
#include <QDebug>

task2_hash::task2_hash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task2_hash),
    m_overflow(false)
{
    ui->setupUi(this);
}

task2_hash::~task2_hash()
{
    delete ui;
}

unsigned long long task2_hash::calculateHash(const QString &input)
{
    m_overflow = false;
    if (input.isEmpty()) return 0;

    unsigned long long sum = 0;
    for (const QChar &ch : input) {
        unsigned long long newSum = sum + ch.unicode();
        if (newSum < sum || sum > 1e9) {
            m_overflow = true;
            qDebug() << "Overflow triggered at sum:" << sum;
            break;
        }
        sum = newSum;
    }
    qDebug() << "Final sum:" << sum << "Overflow:" << m_overflow;
    return sum;
}

void task2_hash::on_calculateButton_clicked()
{
    QString input = ui->inputLineEdit->text();
    qDebug() << "Button clicked with input:" << input;
    if (input.isEmpty()) {
        ui->resultLabel->setText("Ошибка: пустой ввод!");
        return;
    }

    unsigned long long hash = calculateHash(input);
    if (m_overflow) {
        ui->resultLabel->setText("Ошибка: переполнение!");
    } else {
        ui->resultLabel->setText("Хеш: " + QString::number(hash));
    }
    qDebug() << "Hash calculated:" << hash;
}

