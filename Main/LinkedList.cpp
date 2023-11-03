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

GroupIterator* LinkedList::getIterator() {
    return iterator = new GroupIterator(head);
}

void LinkedList::add(CustomerComponent* group) {
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

void LinkedList::remove(CustomerComponent* group) {
    if (head == nullptr) {
        return;
    }
    if (head->getGroup()->getID() == group->getID()) {
        head = head->getNext();
        return;
    }
    Node* current = head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getGroup()->getID() == group->getID()) {
            Node* temp = current->getNext();
            current->setNext(temp->getNext());
            return;
        }
        current = current->getNext();
    }
}

void LinkedList::printList(){
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getGroup()->getID();
        current = current->getNext();
    }
}

Node* LinkedList::getHead(){
    return head;
}