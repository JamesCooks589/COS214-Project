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
            cstGrp->addToGroup(new Customer("Customer-"+i+1, i+1));
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

        delete cstGrp;
        delete tblGrp;
        return 0;
    }