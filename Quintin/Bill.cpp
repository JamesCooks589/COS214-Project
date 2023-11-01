#include "Bill.h"
#include <iostream>

Bill::Bill(int orderId) : orderId(orderId), totalAmount(0.0) {
    // Retrieve OrderMemento from Caretaker
    OrderMemento orderMemento = Caretaker::getInstance().getMemento(orderId);
    std::vector<std::vector<std::string>> customerOrders = orderMemento.getCustomerOrders();
    
    for (const auto& order : customerOrders) {
        for (const auto& orderItem : order) {
            foodItems.push_back(orderItem);
        }
    }
}

void Bill::calculateTotalAmount() {
    // Assume each food item costs R10.00 for simplicity
    totalAmount = foodItems.size() * 10.0 + 50;
}

void Bill::printBill() {
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "Food Items:" << std::endl;
    for (const auto& item : foodItems) {
        std::cout << "- " << item << std::endl;
    }
    std::cout << "Total Amount: R" << totalAmount << std::endl;
}
