#include "textgameview.h"
#include "healthpackviewtext.h"
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

    //create a commandline edit
    lineEdit = std::make_shared<CommandLineEdit>(&mainWindow);
    lineEdit->setFixedWidth(textEdit->width());

    // Add the QPlainTextEdit to the main window
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(textEdit.get());
    layout->addWidget(lineEdit.get());


    // Set the layout to the central widget of the main window
    QWidget* centralWidget = new QWidget(&mainWindow);
    centralWidget->setLayout(layout);
    mainWindow.setCentralWidget(centralWidget);

    //pass the text edit to the individual view:
    if(auto pView = dynamic_cast<TileViewText*>(tileView.get())){
        pView->setTextEdit(textEdit);
    };
    if(auto pView = dynamic_cast<HealthPackViewText*>(hpView.get())){
        pView->setTextEdit(textEdit);
    };
}

void TextGameView::clearMainWindow()
{
    ///TO BE IMPLEMENTED!!!
    lineEdit.reset();
    tileView->clearView();
    hpView->clearView();
    textEdit.reset();
}

void TextGameView::setupBasicCommands()
{
    commandTrie = std::make_shared<CommandTrieNode>();
    auto moveRight = [](){

    };
    commandTrie->insert("right", moveRight);

}


///CommandLineEdit here:

void CommandLineEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        //here try to execute command!!
        emit returnPressed();
    } else {
        QLineEdit::keyPressEvent(event);
    }
}
