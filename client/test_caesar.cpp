#include "task1_caesar.h"
#include <QTest>
#include <QApplication> // Добавляем для работы с QWidget

class TestCaesarCipher : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(); // Инициализация перед тестами
    void cleanupTestCase(); // Очистка после тестов
    void testEncrypt_data();
    void testEncrypt();
    void testDecrypt();
};

void TestCaesarCipher::initTestCase()
{
    // Создаем QApplication, если его еще нет
    static int argc = 1;
    static char* argv[] = {(char*)"test"};
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
    QTest::addColumn<QString>("input");
    QTest::addColumn<int>("shift");
    QTest::addColumn<QString>("expected");

    QTest::newRow("Basic") << "ABC" << 3 << "DEF";
    QTest::newRow("Wrap around") << "XYZ" << 5 << "CDE";
}

void TestCaesarCipher::testEncrypt()
{
    QFETCH(QString, input);
    QFETCH(int, shift);
    QFETCH(QString, expected);

    Task1_Caesar cipher;
    cipher.show(); // Показываем виджет (необязательно)
    QString result = cipher.caesarCipher(input, shift, true);
    QCOMPARE(result, expected);
}

void TestCaesarCipher::testDecrypt()
{
    Task1_Caesar cipher;
    QCOMPARE(cipher.caesarCipher("DEF", 3, false), "ABC");
}

// Специальная точка входа для GUI-тестов
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TestCaesarCipher tc;
    return QTest::qExec(&tc, argc, argv);
}

#include "test_caesar.moc"
