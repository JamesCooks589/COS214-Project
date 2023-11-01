#include "Waiter.h"
#include "Menu.h" //do we have a menu class idk?
#include "Order.h"

Waiter::Waiter(std::shared_ptr<Mediator> mediator, Menu* menu) : mediator(mediator), menu(menu) {}

std::unique_ptr<Prototype> Waiter::clone(){
    return std::make_unique<Waiter>(mediator, menu);
}

void Waiter::update(std::string message){
    //do we update the waiter and what the waiter needs to do with a message?
}

void Waiter::orderSignal(int tableID, Order* order){
    std::cout << "Waiter " << this << ": Received signal to take order from table " << tableID << "." << std::endl;
    
    //once the order has been made we save an order ID that is tied with the respective table it is getting the order from
    
    //save the order ID with the corresponding table ID
    tableOrders[tableID] = order; 

    mediator->communicate("take order", this); //using the mediator to communicate that the order has been taken
}

void Waiter::billSignal(int tableID){
    std::cout << "Waiter " << this << ": Received signal to deliver bill to table " << tableID << "." << std::endl;
    
    //delivering the bill to the corresponding table ID
    
    mediator->communicate("deliver bill", this);
}

void Waiter::deliverOrder(int orderID){
    //using the table ID we take the corresponding order to the respective table ID
    int tableID = -1;
    for (const auto& pair : tableOrders){
        if (pair.second->getOrderID == orderID){ //assuming getOrder exists in the order class
            tableID = pair.first;
            break;
        }
    }

    if (tableID != -1){
        std::cout << "Waiter " << this << ": Delivering order " << orderID << " to table " << tableID << "." << std::endl;
        //delivering the order
        
        //update the status to 'delivered' or 'finished'
        //...
        
        mediator->communicate("deliver food", this);
    } else {
        std::cout << "Error: Order not found." << std::endl;
    }
}

void ConcreteMediator::setWaiter(Waiter* waiter){ 
    this->waiter = waiter; 
}

void ConcreteMediator::communicate(std::string message, Waiter* waiter){
    if(message == "take order"){
        //Pass the order from customer to kitchen
    } 
    else if(message == "deliver bill"){
        //Deliver the bill to customer
    }
}
