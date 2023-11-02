#pragma once
#include <string>
#include <unordered_map>
#include "Ingredient.h"

class IngredientFactory {
public:
    static Ingredient* getIngredient(const std::string& name, double price);
    static size_t getIngredientCount();
    static void cleanup();

private:
    static std::unordered_map<std::string, Ingredient*> ingredientPool;
};
