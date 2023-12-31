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

    /**
     * @brief Test case for adding enemies to the EnemyModel.
     * 
     * This test case checks that enemies can be successfully added to the EnemyModel,
     * and that the state of the model is updated correctly when enemies are added.
     */
    void test_addingEnemies();

    /**
     * @brief Test case for getting the strength of enemies in the EnemyModel.
     * 
     * This test case checks that the getStrength method of the EnemyModel returns the correct strength for each enemy.
     */
    void test_getStrength();

    /**
     * @brief Test case for defeating enemies in the EnemyModel.
     * 
     * This test case checks that enemies can be successfully defeated in the EnemyModel,
     * and that the state of the model is updated correctly when enemies are defeated.
     */
    void test_defeatEnemies();

    /**
     * @brief Test case for getting the states of enemies in the EnemyModel.
     * 
     * This test case checks that the getEnemyStates method of the EnemyModel returns the correct state for each enemy,
     * and that the state of the model is updated correctly when the state of an enemy changes.
     */
    void test_getEnemyStates();


    /**
     * @brief Test case for checking if there is an enemy around a position in the EnemyModel.
     * 
     * This test case checks that the isEnemyAround method of the EnemyModel returns the correct damage for each position,
     * and that the damage is updated correctly when the state of an enemy changes.
     */
    void test_isEnemyAround();

};

testenemymodel::testenemymodel() {}

testenemymodel::~testenemymodel() {}



void testenemymodel::test_addingEnemies() {
    // Create an instance of EnemyModel with a 10x10 map
    EnemyModel enemyModel(10, 10);

    // Add enemies at specific positions
    std::vector<std::pair<int, int>> enemyPositions = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (const auto& pos : enemyPositions) {
        enemyModel.addEnemy(std::make_unique<Enemy>(pos.first, pos.second, 1.0f));
    }

    // Check if the enemies are at the correct positions
    for (const auto& pos : enemyPositions) {
        QVERIFY(enemyModel.containsEnemy(pos.first, pos.second));
    }

    // Check all positions where there shouldn't be an enemy
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // We check if the position is not in the enemyPositions vector
            if (std::find(enemyPositions.begin(), enemyPositions.end(), std::make_pair(i, j)) == enemyPositions.end()) {
                QVERIFY(!enemyModel.containsEnemy(i, j));
            }
        }
    }
}



void testenemymodel::test_getStrength()
{
    EnemyModel enemyModel(10, 10);

    // Create some enemies with different strengths and add them to the model
    auto enemy1 = std::make_unique<Enemy>(5, 5, 50.0f);
    auto enemy2 = std::make_unique<Enemy>(3, 3, 75.0f);
    auto enemy3 = std::make_unique<Enemy>(7, 7, 25.0f);

    enemyModel.addEnemy(std::move(enemy1));
    enemyModel.addEnemy(std::move(enemy2));
    enemyModel.addEnemy(std::move(enemy3));

    // Check that getStrength returns the correct strength for each enemy
    QCOMPARE(enemyModel.getStrength(5, 5), 50.0f);
    QCOMPARE(enemyModel.getStrength(3, 3), 75.0f);
    QCOMPARE(enemyModel.getStrength(7, 7), 25.0f);

    // Check that getStrength returns 0 for positions where there is no enemy
    QCOMPARE(enemyModel.getStrength(0, 0), 0.0f);
    QCOMPARE(enemyModel.getStrength(1, 1), 0.0f);
    QCOMPARE(enemyModel.getStrength(2, 2), 0.0f);
}



void testenemymodel::test_defeatEnemies()
{
    EnemyModel enemyModel(10, 10);

    // Create some enemies with different strengths and add them to the model
    auto enemy1 = std::make_unique<Enemy>(5, 5, 100.0f);
    auto enemy2 = std::make_unique<Enemy>(3, 3, 100.0f);
    auto enemy3 = std::make_unique<Enemy>(7, 7, 100.0f);

    enemyModel.addEnemy(std::move(enemy1));
    enemyModel.addEnemy(std::move(enemy2));
    enemyModel.addEnemy(std::move(enemy3));

    // Check that isDefeated returns false for each enemy
    QVERIFY(!enemyModel.isDefeated(5, 5));
    QVERIFY(!enemyModel.isDefeated(3, 3));
    QVERIFY(!enemyModel.isDefeated(7, 7));

    // Attack some of the enemies
    enemyModel.attackEnemy(5, 5, 100);
    enemyModel.attackEnemy(3, 3, 100);

    // Check that isDefeated returns true for the defeated enemies and false for the others
    QVERIFY(enemyModel.isDefeated(5, 5));
    QVERIFY(enemyModel.isDefeated(3, 3));
    QVERIFY(!enemyModel.isDefeated(7, 7));

    // Check that isDefeated returns false for positions where there is no enemy
    QVERIFY(!enemyModel.isDefeated(0, 0));
    QVERIFY(!enemyModel.isDefeated(1, 1));
    QVERIFY(!enemyModel.isDefeated(2, 2));
}



