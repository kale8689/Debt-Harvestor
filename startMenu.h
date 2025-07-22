#ifndef STARTMENU_H
#define STARTMENU_H
#include "plant.h"
#include "harvest.h"

class startMenu{
public:
    void displayMenu();
    void mainMenu();
    // returning plant function from plant class
    void plantingFeature(plant& garden);
    // returning seedToPlant function from harvest class
    void seedsGrow(harvest& grown, plant& garden);
    // returning harvesting plants function from harvest class
    void harvestingFeature(harvest& grown, plant& garden);


private:
    void menuOptions();
    void startGame();
    void inGameMenuOption();
    
};

#endif
