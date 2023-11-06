/**
* @file Vegan.h
* @brief Declaration of the Vegan class.
*        This file contains the declaration of the Vegan class,
*        which represents a vegan pizza derived from PizzaCreator.
* @author Yi-Rou Hung
* @date 23/10/2023
*/

#pragma once
#include "PizzaCreator.h"

/**
* @class Vegan
* @brief Represents a vegan pizza derived from PizzaCreator.
*/
class Vegan : public PizzaCreator {
public:
    /**
    * @brief Default constructor for the Vegan class.
    * Initializes a new instance of Vegan with default values.
    */
    Vegan() {}

    /**
    * @brief Cooks the vegan pizza based on the provided order details and plate.
    * @param orderDetails The details of the vegan pizza order.
    * @param plate Pointer to the Plate object where the cooked vegan pizza is placed.
    * Cooks the vegan pizza using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate) {}
};
