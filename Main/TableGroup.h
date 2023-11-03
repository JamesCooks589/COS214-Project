#pragma once

#include "TableComponent.h"
#include <vector>

class TableGroup : public TableComponent{
    private:
        std::vector<TableComponent*> tables;
    public:
        TableGroup(int id) : TableComponent(id){
            tables = std::vector<TableComponent*>();
        }
        void addToGroup(TableComponent* tableToAdd);
        int getCapacity();
        TableComponent* removeFromGroup();
        bool isEmpty();
        ~TableGroup();
};