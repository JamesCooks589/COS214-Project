/**
 * @file Bill.cpp
 * @brief Implementation file for the Bill class.
 *        This file contains the implementation of methods to manage restaurant bills.
 * @author Ze-Lin Zhang
 * @date 28/10/23
 */

#include "Bill.h"
#include <iostream>

/**
 * @brief Constructor for the Bill class.
 * Retrieves order details from OrderMemento and initializes the Bill object.
 * @param orderId The unique identifier for the order.
 * @throws std::runtime_error if there is an error retrieving order details.
 */
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

/**
 * @brief Calculates the total amount of the bill based on the food items ordered.
 * @return The total amount of the bill.
 */
double Bill::calculateTotalAmount() {
    totalAmount = 50; // Base cost
    for (const auto& itemName : foodItems) {
        Ingredient* ingredient = IngredientFactory::getIngredient(itemName, 0.0); // Get ingredient with price 0.0
        totalAmount += ingredient->getPrice();
    }

    return totalAmount;
}

/**
 * @brief Prints the bill details including order ID, food items, and total amount.
 */
void Bill::printBill() {
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Food Items:" << std::endl;
    
    for (const auto& itemName : foodItems) {
        Ingredient* ingredient = IngredientFactory::getIngredient(itemName, 0.0); // Get ingredient with price 0.0
        std::cout << "- " << ingredient->getName() << " (R" << ingredient->getPrice() << ")" << std::endl;
    }
    std::cout << "Total Amount: R" << totalAmount << std::endl;
}
