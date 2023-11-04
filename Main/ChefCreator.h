#pragma once
#include "PizzaCreator.h"
#include "Chef.h"

class ChefCreator {
public:
    virtual Chef* createVeganPizza() = 0;
    virtual Chef* createNonveganPizza() = 0;
    virtual ~ChefCreator() = default;
};
