#include "TableGroup.h"

void TableGroup::addToGroup(TableComponent* tableToAdd){
    if(tableToAdd != nullptr){
        tables.push_back(tableToAdd);
    }
}

int TableGroup::getCapacity(){
    int capacity = 0;
    for(int i = 0; i < tables.size(); i++){
        capacity = tables[i]->getCapacity();
    }
    return capacity;
}

TableComponent* TableGroup::removeFromGroup(){
    if(!tables.empty()){
        TableComponent* element = tables[0];
        tables.erase(tables.begin());
        return element;
    }
    return nullptr;
}

bool TableGroup::isEmpty(){
    return tables.empty();
}

TableGroup::~TableGroup(){
    for(TableComponent* ptr : tables){
        delete ptr;
    }
    tables.clear();
}
