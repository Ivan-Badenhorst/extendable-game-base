#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "graphicalgameview.h"
#include "levelfactory.h"
#include "constants.h"
#include "gameview.h"
#include "HealthPackH/healthpackcontroller.h"
#include "TileH/tilecontroller.h"
#include "enemycontroller.h"
#include "protagonistcontroller.h"

#include <deque>
#include <memory>

/**
 * @brief Represents the collection of controllers managing a specific level.
 *        This struct provides  access to controllers responsible for handling
 *        level caching and management within the game.
 */
struct LevelControllers {
    std::shared_ptr<TileController> tileController = nullptr;
    std::shared_ptr<HealthPackController> hpController = nullptr;
    std::shared_ptr<ProtagonistController> protController = nullptr;
    std::shared_ptr<EnemyController> enemyController = nullptr;
    bool initialized = false;
};


class GameController
{
public:
    //functions for singleton:
    GameController(GameController& copyController )= delete;
    void operator=(const GameController&) = delete;
    static GameController* getInstance();

   /**
    * @brief Takes input to control the protagonist's movement in the game.
    *
    * @param direction An enum representing the direction of movement
    */
   void input(const ArrowDirection& direction);

    /**
     * @brief Creates easy level + setting up the initial view with the first level.
     * @param GameView object that represents the view to be set up for the game.
     */
   void startGame(std::unique_ptr<GraphicalGameView> gv);

   /**
    * @brief Incorporates a new type of view into the game.
    * @param gv GameView representing the new view to be incorporated into the game.
    * @remarks Ensure that the provided GameView pointer is valid and properly
    *          instantiated: the view should already contain all all views as indicated
    *          in the GameView interface
    */
   void addNewView(std::unique_ptr<GameView> gv);

   /**
    * @brief Switches to the next view within "allGameViews" deque.
    * @param change A boolean indicating whether to switch to the next view.
    *               If 'true' (default), the method progresses to the next view.
    *               If 'false,' the current view remains active, reinstating the
    *               existing display state.
    */
   void switchView(bool change = true);

   /**
    * @brief Adds a new level into the game after existing levels.
    * @param level LevelFactory  representing the new level to be
    *              added to the game after the existing levels.
    */
   void addLevel(const std::shared_ptr<LevelFactory> &level);

   bool getIsInputDisabled() const;


private:
    //singleton:
    GameController();
    ~GameController();
    static GameController* gameControllerInstance;

    //game controllers
    std::shared_ptr<TileController> tileController;
    std::shared_ptr<HealthPackController> hpController;
    std::shared_ptr<ProtagonistController> protController;
    std::shared_ptr<EnemyController> enemyController;

    //level attributes
    int row {0};
    int col {0};
    int width;
    int height;

   //game status
    bool isGameOver{false};
    bool isInputDisabled{false};
    bool isHealthOver{false};
    bool isEnergyOver{false};


    void stopGame(QString title, QString message);


    //level switching:
    std::vector<std::pair<std::shared_ptr<LevelFactory>, LevelControllers>> levels;
    int currentLevel {0};
    void switchLevel(std::shared_ptr<LevelFactory> &levelFactory);
    void cacheLevel(int previousLevel);
    void nextLevel();
    void previousLevel();

    //game views:
    std::vector<std::shared_ptr<EnemyViewInterface>> setupGraphicalView();
    void setupUi();
    void setModelInViews();
    void getNewView();
    void initializeView();
    std::unique_ptr<GameView> gameView;
    std::deque<std::unique_ptr<GameView>> allGameViews;



}
;



#endif // GAMECONTROLLER_H
