#ifndef CARETAKER_H
#define CARETAKER_H

#include "OrderMemento.h"
#include <map>

class Caretaker {
public:
    static Caretaker& getInstance();
    void addMemento(int id, const OrderMemento& memento);
    OrderMemento getMemento(int id);

private:
    std::map<int, OrderMemento> mementos;
};

#endif // CARETAKER_H
