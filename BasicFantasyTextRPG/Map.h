#pragma once
#ifndef MAP_H
#define MAP_H
#include "Encounters.h"
#include "Items.h"
#include "Character.h"


#include <vector>
#include <string>


struct Location {
    std::string description;
    bool isAccessible;
    std::shared_ptr<Encounter> encounter; // Optional encounter
    std::shared_ptr<Item> item; // Optional item

    Location(std::string description, bool isAccessible = true)
        : description(description), isAccessible(isAccessible) {}

    // Add functions to set encounters and items
    void setEncounter(std::shared_ptr<Encounter> enc) { encounter = std::move(enc); }
    void setItem(std::shared_ptr<Item> itm) { item = std::move(itm); }
    
};

class Map {
public:
    std::vector<std::vector<Location>> grid;
    Map();
    int x, y;
    void displayLocation() const;
    void exploreMap(Character Player);
};

#endif // MAP_H


