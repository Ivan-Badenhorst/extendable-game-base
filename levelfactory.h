#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H


#include "mainwindow.h"
#include "level.h"

class LevelFactory
{
public:
    LevelFactory();
    virtual std::shared_ptr<Level> createWorld() {};
};

#endif // LEVELFACTORY_H
