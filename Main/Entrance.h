#pragma once

#include "LinkedList.h"
#include "GroupIterator.h"
#include "floor.h"

class Entrance {
private:
    LinkedList queue;
    Floor* floor;

    
public:
    Entrance(Floor* floor);
    void addGroup(CustomerComponent* group);
    void removeGroup(CustomerComponent* group);
    bool seatGroup();
    bool isEmpty();
};