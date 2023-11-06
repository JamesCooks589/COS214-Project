/**
* @file GroupIterator.h
* @brief Declaration of the GroupIterator class.
*        This file contains the declaration of the GroupIterator class,
*        which represents an iterator for iterating through customer groups.
* @author [Author Name]
* @date [Creation Date]
*/

#pragma once
#include "CustomerComponent.h"
#include "Node.h"

/**
* @class GroupIterator
* @brief Represents an iterator for iterating through customer groups.
*/
class GroupIterator {
private:
    Node* current; ///< Pointer to the current node in the linked list.

public:
    /**
    * @brief Constructor for the GroupIterator class.
    * @param head Pointer to the head node of the linked list.
    * Initializes a new instance of GroupIterator with the given head node.
    */
    GroupIterator(Node* head);

    /**
    * @brief Destructor for the GroupIterator class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~GroupIterator();

    /**
    * @brief Checks if there is a next element in the linked list.
    * @return True if there is a next element, false otherwise.
    */
    bool hasNext();

    /**
    * @brief Gets the current customer component pointed by the iterator.
    * @return Pointer to the CustomerComponent object representing the current element.
    */
    CustomerComponent* getCurrent();

    /**
    * @brief Moves the iterator to the next element in the linked list.
    */
    void next();
};
