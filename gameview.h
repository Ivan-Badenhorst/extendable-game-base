#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <memory>

#include "TileH/tileview.h"
#include "HealthPackH/healthpackview.h"
#include "enemyviewinterface.h"
#include "protagonistview.h"

class GameView
{
public:
    GameView();

    EnemyViewInterface*getEnemyView() const;
    void setEnemyView(std::unique_ptr<EnemyViewInterface> newEnemyView);

    TileView*getTileView() const;
    void setTileView(std::unique_ptr<TileView> newTileView);

    HealthPackView*getHpView() const;
    void setHpView(std::unique_ptr<HealthPackView> newHpView);

    ProtagonistView*getProtView() const;
    void setProtView(std::unique_ptr<ProtagonistView> newProtView);

private:
    std::unique_ptr<EnemyViewInterface> enemyView;
    std::unique_ptr<TileView> tileView;
    std::unique_ptr<HealthPackView> hpView;
    std::unique_ptr<ProtagonistView> protView;
};

#endif // GAMEVIEW_H
