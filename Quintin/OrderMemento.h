#ifndef ORDERMEMENTO_H
#define ORDERMEMENTO_H

#include <string>

class OrderMemento {
public:
    OrderMemento(int orderId, std::string orderState);
    std::string getOrderState() const;

private:
    int orderId;
    std::string orderState;
};

#endif // ORDERMEMENTO_H
