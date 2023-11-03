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

// class Prototype {
// public:
//     virtual std::unique_ptr<Prototype> clone() = 0;
// };

class Waiter{
private:
    // Menu* menu;
    Kitchen* kitchen;
    std::vector<Plate*> plates;
    std::string name;

public:
    Waiter(Kitchen* kitchen, std::string name);
    //std::unique_ptr<Prototype> clone();
    void update(std::string message);
    void orderSignal(CustomerComponent* customer);
    void billSignal(CustomerComponent* customer);
    //void deliverOrder(Plate* p);
};

#endif