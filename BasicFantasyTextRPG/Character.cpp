#include "Character.h"
#include "Items.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

Character::Character(const std::string& name, const std::string& race, const std::string& characterClass)
    :name(name), race(race), characterClass(characterClass) {
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
        experiencePoints = 0;

        //Class Hit die selection
        if (characterClass == "Fighter") {
            hitDie = 8;
        }
        else if (characterClass == "Thief" or characterClass == "Cleric") {
            hitDie = 6;
        }
        else if (characterClass == "Magic-User") {
            hitDie = 4;
        }

        //Race Ability Modifiers
        if (race == "Dwarf") {
            attributes["Constituion"] = attributes["Constituion"] + 1;
            attributes["Charisma"] = attributes["Charisma"] - 1;
        }

        else if (race == "Elf") {
            attributes["Intelligence"] = attributes["Intelligence"] + 1;
            attributes["Constituion"] = attributes["Constituion"] - 1;
            //Elves cannot have a hit die greater than d6
            if (hitDie > 6) {
                hitDie = 6;
            }
        }

        else if (race == "Halfling") {
            attributes["Dexterity"] = attributes["Dexterity"] + 1;
            attributes["Strength"] = attributes["Strength"] - 1;
        }

        //first level gives max hit die for hp
        maxHitPoints = hitDie;
        hitPoints = maxHitPoints;

    }
}

        // Modify attributes based on race and class if necessary
        // For simplicity, we're just setting up the structure.
        // You can add specific logic for race/class attribute adjustments.
    

    void Character::displayCharacter() {
        cout << "Displaying character information...\n";
        cout << "Race: " << race << ", Class: " << characterClass << "\n";
        cout << "Level: " << level << "\n";
        cout << "Exp:" << experiencePoints << "\n";
        cout << "Hit Points: " << hitPoints << " / " << maxHitPoints << "\n";
        for (auto& attr : attributes) {
            cout << attr.first << ": " << attr.second << "\n";
        }
        
    }

    void equipWeapon(std::unique_ptr<Weapon> weapon) {

    }
    void equipArmor(std::unique_ptr<Armor> armor) {

    }
    void equipShield(std::unique_ptr<Armor> shield) {

    }
    void addItemToInventory(std::unique_ptr<Item> item) {

    }
    void unequipWeapon() {

    }
    void unequipArmor() {

    }
    void unequipShield() {

    }
    void removeItemFromInventory() {

    }

