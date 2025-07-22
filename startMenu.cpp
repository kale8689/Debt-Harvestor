#include <iostream>
using namespace std;
#include "startMenu.h"
#include "plant.h"
#include "harvest.h"
#include <string>

void startMenu::displayMenu(){
        menuOptions();
        int option = 0;
        cin >> option;

        switch(option){
            case 1:
                startGame();
                break;
            case 2:
                cout << "Quitting Game." << endl;
                return;
            default:
                cout << "Invalid Choice" << endl;
        }
}

void startMenu::menuOptions(){
    string space = "                                                 ";
    cout << space << "\n\n\n\n\n\n" << endl;
    cout << space << R"(

                        ·▄▄▄▄  ▄▄▄ .▄▄▄▄· ▄▄▄▄▄     ▄ .▄ ▄▄▄· ▄▄▄   ▌ ▐·▄▄▄ ..▄▄ ·▄▄▄▄▄      ▄▄▄  
                        ██▪ ██ ▀▄.▀·▐█ ▀█▪•██      ██▪▐█▐█ ▀█ ▀▄ █·▪█·█▌▀▄.▀·▐█ ▀.•██  ▪     ▀▄ █·
                        ▐█· ▐█▌▐▀▀▪▄▐█▀▀█▄ ▐█.▪    ██▀▐█▄█▀▀█ ▐▀▀▄ ▐█▐█•▐▀▀▪▄▄▀▀▀█▄▐█.▪ ▄█▀▄ ▐▀▀▄ 
                        ██. ██ ▐█▄▄▌██▄▪▐█ ▐█▌·    ██▌▐▀▐█ ▪▐▌▐█•█▌ ███ ▐█▄▄▌▐█▄▪▐█▐█▌·▐█▌.▐▌▐█•█▌
                        ▀▀▀▀▀•  ▀▀▀ ·▀▀▀▀  ▀▀▀     ▀▀▀ · ▀  ▀ .▀  ▀. ▀   ▀▀▀  ▀▀▀▀ ▀▀▀  ▀█▄▀▪.▀  ▀

)" << endl;
    cout << space << R"(\|/ \|/ START MENU \|/ \|/)" << endl;
    cout << space << "Press 1 to start the game" << endl;
    cout << space << "Press 2 to quit the game" << endl;
    cout << space << "Enter choice: " << endl;
    cout << space << "\n\n\n\n\n\n" << endl;
}


void startMenu::startGame(){
    // start game story
    cout << "Game is starting..." << endl;
    string space = "                                                 ";
    cout << space << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "Once upon a time... in 2025... you went to college to major in Anthroplogy." << endl;
    cout << "After four years of hardwork and dedication you were ready to go into the job market" << endl;
    cout << "However, you realized you had no idea what anthroplogists did, and neither did the current job market" << endl;
    cout << "Then you checked your student loans and saw you were $5000 in debt!" << endl;
    cout << "And if you didn't pay it off in ten turns, the loan sharks will send you to prison camp." << endl;
    cout << "So you picked up a hoe, went back to your home state of Kansas, and started farming." << endl;

    //tutorial turn 1
    cout << "Back at home you found 5 rice seeds from your Aunt Melissa, she's so awesome." << endl;
    cout << "You have a total of ten turns in this game. This turn you will plant all 5 of your seeds" << endl;
    cout << "Then you will have to end your turn. On the next turn, your crops will be ready to harvest." << endl;
    cout << "There's an indicator to keep track of your money as well as what turn it is." << endl;

    cout << R"(
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~plot~one~~~~~~~ ~~~~~plot~two~~~~~~~ ~~~~plot~three~~~~~~ ~~~~~plot~four~~~~~~ ~~~~~plot~five~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~plot~seven~~~~~ ~~~~~plot~seven~~~~~ ~~~~plot~eight~~~~~~ ~~~~~plot~nine~~~~~~ ~~~~~plot~ten~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~)" << endl;

    //tutorial turn 2
    cout << "First you will want to harvest your crops. Then, afterwards you will talk to the merchant." << endl;
    cout << "When talking to the merchant, you can sell your crops, and then buy more seeds to plant." << endl;
    cout << "The merchants' prices are different everytime, so predicting what seeds to buy can be difficult." << endl;

    // call function that calls mainMenu and inGameMenuOption 
    mainMenu();
}

void startMenu::mainMenu(){
    inGameMenuOption();
        int option = 0;
        cin >> option;
        plant garden;
        harvest grown;
        switch(option){
            case 1:
                //openInventory();
                break;
            case 2:
                //talkMerchant();
                break;
            case 3:
                plantingFeature(garden);
                break;
            case 4:
                // if turn 1, make it so this feature cannot be accessed
                harvestingFeature(grown, garden);
                break;
            case 5:
                //when ending your turn, the seeds will turn into crops, so I put the grow function here
                seedsGrow(grown, garden);
                break;
            case 6:
                cout << "Quitting Game." << endl;
                return;
            default:
                cout << "Invalid Choice" << endl;
        }
}

void startMenu::harvestingFeature(harvest& grown, plant& garden){
    grown.harvestInterface(garden);
}

void startMenu::seedsGrow(harvest& grown, plant& garden){
    grown.seedToPlant(garden);
}

void startMenu::plantingFeature(plant& garden){
    garden.plantInteractInterface();
}

void startMenu::inGameMenuOption(){
    string space = "                                                 ";
    cout << space << "\n\n\n\n\n\n" << endl;
    cout << space << "Press 1 to open inventory" << endl;
    cout << space << "Press 2 to talk to merchant" << endl;
    cout << space << "Press 3 to plant" << endl;
    cout << space << "Press 4 to harvest" << endl;
    cout << space << "Press 5 to end your turn" << endl;
    cout << space << "Press 6 to quit" << endl;
}
