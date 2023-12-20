#include "textgameview.h"
#include "gamecontroller.h"
#include "healthpackviewtext.h"
#include "protagonistviewtext.h"
#include "qlabel.h"
#include "tileviewtext.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>


void TextGameView::initializeMainWindow()
{
    // Create a new QPlainTextEdit
    textEdit = std::make_shared<QPlainTextEdit>(&mainWindow);

    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(16);
    // Set size of the QPlainTextEdit
    textEdit->setFixedSize(800, 400); // Adjust size as needed
    textEdit->setReadOnly(true);
    textEdit->setFont(font);
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);


    QHBoxLayout* layout1 = new QHBoxLayout();
    healthLabel = std::make_shared<QLabel>("Health: ", &mainWindow);
    healthValueLabel = std::make_shared<QLabel>(&mainWindow);
    energyLabel = std::make_shared<QLabel>("Energy: ", &mainWindow);
    energyValueLabel = std::make_shared<QLabel>(&mainWindow);
    // Check if protView is an instance of ProtagonistViewText before setting health labels
    if (auto protagonistTextView = dynamic_cast<ProtagonistViewText*>(protView.get())) {
        protagonistTextView->setHealthLabels(healthValueLabel);
        protagonistTextView->setEnergyLabels(energyValueLabel);
    }

    //create a commandline edit
    lineEdit = std::make_shared<CommandLineEdit>(&mainWindow);
    lineEdit->setFixedWidth(textEdit->width());
    setupBasicCommands();

    // Add the QPlainTextEdit to the main window
    QVBoxLayout* layout = new QVBoxLayout();

    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);

    layout1->addWidget(textEdit.get());


    // Add health labels to the layout
    layout1->addWidget(healthLabel.get());
    layout1->addWidget(healthValueLabel.get());
    layout1->addWidget(energyLabel.get());
    layout1->addWidget(energyValueLabel.get());

    layout->addLayout(layout1);
    layout->addWidget(lineEdit.get());





    // Set the layout to the central widget of the main window
    QWidget* centralWidget = new QWidget(&mainWindow);
    centralWidget->setLayout(layout);
    mainWindow.setCentralWidget(centralWidget);

    //pass the text edit to the individual view:
    if(auto tView = dynamic_cast<TileViewText*>(tileView.get())){
        tView->setTextEdit(textEdit);
    };
    if(auto hView = dynamic_cast<HealthPackViewText*>(hpView.get())){
        hView->setTextEdit(textEdit);
    };
    if(auto pView = dynamic_cast<ProtagonistViewText*>(protView.get())){
        pView->setTextEdit(textEdit);
    };
}

void TextGameView::clearMainWindow()
{

    lineEdit.reset();
    tileView->clearView();
    hpView->clearView();
    protView->clearView();
    textEdit.reset();
    healthLabel.reset();
    healthValueLabel.reset();
    energyLabel.reset();
    energyValueLabel.reset();
}

void TextGameView::setupBasicCommands()
{
    commandTrie = std::make_shared<CommandTrieNode>();
    auto moveRight = [](){
        auto gameController = GameController::getInstance();
        gameController->input(ArrowDirection::Right);
    };
    commandTrie->insert("right", moveRight);

    auto moveLeft = [](){
        auto gameController = GameController::getInstance();
        gameController->input(ArrowDirection::Left);
    };
    commandTrie->insert("left", moveLeft);

    auto moveUp = [](){
        auto gameController = GameController::getInstance();
        gameController->input(ArrowDirection::Up);
    };
    commandTrie->insert("up", moveUp);

    auto moveDown = [](){
        auto gameController = GameController::getInstance();
        gameController->input(ArrowDirection::Down);
    };
    commandTrie->insert("down", moveDown);

    lineEdit->setCommandTrie(commandTrie);

}


///CommandLineEdit here:

void CommandLineEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        commandTrie->findFirstMatch(this->text().toStdString(), true);

    } else {
        QLineEdit::keyPressEvent(event);
    }
}

void CommandLineEdit::setCommandTrie(const std::shared_ptr<CommandTrieNode> &newCommandTrie)
{
    commandTrie = newCommandTrie;
}
