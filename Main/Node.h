/**
* @file Node.h
* @brief Declaration of the Node class.
*        This file contains the declaration of the Node class,
*        which represents a node in a linked list containing CustomerComponent objects.
* @author Qwinton Knocklein
* @date 27/10/2023
*/

#pragma once
#include "CustomerComponent.h"

/**
* @class Node
* @brief Represents a node in a linked list containing CustomerComponent objects.
*/
class Node {
private:
    CustomerComponent* group; ///< Pointer to the CustomerComponent object stored in the node.
    Node* next; ///< Pointer to the next node in the linked list.

public:
    /**
    * @brief Constructor for the Node class.
    * @param group Pointer to the CustomerComponent object to be stored in the node.
    * Initializes a new instance of Node with the given CustomerComponent object.
    */
    Node(CustomerComponent* group);

    /**
    * @brief Destructor for the Node class.
    * Cleans up resources and performs necessary cleanup operations.
    */
    ~Node();

    /**
    * @brief Gets the CustomerComponent object stored in the node.
    * @return Pointer to the CustomerComponent object stored in the node.
    */
    CustomerComponent* getGroup() const;

    /**
    * @brief Gets the next node in the linked list.
    * @return Pointer to the next Node object in the linked list.
    */
    Node* getNext() const;

    /**
    * @brief Sets the next node in the linked list.
    * @param next Pointer to the next Node object to be set.
    */
    void setNext(Node* next);
};
