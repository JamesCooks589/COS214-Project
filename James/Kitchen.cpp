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
void Kitchen::setOrder(Order* order) {
    if (this->order == nullptr)
    {      
        this->order = order;

        //Create plates
        this->createPlates();

        //Split order details into seperate vectors for each customer
        vector<string> orderDetails = vector<string>();
        for (size_t i = 0; i < this->order->getCustomerOrders().size(); ++i) {
            orderDetails = this->splitOrder(i);
            //Cook pizza
            this->chefChain->cookFood(orderDetails, this->plates[i]);
        }

        //Reset order
        this->order = nullptr;
    }
    else
    {
        cout << "BUSY with order from Table " << order->getTableNumber() << endl;
    }

}

//Get plates
vector<Plate*> Kitchen::getPlates() {
    //Deep copy of plates to return using copy constructor
    vector<Plate*> platesCopy = vector<Plate*>();
    for (size_t i = 0; i < this->plates.size(); ++i) {
        platesCopy.push_back(new Plate(*this->plates[i]));
    }
    return platesCopy;
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

    
