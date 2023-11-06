/**
 * @file TableGroup.cpp
 * @brief Implementation file for the TableGroup class.
 *        This file contains the implementation of methods to handle table group operations.
 * @author Lloyd Creighton
 * @date 28 October 2023
 */
 
#include "TableGroup.h"

/**
 * @brief Add a table component to the group.
 * @param tableToAdd Pointer to the table component to be added to the group.
 */
void TableGroup::addToGroup(TableComponent* tableToAdd){
    if(tableToAdd != nullptr){
        this->tables.push_back(tableToAdd);
    }
}

/**
 * @brief Calculate the total capacity of all tables in the group.
 * @return The total capacity of the tables in the group.
 */
int TableGroup::getCapacity(){
    int capacity = 0;
    for(TableComponent* table : this->tables){
        capacity += table->getCapacity();
    }
    return capacity;
}

/**
 * @brief Remove and return a table component from the group.
 * @return Pointer to the removed table component, or nullptr if the group is empty.
 */
TableComponent* TableGroup::removeFromGroup(){
    if(!this->tables.empty()){
        TableComponent* element = this->tables[0];
        this->tables.erase(tables.begin());
        return element;
    }
    return nullptr;
}

/**
 * @brief Split the table group, returning a vector of table components.
 * @return A vector of pointers to table components representing the split group.
 */
std::vector<TableComponent*> TableGroup::splitGroup(){
    std::vector<TableComponent*> tablesToAdd = std::vector<TableComponent*>();
    for(TableComponent* table : tables){
        tablesToAdd.push_back(table);
    }
    this->tables.clear();
    return tablesToAdd;
}

/**
 * @brief Check if the table group is empty.
 * @return True if the group is empty, false otherwise.
 */
bool TableGroup::isEmpty(){
    return this->tables.empty();
}

/**
 * @brief Destructor for the TableGroup class.
 *        Deletes all table components in the group and clears the group vector.
 */
TableGroup::~TableGroup(){
    for(TableComponent* ptr : tables){
        delete ptr;
    }
    this->tables.clear();
}