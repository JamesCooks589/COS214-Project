#include "TableComponent.h"

bool TableComponent::isOccupied(){
    return occupied;
}

void TableComponent::occupy(CustomerComponent* Customers){
    if(Customers != nullptr){
        this->Customers = Customers;
        occupied = true;
    }
}

CustomerComponent* TableComponent::vacate(){
    if(Customers == nullptr){
        occupied = false;
        return nullptr;
    }
    CustomerComponent* temp = Customers;
    Customers = nullptr;
    occupied = false;
    return temp;
}

TableComponent::~TableComponent(){
    if(Customers != nullptr){
        delete Customers;
    }
}