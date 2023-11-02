#include <iostream>
#include "Order.h"
#include "OrderMemento.h"
#include "Caretaker.h"
#include "Menu.h"
#include "FoodItem.h"
#include "CheeseDecorator.h"

int main() {
    // Create an initial order
    Order order(1, "Pending");
    order.printOrder();

    // Save the initial state to a memento with ID 1
    Caretaker::getInstance().addMemento(1, order.saveToMemento());

    // Update the order state and print
    order.setOrderState("Shipped");
    order.printOrder();

    // Save the updated state to a memento with ID 2
    Caretaker::getInstance().addMemento(2, order.saveToMemento());

    // Restore the initial state and print
    order.restoreFromMemento(Caretaker::getInstance().getMemento(1));
    order.printOrder();

    // Restore the updated state and print
    order.restoreFromMemento(Caretaker::getInstance().getMemento(2));
    order.printOrder();

    // Example for Decorator pattern
    std::cout << "\n--- Decorator Pattern ---" << std::endl;
    Menu* pizza = new FoodItem("Pizza", 5.99);
    std::cout << "Description: " << pizza->getDescription() << ", Cost: $" << pizza->getCost() << std::endl;

    Menu* veganPizza = new CheeseDecorator(pizza);
    std::cout << "Description: " << veganPizza->getDescription() << ", Cost: $" << veganPizza->getCost() << std::endl;

    delete pizza;
    delete veganPizza;

    return 0;
}
