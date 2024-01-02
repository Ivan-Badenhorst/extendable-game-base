#ifndef PROTAGONISTCONTROLLER_H
#define PROTAGONISTCONTROLLER_H
#include "protagonistmodel.h"
#include "protagonistview.h"
#include <QObject>
#include <QTimer>

class ProtagonistController: public QObject
{
    Q_OBJECT
public:
    ProtagonistController(std::shared_ptr<ProtagonistModel> pm);
    void refreshAll();
    void update(int row, int col);
    void landedOnHp();
    void attackEnemy();
    /// TODO: Isn't the health a float in the lib?
    bool takeDamage(int hpValue);
    int getAttackDamage();
    void showDeath();


    bool updateEnergy(float enValue);
    void updateHealth(int hpValue);

    void setProtView(const std::shared_ptr<ProtagonistView> &newProtView);
    void warn(bool isInDanger);

    std::shared_ptr<ProtagonistModel> getProtModel() const;

    bool getIsDead() const;

private:
    std::shared_ptr<ProtagonistView> protView;
    std::shared_ptr<ProtagonistModel> protModel;
    bool isDead;
    bool forwardAnimation{true};
    int currentFrame;
    QTimer attackTimer;
    QTimer healthGainTimer;
    QTimer deathTimer;
    QTimer takeDamageTimer;

signals:

private slots:
    void onAttackTimerTimeout();
    void onHealthGainTimerTimeout();
    void onDeathTimeTimeout();
    void onDamageTimerTimeout();

};

#endif // PROTAGONISTCONTROLLER_H
