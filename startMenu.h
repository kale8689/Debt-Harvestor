#ifndef STARTMENU_H
#define STARTMENU_H

class plant;
class harvest;

class startMenu{
public:
    startMenu();
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
    plant* garden;    // persistent plant object
    harvest* grown;   // persistent harvest object

};

#endif
