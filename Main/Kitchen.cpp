/**
 * @file Kitchen.cpp
 * @brief Implementation file for the Kitchen class.
 *        This file contains the implementation of methods to handle orders and manage the kitchen operations.
 * @author James Cooks and Lloyd Creighton
 * @date 30/10/2023
 */

#include "Kitchen.h"
#include "floor.h"

/**
 * @brief Constructor for the Kitchen class.
 *        Initializes chef factories, creates the chain of responsibility, and initializes plates and order.
 */
Kitchen::Kitchen() {
    this->baseChefFactory = new BaseChef();
    this->toppingChefFactory = new ToppingChef();
    //Create chain of responsibility
    this->chefChain = this->baseChefFactory->createVeganPizza();
    this->chefChain->Add(this->toppingChefFactory->createVeganPizza());
    this->chefChain->Add(this->baseChefFactory->createNonveganPizza());
    this->chefChain->Add(this->toppingChefFactory->createNonveganPizza());

    //Initialize plates
    this->plates = vector<Plate*>();

    //Initialize order
    this->order = nullptr;
}

/**
 * @brief Destructor for the Kitchen class.
 *        Deletes chef factories, the chain of responsibility, and plates to prevent memory leaks.
 */
Kitchen::~Kitchen() {
    //Delete factories
    delete this->baseChefFactory;
    delete this->toppingChefFactory;

    //Delete chain
    delete this->chefChain;

    //Delete plates
    for (size_t i = 0; i < this->plates.size(); ++i) {
        delete this->plates[i];
    }
}

/**
 * @brief Sets the current order in the kitchen, processes it, and notifies the waiter when the order is ready.
 * @param order Pointer to the Order object containing customer orders.
 * @param waiter Pointer to the PrototypeWaiter serving the order.
 */
void Kitchen::setOrder(Order* order, PrototypeWaiter* waiter) {
    if (this->order == nullptr)
    {      
        this->order = order;
        //Create a memento of the order
        Caretaker::getInstance().addMemento(this->order->createMemento());


        //Create plates
        this->createPlates();

        //Split order details into seperate vectors for each customer
        vector<string> orderDetails = vector<string>();
        for (size_t i = 0; i < this->order->getCustomerOrders().size(); ++i) {
            orderDetails = this->splitOrder(i);
            //Cook pizza
            this->chefChain->cookFood(orderDetails, this->plates[i]);
        }

        //Signal waiter that order is ready
        waiter->signalReadyOrder();

        //Reset order
        delete order;
        this->order = nullptr;
    }
    else
    {
        cout << "BUSY with order from Table " << order->getTableNumber() << endl;
    }

}

/**
 * @brief Sets the floor object associated with the kitchen.
 * @param floor Pointer to the Floor object representing the restaurant floor.
 */
void Kitchen::setFloor(Floor* floor) {
    this->floor = floor;
}

/**
 * @brief Gets the prepared plates, clones them, and returns the cloned plates to the waiter.
 * @return A vector of cloned Plate objects representing the prepared dishes for customers.
 */
vector<Plate*> Kitchen::getPlates() {
    //Return plates using clone function
    vector<Plate*> OutPlates = vector<Plate*>();
    for (size_t i = 0; i < this->plates.size(); ++i) {
        OutPlates.push_back(this->plates[i]->clone());
    }
    //Delete plates
    for (size_t i = 0; i < this->plates.size(); ++i) {
        delete this->plates[i];
    }
    this->plates.clear();
    return OutPlates;
}

//HELPER FUNCTIONS

/**
 * @brief Creates plates for each customer in the order and assigns names and table numbers to the plates.
 */
void Kitchen::createPlates() {
    //Create plate for each row(customer) in order and assign name and table number
    for (size_t i = 0; i < this->order->getCustomerOrders().size(); ++i) {
        this->plates.push_back(new Plate(this->order->getTableNumber(), this->order->getCustomerOrders()[i][0]));
    }
}

/**
 * @brief Splits the order details for a specific customer from the overall order.
 * @param currentRow Index of the customer's order details in the overall order.
 * @return A vector of strings representing the order details for the specific customer.
 */
vector<string> Kitchen::splitOrder(int currentRow){
    //OrderDetails is a 2d vector of strings e.g [["COUSTOMER 1", "Flour", "Cheese"], ["COUSTOMER 2", "Flour", "Cheese"]]
    //Split order details into seperate vectors for each customer
    vector<string> orderDetails = vector<string>();
    for (size_t i = 0; i < this->order->getCustomerOrders()[currentRow].size(); ++i) {
        orderDetails.push_back(this->order->getCustomerOrders()[currentRow][i]);
    }
    return orderDetails;
}

/**
 * @brief Lets a chef visit a random occupied table in the restaurant floor.
 */
void Kitchen::letChefVisitTable(){
    //Get random occupied table
    TableComponent* table = this->floor->getRandomOccupiedTable();
    if (table != nullptr){
        chefChain->visit(table->getCustomers());
    }   
}
    
