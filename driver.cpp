#include <iostream>
#include "startMenu.h"
#include"playerInventory.h"
#include "merchant.h"
#include "plant.h"
#include "harvest.h"

// calling the harvest class
harvest grown;
// calling the plant class
plant garden;
// calling startMenu class
startMenu menu;
//Calling merchant class
merchant merchantMenu;
//Calling player inventory class
playerInventory inventory;

void inGameMenuOption(){
    
    string space = "                                         ";
    cout << "\n\n\n\n";
    cout << "Your current debt is  $"<<inventory.getDebt() << endl;
    cout << "Turn: " << grown.getTurnNumber() << endl;
    cout << space << "\n\n\n\n\n\n" << endl;
    cout << space << "Press 1 to open inventory" << endl;
    cout << space << "Press 2 to talk to merchant" << endl;
    cout << space << "Press 3 to plant" << endl;
    cout << space << "Press 4 to harvest" << endl;
    cout << space << "Press 5 to end your turn" << endl;
    cout << space << "Press 6 to quit" << endl;

    int option = 0;
        cin >> option;
        switch(option){
            case 1:
                //Inventory()
                inventory.displayInventoryMenu();
                break;
            case 2:
                //Merchant()
                // inventory equalled into merchang function to update values
                inventory = merchantMenu.displayMerchant(inventory);
                break;
            case 3:
                //planting();
               garden.plantInteractInterface();
                break;
            case 4:{
                // harvesting():
                // if turn 1, make it so this feature cannot be accessed
                char choice;
                int plotNumber = 0;
                do{
                string empty = "empty";
                cout << "What plot do you want to harvest?" << endl;
                cin >> plotNumber;
                // reads vector from plant class and stores in readVector
                vector<string> readVector = garden.getPlotStatus();
                // harvestingPlants function to change plots
                grown.harvestingPlants(plotNumber, readVector);
                // anything harvested is then updated in inventory
                inventory.addPlants(readVector, plotNumber);
                // updates what was harvested to empty in the readVector
                garden.plantsTracker(plotNumber, empty);
                } while (choice == 'y');
                break; }
            case 5:{
                //end turn();
                //when ending your turn, the seeds will turn into crops, so I put the grow function here
                vector<string> readVector = garden.getPlotStatus(); // from plant
                grown.getHarvestPlotStatus(readVector);
                vector<string> seedToPlantVector = grown.getHarvestPlotStatus(readVector);
                grown.seedToPlant(seedToPlantVector);
                int turn = 1;
                grown.turnNumberIncrement();
                break;}
            case 6:
                cout << "Quitting Game." << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }

}

