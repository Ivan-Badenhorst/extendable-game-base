#include "textgameview.h"
#include "healthpackviewtext.h"
#include "qscrollarea.h"
#include "tileviewtext.h"

#include <QMainWindow>
#include <QHBoxLayout>


void TextGameView::initializeMainWindow()
{
    // Create a new QPlainTextEdit
    textEdit = std::make_shared<QPlainTextEdit>(&mainWindow);

    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    // Set size of the QPlainTextEdit
    textEdit->setFixedSize(800, 400); // Adjust size as needed
    textEdit->setReadOnly(true);
    textEdit->setFont(font);
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);



    // Add the QPlainTextEdit to the main window
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setAlignment(Qt::AlignTop); // Align the QPlainTextEdit at the top of the layout
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(textEdit.get());

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
    textEdit.reset();
}
