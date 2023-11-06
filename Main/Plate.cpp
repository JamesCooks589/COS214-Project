/**
 * @file Plate.cpp
 * @brief Implementation file for the Plate class.
 *        This file contains the implementation of methods to handle plate information.
 * @author [Author Name]
 * @date [Creation Date]
 */

#include "Plate.h"

Plate::Plate(int tableID, string customerName){
    //Initialize empty food vector
    this->food = vector<string>();
    this->tableID = tableID;
    this->customerName = customerName;
    
}

//clone function
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

void Plate::addFood(string food){
    //Add food to plate
    this->food.push_back(food);
}

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

string Plate::getCustomerName(){
    return this->customerName;
}

vector<string> Plate::getFood(){
    return food;
}

int Plate::getID(){
    return tableID;
}