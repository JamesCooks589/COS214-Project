/**
 * @file CustomerComponent.cpp
 * @brief Implementation file for the CustomerComponent class.
 *        This file contains the implementation of methods related to customer components.
 * @author Lloyd Creighton
 * @date 28 October 2023
 */

#include "CustomerComponent.h"
#include <iostream>

/**
 * @brief Constructor for the CustomerComponent class.
 * @param id The unique identifier for the customer component.
 */
CustomerComponent::CustomerComponent(int id){
    this->id = id;
}

/**
 * @brief Gets the unique identifier of the customer component.
 * @return The unique identifier of the customer component.
 */
int CustomerComponent::getID(){
    return this->id;
}

/**
 * @brief Attaches a prototype waiter to the customer component.
 * @param waiter Pointer to the PrototypeWaiter object to be attached.
 */
void CustomerComponent::attachWaiter(PrototypeWaiter* waiter){
    if(waiter != nullptr){
        this->waiter = waiter;
    }
}

/**
 * @brief Detaches the prototype waiter from the customer component.
 */
void CustomerComponent::detachWaiter(){
    this->waiter = nullptr;
}

/**
 * @brief Signals the prototype waiter to take the customer's order.
 *        If no waiter is attached, prints an error message.
 */
void CustomerComponent::signalToOrder(){
    if(this->waiter != nullptr){
        this->waiter->orderSignal(this);
    }
    else{
        std::cout << "WHO ARE YOU TALKING TO?????" << std::endl;
    }
}

/**
 * @brief Signals the prototype waiter to bring the bill to the customer.
 *        If no waiter is attached, prints an error message.
 */
void CustomerComponent::signalForBill(){
    if(this->waiter != nullptr){
        this->waiter->billSignal(this);
    }else{
        std::cout << "WHO ARE YOU TALKING TO?????" << std::endl;
    }
}

/**
 * @brief Destructor for the CustomerComponent class.
 *        Waiter deletion is handled upon restaurant destruction, so no specific cleanup is needed.
 */
CustomerComponent::~CustomerComponent(){
    // Waiter deletion to be done upon restaurant destruction
}

/**
 * @brief Gets the table ID associated with the customer component.
 * @return The table ID of the customer component.
 */
int CustomerComponent::getTableID(){
    return tableID;
}

/**
 * @brief Gets the name of the customer component.
 *        Default implementation returns "Not Applicable".
 * @return The name of the customer component.
 */
std::string CustomerComponent::getName(){
    return "Not Applicable";
}

/**
 * @brief Adds a customer component to a group (not applicable for this class).
 *        Default implementation prints a message indicating inapplicability.
 * @param comp Pointer to the CustomerComponent object to be added to the group.
 */
void CustomerComponent::addToGroup(CustomerComponent* comp){
    std::cout << "Not Applicable";
}