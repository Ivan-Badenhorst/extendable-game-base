#ifndef PROTAGONISTCONTROLLER_H
#define PROTAGONISTCONTROLLER_H
#include "protagonistmodel.h"
#include "protagonistview.h"
#include <QObject>
#include <QVariant>
#include <QVector>
#include <QTimer>
#include <QPointer>

class ProtagonistController: public QObject
{
    Q_OBJECT
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
    bool forwardAnimation{true};
    int currentFrame;
    QTimer attackTimer;

signals:

private slots:
    void onAttackTimerTimeout();

};

#endif // PROTAGONISTCONTROLLER_H
