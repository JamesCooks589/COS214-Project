#include "CustomerComponent.h"

CustomerComponent::CustomerComponent(int id){
    this->id = id;
}

int CustomerComponent::getID(){
    return this->id;
}

void CustomerComponent::attachWaiter(PrototypeWaiter* waiter){
    if(waiter != nullptr){
        this->waiter = waiter;
    }
}

void CustomerComponent::detachWaiter(){
    this->waiter = nullptr;
}

void CustomerComponent::signalToOrder(){
    if(this->waiter != nullptr){
        this->waiter->orderSignal(this);
    }
    else{
        std::cout << "WHO ARE YOU TALKING TO?????" << std::endl;
    }
}

void CustomerComponent::signalForBill(){
    if(this->waiter != nullptr){
        this->waiter->billSignal(this);
    }else{
        std::cout << "WHO ARE YOU TALKING TO?????" << std::endl;
    }
}

CustomerComponent::~CustomerComponent(){
    // Waiter deletion to be done upon restaurant destruction
}

int CustomerComponent::getTableID(){
    return tableID;
}

std::string CustomerComponent::getName(){
    return "Not Applicable";
}

void CustomerComponent::addToGroup(CustomerComponent* comp){
    std::cout << "Not Applicable";
}