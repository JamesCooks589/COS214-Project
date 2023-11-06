/**
 * @file OrderMemento.cpp
 * @brief Implementation file for the OrderMemento class.
 *        This file contains the implementation of methods to handle order mementos.
 * @author Quintin d'Hotman de Villiers
 * @date 2023/10/20
 */

#include "OrderMemento.h"

/**
 * @brief Constructor for the OrderMemento class.
 * @param tableNumber The table number associated with the order.
 * @param customerOrders A vector containing customer-wise order details.
 */
OrderMemento::OrderMemento(int tableNumber, std::vector<std::vector<std::string>> customerOrders/*, std::string orderDetails*/)
    : tableNumber(tableNumber), customerOrders(customerOrders)/*, orderDetails(orderDetails)*/ {}

/**
 * @brief Gets the table number stored in the memento.
 * @return The table number associated with the order.
 */
int OrderMemento::getTableNumber() const {
    return tableNumber;
}

/**
 * @brief Gets the customer-wise order details stored in the memento.
 * @return A vector containing customer-wise order details.
 */
std::vector<std::vector<std::string>> OrderMemento::getCustomerOrders() const {
    return customerOrders;
}

/*std::string OrderMemento::getOrderDetails() const {
    return orderDetails;
}*/
