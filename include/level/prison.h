#ifndef PRISON_H
#define PRISON_H
#include "world.h"
#include <QObject>
#include <QVariant>


class Prison : public QObject
{
    Q_OBJECT
public:
    Prison(std::vector<std::unique_ptr<Tile>> w_tiles, 
        std::vector<std::unique_ptr<Enemy>> w_enemies, 
        std::vector<std::unique_ptr<Tile>> w_healthPacks, 
        int w_rows, int w_cols);
    std::vector<std::unique_ptr<Tile>> getTiles();
    std::vector<std::unique_ptr<Enemy>> getEnemies();
    std::vector<std::unique_ptr<Tile>> getHealthPacks();
    std::unique_ptr<Protagonist> getProtagonist() const;
    void addEnemy(std::unique_ptr<Enemy> enemy);
    int getRows() const {return rows;};
    int getCols() const {return cols;};

private: 
    int rows, cols;
    std::unique_ptr<Protagonist> protagonist;
    std::vector<std::unique_ptr<Tile>> tiles;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Tile>> healthPacks;
};




#endif // PRISON_H
