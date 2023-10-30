#pragma once
#include "PizzaCreator.h"

class ChefCreator {
public:
    virtual PizzaCreator* createVeganPizza() = 0;
    virtual PizzaCreator* createNonveganPizza() = 0;
};
