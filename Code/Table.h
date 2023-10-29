#pragma once

#include "TableComponent.h"

class Table : public TableComponent{
    private:
        int capacity = 2;
    public:
        int getCapacity();
};
