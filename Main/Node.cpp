/**
 * @file Node.cpp
 * @brief Implementation file for the Node class.
 *        This file contains the implementation of methods to manage nodes in the linked list.
* @author Qwinton Knocklein
* @date 27/10/2023
 */

#include "Node.h"

/**
 * @brief Constructor for the Node class.
 * @param group Pointer to the CustomerComponent object that the node represents.
 */
Node::Node(CustomerComponent* group){
    this->group = group;
    this->next = nullptr;
}

/**
 * @brief Destructor for the Node class.
 *        Recursively deletes the next nodes in the linked list.
 */
Node::~Node() {
    delete next;
}

/**
 * @brief Gets the CustomerComponent object associated with the node.
 * @return Pointer to the CustomerComponent object.
 */
CustomerComponent* Node::getGroup() const {
    return group;
}

/**
 * @brief Gets the pointer to the next node in the linked list.
 * @return Pointer to the next node.
 */
Node* Node::getNext() const {
    return next;
}

/**
 * @brief Sets the next node in the linked list.
 * @param next Pointer to the next node to be set.
 */
void Node::setNext(Node* next) {
    this->next = next;
}
