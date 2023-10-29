#include "Customer.h"

Customer::Customer(std::string name, int id) : CustomerComponent(id){
    this->name = name;
}

std::string Customer::getName(){
    return this->name;
}

Order* Customer::getOrder(){
    //Stubbed with a dummy value for now
    return new Order();
}

int Customer::getSize(){
    //Size of 1 customer, atomic leaf
    return 1;
}