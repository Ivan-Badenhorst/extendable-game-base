#include "healthpackviewtext.h"
#include "qtextcursor.h"
#include <future>
#include <iostream>

#include <QApplication>
#include <QPlainTextEdit>
#include <QTextBlock>

HealthPackViewText::HealthPackViewText()
{
//implement
}

void HealthPackViewText::update()
{


    for(auto& hp: hpModel->getHealthPacks()){

        if(hp[2]>0){//unused pack
            update(hp[0], hp[1], false);
        }
        else
        {
            update(hp[0], hp[1]);
        }

    }
}

void HealthPackViewText::update(int row, int col, bool used)
{
    int moveDown = 1 + 2*row;
    int moveRight = 2 + 4*col;

    QTextBlock  b = textEdit->document()->findBlockByLineNumber(moveDown);
    auto position = b.length()*moveDown + moveRight;
    auto newChar = "H";
    if(used) newChar ="h";
    textEdit->document()->setPlainText(textEdit->document()->toPlainText().replace(position, 1, newChar));
}

void HealthPackViewText::clearView()
{
    textEdit.reset();
}

void HealthPackViewText::setHpModel(const std::shared_ptr<HealthPackModel> &newHpModel)
{
    hpModel = newHpModel;
}

void HealthPackViewText::setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit)
{
    textEdit = newTextEdit;
}
