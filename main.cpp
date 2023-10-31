/*Comment out the pizza we are not creating*/
#include "Kitchen.h"

int main() {
    //Seed rand()
    srand(static_cast<unsigned>(time(0)));
    //Create kitchen
    Kitchen* kitchen = new Kitchen();

    //Create order
    vector<vector<string>> customerOrders = vector<vector<string>>();
    
    //Create customer orders
    for (size_t i = 0; i < 2; ++i) {
        vector<string> customerOrder = vector<string>();
        customerOrder.push_back("CUSTOMER " + to_string(i + 1));
        customerOrder.push_back("Flour");
        customerOrder.push_back("Cheese");
        customerOrder.push_back("Meat");
        customerOrders.push_back(customerOrder);
    }

    Order* order = new Order(1, customerOrders, "Extra cheese");

    //Set order
    kitchen->setOrder(order);

    return 0;

}
