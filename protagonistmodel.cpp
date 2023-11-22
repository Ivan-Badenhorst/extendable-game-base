#include "protagonistmodel.h"
#include <iostream>

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
    : protagonist(std::move(prot))
{

}

const std::unique_ptr<Protagonist> &ProtagonistModel::getProtagonist() const
{
    return protagonist;
}

