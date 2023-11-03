// Flour.h - Header for Flour class
#pragma once

#include "Vegan.h"

class Flour: public Vegan{
public:
    Flour();
    virtual void cookFood(vector<string> orderDetails, Plate* plate);
};
