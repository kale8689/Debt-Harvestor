#include "harvest.h"
#include "plant.h"
#include "startMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

harvest::harvest() {

}

void harvest::harvestInterface(plant& garden){
    char choice;
    int plotNumber = 0;
    do{
        cout << "What plot do you want to harvest?" << endl;
        cin >> plotNumber;
        // VERY IMPORTANT calls class as object to remember plantVector data
        harvestingPlants(plotNumber, garden);
    } while (choice == 'y');
    // goes back to mainMenu
    returnMainMenu(*menu);
}

void harvest::returnMainMenu(startMenu& main){
    main.mainMenu();
}

// uses plant& garden as a way to remember data from plant class
void harvest::harvestingPlants(int plotNumber, plant& garden) {
    vector<string>& plantVector = garden.getPlotStatus();


    if (plantVector[plotNumber-1] == "empty"){
        cout << "There is nothing to harvest." << endl;
        return;
    }

    string seedType = plantVector[plotNumber-1];
    // removing Seed.txt  
    size_t pos = seedType.find("Seed.txt");
    if (pos != string::npos) {
        seedType = seedType.substr(0, pos);  // removes "Seed.txt"
    }
    cout << "You are harvesting plot " << plotNumber << " and now you have 1 " << seedType << endl;


    // or statments of all different seed types
    if (plantVector[plotNumber-1] == "riceSeed.txt" || plantVector[plotNumber-1] == "grapeSeed.txt" ||
        plantVector[plotNumber-1] == "pineappleSeed.txt" || plantVector[plotNumber-1] == "dragonSeed.txt"
        || plantVector[plotNumber-1] == "bananaSeed.txt"){
        // if plotNumber == 1 then "emptyPlotOne.txt" for all ten plots
        if(plotNumber == 1){
        garden.plantingSeeds(plotNumber, "emptyPlotOne.txt"); // Modify that plant object
        }
        else if(plotNumber == 2) garden.plantingSeeds(plotNumber, "emptyPlotTwo.txt");
        else if(plotNumber == 3) garden.plantingSeeds(plotNumber, "emptyPlotThree.txt");
        else if(plotNumber == 4) garden.plantingSeeds(plotNumber, "emptyPlotFour.txt");
        else if(plotNumber == 5) garden.plantingSeeds(plotNumber, "emptyPlotFive.txt");
        else if(plotNumber == 6) garden.plantingSeeds(plotNumber, "emptyPlotSix.txt");
        else if(plotNumber == 7) garden.plantingSeeds(plotNumber, "emptyPlotSeven.txt");
        else if(plotNumber == 8) garden.plantingSeeds(plotNumber, "emptyPlotEight.txt");
        else if(plotNumber == 9) garden.plantingSeeds(plotNumber, "emptyPlotNine.txt");
        else if(plotNumber == 10) garden.plantingSeeds(plotNumber, "emptyPlotTen.txt");
    }
    plantVector[plotNumber - 1] = "empty";
}

void harvest::seedToPlant(plant& garden){
    // for loop or read the plot 1 - 10 files using plantVector
    // if have seed files in them turn them into plant files
    // if do not have seed files leave them alone
    garden.getPlotStatus();
    vector<string>& plantVector = garden.getPlotStatus();

    int plotNumber = 0;
    for(int i = 0; i < plantVector.size(); i++){
        if(plantVector[i] == "riceSeed.txt"){
            garden.plantingSeeds(i+1, "ricePlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(plantVector[i] == "grapeSeed.txt"){
            garden.plantingSeeds(i+1, "grapePlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(plantVector[i] == "bananaSeed.txt"){
            garden.plantingSeeds(i+1, "bananaPlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(plantVector[i] == "pineappleSeed.txt"){
            garden.plantingSeeds(i+1, "pineapplePlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
        else if(plantVector[i] == "dragonSeed.txt"){
            garden.plantingSeeds(i+1, "dragonPlant.txt");
            cout << "Plot " << i+1 << " is growing!" << endl;
        }
    }
    cout << "Everything has grown! Look at your beautiful garden ~" << endl;
    // goes back to mainMenu
    returnMainMenu(*menu);
}

void harvest::setMenu(startMenu* m) {
    menu = m;
}