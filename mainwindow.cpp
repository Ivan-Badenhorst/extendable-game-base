#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"

#include <QHBoxLayout>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->setFocus();

    createHealthBar();

    gameController = GameController::getInstance();
    gameController->startGame(*this);

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

void MainWindow::createHealthBar()
{

    // Create a progress bar
    healthBar = std::make_unique<HealthProgressBar>(this);
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

HealthProgressBar*MainWindow::getHealthBar() const
{
    return healthBar.get();
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

