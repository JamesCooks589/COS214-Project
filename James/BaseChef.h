#pragma once
#include "ChefCreator.h"

class BaseChef : public ChefCreator {
public:
    virtual Chef* createVeganPizza() override;
    virtual Chef* createNonveganPizza() override;
    
};
