#include "Plate.h"

Plate::Plate(int tableID, string customerName){
    //Initialize empty food vector
    this->food = vector<string>();
    this->tableID = tableID;
    this->customerName = customerName;
    
}

//Copy constructor for deep copy
Plate::Plate(const Plate& plate){
    //Copy food vector
    this->food = plate.food;
    this->tableID = plate.tableID;
    this->customerName = plate.customerName;
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