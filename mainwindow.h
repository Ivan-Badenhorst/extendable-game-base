#ifndef MAINWINDOW_H
#define MAINWINDOW_H




#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>

class TextGameView;

class GameController;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::unique_ptr<TextGameView> getTextView();
    void setKeyboardEventsEnabled(bool newKeyboardEventsEnabled);

private:
    Ui::MainWindow *ui;
    GameController* gameController;
    bool keyboardEventsEnabled {true};

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

};
#endif // MAINWINDOW_H





