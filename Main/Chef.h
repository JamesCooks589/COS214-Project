#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Plate.h"


using namespace std;

class CustomerComponent;

class Chef
{
protected:
    Chef* next;
public:
    Chef();
    virtual ~Chef();
    void Add(Chef* chef);
    virtual void cookFood(vector<string> orderDetails, Plate* plate);
    void visit(CustomerComponent* visitCandidate);
};

