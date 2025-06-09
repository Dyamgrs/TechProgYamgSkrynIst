#include "task1_caesar.h"
#include <QtTest>
#include <QApplication> // Добавляем для работы с QWidget

class TestCaesarCipher : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(); // Инициализация перед тестами
    void cleanupTestCase(); // Очистка после тестов
    void testEncrypt_data(); //Метод для подготовки данных для теста шифрования
    void testEncrypt(); //Метод, который выполняет тест шифрования
    void testDecrypt(); //Метод, который выполняет тест расшифровки
};

void TestCaesarCipher::initTestCase()
{
    // Создаем QApplication, если его еще нет
    static int argc = 1; //Статическая переменная для хранения количества аргументов командной строки
    static char* argv[] = {(char*)"test"}; //Статический массив для хранения аргументов командной строки
    if (!qApp) {
        new QApplication(argc, argv);
    }
}

void TestCaesarCipher::cleanupTestCase()
{
    // При необходимости можно добавить очистку
}

void TestCaesarCipher::testEncrypt_data()
{
    QTest::addColumn<QString>("input"); //Добавляет столбец данных входных значений для теста
    QTest::addColumn<int>("shift"); //Добавляет столбец данных для значения сдвига
    QTest::addColumn<QString>("expected"); //Добавляет столбец данных для ожидаемого результата

    QTest::newRow("Basic") << "ABC" << 3 << "DEF"; //Добавляет новую строку данных для теста. В данном случае шифрует "ABC" с сдвигом 3, ожидая "DEF"
    QTest::newRow("Wrap around") << "XYZ" << 5 << "CDE"; //Добавляет еще одну строку теста, проверяя, как работает шифр с оборачиванием алфавита.
}

void TestCaesarCipher::testEncrypt()
{
    QFETCH(QString, input); //Извлекает входное значение для шифрования
    QFETCH(int, shift); //Извлекает значение сдвига
    QFETCH(QString, expected); //Извлекает ожидаемый результат

    Task1_Caesar cipher; //Создает объект шифра Цезаря
    cipher.show(); // Показываем виджет (необязательно)
    QString result = cipher.caesarCipher(input, shift, true); //Вызывает метод шифрования и получает результат
    QCOMPARE(result, expected); //Сравнивает полученный результат с ожидаемым
}

void TestCaesarCipher::testDecrypt()
{
    Task1_Caesar cipher; //Создает объект шифра Цезаря
    QCOMPARE(cipher.caesarCipher("DEF", 3, false), "ABC"); //Проверяет, что расшифровка "DEF" приводит к "ABC"
}

// Специальная точка входа для GUI-тестов
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TestCaesarCipher tc; //Создает объект тестового класса
    return QTest::qExec(&tc, argc, argv); //Запускает тесты, передавая объект тестового класса и аргументы командной строки
}

#include "test_caesar.moc" //Подключает файл, сгенерированный moc (Meta-Object Compiler), для обработки сигналов и слотов
