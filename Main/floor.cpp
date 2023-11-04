#include "floor.h"
#include <algorithm>
#include <iostream>

using namespace std;
Floor::Floor() {
    this->tableCount = 0;
    this->vacantTables = 0;
    this->isFull = false;
}

TableComponent* Floor::getTable(int tableID) {
    for (TableComponent* component : this->tables) {
        if (component->getID() == tableID) {
            return component;
        }
    }
    return nullptr;
}

void Floor::addTable(TableComponent* table) {
    if (this->tables.size() < MAX_TABLES) {
        this->tables.push_back(table);
        tableCount++;
        vacantTables++;
    }
    else {
        std::cout << "Cannot add more tables." << std::endl;
    }
}

void Floor::removeTable(TableComponent* table) {
    for (int i = 0; i < tables.size(); i++) {
        if (tables[i]->getID() == table->getID()) {
            tables.erase(tables.begin() + i);
            tableCount--;
            vacantTables--;
        }
    }
}

TableComponent* Floor::mergeTables(int groupSize) {
    if(groupSize > this->getVacantCapacity()){
        return nullptr;
    }
    TableComponent* group = nullptr;
    auto it = tables.begin();
    while(it != tables.end()){
        if(group != nullptr){
            if(group->getCapacity() >= groupSize){
                break;
            }
        }
        if(!(*it)->isOccupied()){
            if(group == nullptr){
                group = new TableGroup((*it)->getID());
                group->addToGroup(*it);
                it = tables.erase(it);
                cout << "Added table " << group->getID() << " to group " << group->getID() << endl;
            }
            else{
                 group->addToGroup(*it);
                 cout << "Added table " << (*it)->getID() << " to group " << group->getID() << endl;
                 it = tables.erase(it);
            }
            
        }
        else{
            it++;
        }
    }
    if(group != nullptr){
        this->tables.push_back(group);
        cout << "Group " << group->getID() << " created" << endl;
        return group;
    }
    return nullptr;
}

void Floor::splitTables(int id){
    TableComponent* group = nullptr;
    // for(TableComponent* table : tables){
    //     if(table->getID() == id){
    //         group = table;
    //         break;
    //     }
    // }
    auto it = tables.begin();
    while(it != tables.end()){
        if((*it)->getID() == id){
            group = *it;
            if(group != nullptr){
                it = tables.erase(it);
            }
            break;
        }
        it++;
    }
    if(group != nullptr){
        vector<TableComponent*> tablesToAdd = group->splitGroup();
        for(TableComponent* table : tablesToAdd){
            this->tables.push_back(table);
            cout << "Table " << table->getID() << " added to floor" << endl;
        }
        cout << "Group " << group->getID() << " split" << endl;
        delete group;

    }
}

int Floor::getVacantCapacity() {
    int vacantCapacity = 0;
    for (TableComponent* table : tables) {
        if (!table->isOccupied()) {
            vacantCapacity += table->getCapacity();
        }
    }
    return vacantCapacity;
}

bool Floor::getIsFull() {
    return isFull;
}

void Floor::setIsFull(bool isFull) {
    this->isFull = isFull;
}

void Floor::printTables() {
    //Print all tables in ascending order
    //Sort tables by ID
    sort(tables.begin(), tables.end(), [](TableComponent* a, TableComponent* b) {
        return a->getID() < b->getID();
    });
    
    for (TableComponent* table : tables) {
        if(table->isOccupied()){
            cout << "Table " << table->getID() << " has capacity " << table->getCapacity() << ": occupied by " << table->getCustomers()->getSize() << endl;
        }
        else{
            cout << "Table " << table->getID() << " has capacity " << table->getCapacity() << ": vacant" << endl;
        }
    }
}

TableComponent* Floor::getFirstVacantTable(){
    for(TableComponent* table : tables){
        if(!table->isOccupied()){
            return table;
        }
    }
    return nullptr;
}

int const Floor::getMAX_TABLES(){
    return MAX_TABLES;
}