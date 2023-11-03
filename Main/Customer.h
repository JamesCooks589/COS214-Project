#pragma once

#include "CustomerComponent.h"
#include <string>
#include <random>

class Customer : public CustomerComponent{
    private:
        std::string name;
        int happiness = 100;
    public:
        Customer(std::string name, int id);
        int getSize();
        Order* getOrder();    
        void givePlate(Plate* plate);
        std::string getName();
        void setTableID(int id);
        int getHappiness();
        void payBill(double amount, bool split);
};