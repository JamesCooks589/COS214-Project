#pragma once
#include "ChefCreator.h"

class ToppingChef : public ChefCreator {
public:
    Chef* createVeganPizza() override;
    Chef* createNonveganPizza() override;
};
