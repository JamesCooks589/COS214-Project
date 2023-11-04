#include "Caretaker.h"
#include <algorithm>

using namespace std;

Caretaker& Caretaker::getInstance() {
    static Caretaker instance;
    return instance;
}

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


OrderMemento Caretaker::getMemento(int id) {
    for (OrderMemento& memento : mementos) {
        if (memento.getTableNumber() == id) {
            return memento;
        }
    }

    throw std::runtime_error("No matching OrderMemento found for the given ID");
}
