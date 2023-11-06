/**
* @file LinkedList.h
* @brief Declaration of the LinkedList class.
*        This file contains the declaration of the LinkedList class,
*        which represents a linked list to store customer groups.
* @author Qwinton Knocklein
* @date 27/10/2023
*/

#pragma once
#include <iostream>
#include "GroupIterator.h"
#include "CustomerGroup.h"
#include "Node.h"

/**
* @class LinkedList
* @brief Represents a linked list to store customer groups.
*/
class LinkedList {
private:
    Node* head; ///< Pointer to the head node of the linked list.
    GroupIterator* iterator; ///< Pointer to the iterator used to traverse the linked list.

public:
    /**
    * @brief Constructor for the LinkedList class.
    * Initializes a new instance of LinkedList with default values.
    */
    LinkedList();

    /**
    * @brief Destructor for the LinkedList class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~LinkedList();

    /**
    * @brief Gets the iterator for the linked list.
    * @return Pointer to the GroupIterator object for traversing the linked list.
    */
    GroupIterator* getIterator();

    /**
    * @brief Adds a customer group to the linked list.
    * @param group Pointer to the CustomerComponent object representing the group to be added.
    */
    void add(CustomerComponent* group);

    /**
    * @brief Removes a customer group from the linked list.
    * @param group Pointer to the CustomerComponent object representing the group to be removed.
    */
    void remove(CustomerComponent* group);

    /**
    * @brief Prints the contents of the linked list.
    */
    void printList();

    /**
    * @brief Gets the head node of the linked list.
    * @return Pointer to the head node of the linked list.
    */
    Node* getHead();

    /**
    * @brief Checks if the linked list is empty.
    * @return True if the linked list is empty, false otherwise.
    */
    bool isEmpty();
};
