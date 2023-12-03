#ifndef TEXTGAMEVIEW_H
#define TEXTGAMEVIEW_H


#include "gameview.h"
#include "qplaintextedit.h"

#include <QLineEdit>
#include <QKeyEvent>
class CommandLineEdit : public QLineEdit {
    Q_OBJECT
public:
    explicit CommandLineEdit(QWidget *parent = nullptr): QLineEdit(parent){};

protected:
    void keyPressEvent(QKeyEvent *event) override;
};


class TextGameView: public GameView
{
public:
    TextGameView(MainWindow& mw) : GameView(mw){};
    void initializeMainWindow() override;
    void clearMainWindow() override;

private:
    std::shared_ptr<QPlainTextEdit> textEdit;
};

#endif // TEXTGAMEVIEW_H
