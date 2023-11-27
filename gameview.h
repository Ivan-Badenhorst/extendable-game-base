#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <memory>

#include "TileH/tileview.h"
#include "HealthPackH/healthpackview.h"
#include "enemyviewinterface.h"
#include "protagonistview.h"
#include "mainwindow.h"

class GameView
{
public:
    GameView(MainWindow& mw);
    virtual void initializeMainWindow() = 0;//function used to create the UI needed for this view
    virtual void clearMainWindow() = 0;

protected:
    MainWindow& mainWindow;
///View attributes, getters and setters:

public:
    std::shared_ptr<EnemyViewInterface>getEnemyView() const;
    void setEnemyView(std::shared_ptr<EnemyViewInterface> newEnemyView);

    std::shared_ptr<TileView>getTileView() const;
    void setTileView(std::shared_ptr<TileView> newTileView);

    std::shared_ptr<HealthPackView>getHpView() const;
    void setHpView(std::shared_ptr<HealthPackView> newHpView);

    std::shared_ptr<ProtagonistView>getProtView() const;
    void setProtView(std::shared_ptr<ProtagonistView> newProtView);

private:
    std::shared_ptr<EnemyViewInterface> enemyView;
    std::shared_ptr<TileView> tileView;
    std::shared_ptr<HealthPackView> hpView;
    std::shared_ptr<ProtagonistView> protView;
};

#endif // GAMEVIEW_H
