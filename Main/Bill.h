/**
* @file Bill.h
* @brief Declaration of the Bill class.
*        This file contains the declaration of the Bill class,
*        which represents a bill for a customer's order,
*        including functions to calculate total amount and print the bill.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once

#include "Caretaker.h"
#include "IngredientFactory.h"
#include <vector>
#include <string>

/**
* @class Bill
* @brief Represents a bill for a customer's order.
*/
class Bill {
public:
    /**
    * @brief Constructor for the Bill class.
    * @param orderId The unique identifier for the order.
    */
    Bill(int orderId);

    /**
    * @brief Calculates the total amount for the bill.
    * @return The total amount for the order.
    */
    double calculateTotalAmount();

    /**
    * @brief Prints the bill with details of food items and total amount.
    */
    void printBill();

private:
    int orderId; ///< The unique identifier for the order.
    std::vector<std::string> foodItems; ///< List of food items in the order.
    double totalAmount; ///< The total amount for the order.
};
