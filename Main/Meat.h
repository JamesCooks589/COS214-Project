/**
* @file Meat.h
* @brief Declaration of the Meat class.
*        This file contains the declaration of the Meat class,
*        which represents a type of non-vegan food derived from Nonvegan class.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "Nonvegan.h"
#include <vector>
#include <string>

/**
* @class Meat
* @brief Represents a type of non-vegan food derived from Nonvegan class.
*/
class Meat : public Nonvegan {
public:
    /**
    * @brief Default constructor for the Meat class.
    * Initializes a new instance of Meat with default values.
    */
    Meat();

    /**
    * @brief Cooks the food based on the provided order details and plate.
    * @param orderDetails The details of the food order.
    * @param plate Pointer to the Plate object where the cooked food is placed.
    * Cooks the Meat-based food using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate) override;
};
