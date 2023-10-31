#include "Meat.h"
#include <iostream>

using namespace std;

Meat::Meat(/* args */)
{
}

void Meat::cookFood(vector<string> orderDetails, Plate* plate){
    for (string food : orderDetails)
    {
        if(food == "Meat"){
            plate->addFood("Meat");
            cout << "Meat added to plate." << endl;
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

