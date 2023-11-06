/**
* @file Order.h
* @brief Declaration of the Order class.
*        This file contains the declaration of the Order class,
*        which represents a customer order in a restaurant.
* @author [Ze-Lin Zhang]
* @date [28/10/23]
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "OrderMemento.h"

using namespace std;

/**
* @class Order
* @brief Represents a customer order in a restaurant.
*/
class Order {
public:
    /**
    * @brief Constructor for the Order class.
    * @param tableNumber The table number associated with the order.
    * @param customerOrders Vector of vectors representing the items in the order.
    * Initializes a new instance of Order with the given table number and customer orders.
    */
    Order(int tableNumber, vector<vector<string>> customerOrders);

    /**
    * @brief Creates a memento for the current order state.
    * @return OrderMemento object representing the current state of the order.
    */
    OrderMemento createMemento();

    /**
    * @brief Restores the order state from a memento.
    * @param memento The OrderMemento object containing the state to be restored.
    */
    void restoreFromMemento(const OrderMemento& memento);

    /**
    * @brief Prints the details of the order.
    */
    void printOrder();

    /**
    * @brief Gets the table number associated with the order.
    * @return The table number of the order.
    */
    int getTableNumber();

    /**
    * @brief Gets the vector of vectors representing customer orders.
    * @return Vector of vectors containing customer order details.
    */
    vector<vector<string>> getCustomerOrders();

    /**
    * @brief Gets the order details as a formatted string.
    * @return Formatted string containing order details.
    */
    string getOrderDetails();

    /**
    * @brief Checks if the customer order details are valid.
    * @param customerOrder Vector of strings representing the customer order.
    * @return True if the order details are valid, false otherwise.
    */
    bool IsValidOrderDetails(vector<string> customerOrder);

    /**
    * @brief Trims leading and trailing whitespace from a string.
    * @param str The input string to be trimmed.
    * @return Trimmed string with leading and trailing whitespace removed.
    */
    string trim(const string& str);

private:
    int tableNumber; ///< The table number associated with the order.
    vector<vector<string>> customerOrders; ///< Vector of vectors representing customer orders.
    string orderDetails; ///< Formatted string containing order details.
};
