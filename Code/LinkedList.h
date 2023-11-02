#pragma once

#include "GroupIterator.h"
#include "CustomerGroup.h"
#include "Node.h"

class LinkedList {
private:
    Node* head;
    GroupIterator* iterator;
public:
    LinkedList();
    ~LinkedList();

    GroupIterator* getIterator();
    void add(CustomerComponent* group);
    void remove(CustomerComponent* group);
    void printList();
};