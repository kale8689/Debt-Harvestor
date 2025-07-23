#include <iostream>
#include "merchant.h"
#include<vector>
#include<algorithm>
#include <string>
#include<iomanip>
#include"playerInventory.h"
#include"startMenu.h"

using namespace std;

playerInventory merchant:: displayMerchant(playerInventory inv){
    
    cout << "Welcome to the Merchant!"<<endl;
    cout << "Here you can buy new seeds, and sell your plants!"<<endl;
    cout << "Be on the lookout, sometimes there will be special offers!"<<endl;
    cout << "Sometimes there'll be a bonus for selling or discounts for buying"<<endl;
    cout << "\n\n";
    const string BLUE = "\033[34m";
    const string RED = "\033[31m";
    const string RESET = "\033[0m";
    string space = "                                         ";

    cout << space << BLUE;
    cout << "         MERCHANT" << endl;
    cout << space << "       —-—————————  " << endl;
    cout << space << " ____/############\\____" << endl;
    cout << space << "/_______   __   _________\\              WHATCHA WANT???"<< endl;
    cout << space << "   |                 |                     YEA BUYIN OR SELLIN?" << endl;
    cout << space << "   |     @       @   |" << endl;
    cout << space << "   |            0    |" << endl;
    cout << space << "   |_________________|           |--^^^--|" << endl;
    cout << space << "           \\\\\\                   (  $$   )" << endl;
    cout << space << " \\\\\\           \\\\\\\\        \\\\\\\\  —------   " << endl;
    cout << space << " \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << space << "                 \\\\\\\\\\\\" << endl;
    cout << space << "                \\\\\\\\" << endl;
    cout << space << "             \\\\\\\\" << endl;
    cout << space << "     \\\\\\\\\\\\          \\\\\\\\\\\\" << endl;
    cout <<RESET;

    cout << "Press 1 to continue"<<endl;
    cout << "Press 2 to exit"<< endl;

    int merchOption;
    cin >> merchOption;

    int buyOrSell;
    if(merchOption == 1){
        cout << "\n\n\n\n\n";
        cout<<"Would you like to buy or sell?"<<endl;
        cout <<"Press 1 to buy"<<endl;
        cout <<"Press 2 to sell"<<endl;
        cout <<"Press 3 to exit"<<endl;
        cin >> buyOrSell;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        if(buyOrSell == 1){
           inv = displayMenuSeeds(inv);
        }
        else if(buyOrSell == 2){
            inv = displayMenuPlants(inv);
        }
        else if(buyOrSell == 3){
            cout << "Exiting"<<endl;
        }
        else{
            cout << "Invalid option;"<<endl;
        }

    }
    else{
        cout << "Exiting"<<endl;
    }

    return inv;
    }



double getRandomPrice(double min, double max) {
    double scale = rand() / (double) RAND_MAX;
    return min + scale * (max - min);
}


