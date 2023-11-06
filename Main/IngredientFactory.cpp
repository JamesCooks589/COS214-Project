/**
 * @file IngredientFactory.cpp
 * @brief Implementation file for the IngredientFactory class.
 *        This file contains the implementation of methods to create and manage ingredients using the IngredientFactory class.
 * @author Quintin d'Hotman de Villiers
 * @date 2023/10/30
 */

#include "IngredientFactory.h"

// Static member initialization
std::unordered_map<std::string, Ingredient*> IngredientFactory::ingredientPool;

/**
 * @brief Gets an ingredient from the ingredient pool.
 *        If the ingredient with the given name is not in the pool, creates a new one and adds it to the pool.
 * @param name The name of the ingredient.
 * @param price The price of the ingredient.
 * @return A pointer to the Ingredient object.
 */
Ingredient* IngredientFactory::getIngredient(const std::string& name, double price) {
    if (ingredientPool.find(name) == ingredientPool.end()) {
        // If the ingredient is not in the pool, create a new one and add it to the pool
        ingredientPool[name] = new Ingredient(name, price);
    }
    return ingredientPool[name];
}

/**
 * @brief Gets the total count of unique ingredients in the ingredient pool.
 * @return The total count of unique ingredients.
 */
size_t IngredientFactory::getIngredientCount() {
    return ingredientPool.size();
}

/**
 * @brief Cleans up the ingredient pool by deleting all created Ingredient objects.
 *        This function should be called when the application is shutting down to prevent memory leaks.
 */
void IngredientFactory::cleanup() {
    for (auto& pair : ingredientPool) {
        delete pair.second; // Delete all created ingredients
    }
    ingredientPool.clear(); // Clear the ingredient pool
}