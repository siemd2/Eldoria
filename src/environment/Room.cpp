#include "Room.h"

Room::Room(std::string roomName, std::string roomDescription)
    : name(roomName), description(roomDescription) {
    // Initialize all walls and doors to false (no walls or doors by default)
    walls = { {"North", false}, {"South", false}, {"East", false}, {"West", false} };
    doors = { {"North", false}, {"South", false}, {"East", false}, {"West", false} };
}

std::string Room::getName() const {
    return name;
}

std::string Room::getDescription() const {
    return description;
}

void Room::setWall(std::string direction) {
    if (walls.find(direction) != walls.end()) {
        walls[direction] = true;
    }
}

void Room::setDoor(std::string direction) {
    if (doors.find(direction) != doors.end()) {
        doors[direction] = true;
    }
}

bool Room::hasWall(std::string direction) const {
    return walls.at(direction);
}

bool Room::hasDoor(std::string direction) const {
    return doors.at(direction);
}
