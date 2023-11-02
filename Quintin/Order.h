#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "OrderMemento.h"

using namespace std;

class Order {
public:
    Order(int tableNumber, vector<vector<string>> customerOrders);
    // Create a memento for the current order state
    OrderMemento createMemento();
    // Restore the order state from a memento
    void restoreFromMemento(const OrderMemento& memento);
    void printOrder();
    int getTableNumber();
    vector<vector<string>> getCustomerOrders();
    string getOrderDetails();

    bool IsValidOrderDetails(vector<string> customerOrder);
    string trim(const string& str);

private:
    int tableNumber;
    vector<vector<string>> customerOrders;
    string orderDetails;
};
