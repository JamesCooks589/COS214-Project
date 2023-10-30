#ifndef ORDER_H
#define ORDER_H

#include "OrderMemento.h"

class Order {
public:
    Order(int orderId, std::string orderState);
    void setOrderState(std::string state);
    OrderMemento saveToMemento();
    void restoreFromMemento(const OrderMemento& memento);
    void printOrder() const;

private:
    int orderId;
    std::string orderState;
};

#endif // ORDER_H
