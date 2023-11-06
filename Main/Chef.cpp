/**
 * @file Chef.cpp
 * @brief Implementation file for the Chef class.
 *        This file contains the implementation of methods related to chefs and their actions.
 * @author James Cooks
 * @date 22/10/2023
 */

#include "Chef.h"
#include "CustomerComponent.h"

/**
 * @brief Default constructor for the Chef class.
 *        Initializes the next chef in the chain as nullptr.
 */
Chef::Chef()
{
    next = nullptr;
}

/**
 * @brief Cooks food based on the given order details and adds them to the plate.
 * @param orderDetails The vector containing order details for different food items.
 * @param plate Pointer to the Plate object where cooked food items are added.
 */
void Chef::cookFood(vector<string> orderDetails, Plate* plate){
    if(next != nullptr){
        next->cookFood(orderDetails, plate);
    }
    else{
        plate->printPlate();
    }
}

/**
 * @brief Adds a chef to the chain of chefs.
 *        If there is no next chef, sets the given chef as the next chef. Otherwise, delegates to the next chef.
 * @param chef Pointer to the Chef object to be added to the chain.
 */
void Chef::Add(Chef* chef){
    if(next == nullptr){
        next = chef;
    }
    else{
        next->Add(chef);
    }
}

/**
 * @brief Visits a customer table and performs chef-related actions.
 *        There is a random chance that the chef will visit the customer.
 * @param visit Pointer to the CustomerComponent representing the customer table to be visited.
 */
void Chef::visit(CustomerComponent* visit){
    if(next == nullptr){
        cout << "\033[1;32m";
        cout << "Chef is visiting customers at table " << to_string(visit->getTableID()) << endl;
        cout << "\033[0m";

        visit->chefVisit();
    }
    else{
        //Random chance that it visits the customer
        int chance = rand() % 10 + 1;
        if(chance <= 1){
            cout << "\033[1;32m";
            cout << "Chef is visiting customers at table " << to_string(visit->getTableID()) << endl;
            cout << "\033[0m";
            visit->chefVisit();
        }
        else{
            next->visit(visit);
        }
    }
}

/**
 * @brief Destructor for the Chef class.
 *        Deletes the next chef in the chain if it exists.
 */
Chef::~Chef()
{
    if (next != nullptr)
    {
        delete next;
    }
    
    
}

