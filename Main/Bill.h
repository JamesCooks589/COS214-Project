#pragma once

#include "Caretaker.h"
#include "IngredientFactory.h"
#include <vector>
#include <string>

class Bill {
public:
    Bill(int orderId);
    double calculateTotalAmount();
    void printBill();

private:
    int orderId;
    std::vector<std::string> foodItems;
    double totalAmount;
};
