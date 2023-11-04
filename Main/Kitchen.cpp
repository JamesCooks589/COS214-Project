#include "Kitchen.h"

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

//Kitchen Handles one order at a time
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

//Get plates
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

void Kitchen::createPlates() {
    //Create plate for each row(customer) in order and assign name and table number
    for (size_t i = 0; i < this->order->getCustomerOrders().size(); ++i) {
        this->plates.push_back(new Plate(this->order->getTableNumber(), this->order->getCustomerOrders()[i][0]));
    }
}

vector<string> Kitchen::splitOrder(int currentRow){
    //OrderDetails is a 2d vector of strings e.g [["COUSTOMER 1", "Flour", "Cheese"], ["COUSTOMER 2", "Flour", "Cheese"]]
    //Split order details into seperate vectors for each customer
    vector<string> orderDetails = vector<string>();
    for (size_t i = 0; i < this->order->getCustomerOrders()[currentRow].size(); ++i) {
        orderDetails.push_back(this->order->getCustomerOrders()[currentRow][i]);
    }
    return orderDetails;
}

    