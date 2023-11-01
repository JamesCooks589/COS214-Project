#include <iostream>
#include <memory>
#include <map>

class Mediator;
class Observer;
class Menu;
class Order;
class Kitchen; 

class Prototype {
public:
    virtual std::unique_ptr<Prototype> clone() = 0;
};

class Waiter : public Prototype, public Observer {
private:
    std::shared_ptr<Mediator> mediator;
    std::map<int, Order*> tableOrders; 
    Menu* menu;
    Kitchen* kitchen;
public:
    Waiter(std::shared_ptr<Mediator> mediator, Menu* menu, Kitchen* kitchen);
    std::unique_ptr<Prototype> clone() override;
    void update(std::string message) override;
    void orderSignal(int tableID, Order* order);
    void billSignal(int tableID);
    void deliverOrder(int tableID); 
};

class Mediator{
public:
    virtual void communicate(std::string message, Waiter* waiter) = 0;
};

class ConcreteMediator : public Mediator{
private:
    Waiter* waiter;
public:
    void setWaiter(Waiter* waiter);
    void communicate(std::string message, Waiter* waiter) override;
};

class Observer{
public:
    virtual void update(std::string message) = 0;
};
