#ifndef GRAPHICALGAMEVIEW_H
#define GRAPHICALGAMEVIEW_H

#include "gameview.h"
#include <QProgressBar>

class HealthProgressBar : public QProgressBar {
public:
    explicit HealthProgressBar(QWidget *parent = nullptr) : QProgressBar(parent) {}

    QString text() const override {
        return QString("%1/%2 HP").arg(value()).arg(maximum());
    }
};

class GraphicalGameView: public GameView
{
public:
    GraphicalGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;

private:
    std::shared_ptr<HealthProgressBar> healthBar;
    std::shared_ptr<QGraphicsScene> scene;


};

#endif // GRAPHICALGAMEVIEW_H
