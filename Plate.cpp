#include "Plate.h"

Plate::Plate(){
    //Initialize empty food vector
    food = vector<string>();
}

void Plate::addFood(string food){
    //Add food to plate
    this->food.push_back(food);
}

void Plate::printPlate(){
    //Print plate contents
    cout << "Plate contains: ";
    for (string food : this->food)
    {
        cout << food << " ";
    }
    cout << endl;
}