#include "Waiter.h"
#include "Order.h" 
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include "floor.h"
#include <vector>
#include <random>
Waiter::Waiter(Kitchen* kitchen, std::string name, Floor* floor){
    this->kitchen = kitchen;
    this->name = name;
    this->floor = floor;
}

//Clone method
PrototypeWaiter* Waiter::clone(){
    return new Waiter(this->kitchen, this->name, this->floor);
}

void Waiter::setName(std::string name) {
    this->name = name;
}

std::string Waiter::getName() {
    return this->name;
}

void Waiter::orderSignal(CustomerComponent* customer) {
    std::cout << name << ": Received signal to take order from table " << customer->getTableID() << "." << std::endl;
    
    Order* order = customer->getOrder();

    kitchen->setOrder(order, this);
}

void Waiter::signalReadyOrder(){
    this->plates = kitchen->getPlates();
    int id = 0;
    if(!this->plates.empty()){
        id = this->plates[0]->getID();
    }

    TableComponent* toDeliver = floor->getTable(id);

    if(toDeliver != nullptr){
        CustomerComponent* customer = toDeliver->getCustomers();
        if(customer != nullptr){
            for(Plate* plate: plates){
                customer->givePlate(plate);
            }
        }
    }
}

void Waiter::billSignal(CustomerComponent* customer) {
    std::cout << name << ": Received signal to deliver bill to table " << customer->getTableID() << "." << std::endl;
    
    int id = customer->getTableID();    
    try{
        Bill* bill = new Bill(id);
        int choice = rand() % 2;
        if(choice == 0){
            std::cout << "Customers at table " << std::to_string(id) << " chose to split the bill." << std::endl;
            customer->payBill(bill->calculateTotalAmount(), true);
        }
        else{
            //cout not in red bold text
            std::cout << "Customers at table " << std::to_string(id) << " chose \033[0;31mNOT\033[0m to split the bill." << std::endl;
            customer->payBill(bill->calculateTotalAmount(), false);
        }
        floor->vacateTable(customer->getTableID());
        delete bill;
    }
    catch(std::runtime_error* e){        
        std::cout << "Error: No order found for this table." << std::endl;
        delete e;
    }
}

// void Waiter::deliverOrder(Plate* p) {
//     int tableID = p->getID();

//     TableComponent* table = floor->getTable(tableID);
    
//     if (table != nullptr && table->isOccupied()) {
//         std::cout << "Waiter " << this << ": Delivering order to table " << tableID << "." << std::endl;
//         for(Plate* pp : plates){
//             if(pp == p){
//                 CustomerComponent* customer = table->getCustomers();
//                 customer->givePlate(pp);

//                 plates.erase(std::remove(plates.begin(), plates.end(), pp), plates.end());

//                 break;
//             }
//         }
        
//     } 
//     else {
//         std::cout << "Error: No occupied table found with this ID." << std::endl;
//     }
// }
