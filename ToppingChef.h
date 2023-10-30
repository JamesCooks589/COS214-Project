#pragma once
#include "ChefCreator.h"

class ToppingChef : public ChefCreator {
public:
    PizzaCreator* createVeganPizza() override;
    PizzaCreator* createNonveganPizza() override;
};
