// ItemFactory.h
#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Items.h"

#include <memory>
#include <string>

class ItemFactory {
public:
    static std::unique_ptr<Item> createItem(std::string name, std::string description, int price, int weight) {
        return std::make_unique<Item>(name, description, price, weight);
    }

    static std::unique_ptr<Weapon> createWeapon(std::string name, std::string description, int price, int weight, char size, int damageDie) {
        return std::make_unique<Weapon>(name, description, price, weight, size, damageDie);
    }

    static std::unique_ptr<Armor> createArmor(std::string name, std::string description, int price, int weight, int armorClass) {
        return std::make_unique<Armor>(name, description, price, weight, armorClass); 
    }

    static std::unique_ptr<Shield> createShield(std::string name, std::string description, int price, int weight, int armorClass) {
        return std::make_unique<Shield>(name, description, price, weight, armorClass); 
    }

    
};

#endif // ITEMFACTORY_H