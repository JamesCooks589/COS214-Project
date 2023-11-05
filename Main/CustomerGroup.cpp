#include "CustomerGroup.h"
#include <iomanip>
CustomerGroup::CustomerGroup(int id) : CustomerComponent(id){};

CustomerGroup::~CustomerGroup(){
    //All customers in the group will be destroyed
    //No intention to ever have access to customers after their group has been destroyed
    for(CustomerComponent* ptr : this->customers){
        delete ptr;
    }
    this->customers.clear();
}

void CustomerGroup::addToGroup(CustomerComponent* customer){
    if(customer != nullptr){
        this->customers.push_back(customer);
    }
}

Order* CustomerGroup::getOrder(){
    if(this->customers.empty()){
        //No customers to get order from
        //Should never happen
        return nullptr;
    }

    //Set up the list of orders to pack into one
    std::vector<Order*> orderVector = std::vector<Order*>();
    std::cout << "<-----------Orders for Table: " << this->getTableID() << "----------->" << std::endl;
    for(CustomerComponent* ptr : this->customers){
        //Gets a vector of all orders from customers to pack into a single order
        orderVector.push_back(ptr->getOrder());
    }
    std::vector<vector<string>> bigOrder = std::vector<std::vector<string>>();
    for(Order* ptr : orderVector){
        //Starts to unpack the orders into a single order
        std::vector<std::vector<string>> order = ptr->getCustomerOrders();
        bigOrder.push_back(order[0]);
        delete ptr;
    }

    //Clear orderVector when done to not hold dangling pointers
    orderVector.clear();

    std::cout << endl;

    //Dummy return until fully implemented
    return new Order(this->getTableID(), bigOrder);
}

int CustomerGroup::getSize(){
    if(this->customers.empty()){
        return 0;
    }

    int size = 0;
    
    for(CustomerComponent* ptr : this->customers){
        //Straightforward, adds up all customers to determine size of group
        size += ptr->getSize();
    }

    return size;
}

void CustomerGroup::setTableID(int id){
    this->tableID = id;
    for(CustomerComponent* customer : this->customers){
        customer->setTableID(id);
    }
}

void CustomerGroup::givePlate(Plate* plate){
    for(CustomerComponent* customer : this->customers){
        if(plate->getCustomerName() == customer->getName()){
            customer->givePlate(plate);
            return;
        }
    }

}

int CustomerGroup::getHappiness(){
    int happiness = 0;
    for(CustomerComponent* customer : this->customers){
        happiness += customer->getHappiness();
    }
    return happiness;
}

void CustomerGroup::payBill(double amount, bool split){
    if(split){
        this->split(amount);
    }    
    else{
        //Adding this for a whole group to pay bill
        int overallHappiness = this->getHappiness();
        int happiness = overallHappiness/this->getSize();
        if(happiness > 200){
            happiness = 200;
        }
        if(happiness < 0){
            happiness = 0;
        }
        double tipModifier = happiness/800.0;
        double tip = amount * tipModifier;
        double total = amount + tip;
        //Print money paid with number in RGB 255,255,0 (yellow)
        std::cout << "Customers at table: " << this->getTableID() << " have paid in total: " << std::fixed << std::setprecision(2) << "\033[1;33m" << "$" << total << "\033[0m" << " including tip: " << "\033[1;33m" << "$" << tip << "\033[0m" << std::endl;
    }
}

void CustomerGroup::split(double total){
    double actualTotal = total/this->getSize();
    for(CustomerComponent* customer : this->customers){
        customer->payBill(actualTotal, true);
    }
}

void CustomerGroup::chefVisit(){
    cout << "\033[1;32m" << "Chef visited table " << this->getTableID() << "\033[0m" << endl;
    for(CustomerComponent* customer : this->customers){
        customer->chefVisit();
    }
}