#pragma once
#include "ChefCreator.h"

class ToppingChef : public ChefCreator {
public:
    virtual Chef* createVeganPizza() override;
    virtual Chef* createNonveganPizza() override;
};
