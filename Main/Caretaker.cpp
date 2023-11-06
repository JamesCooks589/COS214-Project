/**
 * @file Caretaker.cpp
 * @brief Implementation file for the Caretaker class.
 *        This file contains the implementation of methods to manage OrderMementos.
 * @author Quintin d'Hotman de Villiers
 * @date 2023/10/21
 */

#include "Caretaker.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

/**
 * @brief Static method to get the singleton instance of Caretaker.
 * @return Reference to the Caretaker instance.
 */
Caretaker& Caretaker::getInstance() {
    static Caretaker instance;
    return instance;
}

/**
 * @brief Adds a new OrderMemento to the caretaker's collection, removing any existing memento for the same table number.
 * @param m The OrderMemento to be added.
 */
void Caretaker::addMemento(const OrderMemento& m) {
    auto it = std::remove_if(mementos.begin(), mementos.end(),
                             [&m](const OrderMemento& existingMemento) {
                                 return existingMemento.getTableNumber() == m.getTableNumber();
                             });

    // Erase the removed elements (if any) from the vector
    mementos.erase(it, mementos.end());

    // Add the new memento to the vector
    mementos.push_back(m);
}

/**
 * @brief Retrieves the OrderMemento for the given table number.
 * @param id The table number for which the OrderMemento is to be retrieved.
 * @return The OrderMemento object corresponding to the given table number.
 * @throws std::runtime_error if no matching OrderMemento is found for the given ID.
 */
OrderMemento Caretaker::getMemento(int id) {
    for (OrderMemento& memento : mementos) {
        if (memento.getTableNumber() == id) {
            return memento;
        }
    }

    throw std::runtime_error("No matching OrderMemento found for the given ID");
}
