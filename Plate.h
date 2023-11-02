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
    //Copy constructor
    Plate(const Plate& plate);
    
    void addFood(string food);
    void printPlate();
};
