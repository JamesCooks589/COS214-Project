#include "Bill.h"
#include <iostream>

Bill::Bill(int orderId) : orderId(orderId), totalAmount(0.0) {
    // Retrieve OrderMemento from Caretaker
    try {
        OrderMemento orderMemento = Caretaker::getInstance().getMemento(orderId);
        std::vector<std::vector<std::string>> customerOrders = orderMemento.getCustomerOrders();
        
        for (const auto& order : customerOrders) {
            for (const auto& orderItem : order) {
                foodItems.push_back(orderItem);
            }
        }
    } catch (const std::runtime_error& e) {
        // Re-throw the exception after handling it
        throw; // Re-throws the caught exception, preserving its type and message
    }
}

void Bill::calculateTotalAmount() {
    totalAmount = 50; // Base cost
    for (const auto& itemName : foodItems) {
        Ingredient* ingredient = IngredientFactory::getIngredient(itemName, 0.0); // Get ingredient with price 0.0
        totalAmount += ingredient->getPrice();
    }
}

void Bill::printBill() {
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Food Items:" << std::endl;
    
    for (const auto& itemName : foodItems) {
        Ingredient* ingredient = IngredientFactory::getIngredient(itemName, 0.0); // Get ingredient with price 0.0
        std::cout << "- " << ingredient->getName() << " (R" << ingredient->getPrice() << ")" << std::endl;
    }
    std::cout << "Total Amount: R" << totalAmount << std::endl;
}
