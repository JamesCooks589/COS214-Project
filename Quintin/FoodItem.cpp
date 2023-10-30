#include "FoodItem.h"

FoodItem::FoodItem(std::string description, double cost) : description(description), cost(cost) {}

std::string FoodItem::getDescription() const {
    return description;
}

double FoodItem::getCost() const {
    return cost;
}
