#pragma once

#include "TableComponent.h"
#include <vector>

class TableGroup : public TableComponent{
    private:
        std::vector<TableComponent*> tables;
    public:
        TableGroup(int id) : TableComponent(id){
            this->tables = std::vector<TableComponent*>();
        }
        void addToGroup(TableComponent* tableToAdd);
        int getCapacity();
        TableComponent* removeFromGroup();
        virtual std::vector<TableComponent*> splitGroup() override;
        bool isEmpty();
        ~TableGroup();
};