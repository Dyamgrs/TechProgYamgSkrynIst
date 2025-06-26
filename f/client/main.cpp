// Подключаем заголовочный файл нашей формы авторизации
#include "authorization.h"

// Подключаем основной заголовочный файл Qt для приложений
#include <QApplication>

// Точка входа в приложение
int main(int argc, char *argv[])
{
    // Создаем объект приложения Qt
    // argc - количество аргументов командной строки
    // argv - массив строк аргументов командной строки
    QApplication a(argc, argv);

    // Создаем экземпляр нашей формы авторизации
    authorization w;

    // Показываем форму авторизации
    w.show();
    // Отправляем тестовую команду к серверу
    QString response = Singleton_client::getInstance()->doRequest("auth&user,password\r\n");
    qDebug() << "Server response:" << response;
    // Запускаем главный цикл обработки событий приложения
    // Этот вызов блокирует выполнение до закрытия приложения
    return a.exec();
}
