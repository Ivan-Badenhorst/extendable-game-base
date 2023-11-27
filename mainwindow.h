#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>

#include <QProgressBar>

class HealthProgressBar : public QProgressBar {
public:

    explicit HealthProgressBar(QWidget *parent = nullptr) : QProgressBar(parent) {}

    QString text() const override {
        return QString("%1/%2 HP").arg(value()).arg(maximum());
    }
};



//#include "gamecontroller.h"
class GameController;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clearWindow();

    ///REDO THE MAIN WINDOW DESTRUCTOR TO FREE THE GAME CONTROLLER MEMORY!!

    Ui::MainWindow *getUi() const;
    QGraphicsScene *getScene() const;
    HealthProgressBar*getHealthBar() const;


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    GameController* gameController;


    void createHealthBar();//MAYBE MOVE THIS SOMEWHERE ELSE. IDK WHERE LOL
    std::shared_ptr<HealthProgressBar> healthBar;

protected:
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MAINWINDOW_H





