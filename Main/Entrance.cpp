#include "Entrance.h"

void Entrance::addGroup(CustomerComponent *group)
{
    queue.add(group);
}
void Entrance::removeGroup(CustomerComponent *group)
{
    queue.remove(group);
}

void Entrance::seatGroup()
{
    //Get the head of the queue
    this->queue.getHead();

    //Check if floor is full
    

}