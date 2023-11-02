#include <iostream>
#include "LinkedList.h"
#include "CustomerGroup.h"
#include "Customer.h"

int main() {
    LinkedList* customerList = new LinkedList();

    //Create a group of customers
    CustomerGroup* group1 = new CustomerGroup(1);
    CustomerGroup* group2 = new CustomerGroup(2);
    CustomerGroup* group3 = new CustomerGroup(3);
    CustomerGroup* group4 = new CustomerGroup(4);

    //create 10 customers
    CustomerComponent* customer1 = new Customer("John", 1);
    CustomerComponent* customer2 = new Customer("Jane", 2);
    CustomerComponent* customer3 = new Customer("Jack", 3);
    CustomerComponent* customer4 = new Customer("Jill", 4);
    CustomerComponent* customer5 = new Customer("James", 5);
    CustomerComponent* customer6 = new Customer("Judy", 6);
    CustomerComponent* customer7 = new Customer("Joe", 7);
    CustomerComponent* customer8 = new Customer("Jenny", 8);
    CustomerComponent* customer9 = new Customer("Jeff", 9);
    CustomerComponent* customer10 = new Customer("Jasmine", 10);

    //add the customers to the groups
    group1->addToGroup(customer1);
    group1->addToGroup(customer2);
    group2->addToGroup(customer3);
    group2->addToGroup(customer4);
    group3->addToGroup(customer5);
    group3->addToGroup(customer6);
    group4->addToGroup(customer7);
    group4->addToGroup(customer8);
    group4->addToGroup(customer9);
    group4->addToGroup(customer10);

    //add the groups to the list
    customerList->add(group1);
    customerList->add(group2);
    customerList->add(group3);
    customerList->add(group4);

    // Create an iterator
    GroupIterator it = customerList->getIterator();

    // Print the list
    std::cout << "List after adding components:" << std::endl;
    while (it.hasNext()) {
        it.next();
        std::cout << it.getCurrent()->getID() << "->";
    }
    std::cout << std::endl;

    /*// Remove the 3rd component
    customerList->remove(group3);

    // Print the list again
    std::cout << "List after removing group 3:" << std::endl;
    while (it.hasNext()) {
        it.next();
        std::cout << it.getCurrent()->getID() << "->";
    }
    std::cout << std::endl;*/

    // Clean up memory
    delete group1;
    delete group2;
    delete group3;
    delete group4;

    return 0;
}
