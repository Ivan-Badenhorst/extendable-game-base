#ifndef TILEVIEW_H
#define TILEVIEW_H

#include "mainwindow.h"
#include "tilemodel.h"

#include <memory>

class TileView
{
public:
    TileView(MainWindow& mw, std::shared_ptr<TileModel> tm);
    void update();

private:
    MainWindow& mainWindow;
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILEVIEW_H
