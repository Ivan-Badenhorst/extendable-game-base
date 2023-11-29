#ifndef PROTAGONISTVIEWTEXT_H
#define PROTAGONISTVIEWTEXT_H


#include "protagonistmodel.h"
#include "protagonistview.h"
#include <memory>
class ProtagonistViewText: public ProtagonistView
{
public:
    ProtagonistViewText(std::shared_ptr<ProtagonistModel> pm);
    void update() override;
    void update(int row, int col) override;
    void updateHealth() override;
    void clearView() override;

private:
    std::shared_ptr<ProtagonistModel> protModel;
};

#endif // PROTAGONISTVIEWTEXT_H
