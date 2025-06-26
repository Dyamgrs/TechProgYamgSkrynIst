#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , caesarWindow(new Task1_Caesar())
    , hashWindow(new task2_hash())
{
    ui->setupUi(this);

    connect(ui->pushButton_task1, &QPushButton::clicked, this, &MainWindow::onTask1Clicked);
    connect(ui->pushButton_exit, &QPushButton::clicked, this, &MainWindow::on_pushButton_exit_clicked);
    connect(ui->pushButton_result, &QPushButton::clicked, this, [this]() {
        QMessageBox::information(this, "Stats", "Статистика будет здесь");
    });
    connect(caesarWindow, &Task1_Caesar::backToMainWindow, this, [this]() {
        caesarWindow->hide();
        this->show();
    });

    connect(ui->pushButton_task2, &QPushButton::clicked, this, [this]() {
        this->hide();
        hashWindow->show();
    });

    connect(hashWindow, &task2_hash::backToMainWindow, this, [this]() {
        hashWindow->hide();
        this->show();
    });
}

void MainWindow::onTask1Clicked()
{
    if (!caesarWindow) {
        caesarWindow = new Task1_Caesar();
    }
    this->hide();
    caesarWindow->show();
    caesarWindow->activateWindow();  // Делаем окно активным
}

MainWindow::~MainWindow()
{
    delete ui;
    delete caesarWindow;
    delete hashWindow;
}

void MainWindow::on_pushButton_task1_clicked()
{
    this->hide();
    caesarWindow->show();
    caesarWindow->activateWindow();
}

void MainWindow::on_pushButton_exit_clicked()
{
    QApplication::quit();
}
