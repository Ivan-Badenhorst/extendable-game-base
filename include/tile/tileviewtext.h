#ifndef TILEVIEWTEXT_H
#define TILEVIEWTEXT_H


#include "tilemodel.h"
#include "tileview.h"
#include "qplaintextedit.h"
#include <memory>

class TileViewText: public TileView
{
public:
    TileViewText();
    void update(int row = 0, int col = 0) override;
    void clearView() override;
    void setTileModel(const std::shared_ptr<TileModel> &newTileModel) override;

    void setTextEdit(const std::shared_ptr<QPlainTextEdit> &newTextEdit);

private:
    std::shared_ptr<QPlainTextEdit> textEdit;
    bool displayed {false};
};

#endif // TILEVIEWTEXT_H
