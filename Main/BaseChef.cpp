/**
* @file ChefFactory.cpp
* @brief Implementation file for the ChefFactory class.
*        This file contains the implementation of functions to create
*        different types of pizzas using the ChefFactory class.
* @author Yi-Rou Hung
* @date 22/10/2023
*/

#include "BaseChef.h"
#include "Veggies.h"
#include "Flour.h"
#include "Cheese.h"
#include "Vegan.h"
#include "Nonvegan.h"

/**
* @brief Creates a new instance of Chef for a vegan pizza.
* @return A pointer to the Chef object for a vegan pizza (Flour object).
*/
Chef* BaseChef::createVeganPizza() {
    return new Flour();
}

/**
* @brief Creates a new instance of Chef for a non-vegan pizza.
* @return A pointer to the Chef object for a non-vegan pizza (Cheese object).
*/
Chef* BaseChef::createNonveganPizza() {
    return new Cheese();
}
