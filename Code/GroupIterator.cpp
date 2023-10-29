#include "GroupIterator.h"

GroupIterator::GroupIterator(Node* head) {
    current = head;
}

GroupIterator::~GroupIterator() {
    delete current;
}

bool GroupIterator::hasNext() {
    return current != nullptr;
}

Group GroupIterator::getCurrent() {
    return current->getGroup();
}

void GroupIterator::next() {
    current = current->getNext();
}