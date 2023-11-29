#include "graphicalgameview.h"
#include "HealthPackH/healthpackviewgraphical.h"
#include "TileH/tileviewgraphical.h"
#include "protagonistviewgraphical.h"
#include "qboxlayout.h"
#include "qgraphicsview.h"


void GraphicalGameView::initializeMainWindow()
{
   //create health bar:
    healthBar = std::make_shared<HealthProgressBar>(&mainWindow);
    healthBar->setRange(0, 122);
    healthBar->setValue(24);
    healthBar->setTextVisible(true);
    healthBar->setStyleSheet(
        "QProgressBar { border: 2px solid grey; border-radius: 5px; background-color: grey; text-align: center; }"
        "QProgressBar::chunk { background-color: green; width: 10px; }"
        "QProgressBar::chunk:horizontal { margin: 0px; }"
        );
    healthBar->setGeometry(300, 500, 280, 20);
    healthBar->show();

    if(auto pView = dynamic_cast<ProtagonistViewGraphical*>(protView.get())){
        pView->setHealthBar(healthBar);
    };

    ///TRANSFORM TO SMART POINTER!!!!!!!!!!!
    scene = std::make_shared<QGraphicsScene>(&mainWindow);
    view =  std::make_shared<QGraphicsView>(scene.get());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainWindow.setCentralWidget(view.get());

    // Create a widget to hold the view
    widget = std::make_shared<QWidget>(&mainWindow);

    widget->setFixedSize(800, 400);
    layout = std::make_shared<QHBoxLayout>(widget.get());
    layout->addWidget(view.get());
    layout->setContentsMargins(0, 0, 0, 0);

    mainWindow.setCentralWidget(widget.get());

    if(auto tView = dynamic_cast<TileViewGraphical*>(tileView.get())){
        tView->setScene(scene);
    };
    if(auto pView = dynamic_cast<ProtagonistViewGraphical*>(protView.get())){
        pView->setScene(scene);
    };
    if(auto hView = dynamic_cast<HealthPackViewGraphical*>(hpView.get())){
        hView->setScene(scene);
    };
    for(auto& eV: enemyView){
        if(auto eView = dynamic_cast<EnemyViewInterface*>(eV.get())){
            eView->setScene(scene);
        };
    }
    clearMainWindow();
    /// STILL NEED TO IMPLEMENT THE CLEAR FUNCTION PROPERLY!!! -> CALL THE RESET IN ALL THE VIEWS!!!
}

void GraphicalGameView::clearMainWindow()
{
    tileView->clearView();
    hpView->clearView();
    protView->clearView();
    for(auto& eV: enemyView){
        eV->clearView();
    }



    view.reset();
    widget.reset();
    layout.reset();

    scene.reset();
    healthBar.reset();
    //healthBar->reset();
}