void testenemymodel::test_getEnemyStates()
{
    EnemyModel enemyModel(10, 10);

    // Create some enemies with different strengths and add them to the model
    auto enemy1 = std::make_unique<Enemy>(5, 5, 100.0f);
    auto enemy2 = std::make_unique<Enemy>(3, 3, 100.0f);
    auto enemy3 = std::make_unique<Enemy>(7, 7, 50.0f);
    auto enemy4 = std::make_unique<Enemy>(0, 0, 100.0f); // Top-left corner
    auto enemy5 = std::make_unique<Enemy>(9, 0, 100.0f); // Top-right corner
    auto enemy6 = std::make_unique<Enemy>(0, 9, 100.0f); // Bottom-left corner
    auto enemy7 = std::make_unique<Enemy>(9, 9, 100.0f); // Bottom-right corner

    enemyModel.addEnemy(std::move(enemy1));
    enemyModel.addEnemy(std::move(enemy2));
    enemyModel.addEnemy(std::move(enemy3));
    enemyModel.addEnemy(std::move(enemy4));
    enemyModel.addEnemy(std::move(enemy5));
    enemyModel.addEnemy(std::move(enemy6));
    enemyModel.addEnemy(std::move(enemy7));

    // Defeat four of the enemies
    enemyModel.attackEnemy(5, 5, 100);
    enemyModel.attackEnemy(3, 3, 100);
    enemyModel.attackEnemy(7, 7, 100);
    enemyModel.attackEnemy(0, 0, 100); // Defeat the enemy at the top-left corner

    // Create EnemyState structs for each enemy
    std::vector<EnemyState> expectedStates = {
        {5, 5, true, 100.0f},
        {3, 3, true, 100.0f},
        {7, 7, true, 50.0f},
        {0, 0, true, 100.0f},
        {9, 0, false, 100.0f},
        {0, 9, false, 100.0f},
        {9, 9, false, 100.0f}
    };

    // Check that getOneEnemyState returns the correct state for each enemy
    for (const auto& expectedState : expectedStates) {
        auto state = enemyModel.getOneEnemyState(expectedState.x, expectedState.y);
        QVERIFY(state.has_value());
        QCOMPARE(state->x, expectedState.x);
        QCOMPARE(state->y, expectedState.y);
        QCOMPARE(state->isDefeated, expectedState.isDefeated);
        QCOMPARE(state->strength, expectedState.strength);
    }

    // Check that getAllEnemyStates returns a vector containing the correct states for all enemies
    auto allStates = enemyModel.getAllEnemyStates();
    QCOMPARE(allStates.size(), 7);
    for (const auto& state : allStates) {
        auto it = std::find_if(expectedStates.begin(), expectedStates.end(), [&state](const EnemyState& expectedState) {
            return expectedState.x == state.x && expectedState.y == state.y;
        });
        QVERIFY(it != expectedStates.end());
        QCOMPARE(state.isDefeated, it->isDefeated);
        QCOMPARE(state.strength, it->strength);
    }
}



void testenemymodel::test_isEnemyAround()
{
    EnemyModel enemyModel(10, 10);

    // Create a 10x10 matrix to store the expected damage at each position
    std::map<std::pair<int, int>, float> expectedDamage;

    // Create some enemies with different strengths and add them to the model
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies.push_back(std::make_unique<Enemy>(5, 5, 100.0f));
    enemies.push_back(std::make_unique<Enemy>(3, 3, 75.0f));
    enemies.push_back(std::make_unique<Enemy>(7, 7, 50.0f));
    enemies.push_back(std::make_unique<Enemy>(0, 0, 25.0f)); // Top-left corner
    enemies.push_back(std::make_unique<Enemy>(9, 0, 30.0f)); // Top-right corner
    enemies.push_back(std::make_unique<Enemy>(0, 9, 35.0f)); // Bottom-left corner
    enemies.push_back(std::make_unique<Enemy>(9, 9, 40.0f)); // Bottom-right corner

    for (auto& enemy : enemies)
    {
        int xPos = enemy->getXPos();
        int yPos = enemy->getYPos();
        float value = enemy->getValue();

        enemyModel.addEnemy(std::move(enemy));

        // Add the enemy's strength to the expected damage at the positions around the enemy
        std::vector<std::pair<int, int>> positions = {
            {xPos - 1, yPos},
            {xPos + 1, yPos},
            {xPos, yPos - 1},
            {xPos, yPos + 1}
        };

        for (auto& position : positions)
        {
            if (position.first >= 0 && position.first < 10 && position.second >= 0 && position.second < 10)
            {
                expectedDamage[position] += value;
            }
        }
    }

    // Check isEnemyAround for each position on the map
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            // Check that isEnemyAround returns the expected damage
            std::pair pos = {i, j};
            QCOMPARE(enemyModel.isEnemyAround(i, j), expectedDamage[pos]);
        }
    }
}



QTEST_MAIN(testenemymodel)

#include "tst_testenemymodel.moc"
