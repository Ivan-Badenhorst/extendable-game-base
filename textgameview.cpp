#include "textgameview.h"
#include "healthpackviewtext.h"
#include "protagonistviewtext.h"
#include "qlabel.h"
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
    font.setPointSize(16);
    // Set size of the QPlainTextEdit
    textEdit->setFixedSize(800, 400); // Adjust size as needed
    textEdit->setReadOnly(true);
    textEdit->setFont(font);
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);

    QHBoxLayout* layout = new QHBoxLayout();
    healthLabel = std::make_shared<QLabel>("Health: ", &mainWindow);
    healthValueLabel = std::make_shared<QLabel>(&mainWindow);

    // Check if protView is an instance of ProtagonistViewText before setting health labels
    if (auto protagonistTextView = dynamic_cast<ProtagonistViewText*>(protView.get())) {
        protagonistTextView->setHealthLabels(healthLabel, healthValueLabel);
    }

    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(textEdit.get());
    // Add health labels to the layout
    layout->addWidget(healthLabel.get());
    layout->addWidget(healthValueLabel.get());

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
    tileView->clearView();
    hpView->clearView();
    protView->clearView();
    textEdit.reset();
    healthLabel.reset();
    healthValueLabel.reset();
}
