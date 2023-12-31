#include "mainwindow.h"

#include "mediumlevelfactory.h"
#include "hardlevelfactory.h"

#include "graphicgameviewfactory.h"
#include "textgameviewfactory.h"
#include "ui_mainwindow.h"

#include "constants.h"
#include "gamecontroller.h"


#include <QHBoxLayout>
#include <QLabel>


class TextGameView;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //setup this
    ui->setupUi(this);
    this->setFocus();

    gameController = GameController::getInstance();


    //create views to add to the gameController:
    TextGameViewFactory tvf;
    gameController->addNewView(tvf.createView(*this));

    //start the game
    GraphicGameViewFactory graphicGameViewFactory;
    gameController->startGame(graphicGameViewFactory.createView(*this));

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
