#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H


#include "mainwindow.h"
#include "level.h"

class LevelFactory
{
public:
    LevelFactory();
    virtual Level* createWorld(MainWindow& mw) {};
};

#endif // LEVELFACTORY_H
