#include "Entrance.h"

void Entrance::addGroup(CustomerComponent* group) {
        queue.add(group);
    }
    void Entrance::removeGroup(CustomerComponent* group) {
        queue.remove(group);
    }