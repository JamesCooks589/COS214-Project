#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Plate
{
private:
    vector<string> food;
public:
    Plate();
    
    void addFood(string food);
    void printPlate();
};
