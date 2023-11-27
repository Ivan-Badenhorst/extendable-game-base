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

//    createHealthBar();

    gameController = GameController::getInstance();
    gameController->startGame(*this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearWindow()
{
    // Get the central widget of the main window
    QWidget *centralWidget = this->centralWidget();
    // Create a shared pointer for centralWidget and reset the main window's central widget
    std::shared_ptr<QWidget> sharedCentralWidget(centralWidget);
    this->setCentralWidget(nullptr); // Clear the central widget from mainWindow

    // Delete all child widgets from the original central widget using std::shared_ptr
    std::shared_ptr<QLayout> layout(sharedCentralWidget->layout());
    if (layout) {
        while (QLayoutItem *item = layout->takeAt(0)) {
            std::shared_ptr<QWidget> widget(item->widget());
            if (widget) {
                widget.reset(); // Reset the shared pointer to delete the widget
            }
            delete item;
        }
    }

}

Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

QGraphicsScene *MainWindow::getScene() const
{
    return scene;
}

//void MainWindow::createHealthBar()
//{

//    // Create a progress bar
//    healthBar = std::make_shared<HealthProgressBar>(this);
//    healthBar->setRange(0, 122); // Set the maximum health
//    healthBar->setValue(24); // Set the current health
//    healthBar->setTextVisible(true); // Hide default text
//    healthBar->setStyleSheet(
//        "QProgressBar { border: 2px solid grey; border-radius: 5px; background-color: grey; text-align: center; }"
//        "QProgressBar::chunk { background-color: green; width: 10px; }"
//        "QProgressBar::chunk:horizontal { margin: 0px; }" // Adjust margins
//        );
//    healthBar->setGeometry(300, 500, 280, 20);
//    healthBar->show();


//}

//HealthProgressBar*MainWindow::getHealthBar() const
//{
//    return healthBar.get();
//}




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

