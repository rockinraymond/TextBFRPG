#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <iostream>

class Item {
public:
    std::string name;
    std::string description;

    Item(std::string name, std::string description)
        : name(name), description(description) {}

    virtual void use() const = 0; // Pure virtual function for using the item
};

class Potion : public Item {
public:
    int healAmount;

    Potion(std::string name, std::string description, int healAmount)
        : Item(name, description), healAmount(healAmount) {}

    void use() const override {
        std::cout << "Using " << name << " heals you for " << healAmount << " HP." << std::endl;
        // Add healing logic here
    }
};

// Add more item types like Weapons, Armor, etc., similar to Potion

#endif // ITEMS_H
