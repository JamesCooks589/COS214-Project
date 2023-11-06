/**
* @file Waiter.h
* @brief Declaration of the Waiter class.
*        This file contains the declaration of the Waiter class,
*        which represents a waiter in the restaurant derived from PrototypeWaiter.
* @author Carter Shin
* @date 1 November 2023
*/

#pragma once
#include <memory>
#include "Order.h"
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include <vector>
#include <iostream>

using namespace std;
// class Waiter;
class CustomerComponent;
class Kitchen;
class Floor;

/**
* @class PrototypeWaiter
* @brief Represents a prototype waiter interface with clone and signal methods.
*/
class PrototypeWaiter {
public:
    /**
    * @brief Creates a clone of the prototype waiter.
    * @return Pointer to the cloned PrototypeWaiter object.
    */
    virtual PrototypeWaiter* clone() = 0;

    /**
    * @brief Sets the name of the waiter.
    * @param name The name of the waiter.
    */
    virtual void setName(string name) = 0;

    /**
    * @brief Gets the name of the waiter.
    * @return The name of the waiter.
    */
    virtual string getName() = 0;

    /**
    * @brief Notifies the waiter about a customer's order.
    * @param customer Pointer to the CustomerComponent object placing the order.
    */
    virtual void orderSignal(CustomerComponent* customer) = 0;

    /**
    * @brief Notifies the waiter to generate a bill for a customer.
    * @param customer Pointer to the CustomerComponent object for billing.
    */
    virtual void billSignal(CustomerComponent* customer) = 0;

    /**
    * @brief Notifies the waiter that an order is ready to be served.
    */
    virtual void signalReadyOrder() = 0;

    /**
    * @brief Destructor for the PrototypeWaiter class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    virtual ~PrototypeWaiter(){}
};

/**
* @class Waiter
* @brief Represents a waiter in the restaurant derived from PrototypeWaiter.
*/
class Waiter : public PrototypeWaiter{
private:
    // Menu* menu;
    Kitchen* kitchen; ///< Pointer to the Kitchen object for processing orders.
    vector<Plate*> plates; ///< Vector of pointers to Plate objects representing orders served by the waiter.
    string name; ///< The name of the waiter.
    Floor* floor; ///< Pointer to the Floor object representing the restaurant floor plan.

public:
    /**
    * @brief Constructor for the Waiter class.
    * @param kitchen Pointer to the Kitchen object for processing orders.
    * @param name The name of the waiter.
    * @param floor Pointer to the Floor object representing the restaurant floor plan.
    * Initializes a new instance of Waiter with the given kitchen, name, and floor.
    */
    Waiter(Kitchen* kitchen, string name, Floor* floor);

    /**
    * @brief Creates a clone of the waiter.
    * @return Pointer to the cloned Waiter object.
    */
    PrototypeWaiter* clone();

    /**
    * @brief Sets the name of the waiter.
    * @param name The name of the waiter.
    */
    void setName(string name);

    /**
    * @brief Gets the name of the waiter.
    * @return The name of the waiter.
    */
    string getName();

    /**
    * @brief Notifies the waiter about a customer's order.
    * @param customer Pointer to the CustomerComponent object placing the order.
    */
    void orderSignal(CustomerComponent* customer);

    /**
    * @brief Notifies the waiter to generate a bill for a customer.
    * @param customer Pointer to the CustomerComponent object for billing.
    */
    void billSignal(CustomerComponent* customer);

    /**
    * @brief Notifies the waiter that an order is ready to be served.
    */
    void signalReadyOrder();

    /**
    * @brief Destructor for the Waiter class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~Waiter() {}
    //void deliverOrder(Plate* p);
};
