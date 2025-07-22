#ifndef HARVEST_H
#define HARVEST_H
#include<vector>
#include<string>
#include "plant.h"
using namespace std;

class harvest{
public:
// function to update all seed images to harvest images
void seedToPlant(plant& garden);
// interface to interact with harvest
void harvestInterface(plant& garden);
// pick the plotnumber
void harvestingPlants(int plotNumber, plant& garden);
void returnMainMenu(startMenu& main);
private:

};

#endif