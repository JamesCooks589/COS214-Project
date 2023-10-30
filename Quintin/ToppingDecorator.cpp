#include "ToppingDecorator.h"

ToppingDecorator::ToppingDecorator(Menu* foodItem) : foodItem(foodItem) {}

std::string ToppingDecorator::getDescription() const {
    return foodItem->getDescription();
}

double ToppingDecorator::getCost() const {
    return foodItem->getCost();
}
