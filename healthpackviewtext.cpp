#include "healthpackviewtext.h"
#include "qtextcursor.h"
#include <iostream>


HealthPackViewText::HealthPackViewText()
{
//implement
}

void HealthPackViewText::update()
{
//implement
}

void HealthPackViewText::update(int row, int col, bool used)
{



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
