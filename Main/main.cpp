/*Comment out the pizza we are not creating*/
#include "Kitchen.h"
#include "Entrance.h"
#include "Table.h"
#include "Customer.h"
#include <iostream>
using namespace std;
int main() {

     //Print out Welcome to the pizzeria on font size 36 using ascii codes
     cout << "/////////////////////////////////////////////////////////////////////" << endl;
     cout<<"\033[1;36m";
    std::cout << "      W     W  EEEEE  L      CCCCC   OOO   M     M  EEEEE" << std::endl;
    std::cout << "      W     W  E      L     C       O   O  MM   MM  E" << std::endl;
    std::cout << "      W  W  W  EEEE   L     C       O   O  M M M M  EEEE" << std::endl;
    std::cout << "      W  W  W  E      L     C       O   O  M  M  M  E" << std::endl;
    std::cout << "       W   W   EEEEE  LLLLL  CCCCC   OOO   M     M  EEEEE" << std::endl;
    cout<<"\033[0m";
    cout << "/////////////////////////////////////////////////////////////////////" << endl << endl;

    //Seed random with current time
    srand(static_cast<unsigned>(time(0)));

    int chance = rand() % 10 + 1;
    //Make kitchen
    Kitchen* kitchen = new Kitchen();

    //Make floor
    Floor* floor = new Floor(10, kitchen);

    kitchen->setFloor(floor);


    for (int i = 1; i <= 10; i++) {
        floor->addTable(new Table(i));
    }

    Entrance* entrance = new Entrance(floor);

    input:
    cout << "Would you like to run the program in preconfigured mode or manual mode?" << endl;
    cout << "Enter 1 for preconfigured mode or 2 for manual mode" << endl;
    int mode;
    cin >> mode;
    if (mode == 1)
    {
        CustomerComponent* group1 = new CustomerGroup(1);
        for(int i = 1; i <= 10; i++){
            string name = "Customer-" + to_string(i);
            group1->addToGroup(new Customer(name,i));
        }

        CustomerComponent* group2 = new CustomerGroup(2);
        for(int i = 1; i <= 5; i++){
            string name = "Customer-" + to_string(i);
            group2->addToGroup(new Customer(name,i));
        }
        
        entrance->addGroup(group1);
        entrance->addGroup(group2);




        entrance->seatGroup();
        floor->printTables();
        entrance->seatGroup();
        floor->printTables();

        kitchen->letChefVisitTable();


        //Let customers order
        group1->signalToOrder();
        group1->signalForBill();

        
        group2->signalToOrder();
        group2->signalForBill();
        

        //if all tables vacant simply print all tables are vacant
        if (floor->getNumVacantTables() == floor->getNumTables())
        {
            cout << "All tables are vacant" << endl;
        }
        else
        {
            cout << "Not all tables are vacant" << endl;
        }
    }
    else if(mode == 2){
        modeInput:
        cout << "Would you like 1 group or multiple groups" << endl;
        cout << "Enter 1 for 1 group or 2 for multiple groups" << endl;
        int groupMode;
        cin >> groupMode;
        if (groupMode == 1)
        {
            individualGroupSize:
            cout << "How many people are in the group?" << endl;
            int groupSize;
            cin >> groupSize;
            if(groupSize <= 0 || groupSize > 20){
                cout << "Group size are only allowed to be between 1 and 20" << endl;
                goto individualGroupSize;
            }
            CustomerComponent* group = new CustomerGroup(1);
            for(int i = 1; i <= groupSize; i++){
                string name = "Customer-" + to_string(i);
                group->addToGroup(new Customer(name,i));
            }
            entrance->addGroup(group);
            entrance->seatGroup();
            floor->printTables();
            //Chance chef visits table
            if (chance <= 3)
            {
                kitchen->letChefVisitTable();
            }
            //Let customers order
            group->signalToOrder();
            group->signalForBill();
            //if all tables vacant simply print all tables are vacant
            if (floor->getNumVacantTables() == floor->getNumTables())
            {
                cout << "All tables are vacant" << endl;
            }
            else
            {
                cout << "Not all tables are vacant" << endl;
            }

            cout << endl << "////////////////////////////////////////////////////" << endl;
            cout << "Would you like to add another group?" << endl;
            cout << "Enter 1 for yes or 2 for no" << endl;
            int addGroup;
            cin >> addGroup;
            if(addGroup == 1){
                goto individualGroupSize;
            }
            else{
                goto exit;
            }
        } 
        else if (groupMode == 2){
            cout << "How many groups would you like to add?" << endl;
            int numGroups;
            cin >> numGroups;
            vector<CustomerComponent*> groups;
            for(int i = 1; i <= numGroups; i++){
                individualGroupSize2:
                cout << "How many people are in group " << i << "?" << endl;
                int groupSize;
                cin >> groupSize;
                if(groupSize <= 0 || groupSize > 20){
                    cout << "Group size are only allowed to be between 1 and 20" << endl;
                    goto individualGroupSize2;
                }
                CustomerComponent* group = new CustomerGroup(i);
                for(int i = 1; i <= groupSize; i++){
                    string name = "Customer-" + to_string(i);
                    group->addToGroup(new Customer(name,i));
                }
                entrance->addGroup(group);
                groups.push_back(group);
            }
            bool complete = false;
            while(!complete){
                if(entrance->isEmpty()){
                    complete = true;
                }
                else if(!entrance->seatGroup()){
                    complete = true;
                }
            }
            auto it = groups.begin();
            while(!groups.empty()){
                (*it)->signalToOrder();
                (*it)->signalForBill();
                it = groups.erase(it);
                if(!entrance->isEmpty()){
                    entrance->seatGroup();
                }
            }
            
        }
        else
        {
            cout << "Invalid input" << endl;
            goto modeInput;
        }
        
            
    }
    //Else reprompt user for input
    else{
        cout << "Invalid input" << endl;
        goto input;
    }


    
    exit:
    delete kitchen;
    delete floor;
    delete entrance;
    IngredientFactory::cleanup();
    return 0;

}

