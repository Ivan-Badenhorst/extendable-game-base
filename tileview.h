#ifndef TILEVIEW_H
#define TILEVIEW_H

#include "mainwindow.h"
#include "tilemodel.h"

class TileView
{
public:
    TileView(std::shared_ptr<MainWindow> mw, TileModel& tm);
    void update();

private:
    std::shared_ptr<MainWindow> mainWindow;
    TileModel& tileModel;
};

#endif // TILEVIEW_H
