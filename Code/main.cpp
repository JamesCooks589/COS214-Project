#include "Customer.h"
#include "CustomerGroup.h"
#include "Table.h"
#include "TableGroup.h"
#include <iostream>
    int main(){
        // initialise a table group
        TableGroup* tblGrp = new TableGroup(0);

        for(int i = 0; i < 5; i++){
            //add 5 tables to the group
            tblGrp->addToGroup(new Table(i + 1));
        }

        std::cout << "Table Group capacity: " << tblGrp->getCapacity() << std::endl;

        // initialise a customer group
        CustomerGroup* cstGrp = new CustomerGroup(0);

        for(int i = 0; i < 11; i++){
            //add 11 customers to the group
            std::string name = "Customer-" + std::to_string(i + 1);
            Customer* cust = new Customer(name, i+1);
            cstGrp->addToGroup(cust);
        }

        std::cout << "Customer Group size: "<< cstGrp->getSize() << std::endl;
        tblGrp->occupy(cstGrp);

        std::cout << "Adding new table to meet capacity" << std::endl;

        tblGrp->addToGroup(new Table(6));

        tblGrp->occupy(cstGrp);

        //Make new group to test occupation
        CustomerGroup* newEmptyGroup = new CustomerGroup(10);

        //Testing occupy if already occupied
        tblGrp->occupy(newEmptyGroup);
        //Let cstGrp vacate current group
        tblGrp->vacate();
        //Test that it can successfully occupy
        tblGrp->occupy(newEmptyGroup);

        Order* order = cstGrp->getOrder();
        order->printOrder();

        Customer* cust = new Customer("Bob", 20);
        cust->setTableID(1);
        Order* order2 = cust->getOrder();
        order2->printOrder();

        delete order;
        delete order2;
        delete cust;
        delete cstGrp;
        delete tblGrp;
        return 0;
    }