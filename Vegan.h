#pragma once
#include "PizzaCreator.h"

class Vegan : public PizzaCreator {
public:
    void createPizza() const override;
};
