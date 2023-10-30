#include <vector>
#include <string>
#include "Order.h"

using namespace std;

int main() {
    // Sample customer orders
    vector<string> customerOrder = {"Customer1","Meat","Veggies"};

    // Create an Order object
    Order order(1);
    order.addOrderItem(customerOrder);

    // Print order details
    order.printOrder();

    return 0;
}