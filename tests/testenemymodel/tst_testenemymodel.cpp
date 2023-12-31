#include <QCoreApplication>
#include <QtTest>
#include "enemymodel.h"

// add necessary includes here

class testenemymodel : public QObject
{
    Q_OBJECT

public:
    testenemymodel();
    ~testenemymodel();

private slots:
    void test_case1();
};

testenemymodel::testenemymodel() {}

testenemymodel::~testenemymodel() {}

void testenemymodel::test_case1() {

    QCOMPARE(1,1);
}

QTEST_MAIN(testenemymodel)

#include "tst_testenemymodel.moc"
