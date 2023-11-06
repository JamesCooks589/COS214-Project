/**
 * @file Entrance.cpp
 * @brief Implementation file for the Entrance class.
 *        This file contains the implementation of methods related to managing customer groups at the restaurant entrance.
* @author Qwinton Knocklein
* @date 27/10/2023
 */

#include "Entrance.h"

/**
 * @brief Constructor for the Entrance class.
 * @param floor Pointer to the Floor object representing the restaurant floor.
 */
Entrance::Entrance(Floor *floor)
{
    this->floor = floor;
}

/**
 * @brief Adds a customer group to the entrance queue.
 * @param group Pointer to the CustomerComponent object representing the customer group.
 */
void Entrance::addGroup(CustomerComponent *group)
{
    cout << "Customer group " << group->getID() << " with size: " << group->getSize() << " showed up to the restaurant." << endl;
    queue.add(group);
}

/**
 * @brief Removes a customer group from the entrance queue.
 * @param group Pointer to the CustomerComponent object representing the customer group.
 */
void Entrance::removeGroup(CustomerComponent *group)
{
    queue.remove(group);
}

/**
 * @brief Attempts to seat a customer group from the entrance queue based on available tables.
 * @return True if the group is successfully seated, false otherwise.
 */
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
            floor->attachRandomWaiter(current->getGroup());
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
            floor->attachRandomWaiter(current->getGroup());
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

/**
 * @brief Checks if the entrance queue is empty.
 * @return True if the queue is empty, false otherwise.
 */
bool Entrance::isEmpty(){
    return queue.isEmpty();
}       
        


