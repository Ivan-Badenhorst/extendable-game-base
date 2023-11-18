#include "protagonistcontroller.h"

ProtagonistController::ProtagonistController(std::shared_ptr<ProtagonistView> pv, std::shared_ptr<ProtagonistModel> pm)
    : protView(pv), protModel(pm)
{

}
