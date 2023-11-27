#include "graphicalgameview.h"



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

}

void GraphicalGameView::clearMainWindow()
{
    healthBar->reset();
}
