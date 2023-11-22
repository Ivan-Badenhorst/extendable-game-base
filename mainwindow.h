#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *getUi() const;

    QGraphicsScene *getScene() const;

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

protected:
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MAINWINDOW_H
