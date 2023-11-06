/**
 * @file GroupIterator.cpp
 * @brief Implementation file for the GroupIterator class.
 *        This file contains the implementation of the GroupIterator class methods for iterating over customer groups in a linked list.
 * @author [Author Name]
 * @date [Creation Date]
 */

#include "GroupIterator.h"

GroupIterator::GroupIterator(Node* head) {
    current = head;
}

GroupIterator::~GroupIterator() {
    delete current;
}

bool GroupIterator::hasNext() {
    return current->getNext() != nullptr;
}

CustomerComponent* GroupIterator::getCurrent() {
    return current->getGroup();
}

void GroupIterator::next() {
    if (hasNext()){
    current = current->getNext();
    }
}