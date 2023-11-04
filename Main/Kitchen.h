#pragma once

#include "BaseChef.h"
#include "ToppingChef.h"
#include "Order.h"
#include "Waiter.h"

//Forward declaration of waiter
class PrototypeWaiter;

class Floor;

class Kitchen
{
private:
    ChefCreator* baseChefFactory;
    ChefCreator* toppingChefFactory;
    Chef* chefChain;
    Order* order;
    vector<Plate*> plates;
    Floor* floor = nullptr;
public:
    Kitchen();
    ~Kitchen();
    void setOrder(Order* order, PrototypeWaiter* waiter);
    void setFloor(Floor* floor);
    vector<Plate*> getPlates();
    vector<string> splitOrder(int currentRow);
    void createPlates();
    void letChefVisitTable();
};

