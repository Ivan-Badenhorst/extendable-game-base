#ifndef XENEMYMODEL_H
#define XENEMYMODEL_H
#include "enemymodelinterface.h"
#include "tilemodel.h"


struct XEnemyState {
    int x;
    int y;
    bool isDefeated;
    float strength;
};

class XEnemyModel : public EnemyModelInterface
{
public:
    XEnemyModel(int w_rows, int w_cols);
    void addEnemy(std::unique_ptr<Enemy> enemy) override;
    void addXEnemy(int amount);
    bool containsEnemy(int x, int y) override;
    bool isDefeated(int x, int y) override;
    void attackEnemy(int x, int y, int damage) override;
    bool follow(int protagonistX, int protagonistY);
    float getStrength(int x, int y);

    float isEnemyAround(int x, int y);

    void setTileModel(const std::shared_ptr<TileModel> &newTileModel);
    std::vector<XEnemyState> enemyVector; // Vector to store all the enemies //cng
    std::pair<int, int> getNewPos(int move_encoded, int oldX, int oldY); //cng

private:

    //std::pair<int, int> getNewPos(int move_encoded, int oldX, int oldY);
    /**
     * @brief A vector to store all the enemies.
     *
     * We use a vector because we will be iterating over the enemies very often.
     * Vectors provide efficient random access and are therefore well-suited for this use case.
     */
    //std::vector<XEnemyState> enemyVector; // Vector to store all the enemies
    std::shared_ptr<TileModel> tileModel;
};


#endif // XENEMYMODEL_H
