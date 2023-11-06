/**
 * @file GroupIterator.cpp
 * @brief Implementation file for the GroupIterator class.
 *        This file contains the implementation of the GroupIterator class methods for iterating over customer groups in a linked list.
* @author Qwinton Knocklein
* @date 27/10/2023
 */

#include "GroupIterator.h"

/**
 * @brief Constructor for the GroupIterator class.
 * @param head Pointer to the head node of the linked list.
 */
GroupIterator::GroupIterator(Node* head) {
    current = head;
}

/**
 * @brief Destructor for the GroupIterator class.
 */
GroupIterator::~GroupIterator() {
    delete current;
}

/**
 * @brief Checks if there is a next customer group in the linked list.
 * @return true if there is a next group, false otherwise.
 */
bool GroupIterator::hasNext() {
    return current->getNext() != nullptr;
}

/**
 * @brief Gets the current customer group pointed by the iterator.
 * @return Pointer to the current customer group.
 */
CustomerComponent* GroupIterator::getCurrent() {
    return current->getGroup();
}

/**
 * @brief Moves the iterator to the next customer group in the linked list.
 */
void GroupIterator::next() {
    if (hasNext()){
    current = current->getNext();
    }
}
