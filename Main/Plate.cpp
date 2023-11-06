/**
 * @file Plate.cpp
 * @brief Implementation file for the Plate class.
 *        This file contains the implementation of methods to handle plate information.
 * @author James Cooks
 * @date 30/10/2023
 */

#include "Plate.h"

/**
 * @brief Constructor for the Plate class.
 * @param tableID The ID of the table associated with the plate.
 * @param customerName The name of the customer associated with the plate.
 */
Plate::Plate(int tableID, string customerName){
    //Initialize empty food vector
    this->food = vector<string>();
    this->tableID = tableID;
    this->customerName = customerName;
    
}

/**
 * @brief Clone the plate, creating a new plate with the same tableID and customerName.
 * @return A cloned Plate object.
 */
Plate* Plate::clone(){
    //Create new plate with same tableID and customerName
    Plate* newPlate = new Plate(this->tableID, this->customerName);
    //Copy food vector
    for (string food : this->food)
    {
        newPlate->addFood(food);
    }
    return newPlate;
}

/**
 * @brief Add a food item to the plate.
 * @param food The food item to be added to the plate.
 */
void Plate::addFood(string food){
    //Add food to plate
    this->food.push_back(food);
}

/**
 * @brief Print the contents of the plate.
 */
void Plate::printPlate(){
    //Print plate contents
    long unsigned int i = 0;
    cout << "Plate for " << this->customerName << " at table " << this->tableID << ": ";
    for (string food : this->food)
    {        
        //If last item in vector, don't add comma
        if (i == this->food.size() - 1)
        {
            cout << food;
        }
        else
        {
            cout << food << ", ";
        }
        i++;
    }
    cout << endl;
}

/**
 * @brief Get the name of the customer associated with the plate.
 * @return The customer name.
 */
string Plate::getCustomerName(){
    return this->customerName;
}

/**
 * @brief Get the food items on the plate.
 * @return A vector containing food items.
 */
vector<string> Plate::getFood(){
    return food;
}

/**
 * @brief Get the ID of the table associated with the plate.
 * @return The table ID.
 */
int Plate::getID(){
    return tableID;
}
