#include "Map.h"
#include <iostream>

Map::Map() {
    // Example map initialization
    // Let's create a 5x5 grid
    grid = std::vector<std::vector<Location>>(5, std::vector<Location>(5, Location("Empty")));

    // Customize locations
    grid[0][0] = Location("Town", true);
    grid[1][1] = Location("Forest", true);
    grid[2][2] = Location("Dungeon Entrance", true);
    // Add more locations as needed


    grid[2][2].setEncounter(std::make_unique<Monster>("Goblin", "A small, green-skinned creature", 5));
}

void Map::displayLocation() const {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y].isAccessible) {
        std::cout << "You can't move in that direction." << std::endl;
    }
    else {
        std::cout << "You are at " << grid[x][y].description << "." << " [" << x << "]" << " [" << y << "]" << std::endl;
    }
}

void Map::exploreMap(Character Player) {
    char input;
    std::cout << "Enter direction (N, S, E, W) or Z to stay put: ";
    std::cin >> input;

    switch (input) {
        case 'N': y--; break;
        case 'S': y++; break;
        case 'E': x++; break;
        case 'W': x--; break;
        case 'Z': break;
        default: std::cout << "Invalid input." << std::endl; break;
    }

    if (grid[x][y].encounter) {
        grid[x][y].encounter->interact();
    }

    if (grid[x][y].item) {
        //grid[x][y].item->use();
    }
}


