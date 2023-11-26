#ifndef PROTAGONISTCONTROLLER_H
#define PROTAGONISTCONTROLLER_H
#include "protagonistmodel.h"
#include "protagonistview.h"


class ProtagonistController
{
public:
    ProtagonistController(std::shared_ptr<ProtagonistView> pv, std::shared_ptr<ProtagonistModel> pm);
    void refreshAll();
    void update(int row, int col);
private:
    std::shared_ptr<ProtagonistView> protView;
    std::shared_ptr<ProtagonistModel> protModel;

};

#endif // PROTAGONISTCONTROLLER_H