#ifndef WAITER_H
#define WAITER_H

#include <memory>
#include "Order.h"
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include <vector>
#include <iostream>

// class Waiter;
class CustomerComponent;
class Kitchen;
class Floor;

class PrototypeWaiter {
public:
    //Clone method
    public:
        virtual PrototypeWaiter* clone() = 0;
        virtual void setName(std::string name) = 0;
        virtual std::string getName() = 0;
        virtual void orderSignal(CustomerComponent* customer) = 0;
        virtual void billSignal(CustomerComponent* customer) = 0;
        virtual void signalReadyOrder() = 0;
};

class Waiter : public PrototypeWaiter{
private:
    // Menu* menu;
    Kitchen* kitchen;
    std::vector<Plate*> plates;
    std::string name;
    Floor* floor;

public:
    Waiter(Kitchen* kitchen, std::string name, Floor* floor);
    PrototypeWaiter* clone();
    void setName(std::string name);
    std::string getName();
    void orderSignal(CustomerComponent* customer);
    void billSignal(CustomerComponent* customer);
    void signalReadyOrder();
    //void deliverOrder(Plate* p);
};

#endif