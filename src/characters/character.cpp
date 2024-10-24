#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, const std::string& description)
    : name(name), description(description) {}

std::string Character::getName() const {
    return name;
}

std::string Character::getDescription() const {
    return description;
}

void Character::addItem(const std::string& item) {
    inventory.push_back(item);
}

void Character::showInventory() const {
    std::cout << name << "'s Inventory:" << std::endl;
    for (const std::string& item : inventory) {
        std::cout << "- " << item << std::endl;
    }
}
