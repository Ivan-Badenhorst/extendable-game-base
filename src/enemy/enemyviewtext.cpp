#include "enemyviewtext.h"

#include <iostream>

EnemyViewText::EnemyViewText()

{

}

void EnemyViewText::render(int x, int y)
{
    // We position the cursor at the correct position in the text edit.
    int moveDown = 1 + 2*y;
    int moveRight = 2 + 4*x;
    QTextBlock  b = textEdit->document()->findBlockByLineNumber(moveDown);
    auto position = b.length()*moveDown + moveRight;

    // Then we fetch data for this Enemy from the EnemyModel.
    auto enemyState = enemyModel->getOneEnemyState(x, y);

    // Then we render the Enemy if we have data for it.
    if(enemyState.has_value()){
        auto newChar = "E";
        if(enemyState.value().isDefeated) newChar ="e";
        textEdit->document()->setPlainText(textEdit->document()->toPlainText().replace(position, 1, newChar));
    }
}

void EnemyViewText::render()
{

    // First we fetch all enemy data from the EnemyModel
    auto allEnemiesState = enemyModel->getAllEnemyStates();

    // Then display each enemy
    for(auto& enemyState : allEnemiesState){
        // We position the cursor at the correct position in the text edit.
        int moveDown = 1 + 2*enemyState.y;
        int moveRight = 2 + 4*enemyState.x;
        QTextBlock  b = textEdit->document()->findBlockByLineNumber(moveDown);
        auto position = b.length()*moveDown + moveRight;

        // Then we render the Enemy
        auto newChar = "E";
        if(enemyState.isDefeated) newChar ="e";
        textEdit->document()->setPlainText(textEdit->document()->toPlainText().replace(position, 1, newChar));
    }
    
}

void EnemyViewText::clearView()
{
    textEdit.reset();
}

void EnemyViewText::setEnemyModel(const std::shared_ptr<EnemyModel> &newEnemyModel)
{
    enemyModel = newEnemyModel;
}



