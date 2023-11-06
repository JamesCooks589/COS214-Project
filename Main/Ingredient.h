/**
* @file Ingredient.h
* @brief Declaration of the Ingredient class.
*        This file contains the declaration of the Ingredient class,
*        which represents an ingredient used in food preparation.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include <string>

/**
* @class Ingredient
* @brief Represents an ingredient used in food preparation.
*/
class Ingredient {
public:
    /**
    * @brief Constructor for the Ingredient class.
    * @param name The name of the ingredient.
    * @param price The price of the ingredient.
    * Initializes a new instance of Ingredient with the given name and price.
    */
    Ingredient(const std::string& name, double price);

    /**
    * @brief Gets the name of the ingredient.
    * @return The name of the ingredient.
    */
    const std::string& getName() const;

    /**
    * @brief Gets the price of the ingredient.
    * @return The price of the ingredient.
    */
    double getPrice() const;

private:
    std::string name; ///< The name of the ingredient.
    double price; ///< The price of the ingredient.
};
