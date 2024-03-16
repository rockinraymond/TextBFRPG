// BasicFantasyTextRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Map.h"
// Include other necessary headers here

using namespace std;

// Assume Character and other classes are defined here or in included headers

void displayMainMenu() {
    cout << "\nMain Menu:\n";
    cout << "1. Explore\n";
    cout << "2. View Character\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
}

void displayRaces(std::vector<std::string> validRaces) {
    int size = validRaces.size();
    
    for (int i = 1; i <= size; i++) {
        cout << i << ". " << validRaces[i - 1] << "\n";
    }
    cout << "Enter your choice: ";
}


Character characterCreation() {
    std::vector<std::string> validRaces = { "Dwarf", "Elf", "Halfling", "Human" };
    std::vector<std::string> validClasses = { "Cleric", "Fighter", "Magic-User", "Thief" };

    bool raceSelect = false;
    bool classSelect = false;

    string name, race, characterClass;
    int choice;
    
    std::cout << "\nWhat is your name?:";
    std::cin >> name;

    cout << "\nWhat is your Race?:\n";
    while(!raceSelect){
        displayRaces(validRaces);
        std::cin >> choice;
        switch (choice) {
        case 1:
            race = "Dwarf";
            raceSelect = true;
            break;
        case 2:
            race = "Elf";
            raceSelect = true;
            break;
        case 3:
            race = "Halfling";
            raceSelect = true;
            break;
        case 4:
            race = "Human";
            raceSelect = true;
            break;
        default:
            cout << "Invalid choice, try again.";
        }
    }

    cout << "\nWhat is your Class?:\n";
    while (!classSelect) {
        displayRaces(validClasses);
        std::cin >> choice;
        switch (choice) {
        case 1:
            characterClass = "Cleric";
            classSelect = true;
            break;
        case 2:
            characterClass = "Fighter";
            classSelect = true;
            break;
        case 3:
            if ((race == "Dwarf") or (race == "Halfling")) { cout << "\nDwarves and Halflings cannot be Magic-Users.\n"; }
            else {
                characterClass = "Magic-User";
                classSelect = true;
            }
            break;
        case 4:
            characterClass = "Thief";
            classSelect = true;
            break;
        default:
            cout << "\nInvalid choice, try again.\n";
        }
    }
    
   
   
    Character playerCharacter(name, race, characterClass);
    return playerCharacter;
}



int main() {
    //create game map
    Map gameMap;
    int playerX = 0, playerY = 0; // Starting position

    // Seed for random number generation
    srand(static_cast<unsigned>(time(nullptr)));

    srand(time(NULL)); // Seed for random number generation

    cout << "Welcome to the Basic Fantasy RPG Character Creator!\n";

    //run player character creation
    Character playerCharacter = characterCreation();
    playerCharacter.displayCharacter();

    cout << "Character created successfully!\n";

    bool gameOver = false;
    int choice;

    while (!gameOver) {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
           // gameMap.exploreMap(playerCharacter);
            gameMap.displayLocation();
            break;
        case 2:
            playerCharacter.displayCharacter();
            break;
        case 3:
            cout << "Quitting the game...\n";
            gameOver = true;
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}


