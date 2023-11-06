/**
* @file CustomerComponent.h
* @brief Declaration of the CustomerComponent class.
*        This file contains the declaration of the CustomerComponent class,
*        which represents a component of the customer, such as a customer or a group of customers.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once

#include "Waiter.h"
#include "Order.h"
#include "Plate.h"

class PrototypeWaiter; // Forward declaration

/**
* @class CustomerComponent
* @brief Represents a component of the customer, such as a customer or a group of customers.
*/
class CustomerComponent{
private:
    PrototypeWaiter* waiter = nullptr; ///< Pointer to the PrototypeWaiter object associated with the customer.
    int id; ///< The unique identifier for the customer component.

protected:
    int tableID; ///< The table ID where the customer component is located.
    
public:
    /**
    * @brief Constructor for the CustomerComponent class.
    * @param id The unique identifier for the customer component.
    * Initializes a new instance of CustomerComponent with the given ID.
    */
    CustomerComponent(int id);

    /**
    * @brief Gets the ID of the customer component.
    * @return The ID of the customer component.
    */
    int getID();

    /**
    * @brief Gets the table ID where the customer component is located.
    * @return The table ID where the customer component is located.
    */
    int getTableID();


    /**
    * @brief Pure virtual function to set the table ID for the customer component.
    * @param id The table ID to be set for the customer component.
    */
    virtual void setTableID(int id) = 0;

    /**
    * @brief Pure virtual function to give a plate to the customer component.
    * @param plate Pointer to the Plate object to be given to the customer component.
    */
    virtual void givePlate(Plate* plate) = 0;

    /**
    * @brief Gets the name of the customer component.
    * @return The name of the customer component.
    */
    virtual std::string getName();


    /**
    * @brief Pure virtual function to get the order of the customer component.
    * @return Pointer to the Order object representing the customer's order.
    */
    virtual Order* getOrder() = 0;

    /**
    * @brief Pure virtual function to get the size of the customer component.
    * @return The size of the customer component.
    */
    virtual int getSize() = 0;

    /**
    * @brief Pure virtual function to get the happiness level of the customer component.
    * @return The happiness level of the customer component.
    */
    virtual int getHappiness() = 0;

    /**
    * @brief Attaches a waiter to the customer component.
    * @param waiter Pointer to the PrototypeWaiter object to be attached.
    */
    void attachWaiter(PrototypeWaiter* waiter);

    /**
    * @brief Detaches the waiter from the customer component.
    */
    void detachWaiter();

    /**
    * @brief Signals the waiter to take the order.
    */
    void signalToOrder();

    /**
    * @brief Signals the waiter to bring the bill.
    */
    void signalForBill();

    /**
    * @brief Adds a customer component to the group.
    * @param comp Pointer to the CustomerComponent object to be added to the group.
    */
    virtual void addToGroup(CustomerComponent* comp);

    /**
    * @brief Pays the bill for the customer component.
    * @param amount The amount to be paid.
    * @param split Flag indicating whether the bill is split or not.
    */
    virtual void payBill(double amount, bool split) = 0;

    /**
    * @brief Virtual destructor for the CustomerComponent class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    virtual ~CustomerComponent();

    /**
    * @brief Simulates a visit from the chef.
    */
    virtual void chefVisit() = 0;
};