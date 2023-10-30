#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Order {
public:
    // Constructor to create an order
    Order(int tableNumber);
    void addOrderItem(vector<string> item);
    // Method to print order details
    void printOrder();

private:
    int tableNumber_;
    vector<string> orderDetails_;   
};