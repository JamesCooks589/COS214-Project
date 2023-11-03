#include "Waiter.h"
#include "Order.h" 
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include "floor.h"
#include <vector>

Waiter::Waiter(Kitchen* kitchen, std::string name){
    this->kitchen = kitchen;
    this->name = name;
}

// std::unique_ptr<Prototype> Waiter::clone() {
//     return std::make_unique<Waiter>(kitchen);
// }

void Waiter::update(std::string message) {
    // implement if we want to update what the waiter should do using an update method with a passed in msg
}

void Waiter::orderSignal(CustomerComponent* customer) {
    std::cout << "Waiter " << name << ": Received signal to take order from table " << customer->getTableID() << "." << std::endl;
    
    Order* order = customer->getOrder();

    kitchen->setOrder(order);
    this.plates = kitchen->getPlates();

    for(Plate* plate: plates){
        customer->givePlate(plate);
    }

}

void Waiter::billSignal(CustomerComponent* customer) {
    std::cout << "Waiter " << name << ": Received signal to deliver bill to table " << customer->getTableID() << "." << std::endl;
    
    int id = customer->getTableID();    
    try{
        Bill bill((id));
        bill.calculateTotalAmount();
        bill.printBill();
    }
    catch(std::runtime_error e){        
        std::cout << "Error: No order found for this table." << std::endl;
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
