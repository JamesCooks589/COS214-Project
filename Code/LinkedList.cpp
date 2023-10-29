#include "LinkedList.h"


LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getNext();
        delete temp;
    }
    delete current;
}

GroupIterator LinkedList::getIterator() {
    return GroupIterator(head);
}

void LinkedList::add(Group group) {
    Node* newNode = new Node(group);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void LinkedList::remove(Group group) {
    if (head == nullptr) {
        return;
    }
    if (head->getGroup().getId() == group.getId()) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return;
    }
    Node* current = head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getGroup().getId() == group.getId()) {
            Node* temp = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete temp;
            return;
        }
        current = current->getNext();
    }
}