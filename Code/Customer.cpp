#include "Customer.h"

Customer::Customer(std::string name, int id) : CustomerComponent(id){
    this->name = name;
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

std::string Customer::getName(){
    return this->name;
}

void Customer::givePlate(Plate* plate){
    std::vector<std::string> vec = plate->getFood();
    for(std::string food : vec){
        size_t opening_parenthesis = food.find("(");
        size_t closing_parenthesis = food.find(")", opening_parenthesis);
        std::string quality = food.substr(opening_parenthesis + 1, closing_parenthesis - opening_parenthesis - 1);
        if(quality == "burnt"){
            //burnt food sucks
            happiness -= 50;
        }
        if(quality == "great"){
            //great food makes it better, but doesn't make up for the burnt bit
            happiness += 20;
        }
    }
    //eat the food, and the plate
    std::cout << this->name << " is eating." << std::endl;
    delete plate;
}

std::string Customer::printHappiness(){
    return this->name + " Happiness level: " + std::to_string(happiness);
}