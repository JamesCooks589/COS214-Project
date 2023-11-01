#pragma once

#include "CustomerComponent.h"
#include <vector>
#include <memory>

class TableComponent{
    private:
        CustomerComponent* Customers = nullptr;
        bool occupied = false;
        int id;
    public:
        TableComponent(int id);
        virtual int getCapacity() = 0;
        int getID();
        bool isOccupied();
        void occupy(CustomerComponent* Customers);
        CustomerComponent* vacate();
        virtual ~TableComponent();
};