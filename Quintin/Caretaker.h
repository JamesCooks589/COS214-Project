#ifndef CARETAKER_H
#define CARETAKER_H

#include "OrderMemento.h"
#include <map>

class Caretaker {
public:
    static Caretaker& getInstance();
    void addMemento(const OrderMemento& memento);
    OrderMemento getMemento(int id);

private:
    std::vector<OrderMemento> mementos;
};

#endif // CARETAKER_H
