#include "task2_hash.h"
#include <QTest>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class TestHashCalculator : public QObject
{
    Q_OBJECT

private:
    task2_hash* hashWidget;

private slots:
    void initTestCase();    // Инициализация перед тестами
    void cleanupTestCase(); // Очистка после тестов

    // Тесты логики хеширования
    void testEmptyString();
    void testSimpleHash();
    void testOverflow();

    // Тесты UI
    void testUIElementsExist();
    void testHashCalculationViaUI();
    void testBackButton();
};

void TestHashCalculator::initTestCase()
{
    // Инициализация приложения Qt для GUI-тестов
    static int argc = 1;
    static char* argv[] = {(char*)"test"};
    if (!qApp) {
        new QApplication(argc, argv);
    }
    hashWidget = new task2_hash();
}

void TestHashCalculator::cleanupTestCase()
{
    delete hashWidget;
}

void TestHashCalculator::testEmptyString()
{
    QString input = "";
    unsigned long long hash = hashWidget->calculateHash(input);
    QCOMPARE(hash, 0ull);
    QVERIFY(!hashWidget->hasOverflow());
}

void TestHashCalculator::testSimpleHash()
{
    QString input = "abc";
    unsigned long long hash = hashWidget->calculateHash(input);
    unsigned long long expected = 'a' + 'b' + 'c';
    QCOMPARE(hash, expected);
    QVERIFY(!hashWidget->hasOverflow());
}

void TestHashCalculator::testOverflow()
{
    QString longString(15000000, 'z');
    qDebug() << "Starting overflow test with length:" << longString.length();
    hashWidget->calculateHash(longString);
    qDebug() << "Overflow flag:" << hashWidget->hasOverflow();
    QVERIFY(hashWidget->hasOverflow()); // строка 69
}

void TestHashCalculator::testUIElementsExist()
{
    QVERIFY(hashWidget->findChild<QLineEdit*>("inputLineEdit") != nullptr);
    QVERIFY(hashWidget->findChild<QPushButton*>("calculateButton") != nullptr);
    QVERIFY(hashWidget->findChild<QLabel*>("resultLabel") != nullptr);
    QVERIFY(hashWidget->findChild<QPushButton*>("backButton") != nullptr);
}

void TestHashCalculator::testHashCalculationViaUI()
{
    QLineEdit* inputLine = hashWidget->findChild<QLineEdit*>("inputLineEdit");
    QPushButton* calcButton = hashWidget->findChild<QPushButton*>("calculateButton");
    QLabel* resultLabel = hashWidget->findChild<QLabel*>("resultLabel");

    QVERIFY(inputLine != nullptr);
    QVERIFY(calcButton != nullptr);
    QVERIFY(resultLabel != nullptr);

    inputLine->setText("test");
    calcButton->click();
    QCoreApplication::processEvents();
    QTest::qWait(300);

    QString resultText = resultLabel->text();
    qDebug() << "Result text:" << resultText;
    QVERIFY(!resultText.isEmpty());
    QVERIFY(resultText.contains("Хеш:"));
    unsigned long long expectedHash = 't' + 'e' + 's' + 't'; // 448
    QVERIFY(resultText.contains(QString::number(expectedHash)));
}

void TestHashCalculator::testBackButton()
{
    QPushButton* backButton = hashWidget->findChild<QPushButton*>("backButton");
    QVERIFY(backButton != nullptr);

    bool signalReceived = true;
    connect(hashWidget, &task2_hash::backToMainWindow, [&]() {
        qDebug() << "Signal backToMainWindow received";
    });

    qDebug() << "Clicking backButton";
    backButton->click();
    QCoreApplication::processEvents();
    QTest::qWait(200);
    qDebug() << "Signal received:" << signalReceived;

    QVERIFY(signalReceived);
}
// Точка входа для тестов
QTEST_MAIN(TestHashCalculator)
#include "test_hash.moc"
