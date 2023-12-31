#include "CustomerGroup.h"

CustomerGroup::CustomerGroup(int id) : CustomerComponent(id){};

CustomerGroup::~CustomerGroup(){
    //All customers in the group will be destroyed
    //No intention to ever have access to customers after their group has been destroyed
    for(CustomerComponent* ptr : customers){
        delete ptr;
    }
    customers.clear();
}

void CustomerGroup::addToGroup(CustomerComponent* customer){
    if(customer != nullptr){
        customers.push_back(customer);
    }
}

Order* CustomerGroup::getOrder(){
    if(customers.empty()){
        //No customers to get order from
        //Should never happen
        return nullptr;
    }

    //Set up the list of orders to pack into one
    std::vector<Order*> orderVector = std::vector<Order*>();
    for(CustomerComponent* ptr : customers){
        //Gets a vector of all orders from customers to pack into a single order
        Order* order = ptr->getOrder();
        orderVector.push_back(ptr->getOrder());
        delete order;
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

    //Dummy return until fully implemented
    return new Order(this->getTableID(), bigOrder);
}

int CustomerGroup::getSize(){
    if(customers.empty()){
        return 0;
    }

    int size = 0;
    
    for(CustomerComponent* ptr : customers){
        //Straightforward, adds up all customers to determine size of group
        size += ptr->getSize();
    }

    return size;
}

void CustomerGroup::setTableID(int id){
    this->tableID = id;
    for(CustomerComponent* customer : customers){
        customer->setTableID(id);
    }
}

void CustomerGroup::givePlate(Plate* plate){
    for(CustomerComponent* customer : customers){
        if(plate->getCustomerName() == customer->getName()){
            customer->givePlate(plate);
            return;
        }
    }
}

std::string CustomerGroup::getHappiness(){
    int happiness = 0;
    for(CustomerComponent* customer : customers){
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
        double tipModifier = happiness/800;
        double tip = amount * tipModifier;
        double total = amount + tipModifier;
        std::cout << "Customers at table: " << this->getTableID() << " have paid in total: " << std::to_string(total) << " including the tip of: " << std::to_string(tip) << std::endl;
    }
}

void CustomerGroup::split(double total){
    int size = this->getSize();
    int actualTotal = total/this->getSize();
    for(CustomerComponent* customer : customers){
        customer->payBill(total, true);
    }
}