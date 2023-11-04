#include "Entrance.h"

Entrance::Entrance(Floor *floor)
{
    this->floor = floor;
}

void Entrance::addGroup(CustomerComponent *group)
{
    cout << "Customer group " << group->getID() << " added to queue" << endl;
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

    //If group size is 1 or 2, seat group at first vacant table
    if (groupSize <= 2)
    {
        //Seat group at first vacant table
        if(floor->getFirstVacantTable() != nullptr){
            TableComponent* table = floor->getFirstVacantTable();
            table->occupy(current->getGroup());
            if(groupSize == vacantCapacity){
                floor->setIsFull(true);
            }
            cout << "Customer group " << current->getGroup()->getID() << " seated at table " << table->getID() << endl;
            queue.remove(current->getGroup());
            delete current;
            return true;
        }
        else{
            cout << "Customer group " << current->getGroup()->getID() << " not seated" << endl;
            return false;
        }
    }
    //If group is larger than 2, merge tables and seat group
    else if(groupSize <= vacantCapacity){
        //Merge tables and seat group
        TableComponent* table = floor->mergeTables(groupSize);
        if(table != nullptr){
            table->occupy(current->getGroup());
            if(groupSize == vacantCapacity){
                floor->setIsFull(true);
            }
            cout << "Customer group " << current->getGroup()->getID() << " seated at table " << table->getID() << endl;
            queue.remove(current->getGroup());
            delete current;
            return true;
        }
        else{
            cout << "Customer group " << current->getGroup()->getID() << " not seated" << endl;
            return false;
        }

    }
    //If group size is greater than vacant capacity, return false
    else{
        cout << "Customer group " << current->getGroup()->getID() << " not seated" << endl;
        return false;
    }
}
       
        