int main(){

// initialzing all the values before the start of game
    garden.resetAllPlotsToEmpty();
    garden.resetPlotPlantedTracker();

// starting up the game use g++ -std=c++17 harvest.cpp plant.cpp startMenu.cpp playerInventory.cpp merchant.cpp driver.cpp
// and ./a.out
// .\driver.cpp .\merchant.cpp .\playerInventory.cpp .\plant.cpp .\harvest.cpp .\startMenu.cpp
// start menu should be a big do while 
    menu.displayMenu();
    int turn = 0;
    turn = grown.getTurnNumber();
    do{
    inGameMenuOption();

    if((inventory.getDebt() > inventory.getSavings()) && grown.getTurnNumber() == 10){
        const string RED = "\033[31m";
    
    cout << "\n\n\n\n\n\n\n";
    cout << RED;
    cout << R"(
                        ▒█░░▒█ ▒█▀▀▀█ ▒█░▒█ 　 ▒█░░░ ▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▀▀ █ █ 
                        ▒█▄▄▄█ ▒█░░▒█ ▒█░▒█ 　 ▒█░░░ ▒█░░▒█ ░▀▀▀▄▄ ▒█▀▀▀ ▀ ▀ 
                        ░░▒█░░ ▒█▄▄▄█ ░▀▄▄▀ 　 ▒█▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ ▒█▄▄▄ ▄ ▄ 

▀▀█▀▀ █▀▀█ 　 ▒█▀▀█ ▒█▀▀█ ▀█▀ ▒█▀▀▀█ ▒█▀▀▀█ ▒█▄░▒█ 　 ▒█░░▒█ ▀█▀ ▀▀█▀▀ ▒█░▒█ 　 ▒█░░▒█ ▒█▀▀▀█ ▒█░▒█ █ █ 
░▒█░░ █░░█ 　 ▒█▄▄█ ▒█▄▄▀ ▒█░ ░▀▀▀▄▄ ▒█░░▒█ ▒█▒█▒█ 　 ▒█▒█▒█ ▒█░ ░▒█░░ ▒█▀▀█ 　 ▒█▄▄▄█ ▒█░░▒█ ▒█░▒█ ▀ ▀ 
░▒█░░ ▀▀▀▀ 　 ▒█░░░ ▒█░▒█ ▄█▄ ▒█▄▄▄█ ▒█▄▄▄█ ▒█░░▀█ 　 ▒█▄▀▄█ ▄█▄ ░▒█░░ ▒█░▒█ 　 ░░▒█░░ ▒█▄▄▄█ ░▀▄▄▀ ▄ ▄)" <<endl;








    cout << "                                            LOAN SHARK" << endl;
    cout << "                                            _________" << endl;
    cout << "                                       |                |" << endl;
    cout << "                                       |                |" << endl;
    cout << "                                   _ __|                |____                     WHERE'S MY MONEY???" << endl;
    cout << "                                    |—-----------------------|" << endl;
    cout << "                                      |   \\            /  |" << endl;
    cout << "                                      |  |_|       |_|     |" << endl;
    cout << "                                      |         w          |" << endl;
    cout << "                                      |____________________|" << endl;
    cout << "          \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                \\\\\\s\\\\\\             \\\\\\\\\\\\\\\\ ----" << endl;
    cout << "                  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ -----" << endl;
    cout << "                         \\\\\\\\\\\\\\\\\\           ||||||                  \\\\\\\\\\\\\\\\\\" << endl;
    cout << "                     \\\\\\\\\\\\\\\\\\                ||||                           \\\\\\\\\\\\\\" << endl;
    cout << "              \\\\\\\\\\\\\\                         ||||                               \\\\\\\\\\\\\\ -----" << endl;
    cout << "                     \\\\\\\\\\                _ __|||____                                     \\\\\\\\\\" << endl;
    cout << "                         M               _|              |_                                     M" << endl;


    break;
    }


    else if((inventory.getDebt() < inventory.getSavings()) && grown.getTurnNumber() == 10){
        cout << R"(
                ██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗██╗██╗  
                ╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║██║██║  
                ░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║██║██║  
                ░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║╚═╝╚═╝  
                ░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║██╗██╗  
                ░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝╚═╝  

                ██████╗░███████╗██████╗░████████╗  ███████╗██████╗░███████╗███████╗██╗██╗
                ██╔══██╗██╔════╝██╔══██╗╚══██╔══╝  ██╔════╝██╔══██╗██╔════╝██╔════╝██║██║
                ██║░░██║█████╗░░██████╦╝░░░██║░░░  █████╗░░██████╔╝█████╗░░█████╗░░██║██║
                ██║░░██║██╔══╝░░██╔══██╗░░░██║░░░  ██╔══╝░░██╔══██╗██╔══╝░░██╔══╝░░╚═╝╚═╝
                ██████╔╝███████╗██████╦╝░░░██║░░░  ██║░░░░░██║░░██║███████╗███████╗██╗██╗
                ╚═════╝░╚══════╝╚═════╝░░░░╚═╝░░░  ╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚══════╝╚═╝╚═╝)"<<endl;
                break;
    }
   // else{
     //   cout << "back to menu...";
    //}

    }while(turn != 10);

}

