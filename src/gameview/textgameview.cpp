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
    mainWindow.setKeyboardEventsEnabled(false);
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

    availableCommandsTextLabel = std::make_shared<QLabel>(&mainWindow);


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
    layout->addWidget(availableCommandsTextLabel.get());





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
    for(auto& eV: enemyView){
        if(auto eView = dynamic_cast<BaseEnemyView*>(eV.get())){
            eView->setTextEdit(textEdit);
        };
    }

    lineEdit->setFocus();
}

void TextGameView::clearMainWindow()
{

    lineEdit.reset();
    tileView->clearView();
    hpView->clearView();
    protView->clearView();
    for(auto& eV: enemyView){
        eV->clearView();
    }
    textEdit.reset();
    healthLabel.reset();
    healthValueLabel.reset();
    energyLabel.reset();
    energyValueLabel.reset();
    availableCommandsTextLabel.reset();
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

    auto switchView = [](){
        auto gameController = GameController::getInstance();
        gameController->switchView();
    };
    commandTrie->insert("switch view", switchView);

    lineEdit->setCommandTrie(commandTrie);

    auto displayHelp = [this]() {
        auto availableCommands = commandTrie->getAllCommands();
        std::string helpText = "Available Commands: \n";
        for (const auto& command : availableCommands) {
            helpText += command + "\n";
        }
        availableCommandsTextLabel->setText(QString::fromStdString(helpText)); // Update the text in the QLabel
    };
    commandTrie->insert("help", displayHelp);

    lineEdit->setCommandTrie(commandTrie);

}


///CommandLineEdit here:

void CommandLineEdit::keyPressEvent(QKeyEvent *event)
{
    std::pair<std::optional<std::string>, int> ret;
    switch (event->key()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        ret = commandTrie->findFirstMatch(this->text().toStdString(), true);

        if(ret.second == 1 || ret.second == 3){
            if(ret.first != "switch view") this->setText("");
        } else{
            ret = commandTrie->findFirstMatch("help", true);
            this->setText("");
        }
        break;
    case Qt::Key_Right:
        ret = commandTrie->findFirstMatch(this->text().toStdString(), false);
        std::cout << "Tab clicked" << std::endl;
        if(ret.first.has_value()) this->setText(QString::fromStdString(ret.first.value()));
        break;
    default:
        QLineEdit::keyPressEvent(event);
        break;
    }

}

void CommandLineEdit::setCommandTrie(const std::shared_ptr<CommandTrieNode> &newCommandTrie)
{
    commandTrie = newCommandTrie;
}
