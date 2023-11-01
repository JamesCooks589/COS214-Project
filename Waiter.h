#ifndef WAITER_H
#define WAITER_H

#include <memory>
#include <map>
#include "Menu.h"
#include "Order.h"
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"

class Waiter;

class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() = 0;
};

class Mediator {
public:
    virtual void communicate(std::string, Waiter*) = 0;
};

class Waiter : public Prototype{
private:
    std::shared_ptr<Mediator> mediator;
    Menu* menu;
    Kitchen* kitchen;
    std::map<int, Order*> tableOrders;

public:
    Waiter(std::shared_ptr<Mediator> mediator, Menu* menu, Kitchen* kitchen);
    std::unique_ptr<Prototype> clone();
    void update(std::string message);
    void orderSignal(CustomerComponent* customer);
    void billSignal(CustomerComponent* customer);
    void deliverOrder(CustomerComponent* customer);
};

#endif