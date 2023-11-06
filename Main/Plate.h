/**
* @file Plate.h
* @brief Declaration of the Plate class.
*        This file contains the declaration of the Plate class,
*        which represents a plate containing food items for a customer order.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
* @class Plate
* @brief Represents a plate containing food items for a customer order.
*/
class Plate
{
private:
    vector<string> food; ///< Vector of strings representing food items on the plate.
    int tableID; ///< The table ID associated with the plate.
    string customerName; ///< The name of the customer associated with the plate.

public:
    /**
    * @brief Constructor for the Plate class.
    * @param tableID The table ID associated with the plate.
    * @param customerName The name of the customer associated with the plate.
    * Initializes a new instance of Plate with the given table ID and customer name.
    */
    Plate(int tableID, string customerName);

    /**
    * @brief Creates a clone of the plate.
    * @return Pointer to the cloned Plate object.
    */
    Plate* clone();

    /**
    * @brief Gets the name of the customer associated with the plate.
    * @return The name of the customer.
    */
    string getCustomerName();

    /**
    * @brief Gets the vector of food items on the plate.
    * @return Vector of strings representing food items.
    */
    vector<string> getFood();

    /**
    * @brief Gets the table ID associated with the plate.
    * @return The table ID.
    */
    int getID();

    /**
    * @brief Adds a food item to the plate.
    * @param food The food item to be added.
    */
    void addFood(string food);

    /**
    * @brief Prints the details of the plate including food items and customer information.
    */
    void printPlate();
};
