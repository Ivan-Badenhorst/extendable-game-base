#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"

#include <QHBoxLayout>
#include <QLabel>


#include "graphicalgameview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFocus();

    GraphicalGameView ggv(*this);
    std::unique_ptr<GameView> gameView = std::make_unique<GraphicalGameView>(ggv);

    gameController = GameController::getInstance();
    gameController->startGame(*this, std::move(gameView));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        gameController->input(ArrowDirection::Left);
        break;
    case Qt::Key_Right:
        gameController->input(ArrowDirection::Right);
        break;
    case Qt::Key_Up:
        gameController->input(ArrowDirection::Up);
        break;
    case Qt::Key_Down:
        gameController->input(ArrowDirection::Down);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
