#include "TableGroup.h"

void TableGroup::addToGroup(TableComponent* tableToAdd){
    if(tableToAdd != nullptr){
        this->tables.push_back(tableToAdd);
    }
}

int TableGroup::getCapacity(){
    int capacity = 0;
    for(TableComponent* table : this->tables){
        capacity += table->getCapacity();
    }
    return capacity;
}

TableComponent* TableGroup::removeFromGroup(){
    if(!this->tables.empty()){
        TableComponent* element = this->tables[0];
        this->tables.erase(tables.begin());
        return element;
    }
    return nullptr;
}

std::vector<TableComponent*> TableGroup::splitGroup(){
    std::vector<TableComponent*> tablesToAdd = std::vector<TableComponent*>();
    for(TableComponent* table : tables){
        tablesToAdd.push_back(table);
    }
    this->tables.clear();
    return tablesToAdd;
}

bool TableGroup::isEmpty(){
    return this->tables.empty();
}

TableGroup::~TableGroup(){
    for(TableComponent* ptr : tables){
        delete ptr;
    }
    this->tables.clear();
}