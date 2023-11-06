/**
* @file IngredientFactory.h
* @brief Declaration of the IngredientFactory class.
*        This file contains the declaration of the IngredientFactory class,
*        which represents a factory for creating Ingredient objects.
* @author Quintin d'Hotman de Villiers
* @date 2023/10/30
*/

#pragma once
#include <string>
#include <unordered_map>
#include "Ingredient.h"

/**
* @class IngredientFactory
* @brief Represents a factory for creating Ingredient objects.
*/
class IngredientFactory {
public:
    /**
    * @brief Gets an ingredient object based on the provided name and price.
    * @param name The name of the ingredient.
    * @param price The price of the ingredient.
    * @return Pointer to the Ingredient object created with the given name and price.
    */
    static Ingredient* getIngredient(const std::string& name, double price);

    /**
    * @brief Gets the total count of ingredients in the factory.
    * @return The total count of ingredients in the factory.
    */
    static size_t getIngredientCount();

    /**
    * @brief Cleans up resources and performs necessary cleanup operations.
    */
    static void cleanup();

private:
    static std::unordered_map<std::string, Ingredient*> ingredientPool; ///< Pool of ingredient objects.
};
