#include "floor.h"
#include "Kitchen.h"
#include <algorithm>
#include <iostream>

using namespace std;
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
    for (long unsigned int i = 0; i < tables.size(); i++) {
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

void Floor::vacateTable(int tableID){
    for(TableComponent* table : tables){
        if(table->getID() == tableID){
            CustomerComponent* leavers = table->vacate();
            int tableID = table->getID();
            if(table->getCapacity() > 2){
                this->splitTables(tableID);
            }
            cout << "Table " << tableID << " vacated" << endl;
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
    cout << waiter->getName() << " is serving group " << customers->getID() << endl;
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