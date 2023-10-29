#pragma once

#include "CustomerComponent.h"
#include <string>

class Customer : public CustomerComponent{
    private:
        std::string name;
    public:
        Customer(std::string name, int id);
        std::string getName();
        int getSize();
        Order* getOrder();    
};
