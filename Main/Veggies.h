/**
* @file Veggies.h
* @brief Declaration of the Veggies class.
*        This file contains the declaration of the Veggies class,
*        which represents a vegan pizza with vegetables derived from Vegan.
* @author James Cooks and Monica Hung
* @date 22/10/2023
*/

#pragma once
#include "Vegan.h"

/**
* @class Veggies
* @brief Represents a vegan pizza with vegetables derived from Vegan.
*/
class Veggies : public Vegan {
public:
    /**
    * @brief Default constructor for the Veggies class.
    * Initializes a new instance of Veggies with default values.
    */
    Veggies();

    /**
    * @brief Cooks the vegan pizza with vegetables based on the provided order details and plate.
    * @param orderDetails The details of the vegan pizza with vegetables order.
    * @param plate Pointer to the Plate object where the cooked vegan pizza with vegetables is placed.
    * Cooks the vegan pizza with vegetables using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate);
};
