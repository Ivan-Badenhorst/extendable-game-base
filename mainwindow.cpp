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
    scene = new QGraphicsScene(this);
    //THE SCENE SHOULD MAYBE BE MOVED TO THE GRAPHICS VIEW CLASS!

    this->setFocus();

//    createHealthBar();
    GraphicalGameView ggv(*this);
    std::unique_ptr<GameView> gameView = std::make_unique<GraphicalGameView>(ggv);

    gameController = GameController::getInstance();
    gameController->startGame(*this, std::move(gameView));

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

    // Delete all child widgets from the original central widget
    std::shared_ptr<QLayout> layout(sharedCentralWidget->layout());
    if (layout) {
        while (QLayoutItem *item = layout->takeAt(0)) {
            std::shared_ptr<QWidget> widget(item->widget());
            if (widget) {
                widget.reset();
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
