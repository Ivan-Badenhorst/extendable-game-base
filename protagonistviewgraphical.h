#ifndef PROTAGONISTVIEWGRAPHICAL_H
#define PROTAGONISTVIEWGRAPHICAL_H

#include "graphicalgameview.h"
#include "protagonistview.h"
#include "protagonistmodel.h"
#include "mainwindow.h"

class ProtagonistViewGraphical : public ProtagonistView
{
public:
    ProtagonistViewGraphical(MainWindow& mw, std::shared_ptr<ProtagonistModel> pm);
    void update() override;
    void update(int row, int col) override;
    void updateHealth() override;

    void setHealthBar(const std::shared_ptr<HealthProgressBar> newHealthBar);

private:
    MainWindow& mainWindow;
    std::shared_ptr<ProtagonistModel> protModel;
    std::shared_ptr<QGraphicsPixmapItem> protagonistDisplay;
    int tileDim {50};
    std::shared_ptr<HealthProgressBar> healthBar;
};

#endif // PROTAGONISTVIEWGRAPHICAL_H
