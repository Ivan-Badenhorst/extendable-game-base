#include "mainwindow.h"
#include <iostream>
#include <QApplication>

#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    auto controller = GameController::getInstance();
    controller->startGame(w);


    return a.exec();
}
