#include <QtTest>
#include <QString>
#include "../lab01/receiver.cpp"


class Task1Test : public QObject
{
    Q_OBJECT

public:
    Task1Test() = default;
    ~Task1Test() = default;
private:
    Receiver r;

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

void Task1Test::test_case1() {
    QCOMPARE(r.task1(QString("Hello"), QString("AppleH")), QString("yes yes yes yes no "));
}

void Task1Test::test_case2() {
    QCOMPARE(r.task2(QString("Начало бурь будет мур но тепер надо лечить")), QString("32"));
    QCOMPARE(r.task2(QString("Токен нир будет расти и нужно ее покупать")), QString("21"));
}

void Task1Test::test_case3() {
    QCOMPARE(r.task3(QString("Hello my dear friend"), QString("Dear mother hello")), QString("yes no yes no "));
}

QTEST_APPLESS_MAIN(Task1Test)

#include "tst_task1test.moc"
