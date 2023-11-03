#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "TableComponent.h"

class Floor {
private:
    std::vector<TableComponent*> tables;

public:
    TableComponent* getTable(int tableID);
};

#endif