/**
* @file Nonvegan.h
* @brief Declaration of the Nonvegan class.
*        This file contains the declaration of the Nonvegan class,
*        which represents a type of pizza creator for non-vegan pizzas.
* @author Yi-Rou Hung
* @date 23/10/2023
*/

#pragma once
#include "PizzaCreator.h"

using namespace std;

/**
* @class Nonvegan
* @brief Represents a type of pizza creator for non-vegan pizzas.
*/
class Nonvegan : public PizzaCreator {
public:
    /**
    * @brief Default constructor for the Nonvegan class.
    * Initializes a new instance of Nonvegan with default values.
    */
    Nonvegan() {}

    /**
    * @brief Cooks the non-vegan pizza based on the provided order details and plate.
    * @param orderDetails The details of the pizza order.
    * @param plate Pointer to the Plate object where the cooked pizza is placed.
    * Cooks the non-vegan pizza using the provided order details and places it on the plate.
    */
    virtual void cookFood(vector<string> orderDetails, Plate* plate) {}
};
