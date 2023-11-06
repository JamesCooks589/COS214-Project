/**
 * @file Order.cpp
 * @brief Implementation file for the Order class.
 *        This file contains the implementation of methods to handle restaurant orders.
 * @author [Ze-Lin Zhang]
 * @date [28/10/23]
 */

#include "Order.h"

/**
 * @brief Constructor for the Order class.
 * @param tableNumber The number of the table placing the order.
 * @param customerOrders A vector containing customer-wise order details.
 */
Order::Order(int tableNumber, vector<vector<string>> customerOrders) {
    this->tableNumber = tableNumber;
    this->customerOrders = customerOrders;

    // Check if orderDetails is not empty
    if (!customerOrders.empty()) {
        // Check if orderDetails contains valid ingredients
        for (vector<string> customerOrder : customerOrders) {
            // Check if the customerOrder has valid ingredients
            if (!IsValidOrderDetails(customerOrder)) {
                cout << "Order details invalid\n";
                break;
            }
            //cout << "Order will be processed shortly\n";
        }
    }
    else {
        cout << "Order details is empty\n";
    }
}

/**
 * @brief Checks if the given order details are valid.
 * @param orderDetails A vector containing food items for a customer's order.
 * @return true if all ingredients in orderDetails are valid, false otherwise.
 */
bool Order::IsValidOrderDetails(vector<string> orderDetails) {
    // Define a list of valid ingredients
    vector<string> validIngredients = {"Flour", "Cheese", "Meat", "Veggies"};

    // Skip the first element which is the customer name
    for (size_t i = 1; i < orderDetails.size(); i++) {
        // Trim leading and trailing spaces from the ingredient
        string ingredient = trim(orderDetails[i]);

        // Check if the ingredient is in the list of valid ingredients
        bool isValid = false;
        for (const string& validIngredient : validIngredients) {
            if (ingredient == validIngredient) {
                isValid = true;
                break;
            }
        }

        if (!isValid) {
            // If an invalid ingredient is found, return false
            return false;
        }
    }

    // If all ingredients are valid, return true
    return true;
}

//HELPER

/**
 * @brief Trims leading and trailing spaces from a string.
 * @param str The string to be trimmed.
 * @return The trimmed string.
 */
string Order::trim(const string& str) {
    // Trim leading and trailing spaces from a string
    size_t first = str.find_first_not_of(" \t\n");
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n");
    return str.substr(first, (last - first + 1));
}

/**
 * @brief Prints the order details to the console.
 */
void Order::printOrder() {
     cout << "Order from Table " << tableNumber << ":\n";
    for (std::vector<std::vector<std::string>>::size_type i = 0; i < customerOrders.size(); i++) {
        cout << customerOrders[i][0] <<" ordered: ";
        for (std::vector<std::string>::size_type j = 1; j < customerOrders[i].size(); j++) {
            cout << customerOrders[i][j];
            if(j != customerOrders[i].size() - 1){
                cout << ", ";                
            }
            else{
                cout << endl;
            }
        }
    }
}

/**
 * @brief Gets the table number associated with the order.
 * @return The table number.
 */
int Order::getTableNumber() {
    return tableNumber;
}

/**
 * @brief Gets the customer orders.
 * @return A vector containing customer-wise order details.
 */
vector<vector<string>> Order::getCustomerOrders() {
    return customerOrders;
}

/**
 * @brief Gets the order details.
 * @return A string containing the order details.
 */
string Order::getOrderDetails() {
    return orderDetails;
}

/**
 * @brief Creates a memento of the current order state.
 * @return An OrderMemento object representing the current order state.
 */
OrderMemento Order::createMemento() {
    return OrderMemento(tableNumber, customerOrders);
}

/**
 * @brief Restores the order state from a given memento.
 * @param memento The OrderMemento object containing the desired order state.
 */
void Order::restoreFromMemento(const OrderMemento& memento) {
    tableNumber = memento.getTableNumber();
    customerOrders = memento.getCustomerOrders();
}

