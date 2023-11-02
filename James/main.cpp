/*Comment out the pizza we are not creating*/
#include "Kitchen.h"

int main() {
    //Seed rand()
    srand(static_cast<unsigned>(time(0)));
    //Create kitchen
    Kitchen* kitchen = new Kitchen();

    //SIMULATING AN ORDER FROM A TABLE
    //SIMULATING HOW AN ORDER IS MADE YOUR WAITERS WOULD DO ALL OF THIS

    //Create order
    vector<vector<string>> customerOrders = vector<vector<string>>();
    
    //Create customer orders
    vector<string> customerOrder1 = vector<string>();
    customerOrder1.push_back("Customer 1");
    customerOrder1.push_back("Flour");
    customerOrder1.push_back("Cheese");
    customerOrders.push_back(customerOrder1);

    vector<string> customerOrder2 = vector<string>();
    customerOrder2.push_back("Customer 2");
    customerOrder2.push_back("Flour");
    customerOrder2.push_back("Meat");
    customerOrders.push_back(customerOrder2);

    //Create order
    Order* order = new Order(1, customerOrders);

    //Add order to kitchen
    //HERE IS WHERE U INTERACT WITH THE KITCHEN USING YOUR WAITERS
    //Simply send in a pointer to the order and my kitchen makes everything and then just fetch the vector of plates to send to customers
    kitchen->setOrder(order);
    vector<Plate*> plates = kitchen->getPlates();

    cout << "-------------------------------" << endl;

    //Print plates
    for (size_t i = 0; i < plates.size(); ++i) {
        plates[i]->printPlate();
    }
    
    return 0;

}
