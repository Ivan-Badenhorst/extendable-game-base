#include "gameview.h"

GameView::GameView(MainWindow& mw)
    :mainWindow(mw)
{


}

///Getters and Setters:

std::vector<std::shared_ptr<BaseEnemyView>>GameView::getEnemyView() const
{
    return enemyView;
}

void GameView::setEnemyView(std::vector<std::shared_ptr<BaseEnemyView> > newEnemyView)
{
    enemyView = newEnemyView;
}

std::shared_ptr<TileView>GameView::getTileView() const
{
    return tileView;
}

void GameView::setTileView(std::shared_ptr<TileView> newTileView)
{
    tileView = newTileView;
}

std::shared_ptr<HealthPackView>GameView::getHpView() const
{
    return hpView;
}

void GameView::setHpView(std::shared_ptr<HealthPackView> newHpView)
{
    hpView = newHpView;
}

std::shared_ptr<ProtagonistView>GameView::getProtView() const
{
    return protView;
}

void GameView::setProtView(std::shared_ptr<ProtagonistView> newProtView)
{
    protView = newProtView;
}
