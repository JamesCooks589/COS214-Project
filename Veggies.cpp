#include "Veggies.h"
#include <iostream>

using namespace std;

Veggies::Veggies(/* args */)
{
}

void Veggies::cookFood(vector<string> orderDetails, Plate* plate){
    for (string food : orderDetails)
    {
        if(food == "Veggies"){
            plate->addFood("Veggies");
            cout << "Veggies added to plate." << endl;
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
    
