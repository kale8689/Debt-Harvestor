#ifndef HARVEST_H
#define HARVEST_H
#include<vector>
#include<string>
using namespace std;

class startMenu;
class plant;

class harvest{
public:
harvest();
void setMenu(startMenu* m);
// function to update all seed images to harvest images
void seedToPlant(plant& garden);
// interface to interact with harvest
void harvestInterface(plant& garden);
// pick the plotnumber
void harvestingPlants(int plotNumber, plant& garden);
// return main menu
void returnMainMenu(startMenu& main);

private:
    //plant* garden;    // persistent plant object
    //startMenu* menu;   // persistent menu object
    startMenu* menu = nullptr;
};

#endif