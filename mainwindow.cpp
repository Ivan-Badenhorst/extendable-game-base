#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

QGraphicsScene *MainWindow::getScene() const
{
    return scene;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    {
        if(event->key() == Qt::Key_Down)
        {
            std::cout << "lmaoooooooooooooo" << std::endl;
        }
        else if(event->key() == Qt::Key_R)
        {
            std::cout << "HEHEHEHE" << std::endl;
        }
    }
}

