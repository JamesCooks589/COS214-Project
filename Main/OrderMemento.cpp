/**
 * @file OrderMemento.cpp
 * @brief Implementation file for the OrderMemento class.
 *        This file contains the implementation of methods to handle order mementos.
 * @author Quintin d'Hotman de Villiers
 * @date 2023/10/20
 */

#include "OrderMemento.h"

OrderMemento::OrderMemento(int tableNumber, std::vector<std::vector<std::string>> customerOrders/*, std::string orderDetails*/)
    : tableNumber(tableNumber), customerOrders(customerOrders)/*, orderDetails(orderDetails)*/ {}

int OrderMemento::getTableNumber() const {
    return tableNumber;
}

std::vector<std::vector<std::string>> OrderMemento::getCustomerOrders() const {
    return customerOrders;
}

/*std::string OrderMemento::getOrderDetails() const {
    return orderDetails;
}*/
