/**
 * @file IngredientFactory.cpp
 * @brief Implementation file for the IngredientFactory class.
 *        This file contains the implementation of methods to create and manage ingredients using the IngredientFactory class.
 * @author [Author Name]
 * @date [Creation Date]
 */

#include "IngredientFactory.h"

std::unordered_map<std::string, Ingredient*> IngredientFactory::ingredientPool;

Ingredient* IngredientFactory::getIngredient(const std::string& name, double price) {
    if (ingredientPool.find(name) == ingredientPool.end()) {
        // If the ingredient is not in the pool, create a new one and add it to the pool
        ingredientPool[name] = new Ingredient(name, price);
    }
    return ingredientPool[name];
}

size_t IngredientFactory::getIngredientCount() {
    return ingredientPool.size();
}

void IngredientFactory::cleanup() {
    for (auto& pair : ingredientPool) {
        delete pair.second; // Delete all created ingredients
    }
    ingredientPool.clear(); // Clear the ingredient pool
}