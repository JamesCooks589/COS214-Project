#pragma once
#include <vector>
#include <string>

class OrderMemento {
public:
    OrderMemento(int tableNumber, std::vector<std::vector<std::string>> customerOrders/*, std::string orderDetails*/);
    int getTableNumber() const;
    std::vector<std::vector<std::string>> getCustomerOrders() const;
    //std::string getOrderDetails() const;

private:
    int tableNumber;
    std::vector<std::vector<std::string>> customerOrders;
    //std::string orderDetails;
};

