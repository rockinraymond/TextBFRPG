#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <map>

class Character {
public:
    std::string race;
    std::string characterClass;
    std::map<std::string, int> attributes;
    int level, hitPoints, maxHitPoints, hitDie, experiencePoints;

    Character(const std::string& race, const std::string& characterClass);
    void setAttributes();
    void displayCharacter();
};

#endif // CHARACTER_H
