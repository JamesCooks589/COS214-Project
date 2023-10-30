#include "OrderMemento.h"

OrderMemento::OrderMemento(int orderId, std::string orderState) : orderId(orderId), orderState(orderState) {}

std::string OrderMemento::getOrderState() const {
    return orderState;
}
