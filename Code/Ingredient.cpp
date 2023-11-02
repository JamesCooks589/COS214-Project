#include "Ingredient.h"

Ingredient::Ingredient(const std::string& name, double price) : name(name), price(price) {}

const std::string& Ingredient::getName() const {
    return name;
}

double Ingredient::getPrice() const {
    return price;
}

