#include "Customer.h"

Customer::Customer(std::string name, int id) : CustomerComponent(id){
    this->name = name;
}

std::string Customer::getName(){
    return this->name;
}

Order* Customer::getOrder(){
    //Will be a single row in the vector simply to match the order structure
    std::vector<std::vector<string>> orderDetails = std::vector<std::vector<string>>();
    std::vector<string> myOrder = std::vector<string>();
    myOrder.push_back(name);
    int baseNum = std::rand() % 2;
    switch(baseNum){
        case 0:
            myOrder.push_back("Flour");
            break;
        case 1:
            myOrder.push_back("Cheese");
            break;
        default:
            myOrder.push_back("Flour");
            break;
    }
    //Generates a random number of toppings, from 1 to 6, can also add up on base ingredients
    int numToppings = std::rand() % 5 + 1;
    for(int i = 0; i < numToppings; i++){
        int toppingNum = std::rand() % 4;
        switch (toppingNum){
            case 0:
                myOrder.push_back("Flour");
                break;
            case 1:
                myOrder.push_back("Cheese");
                break;
            case 2:
                myOrder.push_back("Veggies");
                break;
            case 3:
                myOrder.push_back("Meat");
                break;
            default:
                //Should not be reachable
                break;
        }
    }
    orderDetails.push_back(myOrder);
    return new Order(this->getTableID(), orderDetails);
}

int Customer::getSize(){
    //Size of 1 customer, atomic leaf
    return 1;
}

void Customer::setTableID(int id){
    this->tableID = id;
}