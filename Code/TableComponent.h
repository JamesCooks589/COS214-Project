#pragma once

#include "CustomerComponent.h"
#include <vector>
#include <memory>

class TableComponent{
    private:
        CustomerComponent* Customers = nullptr;
        bool occupied = false;
    public:
        virtual int getCapacity() = 0;
        bool isOccupied();
        void occupy(CustomerComponent* Customers);
        CustomerComponent* vacate();
        virtual ~TableComponent();
};
