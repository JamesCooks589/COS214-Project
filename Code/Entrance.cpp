#include "Entrance.h"

void Entrance::addGroup(Group group) {
        queue.add(group);
    }
    void Entrance::removeGroup(Group group) {
        queue.remove(group);
    }