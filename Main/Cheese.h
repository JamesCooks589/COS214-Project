/**
* @file Cheese.h
* @brief Declaration of the Cheese class.
*        This file contains the declaration of the Cheese class,
*        which represents a type of non-vegan food and inherits from Nonvegan class.
* @author James Cooks and Monica Hung
* @date 22/10/2023
*/

#pragma once
#include "Nonvegan.h"

/**
* @class Cheese
* @brief Represents a type of non-vegan food derived from Nonvegan class.
*/
class Cheese : public Nonvegan {
public:
    /**
    * @brief Default constructor for the Cheese class.
    * Initializes a new instance of Cheese with default values.
    */
    Cheese();

    /**
    * @brief Cooks the food based on the provided order details and plate.
    * @param orderDetails The details of the food order.
    * @param plate Pointer to the Plate object where the cooked food is placed.
    * Cooks the Cheese-based food using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate) override;
};
