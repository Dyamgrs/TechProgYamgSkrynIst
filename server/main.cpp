#include <QCoreApplication>
#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer server(nullptr, 33333); // Запуск сервера на порту 33333
    return a.exec();
}
