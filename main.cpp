/*Comment out the pizza we are not creating*/
#include "Kitchen.h"

int main() {
    //Seed rand()
    srand(static_cast<unsigned>(time(0)));
    //Create kitchen
    Kitchen* kitchen = new Kitchen();

    //SIMULATING AN ORDER FROM A TABLE

    //Create order
    vector<vector<string>> customerOrders = vector<vector<string>>();
    
    //Create customer orders
        vector<string> customerOrder = vector<string>();
        customerOrder.push_back("CUSTOMER 1");
        customerOrder.push_back("Flour");
        customerOrder.push_back("Cheese");
        customerOrder.push_back("Meat");
        customerOrders.push_back(customerOrder);

        //Clear customer order
        customerOrder.clear();

        //New order
        customerOrder.push_back("CUSTOMER 2");
        customerOrder.push_back("Flour");
        customerOrder.push_back("Cheese");
        customerOrder.push_back("Veggies");
        customerOrders.push_back(customerOrder);

    Order* order = new Order(1, customerOrders, "Extra cheese");


    //YOU USE THIS TO SEND IN AN ORDER OBJECT TO THE KITCHEN and it will cook the food and send all of it to the plate vector which can be returned to customers
    //Set order
    kitchen->setOrder(order);

    return 0;

}
