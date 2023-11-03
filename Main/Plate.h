#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Plate
{
private:
    vector<string> food;
    int tableID;
    string customerName;
public:
    Plate(int tableID, string customerName);
    //Clone function
    Plate* clone();
    string getCustomerName();
    vector<string> getFood();
    int getID();
    void addFood(string food);
    void printPlate();
};
