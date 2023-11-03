#pragma once

#include "Vegan.h"

class Veggies: public Vegan{
public:
    Veggies();
    virtual void cookFood(vector<string> orderDetails, Plate* plate);
};
