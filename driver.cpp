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
    
    cout << "Your current debt is "<<inventory.getDebt();
    //cout << space << "\n\n\n\n\n\n" << endl;
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
                inventory.displayInventoryMenu();
                break;
            case 2:
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
                cout << "What plot do you want to harvest?" << endl;
                cin >> plotNumber;
                vector<string> readVector = garden.getPlotStatus();
                grown.harvestingPlants(plotNumber, readVector);
                } while (choice == 'y');
                break; }
            case 5:{
                //end turn();
                //when ending your turn, the seeds will turn into crops, so I put the grow function here
                vector<string> readVector = garden.getPlotStatus(); // from plant
                grown.getHarvestPlotStatus(readVector);
                vector<string> seedToPlantVector = grown.getHarvestPlotStatus(readVector);
                grown.seedToPlant(seedToPlantVector);
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

// starting up the game use g++ -std=c++17 harvest.cpp plant.cpp startMenu.cpp testPlay.cpp and ./a.out
// start menu should be a big do while 
menu.displayMenu();
int Turn = 0;
do{
inGameMenuOption();
}while(Turn == 0);

}