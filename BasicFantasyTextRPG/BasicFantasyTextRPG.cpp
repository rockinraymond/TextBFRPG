// BasicFantasyTextRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Character.h"
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

// Function to check if the choice is valid and prompt again if not
template<typename T>
bool isValidChoice(const T& choice, const std::vector<T>& validChoices) {
    return std::find(validChoices.begin(), validChoices.end(), choice) != validChoices.end();
}

template<typename T>
T getValidInput(const std::string& prompt, const std::vector<T>& validChoices) {
    T input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!isValidChoice(input, validChoices)) {
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (!isValidChoice(input, validChoices));
    return input;
}

Character characterCreation() {
    std::vector<std::string> validRaces = { "Dwarf", "Elf", "Halfling", "Human" };
    std::vector<std::string> validClasses = { "Cleric", "Fighter", "Magic-User", "Thief" };

    string race, characterClass;
    
    race = getValidInput<std::string>("Choose race (Dwarf, Elf, Halfling, Human): ", validRaces);
    characterClass = getValidInput<std::string>("Choose class (Cleric, Fighter, Magic-User, Thief): ", validClasses);


    Character playerCharacter(race, characterClass);
    return playerCharacter;
}

int main() {
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
            cout << "Exploring the world...\n";
            // Exploration logic here
            break;
        case 2:
            cout << "Displaying character information...\n";
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


