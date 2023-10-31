#include "Cheese.h"
#include <iostream>

using namespace std;

Cheese::Cheese(/* args */)
{
}

void Cheese::cookFood(vector<string> orderDetails, Plate* plate){
    for (string food : orderDetails)
    {
        if(food == "Cheese"){
            plate->addFood("Cheese");
            cout << "Cheese added to plate." << endl;
        }
    }
    if (next != nullptr)
    {
        next->cookFood(orderDetails, plate);
    }
    else{
        plate->printPlate();
    }
    
    
}
