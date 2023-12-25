#ifndef PROTAGONISTTIMER_H
#define PROTAGONISTTIMER_H

#include <QObject>
#include <QTimer>
#include <QPointer>
#include <QVector>
#include <QVariant>
#include "protagonistcontroller.h"
class protagonistTimer : public QObject
{
     Q_OBJECT
public:
    explicit protagonistTimer(std::shared_ptr<ProtagonistController> pc);
    void startAttackAnimation();

private:
    std::shared_ptr<ProtagonistController> protController;
    QVector<QPointer<QTimer>> protTimers;
    int currentFrame {0};
signals:

private slots:
    void onAttackTimerTimeout();
};

#endif // PROTAGONISTTIMER_H
