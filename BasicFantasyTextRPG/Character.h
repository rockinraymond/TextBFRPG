#ifndef CHARACTER_H
#define CHARACTER_H

#include "Items.h"
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <iostream>




class Character {
private:
    std::unique_ptr<Weapon> equippedWeapon;
    std::unique_ptr<Armor> equippedArmor;
    std::unique_ptr<Shield> equippedShield;
    std::vector<std::shared_ptr<Item>> inventory;

public:
    std::string name, race, characterClass;  
    std::map<std::string, int> attributes;
    std::map<std::string, int> savingThrows;
    int level, hitPoints, maxHitPoints, hitDie, armorClass, attackBonus, experiencePoints;
 
    Character(const std::string& name, const std::string& race, const std::string& characterClass);
    void setAttributes();
    void displayCharacter();
    
    void equipWeapon(std::unique_ptr<Weapon> weapon);
    void equipArmor(std::unique_ptr<Armor> armor);
    void equipShield(std::unique_ptr<Shield> shield);
    void addItemToInventory(std::shared_ptr<Item> item);
    void unequipWeapon();
    void unequipArmor();
    void unequipShield();
    void removeItemFromInventory(std::string name);
    void displayInventory() const;

    int calculateAbiltyMod(int abilityScore);
    

   

};

#endif // CHARACTER_H
