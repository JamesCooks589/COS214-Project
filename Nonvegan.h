#pragma once
#include "PizzaCreator.h"

class Nonvegan : public PizzaCreator {
public:
    void createPizza() const override;
};
