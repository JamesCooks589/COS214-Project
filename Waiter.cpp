#include "Waiter.h"
#include "Menu.h" 
#include "Order.h" 
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"

Waiter::Waiter(std::shared_ptr<Mediator> mediator, Menu* menu, Kitchen* kitchen) : mediator(mediator), menu(menu), kitchen(kitchen) {}

std::unique_ptr<Prototype> Waiter::clone() {
    return std::make_unique<Waiter>(mediator, menu, kitchen);
}

void Waiter::update(std::string message) {
    // implement if we want to update what the waiter should do using an update method with a passed in msg
}

void Waiter::orderSignal(CustomerComponent* customer) {
    std::cout << "Waiter " << this << ": Received signal to take order from table " << customer->getTableID() << "." << std::endl;
    
    Order* order = customer->getOrder();
    tableOrders[customer->getTableID()] = order;

    kitchen->setOrder(order);

    mediator->communicate("take order", this);
}

void Waiter::billSignal(CustomerComponent* customer) {
    std::cout << "Waiter " << this << ": Received signal to deliver bill to table " << customer->getTableID() << "." << std::endl;
    
    Order* order = tableOrders[customer->getTableID()];
    
    if (order != nullptr) {
        Bill bill(order->getTableNumber());
    
        bill.calculateTotalAmount();
        bill.printBill();
    
        mediator->communicate("deliver bill", this);
    } else {
        std::cout << "Error: No order found for this table." << std::endl;
    }
}

void Waiter::deliverOrder(CustomerComponent* customer) {
    Order* order = tableOrders[customer->getTableID()];
    
    if (order != nullptr) {
        std::cout << "Waiter " << this << ": Delivering order to table " << customer->getTableID() << "." << std::endl;
        
        //what should we do once delivered
        
        mediator->communicate("deliver food", this);
    } else {
        std::cout << "Error: No order found for this table." << std::endl;
    }
}
