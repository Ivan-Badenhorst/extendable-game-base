#include <QCoreApplication>
#include <QtTest>
#include "xenemymodel.h"
#include "node.h"
#include "tilemodel.h"
#include "world.h"
#include <QDebug>

// add necessary includes here

class testtilemodel : public QObject
{
    Q_OBJECT

public:
    testtilemodel();
    ~testtilemodel();

private slots:
    void test_getPosition();
    void test_findPath_getNewPos();


};

testtilemodel::testtilemodel() {}
testtilemodel::~testtilemodel() {}



void testtilemodel::test_getPosition() {

    XEnemyModel xen(30,30);

    std::pair<int, int> expectedPos;
    std::pair<int, int> actualPos;

    // Test case 1: Move up
    expectedPos = std::make_pair(3, 2); // Adjust expected position based on the move
    actualPos = xen.getNewPos(0, 3, 3); // Assuming starting position is (3, 3) and moving up
    QCOMPARE(actualPos, expectedPos);

    // Test case 2: Move up-right
    expectedPos = std::make_pair(2, 2);
    actualPos = xen.getNewPos(1, 3, 3);
    QCOMPARE(actualPos, expectedPos);

    // Test case 3: Move right
    expectedPos = std::make_pair(2, 3);
    actualPos = xen.getNewPos(2, 3, 3);
    QCOMPARE(actualPos, expectedPos);

    // Test case 4: Move down-right
    expectedPos = std::make_pair(2, 4);
    actualPos = xen.getNewPos(3, 3, 3);
    QCOMPARE(actualPos, expectedPos);

    // Test case 5: Move down
    expectedPos = std::make_pair(3, 4);
    actualPos = xen.getNewPos(4, 3, 3);
    QCOMPARE(actualPos, expectedPos);

    // Test case 6: Move down-left
    expectedPos = std::make_pair(4, 4);
    actualPos = xen.getNewPos(5, 3, 3);
    QCOMPARE(actualPos, expectedPos);

    // Test case 7: Move left
    expectedPos = std::make_pair(4, 3);
    actualPos = xen.getNewPos(6, 3, 3);
    QCOMPARE(actualPos, expectedPos);

    // Test case 8: Move up-left
    expectedPos = std::make_pair(4, 2);
    actualPos = xen.getNewPos(7, 3, 3);
    QCOMPARE(actualPos, expectedPos);
}

void testtilemodel::test_findPath_getNewPos() {
    World w;
    w.createWorld(":/map/worldmap.png", 10,10);
    TileModel tileModel(w.getRows(), w.getCols());
    tileModel.populateTileMap(w.getRows(),w.getCols(),w.getTiles());
    XEnemyModel xen(30, 30);

    int startX = 0;
    int startY = 0;
    int endX = 29;
    int endY = 29;
    qDebug() << "Crashed before findPath";
    std::vector<int> moveList = tileModel.findPath(startX, startY, endX, endY);
    qDebug() << "Crashed after findPath";

    std::pair<int, int> currentPos = std::make_pair(startX, startY);
    for (int move : moveList) {
        currentPos = xen.getNewPos(move, currentPos.first, currentPos.second);
    }
    qDebug() << "Crashed after new pos";
    std::pair<int, int> expectedPos = std::make_pair(endX, endY);
    QCOMPARE(currentPos, expectedPos);
}






QTEST_MAIN(testtilemodel)

#include "tst_testtilemodel.moc"
