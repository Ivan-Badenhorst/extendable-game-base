#include "mainwindow.h"
#include "enemyviewtext.h"
#include "hardlevelfactory.h"
#include "healthpackviewtext.h"
#include "mediumlevelfactory.h"
#include "penemyviewtext.h"
#include "protagonistviewtext.h"
#include "textgameviewfactory.h"
#include "tileviewtext.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"
#include  "easylevelfactory.h"

#include <QHBoxLayout>
#include <QLabel>


#include "graphicalgameview.h"
#include "textgameview.h"

class TextGameView;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //setup this
    ui->setupUi(this);
    this->setFocus();

    gameController = GameController::getInstance();
    GraphicalGameView graphicalGameView(*this);
    auto gameView = std::make_unique<GraphicalGameView>(graphicalGameView);

    //create views to add to the gameController:
    TextGameViewFactory tvf;
    gameController->addNewView(tvf.createView(*this));

    //start the game
    gameController->startGame(std::move(gameView));

    //add aditional levels to the gameController:
    auto mediumLevel = std::make_shared<MediumLevelFactory>();
    gameController->addLevel(mediumLevel);
    auto hardLevel = std::make_shared<HardLevelFactory>();
    gameController->addLevel(hardLevel);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setKeyboardEventsEnabled(bool newKeyboardEventsEnabled)
{
    keyboardEventsEnabled = newKeyboardEventsEnabled;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(gameController->getIsInputDisabled()) return;

    if(!keyboardEventsEnabled) return;
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
    case Qt::Key_S:
        gameController->switchView();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
     this->setFocus();

//    If needed later on, pass the event to the base class implementation
//    QMainWindow::mousePressEvent(event);
}
