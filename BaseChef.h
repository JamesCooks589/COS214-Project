#pragma once
#include "ChefCreator.h"

class BaseChef : public ChefCreator {
public:
    PizzaCreator* createVeganPizza() override;
    PizzaCreator* createNonveganPizza() override;
};
