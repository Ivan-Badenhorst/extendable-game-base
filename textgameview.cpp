#include "textgameview.h"

#include <QPlainTextEdit>
#include <QMainWindow>
#include <QHBoxLayout>


void TextGameView::initializeMainWindow()
{
    // Create a new QPlainTextEdit
    QPlainTextEdit* asciiTextEdit = new QPlainTextEdit(&mainWindow);

    // Set size of the QPlainTextEdit
    asciiTextEdit->setFixedSize(800, 400); // Adjust size as needed
    asciiTextEdit->setReadOnly(true);

    // Add the QPlainTextEdit to the main window
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(asciiTextEdit);

    // Set the layout to the central widget of the main window
    QWidget* centralWidget = new QWidget(&mainWindow);
    centralWidget->setLayout(layout);
    mainWindow.setCentralWidget(centralWidget);
}

void TextGameView::clearMainWindow()
{

}
