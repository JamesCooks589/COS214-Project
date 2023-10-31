#pragma once
#include "PizzaCreator.h"

class Vegan : public PizzaCreator {
public:
    Vegan() {}
    virtual void cookFood(vector<string> orderDetails, Plate* plate) {}
};
