#ifndef EASYLEVELFACTORY_H
#define EASYLEVELFACTORY_H

#include "levelfactory.h"
#include "tilemodel.h"
#include "tileview.h"
#include "tilecontroller.h"
#include "easylevel.h"

class EasyLevelFactory/*: public LevelFactory*/
{
public:
    EasyLevelFactory();
    EasyLevel createWorld(MainWindow& mw);

    //remember to cache here when moving to next level


};

#endif // EASYLEVELFACTORY_H
