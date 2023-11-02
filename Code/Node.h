#pragma once

#include "CustomerComponent.h"



class Node {

private:
    CustomerComponent* group;
    Node* next;
    
public:
    Node(CustomerComponent* group);
    ~Node();

    CustomerComponent* getGroup() const;

    Node* getNext() const;

    void setNext(Node* next);

};
