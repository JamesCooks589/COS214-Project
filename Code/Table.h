#pragma once

#include "TableComponent.h"

class Table : public TableComponent{
    private:
        int capacity = 2;
    public:
        Table(int id) : TableComponent(id){}
        int getCapacity();
};