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
    void attackEnemy();
    void takeDamage(int hpValue);
    int getAttackDamage();


    bool updateEnergy(float enValue);
    bool updateHealth(int hpValue);

    void setProtView(const std::shared_ptr<ProtagonistView> &newProtView);

    std::shared_ptr<ProtagonistModel> getProtModel() const;

    bool getIsDead() const;

private:
    std::shared_ptr<ProtagonistView> protView;
    std::shared_ptr<ProtagonistModel> protModel;
    bool isDead;

};

#endif // PROTAGONISTCONTROLLER_H
