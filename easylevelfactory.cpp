#include "easylevelfactory.h"

EasyLevelFactory::EasyLevelFactory()
{

}

LevelFactory EasyLevelFactory::createWorld()
{
    World w;
    w.createWorld(":/worldmap.png", 0,0);
}

