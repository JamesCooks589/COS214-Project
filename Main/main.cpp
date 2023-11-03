/*Comment out the pizza we are not creating*/
#include "Kitchen.h"
#include "Entrance.h"
#include "Table.h"
#include "Customer.h"
#include <iostream>
using namespace std;
int main() {
    // //Seed rand()
    // srand(static_cast<unsigned>(time(0)));
    // //Create kitchen
    // Kitchen* kitchen = new Kitchen();

    // //SIMULATING AN ORDER FROM A TABLE
    // //SIMULATING HOW AN ORDER IS MADE YOUR WAITERS WOULD DO ALL OF THIS

    // //Create order
    // vector<vector<string>> customerOrders = vector<vector<string>>();
    
    // //Create customer orders
    // vector<string> customerOrder1 = vector<string>();
    // customerOrder1.push_back("Customer 1");
    // customerOrder1.push_back("Flour");
    // customerOrder1.push_back("Cheese");
    // customerOrders.push_back(customerOrder1);

    // vector<string> customerOrder2 = vector<string>();
    // customerOrder2.push_back("Customer 2");
    // customerOrder2.push_back("Flour");
    // customerOrder2.push_back("Meat");
    // customerOrders.push_back(customerOrder2);

    // //Create order
    // Order* order = new Order(1, customerOrders);

    // //Add order to kitchen
    // //HERE IS WHERE U INTERACT WITH THE KITCHEN USING YOUR WAITERS
    // //Simply send in a pointer to the order and my kitchen makes everything and then just fetch the vector of plates to send to customers
    // kitchen->setOrder(order);
    // vector<Plate*> plates = kitchen->getPlates();

    // cout << "-------------------------------" << endl;

    // //Print plates
    // for (size_t i = 0; i < plates.size(); ++i) {
    //     plates[i]->printPlate();
    // }

    // //Test tables*
    // Floor* floor = new Floor();

    // //Create 2 tables
    // // Eventually create in a loop
    // // For i: new Table(i);
    // vector<TableComponent*> tables = vector<TableComponent*>();
    // for (int i = 1; i <= 3; i++) {
    //     TableComponent* table = new Table(i);
    //     //TableComponent* table2 = new Table(2);

    //     tables.push_back(table);
    //     //tables.push_back(table2);
    // }

    // //Add merged tables to floor
    // floor->addTable(tables[0]);
    // floor->addTable(tables[1]);
    // floor->addTable(tables[2]);
    // floor->printTables();
    // TableComponent* group = floor->mergeTables(5);
    // floor->printTables();
    // floor->splitTables(group->getID());
    // floor->printTables();

    // for (auto table: tables)
    // {
    //     delete table;
    // }

    Floor* floor = new Floor();
    for (int i = 1; i <= floor->getMAX_TABLES(); i++) {
        floor->addTable(new Table(i));
    }

    Entrance* entrance = new Entrance(floor);

    

    CustomerComponent* group1 = new CustomerGroup(1);
    for(int i = 1; i <= 15; i++){
        string name = "Customer-" + to_string(i);
        group1->addToGroup(new Customer(name,i));
    }
    
    cout << "Group " << group1->getID() << " created with size " << to_string(group1->getSize()) << endl;
    entrance->addGroup(group1);
    cout << "Group " << group1->getID() << " added to entrance queue" << endl;
    
    CustomerComponent* group2 = new CustomerGroup(2);
    for(int i = 1; i <= 4; i++){
        string name = "Customer-" + to_string(i);
        group2->addToGroup(new Customer(name,i));
    }

    cout << "Group " << group2->getID() << " created with size " << to_string(group2->getSize()) << endl;
    entrance->addGroup(group2);
    cout << "Group " << group2->getID() << " added to entrance queue" << endl;

    if(entrance->seatGroup()){
        cout << "Group " << group1->getID() << " seated" << endl;
    }
    else{
        cout << "Group " << group1->getID() << " not seated" << endl;
    }

    if(entrance->seatGroup()){
        cout << "Group " << group2->getID() << " seated" << endl;
    }
    else{
        cout << "Group " << group2->getID() << " not seated" << endl;
    }



    floor->printTables();
    return 0;

}
