#include "Chef.h"

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

Chef::~Chef()
{
    if (next != nullptr)
    {
        delete next;
    }
    
    
}

