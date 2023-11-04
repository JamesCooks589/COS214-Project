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

    //Make waiter
    PrototypeWaiter* waiter = new Waiter(kitchen, "Bob", floor);
    PrototypeWaiter* waiter2 = waiter->clone();
    waiter2->setName("Joe");


    for (int i = 1; i <= 10; i++) {
        floor->addTable(new Table(i));
    }

    Entrance* entrance = new Entrance(floor);

    

    CustomerComponent* group1 = new CustomerGroup(1);
    for(int i = 1; i <= 20; i++){
        string name = "Customer-" + to_string(i);
        group1->addToGroup(new Customer(name,i));
    }

    CustomerComponent* group2 = new CustomerGroup(2);
    for(int i = 1; i <= 5; i++){
        string name = "Customer-" + to_string(i);
        group2->addToGroup(new Customer(name,i));
    }
    
    cout << "Group " << group1->getID() << " created with size " << to_string(group1->getSize()) << endl;
    entrance->addGroup(group1);
    cout << "Group " << group2->getID() << " created with size " << to_string(group2->getSize()) << endl;
    entrance->addGroup(group2);


    entrance->seatGroup();
    entrance->seatGroup();
    
    //Let customers order
    //group1->attachWaiter(waiter);
    group1->signalToOrder();
    group1->signalForBill();

    
    //group2->attachWaiter(waiter2);
    group2->signalToOrder();
    group2->signalForBill();
    

    floor->printTables();

    delete kitchen;
    delete floor;
    delete waiter;
    delete waiter2;
    delete entrance;
    IngredientFactory::cleanup();
    return 0;

}
