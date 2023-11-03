#include "Entrance.h"

Entrance::Entrance(Floor *floor)
{
    this->floor = floor;
}

void Entrance::addGroup(CustomerComponent *group)
{
    queue.add(group);
}
void Entrance::removeGroup(CustomerComponent *group)
{
    queue.remove(group);
}

bool Entrance::seatGroup()
{
    if (queue.isEmpty())
    {
        return false;
    }
    //If floor is full, return false
    if (floor->getIsFull())
    {
        return false;
    }

    //Get head of queue
    Node *current = queue.getHead();
    int groupSize = current->getGroup()->getSize();
    int vacantCapacity = floor->getVacantCapacity();
    //If group size is greater than vacant capacity, return false

    if (groupSize > vacantCapacity)
    {
        return false;
    }

    
