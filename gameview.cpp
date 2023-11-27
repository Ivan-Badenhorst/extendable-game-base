#include "gameview.h"

GameView::GameView(MainWindow& mw)
    :mainWindow(mw)
{


}





///Getters and Setters:

std::vector<std::shared_ptr<EnemyViewInterface>>GameView::getEnemyView() const
{
    return enemyView;
}

void GameView::setEnemyView(std::vector<std::shared_ptr<EnemyViewInterface> > newEnemyView)
{
    enemyView = std::move(newEnemyView);
}

std::shared_ptr<TileView>GameView::getTileView() const
{
    return tileView;
}

void GameView::setTileView(std::shared_ptr<TileView> newTileView)
{
    tileView = std::move(newTileView);
}

std::shared_ptr<HealthPackView>GameView::getHpView() const
{
    return hpView;
}

void GameView::setHpView(std::shared_ptr<HealthPackView> newHpView)
{
    hpView = std::move(newHpView);
}

std::shared_ptr<ProtagonistView>GameView::getProtView() const
{
    return protView;
}

void GameView::setProtView(std::shared_ptr<ProtagonistView> newProtView)
{
    protView = std::move(newProtView);
}
