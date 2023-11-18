#ifndef PROTAGONISTVIEWGRAPHICAL_H
#define PROTAGONISTVIEWGRAPHICAL_H

#include "protagonistview.h"
#include "protagonistmodel.h"
#include "mainwindow.h"

class ProtagonistViewGraphical : public ProtagonistView
{
public:
    ProtagonistViewGraphical(MainWindow& mw, std::shared_ptr<ProtagonistModel> pm);
    void update() override;

private:
    MainWindow& mainWindow;
    std::shared_ptr<ProtagonistModel> protModel;
    int tileDim {50};
};

#endif // PROTAGONISTVIEWGRAPHICAL_H