playerInventory merchant:: displayMenuSeeds(playerInventory inv){
    
    srand(time(0));
    double total = 0;
    double cost =0;
    int continueBuy;


    do {
        vector<Seeds> seedlisting{
            {"Pineapple", "The price of pineapple seeds is: ", getRandomPrice(3, 6)},
            {"Grape", "The price of grape seeds is: ", getRandomPrice(4, 7)},
            {"Dragonfruit", "The price of dragonfruit seeds is: ", getRandomPrice(5, 8)},
            {"Rice", "The price of rice seeds is: ", getRandomPrice(1, 3)},
            {"Banana", "The price of banana seeds is: ", getRandomPrice(2, 4)}
        };

        // Bubble sort 
        for (int i = 0; i < seedlisting.size(); i++) {
            for (int j = 0; j < seedlisting.size() - 1; j++) {
                if (seedlisting[j].price < seedlisting[j + 1].price) {
                    swap(seedlisting[j], seedlisting[j + 1]);
                }
            }
        }

        cout << fixed << setprecision(2);
        for (const auto &seed : seedlisting) {
        cout << seed.listing << seed.price << endl;
    }
        cout << "Enter the index (0-4) of which seed you want to buy: ";
        int index;
        cin >> index;
        cout<<"\n\n\n\n\n\n";

        if (index >= 0 && index < static_cast<int>(seedlisting.size())) {
            Seeds selectedSeed = seedlisting[index];

            

            cout << "Enter how many you want to buy: ";
            int quantity;
            cin >> quantity;
    

            double cost = selectedSeed.price * quantity;

    if (cost > inv.getSavings()) {
        cout << "Insufficient funds! You need $" << cost << " but only have $" << inv.getSavings() << endl;
}   else {
        cout << "You've bought " << quantity << " " << selectedSeed.name << " seeds for $" << cost << endl;

    total += cost;

    inv.subtractfromSavings(cost);  // only subtract after checking
    inv.addSeeds(selectedSeed.name, quantity);  // update inventory

    cout << "Purchase successful! Remaining savings: $" 
         << inv.getSavings() << endl;
}


        }
        else {
        cout << "Invalid index! Please enter a number between 0 and 4." << endl;
        }

        cout << "Buy another? (1 for yes, 0 for no): ";
        cin >> continueBuy;

    } while (continueBuy == 1);

    cout << "Total spent: $" << total << endl;

    return inv;

}



playerInventory merchant:: displayMenuPlants(playerInventory inv){
    
    srand(time(0));
    double total = 0;
    double cost =0;
    int continueBuy;



    do {
        vector<Plants> plantlisting{
        {"Pineapple","The sell price of pineapple is: ",getRandomPrice(10,15)},
        {"Grapes","The sell price of grapes is: ",getRandomPrice(7,9)},
        {"Dragonfruit","The sell price of dragonfruit is: ",getRandomPrice(15,18)},
        {"Rice","The sell price of rice is: ",getRandomPrice(5,7)},
        {"Banana","The sell price of banana is: ",getRandomPrice(9,11)},
        
    };
    
      // Bubble sort 
        for (int i = 0; i < plantlisting.size(); i++) {
            for (int j = 0; j < plantlisting.size() - 1; j++) {
                if (plantlisting[j].plantPrice < plantlisting[j + 1].plantPrice) {
                    swap(plantlisting[j], plantlisting[j + 1]);
                }
            }
        }

        cout << fixed << setprecision(2);

    for(const auto &plant : plantlisting){
        cout << plant.plantlisting << plant.plantPrice<<endl;
    }

    cout << "Enter the index (0-4) of which plant you want to sell: ";
        int index;
        cin >> index;
        cout<<"\n\n\n\n\n\n";

        if (index >= 0 && index < static_cast<int>(plantlisting.size())) {
            Plants selectedPlants = plantlisting[index];

            

            cout << "Enter how many you want to sell: ";
            int quantity;
            cin >> quantity;
    
            int currentOwned = inv.getPlant(selectedPlants.name);

            if (quantity <= 0) {
                cout << "Invalid amount." << endl;
            }

            else if(quantity > currentOwned){
                cout << "You don't have enough " << selectedPlants.name 
                << " plants to sell. You only have " << currentOwned << "." << endl;
            }

            else{

            cout << "You've sold " << quantity << " " << selectedPlants.name
                 << " plants for $" << selectedPlants.plantPrice * quantity << endl;

            total += selectedPlants.plantPrice * quantity;

            inv.addtoSavings(total); 
            inv.losePlants(selectedPlants.name, quantity);
            cout << "Sale successful! Remaining savings: $" << inv.getSavings() << endl;
            }

        }
        else {
        cout << "Invalid index! Please enter a number between 0 and 4." << endl;
        }

        cout << "sell another? (1 for yes, 0 for no): ";
        cin >> continueBuy;

    } while (continueBuy == 1);

    cout << "Total earned: $" << total << endl;

    return inv;


}






