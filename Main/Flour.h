/**
* @file Flour.h
* @brief Declaration of the Flour class.
*        This file contains the declaration of the Flour class,
*        which represents a type of vegan food derived from Vegan class.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "Vegan.h"
#include <vector>
#include <string>

/**
* @class Flour
* @brief Represents a type of vegan food derived from Vegan class.
*/
class Flour : public Vegan {
public:
    /**
    * @brief Default constructor for the Flour class.
    * Initializes a new instance of Flour with default values.
    */
    Flour();

    /**
    * @brief Cooks the food based on the provided order details and plate.
    * @param orderDetails The details of the food order.
    * @param plate Pointer to the Plate object where the cooked food is placed.
    * Cooks the Flour-based food using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate) override;
};
