/**
 * @file Floor.cpp
 * @brief Implementation file for the Floor class.
 *        This file contains the implementation of methods related to managing tables and waiters on the restaurant floor.
 * @author James Cooks and Lloyd Creighton
 * @date 30/10/2023
 */

#include "floor.h"
#include "Kitchen.h"
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief Constructor for the Floor class.
 * @param numWaiters Number of waiters to be initialized on the floor.
 * @param kitchen Pointer to the Kitchen object associated with the floor.
 */
Floor::Floor(int numWaiters, Kitchen* kitchen) {
    this->tableCount = 0;
    this->vacantTables = 0;
    this->isFull = false;
    this->kitchen = kitchen;
    this->waiters = vector<PrototypeWaiter*>();
    if (numWaiters > 0)
    {
        if (numWaiters == 1)
        {   
            PrototypeWaiter* waiter = new Waiter(kitchen, "Waiter-1", this);
            this->waiters.push_back(waiter);
        }
        else
        {
            PrototypeWaiter* waiter = new Waiter(kitchen, "Waiter-1", this);
            this->waiters.push_back(waiter);
            for (int i = 2; i <= numWaiters; i++)
            {
                string name = "Waiter-" + to_string(i);
                PrototypeWaiter* clone = waiter->clone();
                clone->setName(name);
                this->waiters.push_back(clone);
                
            }
        }    
    }
    else
    {
        cout << "Invalid number of waiters" << endl;
        exit(1);
    }
    
}

TableComponent* Floor::getTable(int tableID) {
    for (TableComponent* component : this->tables) {
        if (component->getID() == tableID) {
            return component;
        }
    }
    return nullptr;
}

/**
 * @brief Destructor for the Floor class.
 */
Floor::~Floor() {
    for (TableComponent* table : tables) {
        delete table;
    }
    this->tables.clear();
    for (PrototypeWaiter* waiter : waiters) {
        delete waiter;
    }
    this->waiters.clear();
}

/**
 * @brief Adds a table to the floor.
 * @param table Pointer to the TableComponent object representing the table to be added.
 */
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

/**
 * @brief Removes a table from the floor.
 * @param table Pointer to the TableComponent object representing the table to be removed.
 */
void Floor::removeTable(TableComponent* table) {
    for (long unsigned int i = 0; i < tables.size(); i++) {
        if (tables[i]->getID() == table->getID()) {
            tables.erase(tables.begin() + i);
            tableCount--;
            vacantTables--;
        }
    }
}

/**
 * @brief Merges tables to accommodate a larger group.
 * @param groupSize Size of the customer group to be accommodated.
 * @return Pointer to the TableComponent object representing the merged table group, or nullptr if merge is not possible.
 */
TableComponent* Floor::mergeTables(int groupSize) {
    //Cout in blue
    cout << "\033[1;34m";
    cout << "///// Merging tables to accomodate group of size " << groupSize << " /////" << endl;
    cout << "\033[0m";
    vector<int> tableIDs;
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
                tableIDs.push_back(group->getID());
            }
            else{
                 group->addToGroup(*it);
                 tableIDs.push_back((*it)->getID());
                 it = tables.erase(it);
            }
            
        }
        else{
            it++;
        }
    }
    if(group != nullptr){
        this->tables.push_back(group);
        cout << "Table group: " << group->getID() << " created with tables: ";
        for(int id : tableIDs){
            cout << id << " ";
        }
        cout << endl;
        return group;
    }
    return nullptr;
}

void Floor::splitTables(int id){
    TableComponent* group = nullptr;
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
            cout << "Table " << table->getID() << " has capacity " << table->getCapacity() << ": " << "\033[1;33m" << "occupied " << "\033[0m" << "by " << table->getCustomers()->getSize() << " customers" << endl;
        }
        else{
            cout << "Table " << table->getID() << " has capacity " << table->getCapacity() << ": " << "\033[1;32m" << "vacant" << "\033[0m" << endl;
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

void Floor::vacateTable(int tableID){
    for(TableComponent* table : tables){
        if(table->getID() == tableID){
            CustomerComponent* leavers = table->vacate();
            int tableID = table->getID();
            if(table->getCapacity() > 2){
                this->splitTables(tableID);
            }
            cout << "\033[1;34m" << "Table " << tableID << " vacated" << "\033[0m" << endl;
            if(isFull){
                isFull = false;
            }
            delete leavers;
            return;
        }
    }
}

void Floor::attachRandomWaiter(CustomerComponent* customers){
    int choice = rand() % waiters.size();
    PrototypeWaiter* waiter = waiters[choice];
    if(customers != nullptr){
        customers->attachWaiter(waiter);
    }
    cout << "\033[1;35m"<< waiter->getName() << "\033[0m" <<" is serving group " << customers->getID() << endl;
}

TableComponent* Floor::getRandomOccupiedTable(){
    vector<TableComponent*> occupiedTables;
    for(TableComponent* table : tables){
        if(table->isOccupied()){
            occupiedTables.push_back(table);
        }
    }
    if(occupiedTables.size() > 0){
        int choice = rand() % occupiedTables.size();
        return occupiedTables[choice];
    }
    return nullptr;
}

int Floor::getNumVacantTables(){
    int numVacantTables = 0;
    for(TableComponent* table : tables){
        if(!table->isOccupied()){
            numVacantTables++;
        }
    }
    return numVacantTables;
}

int Floor::getNumOccupiedTables(){
    int numOccupiedTables = 0;
    for(TableComponent* table : tables){
        if(table->isOccupied()){
            numOccupiedTables++;
        }
    }
    return numOccupiedTables;
}

int Floor::getNumTables(){
    return this->tables.size();
}
