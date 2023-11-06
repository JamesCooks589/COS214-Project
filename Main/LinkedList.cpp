/**
 * @file LinkedList.cpp
 * @brief Implementation file for the LinkedList class.
 *        This file contains the implementation of methods to manage a linked list of customer groups.
 * @author [Author Name]
 * @date [Creation Date]
 */
 
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
        Node* temp = head;
        head = head->getNext();
        temp->setNext(nullptr);
        return;
    }
    Node* current = head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getGroup()->getID() == group->getID()) {
            Node* temp = current->getNext();
            current->setNext(temp->getNext());
            temp->setNext(nullptr);
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

bool LinkedList::isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}