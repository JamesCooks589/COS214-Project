#include "floor.h"

TableComponent* Floor::getTable(int tableID) {
    for (TableComponent* component : tables) {
        if (component->getID() == tableID) {
            return component;
        }
    }
    return nullptr;
}
