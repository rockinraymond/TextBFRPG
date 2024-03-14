#include "Character.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

Character::Character(const std::string& race, const std::string& characterClass)
    : race(race), characterClass(characterClass) {
    setAttributes();
}

    void Character::setAttributes() {
        vector<string> attrNames = { "Strength", "Intelligence", "Wisdom", "Dexterity", "Constitution", "Charisma" };
        for (auto& attr : attrNames) {
            attributes[attr] = (rand() % 6) + 1 + (rand() % 6) + 1 + (rand() % 6) + 1; // 3d6
            
            if (attributes[attr] < 8) {
                attributes[attr] = 8;
            }

            level = 1;

            if (characterClass == "Fighter") {
                hitDie = 8;
            }
            else if (characterClass == "Thief" or characterClass == "Cleric") {
                hitDie = 6;
            }
            else if (characterClass == "Magic-User") {
                hitDie = 4;
            }

            if (race == "Dwarf") {
                attributes["Constituion"] = attributes["Constituion"] + 1;
                attributes["Charisma"] = attributes["Charisma"] - 1;
            }

            else if (race == "Elf") {
                attributes["Intelligence"] = attributes["Intelligence"] + 1;
                attributes["Constituion"] = attributes["Constituion"] - 1;
                if (hitDie > 6) {
                    hitDie = 6;
                }
            }

            else if (race == "Halfling") {
                attributes["Dexterity"] = attributes["Dexterity"] + 1;
                attributes["Strength"] = attributes["Strength"] - 1;
            }





        }

        // Modify attributes based on race and class if necessary
        // For simplicity, we're just setting up the structure.
        // You can add specific logic for race/class attribute adjustments.
    }

    void Character::displayCharacter() {
        cout << "Race: " << race << ", Class: " << characterClass << "\n";
        cout << "Level: " << level << "\n";
        for (auto& attr : attributes) {
            cout << attr.first << ": " << attr.second << "\n";
        }
        
    }

