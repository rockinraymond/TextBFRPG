#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H

#include <string>
#include <iostream>

class Encounter {
public:
    std::string name;
    std::string description;

    Encounter(std::string name, std::string description)
        : name(name), description(description) {}

    virtual void interact() const = 0; // Pure virtual function for interaction
};

class Monster : public Encounter {
public:
    int strength;

    Monster(std::string name, std::string description, int strength)
        : Encounter(name, description), strength(strength) {}

    void interact() const override {
        std::cout << "You encounter a " << name << ": " << description << std::endl;
        // Add combat or escape logic here
    }
};

// Add more encounter types like NPCs, Traps, etc., similar to Monster

#endif // ENCOUNTERS_H
