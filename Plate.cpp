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
    newPlate->food = this->food;
    return newPlate;
}


void Plate::addFood(string food){
    //Add food to plate
    this->food.push_back(food);
}

void Plate::printPlate(){
    //Print plate contents
    cout << "Plate for " << this->customerName << " at table " << this->tableID << ": ";
    for (string food : this->food)
    {
        //If last item in vector, don't add comma
        if (food == this->food.back())
        {
            cout << food;
        }
        else
        {
            cout << food << ", ";
        }
        
    }
    cout << endl;
}