/**
* @file Customer.h
* @brief Declaration of the Customer class.
*        This file contains the declaration of the Customer class,
*        which represents a customer and inherits from CustomerComponent.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "CustomerComponent.h"
#include <string>
#include <random>

/**
* @class Customer
* @brief Represents a customer inheriting from CustomerComponent.
*/
class Customer : public CustomerComponent {
private:
    std::string name; ///< The name of the customer.
    int happiness = 100; ///< The happiness level of the customer.
public:
    /**
    * @brief Constructor for the Customer class.
    * @param name The name of the customer.
    * @param id The unique identifier for the customer.
    * Initializes a new instance of Customer with the given name and ID.
    */
    Customer(std::string name, int id);

    /**
    * @brief Gets the size of the customer.
    * @return The size of the customer.
    */
    int getSize();

    /**
    * @brief Gets the order for the customer.
    * @return Pointer to the Order object for the customer.
    */
    Order* getOrder();

    /**
    * @brief Gives a plate to the customer.
    * @param plate Pointer to the Plate object to be given to the customer.
    */
    void givePlate(Plate* plate);

    /**
    * @brief Gets the name of the customer.
    * @return The name of the customer.
    */
    std::string getName();

    /**
    * @brief Sets the table ID for the customer.
    * @param id The table ID to be set for the customer.
    */
    void setTableID(int id);

    /**
    * @brief Gets the happiness level of the customer.
    * @return The happiness level of the customer.
    */
    int getHappiness();

    /**
    * @brief Pays the bill for the customer.
    * @param amount The amount to be paid.
    * @param split Flag indicating whether the bill is split or not.
    */
    void payBill(double amount, bool split);

    /**
    * @brief Simulates a visit from the chef.
    */
    void chefVisit();
};
