#include "TableComponent.h"
#include <iostream>

TableComponent::TableComponent(int id){
    this->id = id;
}

int TableComponent::getID(){
    return id;
}

bool TableComponent::isOccupied(){
    return occupied;
}

void TableComponent::occupy(CustomerComponent* Customers){
    if(this->Customers == nullptr && Customers != nullptr){
        if(Customers->getSize() <= this->getCapacity()){
            this->Customers = Customers;
            occupied = true;
            this->Customers->setTableID(this->getID());
        }
        else{
            std::cout << "Customers greater than capacity" << std::endl;
        }
    }
    else{
        std::cout << "Table is occupied" << std::endl;
    }
}

CustomerComponent* TableComponent::vacate(){
    if(Customers == nullptr){
        occupied = false;
        return nullptr;
    }
    CustomerComponent* temp = this->Customers;
    Customers = nullptr;
    occupied = false;
    return temp;
}

TableComponent::~TableComponent(){
    if(Customers != nullptr){
        delete Customers;
    }
}

CustomerComponent* TableComponent::getCustomers(){
    return this->Customers;
}

void TableComponent::addToGroup(TableComponent* tableToAdd){
    std::cout << "Not supported" << std::endl;
}

TableComponent* TableComponent::removeFromGroup(){
    std::cout << "Not supported" << std::endl;
    return nullptr;
}

bool TableComponent::isEmpty(){
    return true;
}

vector<TableComponent*> TableComponent::splitGroup(){
    std::cout << "Not supported" << std::endl;
    return vector<TableComponent*>();
}