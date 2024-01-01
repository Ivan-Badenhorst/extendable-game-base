#include "prison.h"

Prison::Prison(std::vector<std::unique_ptr<Tile>> w_tiles, 
        std::vector<std::unique_ptr<Enemy>> w_enemies, 
        std::vector<std::unique_ptr<Tile>> w_healthPacks,
        int w_rows, int w_cols) {
    rows = w_rows;
    cols = w_cols;
    tiles = std::move(w_tiles);
    enemies = std::move(w_enemies);
    healthPacks = std::move(w_healthPacks);

    // Iterate through the enemies to give them a QProperty "enemyType"
    for (auto& enemy : enemies) {
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            pEnemy->setProperty("enemyType", QVariant("PEnemy"));
        } else {
            enemy->setProperty("enemyType", QVariant("Enemy"));
        }
    }
}



std::unique_ptr<Protagonist> Prison::getProtagonist() const
{
  return std::make_unique<Protagonist>();
}



std::vector<std::unique_ptr<Tile>> Prison::getTiles()
{
  return std::move(tiles);
}



std::vector<std::unique_ptr<Enemy>> Prison::getEnemies()
{
  return std::move(enemies);
}



std::vector<std::unique_ptr<Tile>> Prison::getHealthPacks()
{
  return std::move(healthPacks);
}



void Prison::addEnemy(std::unique_ptr<Enemy> enemy)
{
  enemies.push_back(std::move(enemy));
}

