/**
 * @file ToppingChef.cpp
 * @brief Implementation file for the ToppingChef class.
 *        This file contains the implementation of methods to create different types of pizzas.
 * @author [Author Name]
 * @date [Creation Date]
 */

#include "ToppingChef.h"
#include "Veggies.h"
#include "Meat.h"

/**
 * @brief Create a vegan pizza with vegetable toppings.
 * @return A pointer to a Chef object representing a vegan pizza.
 */
Chef* ToppingChef::createVeganPizza() {
    return new Veggies();
}

/**
 * @brief Create a non-vegan pizza with meat toppings.
 * @return A pointer to a Chef object representing a non-vegan pizza.
 */
Chef* ToppingChef::createNonveganPizza() {
    return new Meat();
}
