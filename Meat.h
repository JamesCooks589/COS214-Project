#pragma once

#include "Nonvegan.h"

class Meat : public Nonvegan{
public:
    Meat();
    virtual void cookFood(vector<string> orderDetails, Plate* plate);
};
