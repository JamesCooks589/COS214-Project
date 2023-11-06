/**
* @file ToppingChef.h
* @brief Declaration of the ToppingChef class.
*        This file contains the declaration of the ToppingChef class,
*        which represents a chef creator for pizza toppings derived from ChefCreator.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "ChefCreator.h"

/**
* @class ToppingChef
* @brief Represents a chef creator for pizza toppings derived from ChefCreator.
*/
class ToppingChef : public ChefCreator {
public:
    /**
    * @brief Creates a vegan pizza with toppings.
    * @return Pointer to the Chef object representing the created vegan pizza.
    */
    virtual Chef* createVeganPizza() override;

    /**
    * @brief Creates a non-vegan pizza with toppings.
    * @return Pointer to the Chef object representing the created non-vegan pizza.
    */
    virtual Chef* createNonveganPizza() override;
};
