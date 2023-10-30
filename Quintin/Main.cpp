#include <iostream>
#include "FoodItem.h"
#include "CheeseDecorator.h"

//Example main for decorator
int main() {
    Menu* burger = new FoodItem("Burger", 5.99);
    std::cout << "Description: " << burger->getDescription() << ", Cost: $" << burger->getCost() << std::endl;

    Menu* cheeseBurger = new CheeseDecorator(burger);
    std::cout << "Description: " << cheeseBurger->getDescription() << ", Cost: $" << cheeseBurger->getCost() << std::endl;

    delete burger;
    delete cheeseBurger;

    return 0;
}
