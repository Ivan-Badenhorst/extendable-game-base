#ifndef PROTAGONISTVIEWGRAPHICAL_H
#define PROTAGONISTVIEWGRAPHICAL_H
#include "mainwindow.h"
#include "protagonistview.h"
#include "protagonistmodel.h"

class ProtagonistViewGraphical : public ProtagonistView
{
public:
    ProtagonistViewGraphical(MainWindow& mw, std::shared_ptr<ProtagonistModel> pm);
    void update();
private:
    MainWindow& mainWindow;
    std::shared_ptr<ProtagonistModel> protModel;
    int tileDim {50};

};

#endif // PROTAGONISTVIEWGRAPHICAL_H
