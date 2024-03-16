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

int Character::calculateAbiltyMod(int abilityScore) {
    switch (abilityScore) {
    case 8:
        return -1;
        break;
    case 13:
        return 1;
        break;
    case 14:
        return 1;
        break;
    case 15:
        return 1;
        break;
    case 16:
        return 2;
        break;
    case 17:
        return 2;
        break;
    case 18:
        return 3;
        break;
    default:
        return 0;
        break;
    }

    return 0;
}

void Character::setAttributes() {
    vector<string> attrNames = { "Strength", "Intelligence", "Wisdom", "Dexterity", "Constitution", "Charisma" };
    for (auto& attr : attrNames) {
        attributes[attr] = (rand() % 6) + 1 + (rand() % 6) + 1 + (rand() % 6) + 1; // 3d6

        //give the player a break
        if (attributes[attr] < 8) {
            attributes[attr] = 8;
        }
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
            attributes["Constitution"] = attributes["Constitution"] + 1;
            attributes["Charisma"] = attributes["Charisma"] - 1;
        }

        else if (race == "Elf") {
            attributes["Intelligence"] = attributes["Intelligence"] + 1;
            attributes["Constitution"] = attributes["Constitution"] - 1;
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
            int abilityMod = this->calculateAbiltyMod(attr.second);
            cout << attr.first << ": " << attr.second << " (" << abilityMod << ")" << "\n";
        }
        
    }

    void Character::equipWeapon(std::unique_ptr<Weapon> weapon) {
        this->unequipWeapon();
        equippedWeapon = std::move(weapon);
    }
    void Character::equipArmor(std::unique_ptr<Armor> armor) {
        this->unequipArmor();
        equippedArmor = std::move(armor);
    }
    void Character::equipShield(std::unique_ptr<Shield> shield) {
        this->unequipShield();
        equippedShield = std::move(shield);
    }
    void Character::addItemToInventory(std::shared_ptr<Item> item) {
        inventory.push_back(item);
    }
    void Character::unequipWeapon() {
        this->addItemToInventory(std::move(equippedWeapon));
        equippedWeapon.reset();
    }
    void Character::unequipArmor() {
        this->addItemToInventory(std::move(equippedArmor));
        equippedArmor.reset();
    }
    void Character::unequipShield() {
        this->addItemToInventory(std::move(equippedShield));
        equippedShield.reset();
    }
    void Character::removeItemFromInventory(std::string name) {
        inventory.erase(std::remove_if(inventory.begin(), inventory.end(),
            [name](const std::shared_ptr<Item>& item) { return item->name == name; }),
            inventory.end());
    }

    void Character::displayInventory() const {
        std::cout << name << "'s Inventory:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item->name << ": " << item->description << std::endl;
        }
    }


