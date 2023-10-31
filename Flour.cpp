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
            //Seed current unix time to rand()
            int quality = rand() % 10 + 1;
            //If quality is 0...1, then the food is burnt so food(burnt)
            //If quality is 4...6, then the food is fine so food(fine)
            //If quality is 7...10, then the food is great so food(great)
            string product = "";
            if (quality <= 1)
            {
                product = "Flour(burnt)";
            }
            else if (quality <= 6)
            {
                product= "Flour(fine)";
            }
            else
            {
                product = "Flour(great)";
            }
            plate->addFood(product);
            cout << product << " added to plate." << endl;
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