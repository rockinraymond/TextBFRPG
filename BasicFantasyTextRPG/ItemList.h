// ItemList.h
#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "ItemFactory.h"
#include <unordered_map>
#include <string>
#include <functional>

// Using std::function to store factory calls
std::unordered_map<std::string, std::function<std::unique_ptr<Item>()>> predefinedItems = {
    
    //Weapons
    {"Hand Axe", []() { return ItemFactory::createWeapon("Hand Axe", "A small, light axe that is balanced for throwing", 400, 5, 'S', 6); }},
    {"Battle Axe", []() { return ItemFactory::createWeapon("Battle Axe", "A sturdy axe designed to deliver heavy, chopping blows.", 700, 7, 'M', 8); }},
    {"Great Axe", []() { return ItemFactory::createWeapon("Great Axe", "A large, heavy axe that can only be wielded with two hands.", 1400, 15, 'L', 10); }},
    {"Dagger", []() { return ItemFactory::createWeapon("Dagger", "A short and sharpened blade meant for thrusting attacks.", 200, 1, 'S', 4); }},
    {"Short Sword", []() { return ItemFactory::createWeapon("Short Sword", "A straight thrusting weapon, much like a dagger, but with a longer blade", 600, 3, 'S', 6); }},
    {"Long Sword", []() { return ItemFactory::createWeapon("Long Sword", "A straight bladed weapon, designed for both slashing and thrusting.", 1000, 4, 'M', 8); }},
    {"Scimitar", []() { return ItemFactory::createWeapon("Scimitar", "A curved bladed weapon, designed for slashing attacks.", 1000, 4, 'M', 8); }},
    {"Two-handed Sword", []() { return ItemFactory::createWeapon("Two-handed Sword", "A large, straight double-edged blade, meant to be used with both hands.", 1800, 10, 'L', 10); }},
    {"Warhammer", []() { return ItemFactory::createWeapon("Warhammer", "A small, balanced hammer with a hooked pick.", 400, 6, 'S', 6); }},
    {"Mace", []() { return ItemFactory::createWeapon("Mace", "A weighted blunt weapon with a flanged head.", 600, 10, 'M', 8); }},
    {"Maul", []() { return ItemFactory::createWeapon("Maul", "A large and heavy blunt weapon that requires both hands for use.", 1000, 16, 'L', 10); }},
    {"Club", []() { return ItemFactory::createWeapon("Club", "A crude wooden blunt weapon.", 20, 1, 'M', 4); }},
    {"Walking Stick", []() { return ItemFactory::createWeapon("Walking Stick", "A humble walking aid that can  be used as a weapon in a pinch.", 20, 1, 'M', 4); }},
    {"Quarter Staff", []() { return ItemFactory::createWeapon("Quarter Staff", "A sturdy wooden staff designed for martial combat.", 200, 4, 'L', 6); }},
    {"Short Spear", []() { return ItemFactory::createWeapon("Short Spear", "A wooden shaft with a sharpened metal point that can be used with a shield.", 500, 5, 'M', 6); }},
    {"Long Spear", []() { return ItemFactory::createWeapon("Long Spear", "A large pointed weapon that requires the use of two hands.", 600, 6, 'L', 8); }},

    //Armor
    {"Leather Armor", []() { return ItemFactory::createArmor("Leather Armor", "Light armor that consists of pieces of hardened and layered leather.", 2000, 15, 13); }},
    {"Chain Mail", []() { return ItemFactory::createArmor("Chain Mail", "Medium armor that consists of rings of metal that are interwoven in a leather garment.", 6000, 40, 15); }},
    {"Plate Mail", []() { return ItemFactory::createArmor("Plate Mail", "Heavy armor that consists of Large plates of hard metal are fashioned to cover the wearer.", 30000, 50, 17); }},

    //Shields
    {"Shield", []() { return ItemFactory::createShield("Shield", "A metal reinforced wooden shield that provides extra protection in combat.", 700, 5, 1); }},


};

#endif // ItemList_H