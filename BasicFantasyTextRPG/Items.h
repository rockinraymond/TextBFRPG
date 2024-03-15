#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <iostream>


class Item {
public:
    std::string name, description;
    int price, weight;
     
    Item(std::string name, std::string description, int price, int weight)
        : name(name), description(description), price(price), weight(weight) {}

    virtual ~Item() = default;

};

class Weapon : public Item {
public:
    char size;
    int damageDie;

    Weapon(std::string name, std::string description, int price, int weight, char size, int damageDie)
        : Item(name, description, price, weight), size(size), damageDie(damageDie) {}
};

class Armor : public Item {
public:
    int armorClass;

    Armor(std::string name, std::string description, int price, int weight, int armorClass)
        : Item(name, description, price, weight), armorClass(armorClass) {}
};

class Shield : public Item {
public:
    int armorBonus;

    Shield(std::string name, std::string description, int price, int weight, int armorBonus)
        : Item(name, description, price, weight), armorBonus(armorBonus) {}
};

// Add more item types like Weapons, Armor, etc., similar to Potion

#endif // ITEMS_H
