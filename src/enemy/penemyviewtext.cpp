#include "penemyviewtext.h"

PEnemyViewText::PEnemyViewText()

{

}

void PEnemyViewText::render(int x, int y)
{
    // We position the cursor at the correct position in the text edit.
    int moveDown = 1 + 2*y;
    int moveRight = 2 + 4*x;
    QTextBlock  b = textEdit->document()->findBlockByLineNumber(moveDown);
    auto position = b.length()*moveDown + moveRight;

    // Then we fetch data for this Enemy from the EnemyModel.
    auto enemyState = penemyModel->getOnePEnemyState(x, y);

    // Then we render the Enemy if we have data for it.
    if(enemyState.has_value()){
        auto newChar = "Z";
        if(enemyState.value().isDefeated) newChar ="z";
        textEdit->document()->setPlainText(textEdit->document()->toPlainText().replace(position, 1, newChar));
    }
}

void PEnemyViewText::render()
{
    // First we fetch all enemy data from the EnemyModel
    auto allEnemiesState = penemyModel->getAllPEnemyStates();

    // Then display each enemy
    for(auto& enemyState : allEnemiesState){
        // We position the cursor at the correct position in the text edit.
        int moveDown = 1 + 2*enemyState.y;
        int moveRight = 2 + 4*enemyState.x;
        QTextBlock  b = textEdit->document()->findBlockByLineNumber(moveDown);
        auto position = b.length()*moveDown + moveRight;

        // Then we render the Enemy
        auto newChar = "Z";
        if(enemyState.isDefeated) newChar ="z";
        textEdit->document()->setPlainText(textEdit->document()->toPlainText().replace(position, 1, newChar));
    }
}

void PEnemyViewText::clearView()
{
    textEdit.reset();
}


void PEnemyViewText::setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel)
{
    penemyModel = newPenemyModel;
}
