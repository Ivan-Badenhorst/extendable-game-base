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
    healthBar->setRange(0, 122); // Set the maximum health
    healthBar->setValue(24); // Set the current health
    healthBar->setTextVisible(true); // Hide default text
    healthBar->setStyleSheet(
        "QProgressBar { border: 2px solid grey; border-radius: 5px; background-color: grey; text-align: center; }"
        "QProgressBar::chunk { background-color: green; width: 10px; }"
        "QProgressBar::chunk:horizontal { margin: 0px; }" // Adjust margins
        );
    healthBar->setGeometry(300, 500, 280, 20);
    healthBar->show();

    if(auto pView = dynamic_cast<ProtagonistViewGraphical*>(protView.get())){
        pView->setHealthBar(healthBar);
    };

    ///TRANSFORM TO SMART POINTER!!!!!!!!!!!
    scene = std::make_shared<QGraphicsScene>(&mainWindow);
    QGraphicsView* view = new QGraphicsView(scene.get());
//    view->setGeometry(60, 30, 800, 400);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainWindow.setCentralWidget(view);

    // Create a widget to hold the view
    QWidget* widget = new QWidget(&mainWindow);

    widget->setFixedSize(800, 400); // Fixed size for the widget
    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->addWidget(view);
    layout->setContentsMargins(0, 0, 0, 0);

    mainWindow.setCentralWidget(widget);

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

    /// We now pass the scene to the views as needed
}

void GraphicalGameView::clearMainWindow()
{
    healthBar->reset();
}
