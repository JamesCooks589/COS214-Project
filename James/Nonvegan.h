#pragma once
#include "PizzaCreator.h"

class Nonvegan : public PizzaCreator {
public:
    Nonvegan() {}
    virtual void cookFood(vector<string> orderDetails, Plate* plate) {}
};
