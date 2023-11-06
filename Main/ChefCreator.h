/**
* @file ChefCreator.h
* @brief Declaration of the ChefCreator class.
*        This file contains the declaration of the ChefCreator class,
*        which is responsible for creating chefs capable of cooking vegan and non-vegan pizzas.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "PizzaCreator.h"
#include "Chef.h"

/**
* @class ChefCreator
* @brief Represents a creator class responsible for creating chefs capable of cooking pizzas.
*/
class ChefCreator {
public:
    /**
    * @brief Creates a Chef object for cooking vegan pizzas.
    * @return A pointer to the Chef object for cooking vegan pizzas.
    */
    virtual Chef* createVeganPizza() = 0;

    /**
    * @brief Creates a Chef object for cooking non-vegan pizzas.
    * @return A pointer to the Chef object for cooking non-vegan pizzas.
    */
    virtual Chef* createNonveganPizza() = 0;

    /**
    * @brief Virtual destructor for the ChefCreator class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    virtual ~ChefCreator() = default;
};
