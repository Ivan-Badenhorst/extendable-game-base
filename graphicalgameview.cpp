#include "graphicalgameview.h"
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
//        auto pViewS = std::make_shared<ProtagonistViewGraphical>(*pView);
//        pViewS->setHealthBar(healthBar);
        pView->setHealthBar(healthBar);
    };
    ///TRANSFORM TO SMART POINTER!!!!!!!!!!!
    QGraphicsView* view = new QGraphicsView(mainWindow.getScene());
//    view->setGeometry(60, 30, 800, 400);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainWindow.setCentralWidget(view);

    // Create a widget to hold the view
    QWidget* widget = new QWidget(&mainWindow);
    widget->setFixedSize(800, 400); // Fixed size for the widget
    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->addWidget(view);
    layout->setContentsMargins(60, 30, 0, 0); // Adjust the margins as needed

    mainWindow.setCentralWidget(widget);

    //create QGraphicsScene
//    mainWindow->getscene = new QGraphicsScene(this);
//    ui->graphicsView->setScene(scene);
}

void GraphicalGameView::clearMainWindow()
{
    healthBar->reset();
}
