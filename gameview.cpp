#include "gameview.h"

GameView::GameView()
{

}








///Getters and Setters:

EnemyViewInterface*GameView::getEnemyView() const
{
    return enemyView.get();
}

void GameView::setEnemyView(std::unique_ptr<EnemyViewInterface> newEnemyView)
{
    enemyView = std::move(newEnemyView);
}

TileView*GameView::getTileView() const
{
    return tileView.get();
}

void GameView::setTileView(std::unique_ptr<TileView> newTileView)
{
    tileView = std::move(newTileView);
}

HealthPackView*GameView::getHpView() const
{
    return hpView.get();
}

void GameView::setHpView(std::unique_ptr<HealthPackView> newHpView)
{
    hpView = std::move(newHpView);
}

ProtagonistView*GameView::getProtView() const
{
    return protView.get();
}

void GameView::setProtView(std::unique_ptr<ProtagonistView> newProtView)
{
    protView = std::move(newProtView);
}
