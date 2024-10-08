#include "entity.h"

Entity::Entity(const std::string& name, int id, const std::string& asciiArt)
    : name(name), id(id), asciiArt(asciiArt) {}

std::string Entity::getName() const {
    return name;
}

int Entity::getId() const {
    return id;
}

std::string Entity::getAsciiArt() const {
    return asciiArt;
}
