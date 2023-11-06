/**
 * @file: TableComponent.cpp
 * @author Lloyd Creighton
 * @date 28 October 2023
 * @brief: Implementation file for the TableComponent class. Contains the member function definitions.
 */

#include "TableComponent.h"
#include <iostream>

/*
 * Constructor: TableComponent::TableComponent
 * Description: Initializes a TableComponent object with the given ID.
 * Parameters: int id - ID of the table component.
 * Return value: None
 * Exceptions: None
 */
TableComponent::TableComponent(int id){
    this->id = id;
}

/*
 * Function: TableComponent::getID
 * Description: Returns the ID of the table component.
 * Parameters: None
 * Return value: An integer representing the ID of the table component.
 * Exceptions: None
 */
int TableComponent::getID(){
    return id;
}

/*
 * Function: TableComponent::isOccupied
 * Description: Checks if the table component is occupied.
 * Parameters: None
 * Return value: A boolean indicating whether the table component is occupied or not.
 * Exceptions: None
 */
bool TableComponent::isOccupied(){
    return occupied;
}

/*
 * Function: TableComponent::occupy
 * Description: Occupies the table component with the given CustomerComponent if it is unoccupied and within capacity.
 * Parameters: CustomerComponent* Customers - Pointer to the CustomerComponent to be assigned to the table.
 * Return value: None
 * Exceptions: None
 */
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

/*
 * Function: TableComponent::vacate
 * Description: Vacates the table component, returning the occupied CustomerComponent.
 * Parameters: None
 * Return value: A pointer to the vacated CustomerComponent, or nullptr if the table was unoccupied.
 * Exceptions: None
 */
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

/*
 * Destructor: TableComponent::~TableComponent
 * Description: Destroys the TableComponent object, releasing memory occupied by the CustomerComponent if present.
 * Parameters: None
 * Return value: None
 * Exceptions: None
 */
TableComponent::~TableComponent(){
    if(Customers != nullptr){
        delete Customers;
    }
}

/*
 * Function: TableComponent::getCustomers
 * Description: Returns the CustomerComponent currently occupying the table component.
 * Parameters: None
 * Return value: A pointer to the CustomerComponent occupying the table component.
 * Exceptions: None
 */
CustomerComponent* TableComponent::getCustomers(){
    return this->Customers;
}

/*
 * Function: TableComponent::addToGroup
 * Description: Adds another table component to the group. Not supported in this implementation.
 * Parameters: TableComponent* tableToAdd - Pointer to the table component to be added to the group.
 * Return value: None
 * Exceptions: None
 */
void TableComponent::addToGroup(TableComponent* tableToAdd){
    std::cout << "Not supported" << std::endl;
}

/*
 * Function: TableComponent::removeFromGroup
 * Description: Removes the table component from the group. Not supported in this implementation.
 * Parameters: None
 * Return value: None
 * Exceptions: None
 */
TableComponent* TableComponent::removeFromGroup(){
    std::cout << "Not supported" << std::endl;
    return nullptr;
}

/*
 * Function: TableComponent::isEmpty
 * Description: Checks if the table component is empty.
 * Parameters: None
 * Return value: A boolean indicating whether the table component is empty or not.
 * Exceptions: None
 */
bool TableComponent::isEmpty(){
    return true;
}

/*
 * Function: TableComponent::splitGroup
 * Description: Splits the group of table components. Not supported in this implementation.
 * Parameters: None
 * Return value: A vector of pointers to table components representing the split group.
 * Exceptions: None
 */
vector<TableComponent*> TableComponent::splitGroup(){
    std::cout << "Not supported" << std::endl;
    return vector<TableComponent*>();
}