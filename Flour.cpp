#include "Flour.h"
#include <iostream>

using namespace std;

Flour::Flour(/* args */)
{
}

void Flour::cookFood(vector<string> orderDetails, Plate* plate){
    for (string food : orderDetails)
    {
        if(food == "Flour"){
            plate->addFood("Flour");
            cout << "Flour added to plate." << endl;
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