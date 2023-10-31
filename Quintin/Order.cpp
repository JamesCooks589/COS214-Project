#include "Order.h"
#include <string>
#include <iostream>

Order::Order(int orderId, std::string orderState) : orderId(orderId), orderState(orderState) {}

void Order::setOrderState(std::string state) {
    orderState = state;
}

OrderMemento Order::saveToMemento() {
    return OrderMemento(orderId, orderState);
}

void Order::restoreFromMemento(const OrderMemento& memento) {
    orderState = memento.getOrderState();
}

void Order::printOrder() const {
    std::cout << "Order ID: " << orderId << ", State: " << orderState << std::endl;
}
