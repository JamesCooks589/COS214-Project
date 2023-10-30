#ifndef BILL_H
#define BILL_H

#include "Caretaker.h"
#include <vector>
#include <string>

class Bill {
public:
    Bill(int orderId);
    void calculateTotalAmount();
    void printBill();

private:
    int orderId;
    std::vector<std::string> foodItems;
    double totalAmount;
};

#endif // BILL_H
