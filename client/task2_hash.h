#ifndef TASK2_HASH_H
#define TASK2_HASH_H

#include <QWidget>
#include <QString>

namespace Ui {
class task2_hash;
}

class task2_hash : public QWidget
{
    Q_OBJECT

public:
    explicit task2_hash(QWidget *parent = nullptr);
    ~task2_hash();

    unsigned long long calculateHash(const QString &input);
    bool hasOverflow() const { return m_overflow; }

signals:
    void backToMainWindow();

private slots:
    void on_calculateButton_clicked();

private:
    Ui::task2_hash *ui;
    bool m_overflow = false;
};

#endif // TASK2_HASH_H
