/**
* @file PizzaCreator.h
* @brief Declaration of the PizzaCreator class.
*        This file contains the declaration of the PizzaCreator class,
*        which represents a pizza creator derived from the Chef class.
* @author Yi-Rou Hung
* @date 23/10/2023
*/

#pragma once
#include "Chef.h"

/**
* @class PizzaCreator
* @brief Represents a pizza creator derived from the Chef class.
*/
class PizzaCreator : public Chef {
public:
    /**
    * @brief Default constructor for the PizzaCreator class.
    * Initializes a new instance of PizzaCreator with default values.
    */
    PizzaCreator() {}

    /**
    * @brief Cooks the pizza based on the provided order details and plate.
    * @param orderDetails The details of the pizza order.
    * @param plate Pointer to the Plate object where the cooked pizza is placed.
    * Cooks the pizza using the provided order details and places it on the plate.
    */
    virtual void cookFood(std::vector<std::string> orderDetails, Plate* plate) {}
};
