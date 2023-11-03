#pragma once

#include "LinkedList.h"
#include "GroupIterator.h"

class Entrance {
private:
    LinkedList queue;
    
public:
    void addGroup(CustomerComponent* group);
    void removeGroup(CustomerComponent* group);
};