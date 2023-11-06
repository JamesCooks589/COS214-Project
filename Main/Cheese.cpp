/**
 * @file Cheese.cpp
 * @brief Implementation file for the Cheese class.
 *        This file contains the implementation of methods to cook Cheese food items.
 * @author [Author Name]
 * @date [Creation Date]
 */

#include "Cheese.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for the Cheese class.
 */
Cheese::Cheese(/* args */)
{
}

/**
 * @brief Cooks Cheese food items based on order details and adds them to the plate.
 *        Checks the quality of the cooked food and categorizes it as burnt, fine, or great.
 * @param orderDetails The vector containing order details for different food items.
 * @param plate Pointer to the Plate object where cooked food items are added.
 */
void Cheese::cookFood(vector<string> orderDetails, Plate* plate){
    for (string food : orderDetails)
    {
        if(food == "Cheese"){
            //Seed current unix time to rand()
            int quality = rand() % 10 + 1;
            //If quality is 0...1, then the food is burnt so food(burnt)
            //If quality is 2...6, then the food is fine so food(fine)
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
