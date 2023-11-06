/**
* @file Chef.h
* @brief Declaration of the Chef class.
*        This file contains the declaration of the Chef class,
*        which represents a chef capable of cooking food and handling orders.
* @author James Cooks
* @date 22/10/2023
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Plate.h"

class CustomerComponent; // Forward declaration

/**
* @class Chef
* @brief Represents a chef capable of cooking food and handling orders.
*/
class Chef {
protected:
    Chef* next; ///< Pointer to the next chef in the chain.
public:
    /**
    * @brief Default constructor for the Chef class.
    * Initializes a new instance of Chef with default values.
    */
    Chef();

    /**
    * @brief Virtual destructor for the Chef class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    virtual ~Chef();

    /**
    * @brief Adds a chef to the chain of responsibility.
    * @param chef Pointer to the Chef object to be added.
    */
    void Add(Chef* chef);

    /**
    * @brief Cooks the food based on the provided order details and plate.
    * @param orderDetails The details of the food order.
    * @param plate Pointer to the Plate object where the cooked food is placed.
    * Cooks the food using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate);

    /**
    * @brief Visits a customer component using the visitor pattern.
    * @param visitCandidate Pointer to the CustomerComponent object to be visited.
    * Visits the customer component using the visitor pattern.
    */
    void visit(CustomerComponent* visitCandidate);
};
