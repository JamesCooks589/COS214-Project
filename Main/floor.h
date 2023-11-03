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
    int const MAX_TABLES = 10;
    bool isFull;
    int vacantTables;


public:
    Floor();
    TableComponent* getTable(int tableID);
    void addTable(TableComponent* table);
    void removeTable(TableComponent* table);
    void splitTable(TableComponent* table);
    void mergeTables(vector<TableComponent*> tables);
    void printTables();
    int getVacantTables();
    void setVacantTables(int vacantTables);
    bool getIsFull();
    void setIsFull(bool isFull);
};

#endif