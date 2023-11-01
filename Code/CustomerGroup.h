#pragma once

#include "CustomerComponent.h"
#include <vector>

class CustomerGroup : public CustomerComponent{
    private:
        std::vector<CustomerComponent*> customers;
    public:
        CustomerGroup(int id);
        ~CustomerGroup();
        void addToGroup(CustomerComponent* customer);
        void givePlate(Plate* plate);
        void setTableID(int id);
        std::string printHappiness();
        Order* getOrder();
        int getSize();
};