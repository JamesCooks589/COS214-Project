#include "Bill.h"
#include <iostream>

Bill::Bill(int orderId) : orderId(orderId), totalAmount(0.0) {
    OrderMemento orderMemento = Caretaker::getInstance().getMemento(orderId);
    // Assuming getOrderState returns a comma-separated list of food items
    std::string orderState = orderMemento.getOrderState();
    size_t pos = 0;
    while ((pos = orderState.find(',')) != std::string::npos) {
        foodItems.push_back(orderState.substr(0, pos));
        orderState.erase(0, pos + 1);
    }
    foodItems.push_back(orderState);
}

void Bill::calculateTotalAmount() {
    // Assume each food item costs $5.00 for simplicity
    totalAmount = foodItems.size() * 5.0;
}

void Bill::printBill() {
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Food Items:" << std::endl;
    for (const auto& item : foodItems) {
        std::cout << "- " << item << std::endl;
    }
    std::cout << "Total Amount: $" << totalAmount << std::endl;
}
