#include "mainwindow.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto w_p = std::make_shared<MainWindow>(w);
    w.show();
    return a.exec();
}
