#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>

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

    ///REDO THE MAIN WINDOW DESTRUCTOR TO FREE THE GAME CONTROLLER MEMORY!!

    Ui::MainWindow *getUi() const;

    QGraphicsScene *getScene() const;



private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    GameController* gameController;

protected:
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MAINWINDOW_H
