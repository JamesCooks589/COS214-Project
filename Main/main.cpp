/**
 * @file main.cpp
 * @brief Main file for the pizzeria simulation program.
 *        This file contains the entry point of the program and the main logic for simulating the restaurant operations.
 * @author [Author Name]
 * @date [Creation Date]
 */

/*Comment out the pizza we are not creating*/
#include "Kitchen.h"
#include "Entrance.h"
#include "Table.h"
#include "Customer.h"
#include <iostream>
using namespace std;
int main() {
    string asciiHello = R"(
        
 ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄       ▄▄  ▄▄▄▄▄▄▄▄▄▄▄      
▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌     ▐░░▌▐░░░░░░░░░░░▌     
▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌   ▐░▐░▌▐░█▀▀▀▀▀▀▀▀▀      
▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌▐░▌ ▐░▌▐░▌▐░▌               
▐░▌   ▄   ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌ ▐░▐░▌ ▐░▌▐░█▄▄▄▄▄▄▄▄▄      
▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌     
▐░▌ ▐░▌░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌   ▀   ▐░▌▐░█▀▀▀▀▀▀▀▀▀      
▐░▌▐░▌ ▐░▌▐░▌▐░▌          ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌               
▐░▌░▌   ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄      
▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌     
 ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀      
                                                                                                
)";

     //Print out Welcome to the pizzeria on font size 36 using ascii codes
     cout << "//////////////////////////////////////////////////////////////////////////////////////////" << endl;
     cout<<"\033[1;36m";
        cout << asciiHello << endl;
    cout<<"\033[0m";
    cout << "//////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;

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
        cout << endl << "////////////////////////////////////////////////////" << endl;
        cout << "OUR TABLES NOW LOOK LIKE THIS" << endl;
        floor->printTables();
        cout << "////////////////////////////////////////////////////" << endl << endl;
        entrance->seatGroup();
        cout << endl << "////////////////////////////////////////////////////" << endl;
        cout << "OUR TABLES NOW LOOK LIKE THIS" << endl;
        floor->printTables();
        cout << "////////////////////////////////////////////////////" << endl << endl;

        kitchen->letChefVisitTable();


        //Let customers order
        group1->signalToOrder();
        group1->signalForBill();

        
        group2->signalToOrder();
        group2->signalForBill();
        

        //if all tables vacant simply print all tables are vacant
        if (floor->getNumVacantTables() == floor->getNumTables())
        {
            //cout in a colour
            cout<<"\033[1;32m";
            cout << "All tables are available" << endl;
            cout<<"\033[0m";
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
                cout << "\033[1;37;41m" << "Group size are only allowed to be between 1 and 20" << "\033[0m" << endl;

                goto individualGroupSize;
            }
            CustomerComponent* group = new CustomerGroup(1);
            for(int i = 1; i <= groupSize; i++){
                string name = "Customer-" + to_string(i);
                group->addToGroup(new Customer(name,i));
            }
            entrance->addGroup(group);
            entrance->seatGroup();
            cout << endl << "////////////////////////////////////////////////////" << endl;
            cout << "OUR TABLES NOW LOOK LIKE THIS" << endl;
            floor->printTables();
            cout << "////////////////////////////////////////////////////" << endl << endl;
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
                //cout in a colour
                cout<<"\033[1;32m";
                cout << "All tables are available" << endl;
                cout<<"\033[0m";
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
                    //Output error with white text and red background
                    cout << "\033[1;37;41m" << "Group size are only allowed to be between 1 and 20" << "\033[0m" << endl;

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
                    cout << endl << "////////////////////////////////////////////////////" << endl;
                    cout << "OUR TABLES NOW LOOK LIKE THIS" << endl;
                    floor->printTables();
                    cout << "////////////////////////////////////////////////////" << endl << endl;
                }
            }
            
        }
        else
        {
            cout << "\033[1;37;41m" << "Invalid input for group mode" << "\033[0m" << endl;
            goto modeInput;
        }
        
            
    }
    //Else reprompt user for input
    else{
        cout << "\033[1;37;41m" << "Invalid input" << "\033[0m";
        goto input;
    }


    
    exit:
    //Cout in colour that the restaurant is closing
    string asciiBye = R"(
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠴⠒⠤⣄⡀⠀⠀⠀⠀⢠⣾⠉⠉⠉⠉⠑⠒⠦⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠋⠀⠀⠀⠀⠀⠉⠲⡄⠀⢠⠏⡏⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⢤⣤⣀⡀⠀⠀⠀⠀⠀⢰⡏⠀⠀⠀⠀⠀⠀⠀⠀⠘⢆⢸⠀⡇⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⢸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⠈⠙⠢⣄⠀⠀⣿⠀⠀⠀⢰⣿⣷⣆⠀⠀⠀⠘⣾⠀⠇⠀⠀⠀⢾⣿⣿⣦⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣀⡤⣄⠀⠀⠀⣼⡇⠀⠀⠀⢀⣀⠀⠀⠀⠈⠳⣴⢿⡄⠀⠀⢸⡿⣿⢹⠀⠀⠀⠀⣿⠀⡆⠀⠀⠀⣼⠻⣇⣸⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⡴⠚⠉⠀⠀⠈⠳⡄⠀⣿⡇⠀⠀⠀⣿⣿⡷⡄⠀⠀⠀⢹⣆⢧⠀⠀⠀⠙⠿⠋⠀⠀⠀⠀⣿⠀⡇⠀⠀⠀⠙⠛⠉⠁⠀⠀⠀⢠⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢠⠟⠀⠀⠀⠀⢀⣤⣾⣷⣀⡇⢣⠀⠀⠀⢻⣟⣄⣷⠀⠀⠀⠈⣿⣾⣆⠀⠀⠀⠀⠀⠀⠀⠀⣸⢿⢰⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣠⡏⠀⠀⠀⣼⡟⣿⣿⡿⠛⠉⢻⣞⣧⠀⠀⠀⠉⠛⠁⠀⠀⠀⠀⡿⣿⣿⣦⣀⠀⠀⠀⠀⣠⣾⡏⢸⣠⣧⣤⣄⣤⣤⣤⣤⣤⣴⣾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⠀⠀⠀⢸⠋⣿⠛⠁⠀⠀⠀⠀⠻⣯⣷⣄⠀⠀⠀⠀⠀⠀⢀⣼⠁⠘⠿⣿⣿⣻⣿⣿⣿⣿⠏⠀⣾⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⡟⣇⠀⠀⠈⢿⣏⢧⣴⣶⡆⠀⠀⠀⢿⣿⣿⢳⢦⣤⣤⣤⣶⣿⠟⠀⠀⠀⠀⠉⠉⠛⠋⢩⡤⠖⠒⠛⠛⡿⢁⣾⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣷⠀⠀⠀⠀⢀⣤⠤⠤⣀⡀⠀
⣇⠘⣆⠀⠀⠀⠙⠻⠿⠛⠃⠀⠀⠀⣸⡙⠻⢿⣿⣿⣿⣿⠿⠋⠀⣀⡤⠤⠒⠚⠳⣄⢠⣿⠁⠀⠀⠀⢠⠇⡏⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠀⠀⢀⡴⢫⡇⠀⠀⠀⠈⠙
⠘⣶⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⣀⣼⣿⠇⠀⠀⠀⣀⣀⣀⠀⢀⣼⣿⣦⡀⠀⠀⠀⠈⢻⡏⠀⠀⠀⠀⡞⠀⡇⢸⠀⠀⠀⠀⢰⣾⣶⣶⣶⣶⣶⡏⠀⠀⡼⠀⡞⠀⠀⠀⠀⠀⢸
⠀⠈⠻⣿⣿⣿⣶⢶⡶⡶⣶⣾⣿⡿⠋⣠⠴⠚⠉⠁⠀⠉⠙⠺⡿⢿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⣸⠃⢰⠀⢸⠀⠀⠀⠀⠘⠛⠛⠿⠿⢿⡏⠀⠀⢰⠃⢠⠇⠀⠀⠀⠀⠀⠌
⠀⠀⠀⠈⠙⠻⠿⠼⠽⠿⠿⠟⠋⢰⡟⠁⠀⠀⢀⣤⣄⡀⠀⠀⠹⡆⠙⢿⣿⣿⣦⡀⠀⠀⠀⠀⢰⡇⠀⢸⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⡞⠀⡜⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⢳⡀⠀⠀⠈⢿⡿⠇⠀⠀⣼⠃⠀⠀⠙⢿⣿⣿⣷⠀⠀⠀⠈⡇⠀⢸⠀⡄⠀⠀⠀⠀⢰⣶⣤⣤⣤⣼⠃⠀⢰⠃⢰⠃⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⠀⢣⠀⠀⠀⠀⠀⠀⠀⠈⠋⠉⠲⣄⠀⠀⠙⢿⠸⡄⠀⠀⠀⢳⠀⢸⠀⡇⠀⠀⠀⠀⠸⣿⣿⣿⣿⣃⠀⠀⣞⣠⣾⣤⣀⣀⠀⠀⡄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣆⠈⣇⠀⠀⠀⠀⣠⣤⣀⠀⠀⠀⠘⣆⠀⠀⠸⡄⢳⠀⠀⠀⠸⡆⢸⠀⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠘⠻⢿⣿⣿⣿⣿⡿⠞⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡆⠘⡄⠀⠀⠀⢻⣿⣿⠆⠀⠀⠀⢸⠀⠀⠀⣇⠘⡆⠀⢀⣀⣧⢸⢀⣿⣶⣤⣤⣤⣀⣀⣀⠀⢀⡏⠀⢀⣴⠟⠁⠀⠀⠈⢳⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⠹⡄⠀⠀⠈⠉⠁⠀⠀⠀⣠⡾⠀⠀⠀⢹⢀⣿⣿⣿⡿⠃⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⢰⣯⡏⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⠀⠹⡄⠀⠀⠀⢀⣠⣴⣾⣿⠃⠀⠀⠀⠘⠿⠟⠛⠛⠁⠀⠀⠀⠉⠉⠉⠛⠛⠛⠿⠟⠁⠀⠀⢾⣿⣷⣄⡀⠀⠀⢀⡼⠃⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⠀⢳⣴⣶⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣦⣿⣿⡿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⣀⠀⠀⠀⠀⠀⠀⠀
)";
cout << asciiBye << endl;
    delete kitchen;
    delete floor;
    delete entrance;
    IngredientFactory::cleanup();
    return 0;

}

