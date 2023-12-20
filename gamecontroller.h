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
   void switchView(bool change = true);



   void initializeView();
   bool getIsInputDisabled() const;

   void nextLevel(); //MAKE THIS PRIVATE MAYBE? MAKE LINKED LIST OF LEVELS!!
   void previousLevel();
   void addLevel(const std::shared_ptr<LevelFactory> &level);


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



    std::vector<std::shared_ptr<LevelFactory>> levels;
    int currentLevel {0};
    std::shared_ptr<TileController> tileControllerPrevious {nullptr};
    std::shared_ptr<HealthPackController> hpControllerPrevious {nullptr};
    std::shared_ptr<ProtagonistController> protControllerPrevious {nullptr};
    std::shared_ptr<EnemyController> enemyControllerPrevious {nullptr};
    bool previous {false};
    std::shared_ptr<TileController> tileControllerNext {nullptr};
    std::shared_ptr<HealthPackController> hpControllerNext{nullptr};
    std::shared_ptr<ProtagonistController> protControllerNext{nullptr};
    std::shared_ptr<EnemyController> enemyControllerNext {nullptr};
    bool next {false};


    void switchLevel(std::shared_ptr<LevelFactory> &levelFactory);
    void setupUi();
}
;



#endif // GAMECONTROLLER_H
