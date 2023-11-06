/**
* @file Entrance.h
* @brief Declaration of the Entrance class.
*        This file contains the declaration of the Entrance class,
*        which represents the entrance area for customers entering the restaurant.
*        It manages customer groups in a queue and handles seating them on the floor.
* @author Qwinton Knocklein
* @date 27/10/2023
*/

#pragma once
#include "LinkedList.h"
#include "GroupIterator.h"
#include "floor.h"

/**
* @class Entrance
* @brief Represents the entrance area for customers entering the restaurant.
*/
class Entrance {
private:
    LinkedList queue; ///< Linked list to manage customer groups waiting in the queue.
    Floor* floor; ///< Pointer to the Floor object where customers will be seated.

public:
    /**
    * @brief Constructor for the Entrance class.
    * @param floor Pointer to the Floor object where customers will be seated.
    * Initializes a new instance of Entrance with the given floor.
    */
    Entrance(Floor* floor);

    /**
    * @brief Adds a customer group to the entrance queue.
    * @param group Pointer to the CustomerComponent object representing the group to be added.
    */
    void addGroup(CustomerComponent* group);

    /**
    * @brief Removes a customer group from the entrance queue.
    * @param group Pointer to the CustomerComponent object representing the group to be removed.
    */
    void removeGroup(CustomerComponent* group);

    /**
    * @brief Seats a customer group from the entrance queue on the restaurant floor.
    * @return True if a group is successfully seated, false otherwise.
    */
    bool seatGroup();

    /**
    * @brief Checks if the entrance queue is empty.
    * @return True if the entrance queue is empty, false otherwise.
    */
    bool isEmpty();
};
