#pragma once

#include "BaseChef.h"
#include "ToppingChef.h"
#include "Order.h"

class Kitchen
{
private:
    ChefCreator* baseChefFactory;
    ChefCreator* toppingChefFactory;
    Chef* chefChain;
    Order* order;
    vector<Plate*> plates;
public:
    Kitchen();
    ~Kitchen();
    void setOrder(Order* order);
    vector<Plate*> getPlates();
    vector<string> splitOrder(int currentRow);
    void createPlates();
};

