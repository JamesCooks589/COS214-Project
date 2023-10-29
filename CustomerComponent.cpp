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
    this->waiter->orderSignal();
}

void CustomerComponent::signalForBill(){
    this->waiter->billSignal();
}

CustomerComponent::~CustomerComponent(){
    // Waiter deletion to be done upon restaurant destruction
}