/**
 * @file gamecontroller.h
 * @brief Defines the GameController class, responsible for managing the game's logic, input, and level progression.
 */

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "graphicalgameview.h"
#include "levelfactory.h"
#include "constants.h"
#include "gameview.h"
#include "healthpackcontroller.h"
#include "tilecontroller.h"
#include "enemycontroller.h"
#include "protagonistcontroller.h"

#include <deque>
#include <memory>

/**
 * @struct LevelControllers
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


/**
 * @class GameController
 * @brief Manages the game, including player input, level progression, and interaction with various controllers.
 *
 * The GameController class acts as a central point for coordinating game-related activities, including player input handling,
 * level management, and interaction with various controllers such as tile, health pack, protagonist, and enemy controllers.
 */
class GameController
{
public:
    //functions for singleton:
    GameController(GameController& copyController )= delete;
    void operator=(const GameController&) = delete;

    /**
     * @brief Retrieves the singleton instance of GameController.
     * @return The singleton instance of GameController.
     */
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
   void startGame(std::unique_ptr<GameView> gv);

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

   /**
     * @brief Gets the status of input disablement.
     * @return A boolean indicating whether input is currently disabled.
     */
   bool getIsInputDisabled() const;

   /**
     * @brief Moves to the next level in the game.
     */
   void nextLevel();

   /**
     * @brief Moves to the previous level in the game.
     */
   void previousLevel();

   /**
     * @brief Applies damage to the protagonist.
     * @param damage The amount of damage to be applied to the protagonist.
     */
   void damageToProtagonist(float damage);

   /**
     * @brief Warns the protagonist of danger.
     * @param isInDanger A boolean indicating whether the protagonist is in danger.
     */
   void warnProtagonist(bool isInDanger);

   /**
     * @brief Checks if the current level is complete.
     * @return A boolean indicating whether the current level is complete.
     */
   bool getIsLevelComplete();

private:
    //singleton:
    GameController();
    ~GameController();
    static GameController* gameControllerInstance;

    ///game controllers
    std::shared_ptr<TileController> tileController;
    std::shared_ptr<HealthPackController> hpController;
    std::shared_ptr<ProtagonistController> protController;
    std::shared_ptr<EnemyController> enemyController;

    ///level attributes
    int row {0};
    int col {0};
    int width;
    int height;

   ///game status
    bool isGameOver{false};
    bool isInputDisabled{false};
    bool isHealthOver{false};
    bool isEnergyOver{false};

    std::unique_ptr<GameView> gameView;
    std::deque<std::unique_ptr<GameView>> allGameViews;

    std::vector<std::pair<std::shared_ptr<LevelFactory>, LevelControllers>> levels;
    int currentLevel {0};

    /**
     * @brief Stops the game and displays a message indicating game over.
     *
     * @param title The title of the game over message box.
     * @param message The content of the game over message box.
     */
    void stopGame(QString title, QString message);

    ///level switching:

    /**
     * @brief Creates a new level using the provided level factory.
     *
     * @param levelFactory The level factory used to create the new level.
     */
    void createLevel(std::shared_ptr<LevelFactory> &levelFactory);

    /**
     * @brief Caches the current level's controllers for later retrieval.
     *
     * @param level_id The index of the level to be cached.
     */
    void cacheLevel(int level_id);

    /**
     * @brief Uncaches the controllers of a cached level for use in the game.
     *
     * @param level_id The index of the level to be uncached.
     */
    void uncacheLevel(int level_id);


    ///game views:

    /**
     * @brief Sets up the user interface for the current level.
     */
    void setupUi();

    /**
     * @brief Sets the models in views to ensure proper data binding.
     */
    void setModelInViews();

    /**
     * @brief Retrieves a new view from the "allGameViews" deque.
     */
    void getNewView();

    /**
     * @brief Initializes the game view and sets up the controllers.
     */
    void initializeView();
}
;



#endif // GAMECONTROLLER_H
