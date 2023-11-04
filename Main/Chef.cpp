#include "Chef.h"
#include "CustomerComponent.h"

Chef::Chef()
{
    next = nullptr;
}

void Chef::cookFood(vector<string> orderDetails, Plate* plate){
    if(next != nullptr){
        next->cookFood(orderDetails, plate);
    }
    else{
        plate->printPlate();
    }
}

void Chef::Add(Chef* chef){
    if(next == nullptr){
        next = chef;
    }
    else{
        next->Add(chef);
    }
}

void Chef::visit(CustomerComponent* visit){
    if(next == nullptr){
        cout << "Chef is visiting customers at table " << to_string(visit->getTableID()) << endl;
        visit->chefVisit();
    }
    else{
        //Random chance that it visits the customer
        int chance = rand() % 10 + 1;
        if(chance <= 1){
            cout << "Chef is visiting customers at table " << to_string(visit->getTableID()) << endl;
            visit->chefVisit();
        }
        else{
            next->visit(visit);
        }
    }
}

Chef::~Chef()
{
    if (next != nullptr)
    {
        delete next;
    }
    
    
}

