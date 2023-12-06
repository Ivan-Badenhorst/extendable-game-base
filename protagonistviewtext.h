#ifndef PROTAGONISTVIEWTEXT_H
#define PROTAGONISTVIEWTEXT_H


#include "protagonistmodel.h"
#include "protagonistview.h"
#include "qlabel.h"
#include "qplaintextedit.h"
#include <memory>
class ProtagonistViewText: public ProtagonistView
{
public:
    ProtagonistViewText();
    void update() override;
    void update(int row, int col) override;
    void updateHealth() override;
    void clearView() override;
    void setProtModel(const std::shared_ptr<ProtagonistModel> &newProtModel) override;
    void erasePreviousPosition(QTextCursor& cursor);
    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

    void setHealthLabels(QLabel *health, QLabel *healthValue);
private:
    std::shared_ptr<ProtagonistModel> protModel;
    std::shared_ptr<QPlainTextEdit> textEdit;

    QLabel* healthLabel;
    QLabel* healthValueLabel;

};

#endif // PROTAGONISTVIEWTEXT_H
