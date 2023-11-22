#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "mainwindow.h"
#include "easylevelfactory.h"
#include "constants.h"
#include "easylevel.h"

#include <memory>

class GameController
{
public:
   GameController(GameController& copyController )= delete;
   void operator=(const GameController&) = delete;
   void input(const ArrowDirection& direction) const;

   static GameController* getInstance();
   void startGame(MainWindow & mw);



private:
   static GameController* gameControllerInstance;
   std::shared_ptr<TileController> tileController;
   std::shared_ptr<HealthPackController> hpController;

   GameController();
   ~GameController();

}
;



#endif // GAMECONTROLLER_H
