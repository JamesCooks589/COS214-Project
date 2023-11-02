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
    if (current != nullptr){
    current = current->getNext();
    }
}