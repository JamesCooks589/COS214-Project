#pragma once
#include "ChefCreator.h"

hey bae :o
class BaseChef : public ChefCreator {
public:
    virtual Chef* createVeganPizza() override;
    virtual Chef* createNonveganPizza() override;
    
};