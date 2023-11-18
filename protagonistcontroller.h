#ifndef PROTAGONISTCONTROLLER_H
#define PROTAGONISTCONTROLLER_H
#include "protagonistmodel.h"
#include "protagonistview.h"


class ProtagonistController
{
public:
    ProtagonistController(std::shared_ptr<ProtagonistView> pv, std::shared_ptr<ProtagonistModel> pm);
    // add an update method to update the view
private:
    std::shared_ptr<ProtagonistView> protView;
    std::shared_ptr<ProtagonistModel> protModel;

};

#endif // PROTAGONISTCONTROLLER_H
