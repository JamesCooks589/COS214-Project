#include "Caretaker.h"

Caretaker& Caretaker::getInstance() {
    static Caretaker instance;
    return instance;
}

void Caretaker::addMemento(int id, const OrderMemento& memento) {
    mementos[id] = memento;
}

OrderMemento Caretaker::getMemento(int id) {
    return mementos[id];
}
