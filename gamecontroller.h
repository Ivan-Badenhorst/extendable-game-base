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
   void input(const ArrowDirection& direction);

   static GameController* getInstance();
   void startGame(MainWindow & mw);



private:
   static GameController* gameControllerInstance;
   std::shared_ptr<TileController> tileController;
   std::shared_ptr<HealthPackController> hpController;
   std::shared_ptr<ProtagonistController> protController;
   std::shared_ptr<EnemyController> enemyController;
   int row {0};
   int col {0};
   int width;
   int height;

   GameController();
   ~GameController();

}
;



#endif // GAMECONTROLLER_H
