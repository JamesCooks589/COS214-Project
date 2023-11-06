/**
* @file CustomerGroup.h
* @brief Declaration of the CustomerGroup class.
*        This file contains the declaration of the CustomerGroup class,
*        which represents a group of customers and inherits from CustomerComponent.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "CustomerComponent.h"
#include <vector>

/**
* @class CustomerGroup
* @brief Represents a group of customers inheriting from CustomerComponent.
*/
class CustomerGroup : public CustomerComponent{
private:
    std::vector<CustomerComponent*> customers; ///< Vector containing individual customers in the group.
public:
    /**
    * @brief Constructor for the CustomerGroup class.
    * @param id The unique identifier for the customer group.
    * Initializes a new instance of CustomerGroup with the given ID.
    */
    CustomerGroup(int id);

    /**
    * @brief Destructor for the CustomerGroup class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~CustomerGroup();

    /**
    * @brief Adds an individual customer to the customer group.
    * @param customer Pointer to the CustomerComponent object to be added to the group.
    */
    void addToGroup(CustomerComponent* customer);

    /**
    * @brief Gives a plate to the customer group.
    * @param plate Pointer to the Plate object to be given to the customer group.
    */
    void givePlate(Plate* plate);

    /**
    * @brief Sets the table ID for the customer group.
    * @param id The table ID to be set for the customer group.
    */
    void setTableID(int id);

    /**
    * @brief Gets the overall happiness level of the customer group.
    * @return The average happiness level of the customers in the group.
    */
    int getHappiness();

    /**
    * @brief Gets the overall happiness level of the customer group.
    * @return The average happiness level of the customers in the group.
    */
    Order* getOrder();

    /**
    * @brief Gets the total number of customers in the group.
    * @return The total number of customers in the group.
    */
    int getSize();

    /**
    * @brief Pays the bill for the customer group.
    * @param amount The total amount to be paid.
    * @param split Flag indicating whether the bill is split among customers or not.
    */
    void payBill(double amount, bool split);

    /**
    * @brief Splits the bill among customers based on their individual orders.
    * @param total The total bill amount to be split among customers.
    */
    void split(double total);

    /**
    * @brief Simulates a visit from the chef for the customer group.
    */
    void chefVisit();
};