#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "mainwindow.h"
#include "easylevelfactory.h"

#include <memory>

class GameController
{
public:
   GameController(GameController& copyController )= delete;
   void operator=(const GameController&) = delete;

   static GameController* getInstance();
   static void startGame(MainWindow & mw);


private:
   static GameController* gameControllerInstance;

   GameController();
   ~GameController();

}
;



#endif // GAMECONTROLLER_H
