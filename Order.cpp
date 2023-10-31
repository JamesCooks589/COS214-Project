#include "Order.h"

Order::Order(int tableNumber, vector<vector<string>> customerOrders, string orderDetails) {
    tableNumber_ = tableNumber;
    customerOrders_ = customerOrders;
    orderDetails_ = orderDetails;
}

// Method to print order details
void Order::printOrder() {
    cout << "Order from Table " << tableNumber_ << ":\n";
    for (size_t i = 0; i < customerOrders_.size(); ++i) {
        cout << "Customer " << i + 1 << " ordered: " << customerOrders_[i][0] << " - " << customerOrders_[i][1] << "\n";
    }
    cout << "Order Details: " << orderDetails_ << "\n";
}

// Method to get table number
int Order::getTableNumber() {
    return tableNumber_;
}

// Method to get customer orders
vector<vector<string>> Order::getCustomerOrders() {
    return customerOrders_;
}

// Method to get order details
string Order::getOrderDetails() {
    return orderDetails_;
}