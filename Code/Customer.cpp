#include "Customer.h"
#include "IngredientFactory.h"

Customer::Customer(std::string name, int id) : CustomerComponent(id){
    this->name = name;
}

Order* Customer::getOrder() {
    std::vector<std::vector<std::string>> orderDetails;
    std::vector<std::string> myOrder;
    myOrder.push_back(name);

    // Base ingredient
    int baseNum = std::rand() % 2;
    std::string baseIngredientName;
    switch(baseNum) {
        case 0:
            baseIngredientName = "Flour";
            break;
        case 1:
            baseIngredientName = "Cheese";
            break;
        default:
            baseIngredientName = "Flour";
            break;
    }
    Ingredient* baseIngredient = IngredientFactory::getIngredient(baseIngredientName, 5.0);
    myOrder.push_back(baseIngredient->getName());

    // Generates a random number of toppings, from 1 to 6, can also add up on base ingredients
    int numToppings = std::rand() % 5 + 1;
    for(int i = 0; i < numToppings; i++) {
        int toppingNum = std::rand() % 4;
        std::string toppingName;
        switch(toppingNum) {
            case 0:
                toppingName = "Flour";
                break;
            case 1:
                toppingName = "Cheese";
                break;
            case 2:
                toppingName = "Veggies";
                break;
            case 3:
                toppingName = "Meat";
                break;
            default:
                // Should not be reachable
                break;
        }
        Ingredient* toppingIngredient = IngredientFactory::getIngredient(toppingName, 2.0);
        myOrder.push_back(toppingIngredient->getName());
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

void Customer::pay(Bill* bill, double amount){
    bill->totalAmount -= amount;

    if (bill->totalAmount == 0)
    {
        std::cout << "Bill has been paid in full." << std::endl;
    }
    else
    {
        std::cout << name << " paid $" << amount << " for their share of the bill." << std::endl;
    }
}