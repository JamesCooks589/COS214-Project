#pragma once

#include "Nonvegan.h"

class Cheese : public Nonvegan{
public:
    Cheese();
    virtual void cookFood(vector<string> orderDetails, Plate* plate) override;
};
