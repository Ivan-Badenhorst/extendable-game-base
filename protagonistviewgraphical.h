#ifndef PROTAGONISTVIEWGRAPHICAL_H
#define PROTAGONISTVIEWGRAPHICAL_H

#include "graphicalgameview.h"
#include "protagonistview.h"
#include "protagonistmodel.h"


class ProtagonistViewGraphical : public ProtagonistView
{
public:
    ProtagonistViewGraphical();
    void update() override;
    void update(int row, int col) override;
    void updateHealth() override;
    void updateEnergy() override;
    void clearView() override;
    void updateFrame(int currentFrame) override;

    void setHealthBar(const std::shared_ptr<HealthProgressBar> newHealthBar);
    void setEnergyBar(const std::shared_ptr<EnergyProgressBar> newEnergyBar);

    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);

    void setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel) override;

private:
    std::shared_ptr<QGraphicsPixmapItem> protagonistDisplay;
    int tileDim {50};

    std::shared_ptr<HealthProgressBar> healthBar;
    std::shared_ptr<EnergyProgressBar> energyBar;
    std::shared_ptr<QGraphicsScene> scene;
    QPixmap prot;
};

#endif // PROTAGONISTVIEWGRAPHICAL_H
