#include <iostream>
#include "FoodItem.h"
#include "CheeseDecorator.h"

//Example main for decorator
int main() {
    Menu* pizza = new FoodItem("Pizza", 5.99);
    std::cout << "Description: " << pizza->getDescription() << ", Cost: $" << pizza->getCost() << std::endl;

    Menu* veganPizza = new CheeseDecorator(pizza);
    std::cout << "Description: " << veganPizza->getDescription() << ", Cost: $" << veganPizza->getCost() << std::endl;

    delete pizza;
    delete veganPizza;

    return 0;
}
