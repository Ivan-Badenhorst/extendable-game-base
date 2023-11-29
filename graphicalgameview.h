#ifndef GRAPHICALGAMEVIEW_H
#define GRAPHICALGAMEVIEW_H

#include "gameview.h"
#include "qboxlayout.h"
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
    //main components
    std::shared_ptr<HealthProgressBar> healthBar;
    std::shared_ptr<QGraphicsScene> scene;

    //supporting components
    std::shared_ptr<QGraphicsView> view;
    std::shared_ptr<QWidget> widget;
    std::shared_ptr<QHBoxLayout> layout;
};

#endif // GRAPHICALGAMEVIEW_H
