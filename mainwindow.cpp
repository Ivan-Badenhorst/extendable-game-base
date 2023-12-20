#include "mainwindow.h"
#include "enemyviewtext.h"
#include "healthpackviewtext.h"
#include "mediumlevelfactory.h"
#include "penemyviewtext.h"
#include "protagonistviewtext.h"
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
    auto textView = getTextView();
    gameController->addNewView(std::move(textView));

    //add aditional levels to the gameController:
    auto easyLevelFactory = std::make_shared<EasyLevelFactory>();
    gameController->addLevel(easyLevelFactory);
    auto levelF = std::make_shared<MediumLevelFactory>();
    gameController->addLevel(levelF);

    gameController->startGame(std::move(gameView));

}

MainWindow::~MainWindow()
{
    delete ui;
}


std::unique_ptr<TextGameView> MainWindow::getTextView()
{
    auto gameView = std::make_unique<TextGameView>(*this);

    //make the views:
    gameView->setHpView(std::make_shared<HealthPackViewText>());
    gameView->setProtView(std::make_shared<ProtagonistViewText>());
    gameView->setTileView(std::make_shared<TileViewText>());

    //for each type of enemy view we make a view!!
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews;
    auto pev = std::make_shared<PEnemyViewText>();
    enemyViews.push_back(pev);
    auto ev = std::make_shared<EnemyViewText>();
    enemyViews.push_back(ev);
    gameView->setEnemyView(enemyViews);

    return gameView;
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
