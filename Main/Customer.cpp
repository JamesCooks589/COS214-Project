/**
 * @file Customer.cpp
 * @brief Implementation file for the Customer class.
 *        This file contains the implementation of methods related to customers and their actions.
 * @author [Author Name]
 * @date [Creation Date]
 */

#include "Customer.h"
#include "IngredientFactory.h"
#include <iomanip>

/**
 * @brief Constructor for the Customer class.
 * @param name The name of the customer.
 * @param id The unique identifier for the customer.
 */
Customer::Customer(std::string name, int id) : CustomerComponent(id){
    this->name = name;
}

/**
 * @brief Generates a random order for the customer and returns an Order object.
 *        The order includes a base ingredient and a random number of toppings.
 * @return Pointer to the generated Order object.
 */
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
    //Print customer order
    std::cout << '\t' << name << " ordered: ";
    long unsigned int i = 0;
    for (std::string food : myOrder)
    {   
        if(i != 0){
            if (i == myOrder.size() - 1)
            {
                std::cout << food;
            }
            else
            {
                std::cout << food << ", ";
            }
        }
        i++;
    }
    std::cout << std::endl;
    orderDetails.push_back(myOrder);
    return new Order(this->getTableID(), orderDetails);
}

/**
 * @brief Gets the size of the customer, which is 1 (atomic leaf node).
 * @return 1, indicating the size of the customer.
 */
int Customer::getSize(){
    //Size of 1 customer, atomic leaf
    return 1;
}

/**
 * @brief Sets the table ID for the customer.
 * @param id The table ID to be set for the customer.
 */
void Customer::setTableID(int id){
    this->tableID = id;
}

/**
 * @brief Gets the name of the customer.
 * @return The name of the customer.
 */
std::string Customer::getName(){
    return this->name;
}

/**
 * @brief Processes the plate received from the chef.
 *        Evaluates the quality of the food and adjusts the customer's happiness accordingly.
 * @param plate Pointer to the Plate object containing cooked food items.
 */
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
    //if happiness is above 100 set output text for happiness to green, if 70..100 set to yellow, if 0..70 set to red
    if(happiness > 100){   
        std::cout << this->name << " happiness level: " << "\033[1;32m" << happiness << "\033[0m" << std::endl;
    }else if(happiness > 70){
        std::cout << this->name << " happiness level: " << "\033[1;33m" << happiness << "\033[0m" << std::endl;
    }else{
        std::cout << this->name << " happiness level: " << "\033[1;31m" << happiness << "\033[0m" << std::endl;
    }

    delete plate;
}

/**
 * @brief Gets the current happiness level of the customer.
 * @return The happiness level of the customer.
 */
int Customer::getHappiness(){
    return happiness;
}

/**
 * @brief Pays the bill and calculates the tip based on the customer's happiness level.
 *        Adjusts the happiness level and prints the payment details.
 * @param amount The total amount of the bill.
 * @param split A boolean indicating whether the bill is being split (not used in the current implementation).
 */
void Customer::payBill(double amount, bool split){
    // Adjust happiness level within a valid range
    int happinessAdjust = this->getHappiness();
    if(happinessAdjust > 200){
        happinessAdjust = 200;
    }
    if(happinessAdjust < 0){
        happinessAdjust = 0;
    }

    // Calculate tip based on happiness level and total bill amount
    double tipModifier = happinessAdjust/800.0; 
    double tip = amount * tipModifier;
    double total = amount + tip;

    // Print payment details with appropriate color codes for better visualization
    std::cout << name << " paid: " << std::fixed << std::setprecision(2) << "\033[1;33m" << "$" << total << "\033[0m" << " including tip: " << "\033[1;33m" << "$" << tip << "\033[0m" << std::endl;
}

/**
 * @brief Increases customer's happiness when the chef visits the customer.
 */
void Customer::chefVisit(){
    happiness += 20;
}