#pragma once

#include "CustomerComponent.h"
#include "Node.h"

class GroupIterator {
    
private:
    Node* current;

public:
    GroupIterator(Node* head);
    ~GroupIterator();

    bool hasNext();

    CustomerComponent* getCurrent();

    void next();
};