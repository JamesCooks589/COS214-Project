#include "CheeseDecorator.h"

CheeseDecorator::CheeseDecorator(Menu* foodItem) : ToppingDecorator(foodItem) {}

std::string CheeseDecorator::getDescription() const {
    return ToppingDecorator::getDescription() + ", Cheese";
}

double CheeseDecorator::getCost() const {
    return ToppingDecorator::getCost() + 1.50; // Cheese costs $1.50
}
