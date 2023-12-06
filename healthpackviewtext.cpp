#include "healthpackviewtext.h"
#include "qtextcursor.h"
#include <future>
#include <iostream>


HealthPackViewText::HealthPackViewText()
{
//implement
}

void HealthPackViewText::update()
{

// Define a lambda function to process each element
auto hps = hpModel->getHealthPacks();
auto processParallel = [&hps, this](int index) {
    auto hp = hps[index];
    if(hp[2]>0){//unused pack
        update(hp[0], hp[1], false);
    }
    else
    {
        update(hp[0], hp[1]);
    }
};

// Process each element in parallel
std::vector<std::future<void>> futures;
for (size_t i = 0; i < hps.size(); ++i) {
    futures.push_back(std::async(std::launch::async, processParallel, i));
}

// Wait for all tasks to complete
for (auto& future : futures) {
    future.wait();
}



//    for(auto& hp: hpModel->getHealthPacks()){

//        if(hp[2]>0){//unused pack
//            update(hp[0], hp[1], false);
//        }
//        else
//        {
//            update(hp[0], hp[1]);
//        }

//    }
}

void HealthPackViewText::update(int row, int col, bool used)
{

    int moveDown = 1 + 2*row;
    int moveRight = 2 + 4*col;

    auto cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    cursor.clearSelection();

    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, moveDown);
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, moveRight);


    cursor.deleteChar();
    if(used) {cursor.insertText("h");}
    else {cursor.insertText("H");}


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
