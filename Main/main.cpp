/*Comment out the pizza we are not creating*/
#include "Kitchen.h"
#include "floor.h"
#include "Table.h"
#include <iostream>
using namespace std;
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

    //Test tables*
    Floor* floor = new Floor();

    //Create 2 tables
    // Eventually create in a loop
    // For i: new Table(i);
    vector<TableComponent*> tables = vector<TableComponent*>();
    for (int i = 1; i <= 2; i++) {
        TableComponent* table = new Table(i);
        //TableComponent* table2 = new Table(2);

        tables.push_back(table);
        //tables.push_back(table2);
    }

    //Add merged tables to floor
    floor->addTable(tables[0]);
    floor->addTable(tables[1]);
    floor->printTables();
    TableComponent* group = floor->mergeTables(3);
    floor->printTables();
    floor->splitTables(group->getID());
    floor->printTables();

    for (auto table: tables)
    {
        delete table;
    }
    
    return 0;

}
