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
    for (TableComponent* component : tables) {
        if (component->getID() == tableID) {
            return component;
        }
    }
    return nullptr;
}

void Floor::addTable(TableComponent* table) {
    if (tables.size() < MAX_TABLES) {
        tables.push_back(table);
        tableCount++;
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
        }
    }
}


void Floor::splitTable(TableComponent* table){
    vector<TableComponent*> tablesToAdd;
    while(!table->isEmpty()){
        tablesToAdd.push_back(table->removeFromGroup());
    }
    if(!tablesToAdd.empty()){
        //Remove table from floor
        //Find table in tables
        for(int i = 0; i < tables.size(); i++){
            if(tables[i] == table){
                tables.erase(tables.begin() + i);
            }
        }
        for(TableComponent* tableT : tablesToAdd){
            tables.push_back(tableT);
        }
    }
}

/*void Floor::mergeTables(vector<TableComponent*> tablesToMerge){
    TableComponent* table = new TableGroup(tablesToMerge[0]->getID());
    for(TableComponent* tableT : tablesToMerge){
        for(int i = 0; i < tables.size(); i++){
            if(tables[i] == tableT){
                tables.erase(tables.begin() + i);
            }
        }
        table->addToGroup(table);
    }
    tables.push_back(table);
}*/

void Floor::mergeTables(vector<TableComponent*> tablesToMerge) {
    // Create a new TableGroup object
    cout << "0";
    TableComponent* table = new TableGroup(1);
    cout << "1";
    // Iterate through tablesToMerge and remove matching tables from the 'tables' vector
    tables.erase(std::remove_if(tables.begin(), tables.end(), [&](TableComponent* t) {
        for (TableComponent* tableT : tablesToMerge) {
            if (t->getID() == tableT->getID()) {
                // Add the matched table to the new TableGroup
                cout << "2";
                table->addToGroup(t);
                // Note: You may want to handle ownership using smart pointers for better memory management
                return true; // Remove this table from the 'tables' vector
            }
        }
        return false; // Keep this table in the 'tables' vector
    }), tables.end());

    cout << "3";
    // Add the new TableGroup to the 'tables' vector
    tables.push_back(table);
}

int Floor::getVacantTables() {
    int vacantTables = 0;
    for (TableComponent* table : tables) {
        if (!table->isOccupied()) {
            vacantTables += table->getCapacity();
        }
    }
    return vacantTables;
}

void Floor::setVacantTables(int vacantTables) {
    this->vacantTables = vacantTables;
}

bool Floor::getIsFull() {
    return isFull;
}

void Floor::setIsFull(bool isFull) {
    this->isFull = isFull;
}
