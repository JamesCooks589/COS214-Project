#include "Order.h"

Order::Order(int tableNumber) {
    tableNumber_ = tableNumber;
}

// Method to print order details
void Order::printOrder() {
    cout << "Order from Table " << tableNumber_ << ":\n";
    for (string food : orderDetails_){
        cout << food << endl;
    }
}