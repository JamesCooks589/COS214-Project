#include "CustomerComponent.h"

CustomerComponent::CustomerComponent(int id){
    this->id = id;
}

int CustomerComponent::getID(){
    return this->id;
}

void CustomerComponent::attachWaiter(Waiter* waiter){
    if(waiter != nullptr){
        this->waiter = waiter;
    }
}

void CustomerComponent::detachWaiter(){
    this->waiter = nullptr;
}

void CustomerComponent::signalToOrder(){
    this->waiter->orderSignal(this);
}

void CustomerComponent::signalForBill(){
    this->waiter->billSignal(this);
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