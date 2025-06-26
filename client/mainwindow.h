#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task1_caesar.h"
#include "task2_hash.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_task1_clicked();
    void on_pushButton_exit_clicked();
    void onTask1Clicked();

private:
    Ui::MainWindow *ui;
    Task1_Caesar *caesarWindow;
    task2_hash *hashWindow;
};
#endif // MAINWINDOW_H
