#ifndef TILEVIEW_H
#define TILEVIEW_H

#include "mainwindow.h"
#include "tilemodel.h"

class TileView
{
public:
    TileView(MainWindow& mw, TileModel& tm);
    void update();

private:
    MainWindow& mainWindow;
    TileModel& tileModel;
};

#endif // TILEVIEW_H
