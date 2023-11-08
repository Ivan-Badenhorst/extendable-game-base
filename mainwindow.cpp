#include "Error in " Util.relativeFilePath('D:/University/Master's/APT/Project/fp/mainwindow.h', 'D:/University/Master's/APT/Project/fp' + '/' + Util.path('mainwindow.cpp'))": SyntaxError: Expected token `)'"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

