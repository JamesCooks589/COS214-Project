/**
* @file BaseChef.h
* @brief Declaration of the BaseChef class.
*        This file contains the declaration of the BaseChef class,
*        which is a subclass of ChefCreator and defines functions to
*        create vegan and non-vegan pizzas.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "ChefCreator.h"

/**
* @class BaseChef
* @brief Represents a base chef class that creates vegan and non-vegan pizzas.
*        This class is a subclass of ChefCreator.
*/
class BaseChef : public ChefCreator {
public:
    /**
    * @brief Creates a new instance of Chef for a vegan pizza.
    * @return A pointer to the Chef object for a vegan pizza.
    */
    virtual Chef* createVeganPizza() override;

    /**
    * @brief Creates a new instance of Chef for a non-vegan pizza.
    * @return A pointer to the Chef object for a non-vegan pizza.
    */
    virtual Chef* createNonveganPizza() override;
};
