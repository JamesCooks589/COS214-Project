#pragma once
#include "ChefCreator.h"


class BaseChef : public ChefCreator {
public:
    Chef* createVeganPizza() override;
    Chef* createNonveganPizza() override;
    
};
