#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Order {
public:
    // Constructor to create an order
    Order(int tableNumber, vector<vector<string>> customerOrders);
    // Method to print order details
    void printOrder();
    // Method to get table number
    int getTableNumber();
    // Method to get customer orders
    vector<vector<string>> getCustomerOrders();
    // Method to get order details
    string getOrderDetails();

    bool IsValidOrderDetails(vector<string> customerOrder);
    string trim(const string& str);

private:
    int tableNumber;
    vector<vector<string>> customerOrders;
    string orderDetails;
};

