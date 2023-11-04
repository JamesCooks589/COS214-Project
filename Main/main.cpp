/*Comment out the pizza we are not creating*/
#include "Kitchen.h"
#include "Entrance.h"
#include "Table.h"
#include "Customer.h"
#include <iostream>
using namespace std;
int main() {

    //Seed random with current time
    srand(static_cast<unsigned>(time(0)));


    //Make kitchen
    Kitchen* kitchen = new Kitchen();

    //Make floor
    Floor* floor = new Floor(10, kitchen);

    kitchen->setFloor(floor);

    //Make waiter


    for (int i = 1; i <= 10; i++) {
        floor->addTable(new Table(i));
    }

    Entrance* entrance = new Entrance(floor);

    

    CustomerComponent* group1 = new CustomerGroup(1);
    for(int i = 1; i <= 10; i++){
        string name = "Customer-" + to_string(i);
        group1->addToGroup(new Customer(name,i));
    }

    CustomerComponent* group2 = new CustomerGroup(2);
    for(int i = 1; i <= 5; i++){
        string name = "Customer-" + to_string(i);
        group2->addToGroup(new Customer(name,i));
    }
    
    entrance->addGroup(group1);
    entrance->addGroup(group2);


    entrance->seatGroup();
    floor->printTables();
    entrance->seatGroup();
    floor->printTables();

    kitchen->letChefVisitTable();


    //Let customers order
    group1->signalToOrder();
    group1->signalForBill();

    
    group2->signalToOrder();
    group2->signalForBill();
    

    //if all tables vacant simply print all tables are vacant
    if (floor->getNumVacantTables() == floor->getNumTables())
    {
        cout << "All tables are vacant" << endl;
    }
    else
    {
        cout << "Not all tables are vacant" << endl;
    }

    delete kitchen;
    delete floor;
    delete entrance;
    IngredientFactory::cleanup();
    return 0;

}
