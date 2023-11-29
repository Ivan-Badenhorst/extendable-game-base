#ifndef PROTAGONISTCONTROLLER_H
#define PROTAGONISTCONTROLLER_H
#include "protagonistmodel.h"
#include "protagonistview.h"


class ProtagonistController
{
public:
    ProtagonistController(std::shared_ptr<ProtagonistModel> pm);
    void refreshAll();
    void update(int row, int col);
    void landedOnHp();
    void addHealth(int hpValue);
    void attackEnemy();
    void takeDamage(int hpValue);
    int getAttackDamage();


    void setProtView(const std::shared_ptr<ProtagonistView> &newProtView);

    std::shared_ptr<ProtagonistModel> getProtModel() const;

private:
    std::shared_ptr<ProtagonistView> protView;
    std::shared_ptr<ProtagonistModel> protModel;

};

#endif // PROTAGONISTCONTROLLER_H
