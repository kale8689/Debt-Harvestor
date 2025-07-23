#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H

#include "startMenu.h"
#include <string>

using namespace std;
class playerInventory{
    private:
    int riceSeeds = 0, dragonSeeds = 0, pineappleSeeds =0, bananaSeeds = 0, grapeSeeds = 0;
    int ricePlants = 0, dragonPlants =0, pineapplePlants=0, bananaPlants=0,grapePlants=0;
    double playerDebt = 100000;
    double savings = 10;
    int dayCounter = 0;

    public:
        double sellPlants();
        double buySeeds();
        void setSavings(double amount);
        void subtractfromSavings(double amount);
        void addtoSavings(double amount);
        double getSavings();
        void displayInventoryMenu();
        void addSeeds(string seedName, int quantity);
        void loseSeeds(string seedName, int quantity);
        void addPlants(string plantName, int quantity);
        void losePlants(string plantName, int quantity);
        int getPlant(string plantName);
        int getSeeds(string seedName);


        
};
#endif
