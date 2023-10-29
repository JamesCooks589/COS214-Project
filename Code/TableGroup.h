#pragma once

#include "TableComponent.h"
#include <vector>

class TableGroup : public TableComponent{
    private:
        std::vector<TableComponent*> tables;
    public:
        void addToGroup(TableComponent* tableToAdd);
        int getCapacity();
        TableComponent* removeFromGroup();
        bool isEmpty();
        ~TableGroup();
};
