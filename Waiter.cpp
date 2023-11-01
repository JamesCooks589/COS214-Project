#include "Waiter.h"
#include "Menu.h" 
#include "Order.h" 
#include "Kitchen.h"

Waiter::Waiter(std::shared_ptr<Mediator> mediator, Menu* menu, Kitchen* kitchen) : mediator(mediator), menu(menu), kitchen(kitchen) {}

std::unique_ptr<Prototype> Waiter::clone() {
    return std::make_unique<Waiter>(mediator, menu, kitchen);
}

void Waiter::update(std::string message) {
    if(message == "customer ready to order") {
        orderSignal();
    } else if(message == "deliver bill") {
        billSignal();
    } else if(message == "food ready") {
        deliverOrder();
    }
}

void Waiter::orderSignal(int tableID, Order* order) {
    std::cout << "Waiter " << this << ": Received signal to take order from table " << tableID << "." << std::endl;

    tableOrders[tableID] = order;
    kitchen->setOrder(order);
    mediator->communicate("take order", this);
}

void Waiter::billSignal(int tableID) {
    std::cout << "Waiter " << this << ": Received signal to deliver bill to table " << tableID << "." << std::endl;
    
    mediator->communicate("deliver bill", this);
}

void Waiter::deliverOrder(int orderID) {
    int tableID = -1;
    for (const auto& pair : tableOrders) {
        if (pair.second->getOrderID() == orderID) { 
            tableID = pair.first;
            break;
        }
    }

    if (tableID != -1) {
        std::cout << "Waiter " << this << ": Delivering order " << orderID << " to table " << tableID << "." << std::endl;
        
        mediator->communicate("deliver food", this);
    } else {
        std::cout << "Error: Order not found." << std::endl;
    }
}