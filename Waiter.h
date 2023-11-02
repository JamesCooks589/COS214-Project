#ifndef WAITER_H
#define WAITER_H

#include <memory>
#include "Menu.h"
#include "Order.h"
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include <vector>

class Waiter;

class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() = 0;
};

class Waiter : public Prototype{
private:
    Menu* menu;
    Kitchen* kitchen;
    std::vector<Plate*> plates;

public:
    Waiter(Menu* menu, Kitchen* kitchen);
    std::unique_ptr<Prototype> clone();
    void update(std::string message);
    void orderSignal(CustomerComponent* customer);
    void billSignal(CustomerComponent* customer);
    void deliverOrder(Plate* p);
};

#endif