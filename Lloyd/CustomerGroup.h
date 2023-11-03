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
        int getHappiness();
        Order* getOrder();
        int getSize();
        void payBill(double amount, bool split);
        void split(double total);
};