#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <mutex>
#include <memory>

class GameController
{
public:
   GameController(GameController& copyController )= delete;
   void operator=(const GameController&) = delete;

   static GameController& getInstance();


private:
   static GameController* gameControllerInstance;
   static std::mutex mutex_;

   GameController();
   ~GameController();

}
;
GameController* GameController::gameControllerInstance;
std::mutex GameController::mutex_;




#endif // GAMECONTROLLER_H
