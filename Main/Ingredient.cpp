/**
 * @file Ingredient.cpp
 * @brief Implementation file for the Ingredient class.
 *        This file contains the implementation of the Ingredient class methods for managing ingredients in a restaurant menu.
 * @author Quintin d'Hotman de Villiers
 * @date 2023/10/30
 */

#include "Ingredient.h"

/**
 * @brief Constructor for the Ingredient class.
 * @param name The name of the ingredient.
 * @param price The price of the ingredient.
 */
Ingredient::Ingredient(const std::string& name, double price) : name(name), price(price) {}

/**
 * @brief Gets the name of the ingredient.
 * @return The name of the ingredient.
 */
const std::string& Ingredient::getName() const {
    return name;
}

/**
 * @brief Gets the price of the ingredient.
 * @return The price of the ingredient.
 */
double Ingredient::getPrice() const {
    return price;
}

