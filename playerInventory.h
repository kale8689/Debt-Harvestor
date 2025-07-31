#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H

#include "startMenu.h"
#include <string>

using namespace std;
class playerInventory{
    private:
    int riceSeeds = 0, dragonSeeds = 0, pineappleSeeds =0, bananaSeeds = 0, grapeSeeds = 0;
    int ricePlants = 10, dragonPlants = 10 , pineapplePlants= 10, bananaPlants= 10,grapePlants=10;
    double playerDebt = 10000;
    double savings = 1000;
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
        void addPlants(vector<string> readVectorPlant, int i);
        void losePlants(string plantName, int quantity);
        int getPlant(string plantName);
        int getSeeds(string seedName);
        double getDebt();


        
};
#endif
