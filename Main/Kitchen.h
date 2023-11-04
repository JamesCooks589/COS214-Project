#pragma once

#include "BaseChef.h"
#include "ToppingChef.h"
#include "Order.h"
#include "Waiter.h"

//Forward declaration of waiter
class PrototypeWaiter;

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
    void setOrder(Order* order, PrototypeWaiter* waiter);
    vector<Plate*> getPlates();
    vector<string> splitOrder(int currentRow);
    void createPlates();
};

