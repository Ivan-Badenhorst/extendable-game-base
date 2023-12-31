#ifndef HEALTHPACKVIEWGRAPHICAL_H
#define HEALTHPACKVIEWGRAPHICAL_H

#include <memory>

#include "healthpackview.h"
#include "healthpackmodel.h"
#include "qgraphicsscene.h"



class HealthPackViewGraphical: public HealthPackView
{
public:
    HealthPackViewGraphical();
    void update() override;
    void update(int row, int col, bool used = true) override;
    void clearView() override;

    void setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel) override;

    void setScene(const std::shared_ptr<QGraphicsScene> &newScene);


private:


    float zValue {1};
    int tileDim {50};

    std::vector<std::shared_ptr<QGraphicsPixmapItem>> healthpackDisplays;
    void displayHp(std::shared_ptr<QGraphicsPixmapItem> icon, std::array<int, 3> hp);

    std::shared_ptr<QGraphicsScene> scene;

};

#endif // HEALTHPACKVIEWGRAPHICAL_H
