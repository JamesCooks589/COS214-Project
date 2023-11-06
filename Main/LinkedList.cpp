/**
 * @file LinkedList.cpp
 * @brief Implementation file for the LinkedList class.
 *        This file contains the implementation of methods to manage a linked list of customer groups.
 * @author [Author Name]
 * @date [Creation Date]
 */
 
#include "LinkedList.h"

/**
 * @brief Constructor for the LinkedList class.
 *        Initializes the head pointer to nullptr.
 */
LinkedList::LinkedList() {
    head = nullptr;
}

/**
 * @brief Destructor for the LinkedList class.
 *        Deletes all nodes in the linked list to prevent memory leaks.
 */
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getNext();
        delete temp;
    }
    delete current;
}

/**
 * @brief Returns a new GroupIterator object to iterate through the linked list.
 * @return Pointer to the GroupIterator object.
 */
GroupIterator* LinkedList::getIterator() {
    return iterator = new GroupIterator(head);
}

/**
 * @brief Adds a new customer group to the end of the linked list.
 * @param group Pointer to the CustomerComponent object representing the customer group to be added.
 */
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

/**
 * @brief Removes a customer group from the linked list based on its ID.
 * @param group Pointer to the CustomerComponent object representing the customer group to be removed.
 */
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

/**
 * @brief Prints the IDs of customer groups in the linked list.
 */
void LinkedList::printList(){
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getGroup()->getID();
        current = current->getNext();
    }
}

/**
 * @brief Retrieves the head node of the linked list.
 * @return Pointer to the head node of the linked list.
 */
Node* LinkedList::getHead(){
    return head;
}

/**
 * @brief Checks if the linked list is empty.
 * @return True if the linked list is empty, false otherwise.
 */
bool LinkedList::isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}