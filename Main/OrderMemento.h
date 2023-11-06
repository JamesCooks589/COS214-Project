/**
* @file OrderMemento.h
* @brief Declaration of the OrderMemento class.
*        This file contains the declaration of the OrderMemento class,
*        which represents a memento containing the state of a customer order.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include <vector>
#include <string>

/**
* @class OrderMemento
* @brief Represents a memento containing the state of a customer order.
*/
class OrderMemento {
public:
    /**
    * @brief Constructor for the OrderMemento class.
    * @param tableNumber The table number associated with the order.
    * @param customerOrders Vector of vectors representing the items in the order.
    * Initializes a new instance of OrderMemento with the given table number and customer orders.
    */
    OrderMemento(int tableNumber, std::vector<std::vector<std::string>> customerOrders);

    /**
    * @brief Gets the table number associated with the order memento.
    * @return The table number of the order memento.
    */
    int getTableNumber() const;

    /**
    * @brief Gets the vector of vectors representing customer orders in the order memento.
    * @return Vector of vectors containing customer order details in the order memento.
    */
    std::vector<std::vector<std::string>> getCustomerOrders() const;

    // Uncomment the following lines if getOrderDetails() method needs to be implemented.
    // /**
    // * @brief Gets the order details as a formatted string from the order memento.
    // * @return Formatted string containing order details from the order memento.
    // */
    // std::string getOrderDetails() const;

private:
    int tableNumber; ///< The table number associated with the order memento.
    std::vector<std::vector<std::string>> customerOrders; ///< Vector of vectors representing customer orders in the order memento.
    // Uncomment the following line if orderDetails member variable is added.
    // std::string orderDetails; ///< Formatted string containing order details in the order memento.
};
