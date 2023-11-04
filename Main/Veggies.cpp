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
            //Seed current unix time to rand()
            int quality = rand() % 10 + 1;
            //If quality is 0...1, then the food is burnt so food(burnt)
            //If quality is 2...6, then the food is fine so food(fine)
            //If quality is 7...10, then the food is great so food(great)
            string product = "";
            if (quality <= 1)
            {
                product = "Veggies(burnt)";
            }
            else if (quality <= 6)
            {
                product= "Veggies(fine)";
            }
            else
            {
                product = "Veggies(great)";
            }
            plate->addFood(product);
            //cout << product << " added to plate." << endl;
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
    
