#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "TableComponent.h"
#include "TableGroup.h"

using namespace std;

class Floor {
private:
    vector<TableComponent*> tables;
    int tableCount;
    const long unsigned int MAX_TABLES = 10;
    bool isFull;
    int vacantTables;


public:
    Floor();
    ~Floor();
    TableComponent* getTable(int tableID);
    void addTable(TableComponent* table);
    void removeTable(TableComponent* table);
    void splitTables(int id);
    TableComponent* mergeTables(int groupSize);
    void printTables();
    int getVacantCapacity();
    bool getIsFull();
    void setIsFull(bool isFull);
    TableComponent* getFirstVacantTable();
    void vacateTable(int tableID);
    int const getMAX_TABLES();
};

#endif