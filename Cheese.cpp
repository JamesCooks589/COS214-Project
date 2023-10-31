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
            //Seed current unix time to rand()
            int quality = rand() % 10 + 1;
            //If quality is 0...1, then the food is burnt so food(burnt)
            //If quality is 4...6, then the food is fine so food(fine)
            //If quality is 7...10, then the food is great so food(great)
            string product = "";
            if (quality <= 1)
            {
                product = "Cheese(burnt)";
            }
            else if (quality <= 6)
            {
                product= "Cheese(fine)";
            }
            else
            {
                product = "Cheese(great)";
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
