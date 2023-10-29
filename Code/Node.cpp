#include "Node.h"

Node::Node(Group group, Node* next) : group(group), next(next) {}

Node::~Node() {
    delete next;
}

Group Node::getGroup() const {
    return group;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* next) {
    this->next = next;
}
