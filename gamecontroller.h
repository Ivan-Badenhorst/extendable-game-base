#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "mainwindow.h"
#include "easylevelfactory.h"
#include "constants.h"
#include "easylevel.h"
#include "gameview.h"

#include <deque>
#include <memory>

class GameController
{
public:
   GameController(GameController& copyController )= delete;
   void operator=(const GameController&) = delete;
   void input(const ArrowDirection& direction);

   static GameController* getInstance();
   void startGame(std::unique_ptr<GameView> gv);
   void addNewView(std::unique_ptr<GameView> gv);
   void switchView();



   void initializeView();

   bool getIsInputDisabled() const;

   private:
   static GameController* gameControllerInstance;
   std::unique_ptr<GameView> gameView;
   std::deque<std::unique_ptr<GameView>> allGameViews;


   std::shared_ptr<TileController> tileController;
   std::shared_ptr<HealthPackController> hpController;
   std::shared_ptr<ProtagonistController> protController;
   std::shared_ptr<EnemyController> enemyController;
   int row {0};
   int col {0};
   int width;
   int height;
   bool isGameOver {false};
   bool isInputDisabled{false};


   void stopGame();
   GameController();
   ~GameController();
   void getNewView();
}
;



#endif // GAMECONTROLLER_H
