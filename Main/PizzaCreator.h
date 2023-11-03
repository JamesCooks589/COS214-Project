#pragma once

#include "Chef.h"

using namespace std;

class PizzaCreator: public Chef{
public:
    PizzaCreator(){}
    virtual void cookFood(vector<string> orderDetails, Plate* plate){}
};
