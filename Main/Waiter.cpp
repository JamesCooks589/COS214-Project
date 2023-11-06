/**
 * @file Waiter.cpp
 * @brief Implementation file for the Waiter class.
 *        This file contains the implementation of methods to handle waiter actions.
 * @author Carter Shin
 * @date 1 November 2023
 */
 
#include "Waiter.h"
#include "Order.h" 
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include "floor.h"
#include <vector>
#include <random>

/**
 * @brief Constructor for the Waiter class.
 * @param kitchen Pointer to the Kitchen object associated with the waiter.
 * @param name The name of the waiter.
 * @param floor Pointer to the Floor object associated with the waiter.
 */
Waiter::Waiter(Kitchen* kitchen, std::string name, Floor* floor){
    this->kitchen = kitchen;
    this->name = name;
    this->floor = floor;
}

/**
 * @brief Clone the Waiter object, creating a new Waiter with the same kitchen, name, and floor.
 * @return A cloned Waiter object.
 */
PrototypeWaiter* Waiter::clone(){
    return new Waiter(this->kitchen, this->name, this->floor);
}

/**
 * @brief Set the name of the waiter.
 * @param name The new name for the waiter.
 */
void Waiter::setName(std::string name) {
    this->name = name;
}

/**
 * @brief Get the name of the waiter.
 * @return The name of the waiter.
 */
std::string Waiter::getName() {
    return this->name;
}

/**
 * @brief Receive a signal to take the order from the customer and pass the order to the kitchen.
 * @param customer Pointer to the CustomerComponent object placing the order.
 */
void Waiter::orderSignal(CustomerComponent* customer) {
    std::cout << "\033[1;35m"<< name << "\033[0m" << ": Received signal to take order from table " << customer->getTableID() << "." << std::endl;
    
    Order* order = customer->getOrder();

    kitchen->setOrder(order, this);
}

/**
 * @brief Receive a signal that the order is ready and deliver the order to the customer.
 */
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
            cout << "\033[1;35m"<< name << "\033[0m" << ": Delivering order to table " << customer->getTableID() << "." << endl;
            
            for(Plate* plate: plates){
                customer->givePlate(plate);
            }
        }
    }
}

/**
 * @brief Receive a signal to deliver the bill to the customer and handle the payment process.
 * @param customer Pointer to the CustomerComponent object to whom the bill is delivered.
 */
void Waiter::billSignal(CustomerComponent* customer) {
    std::cout << "\033[1;35m"<< name << "\033[0m" << ": Received signal to deliver bill to table " << customer->getTableID() << "." << std::endl;
    
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
