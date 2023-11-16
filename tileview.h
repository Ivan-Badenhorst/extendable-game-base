#ifndef TILEVIEW_H
#define TILEVIEW_H

#include "mainwindow.h"
#include "tilemodel.h"

#include <memory>

class TileView //refactor this -> we need a subclass for graphical view
{
public:
    TileView(MainWindow& mw, std::shared_ptr<TileModel> tm);
    void update(); //change this such that it only renders as the player walks!!!


private:
    MainWindow& mainWindow;
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILEVIEW_H
