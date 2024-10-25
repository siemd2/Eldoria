#include "environment_manager.h"


// Room class implementation
Room::Room(std::string name, std::string description)
    : name(name), description(description) {
    walls = { {"North", true}, {"South", true}, {"East", true}, {"West", true} };
    doors = { {"North", false}, {"South", false}, {"East", false}, {"West", false} };
}

void Room::setWall(const std::string& direction) {
    walls[direction] = true;
}

void Room::setDoor(const std::string& direction) {
    doors[direction] = true;
    walls[direction] = false;
}

bool Room::hasWall(const std::string& direction) const {
    return walls.at(direction);
}

bool Room::hasDoor(const std::string& direction) const {
    return doors.at(direction);
}

void Room::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

void Room::addItem(Item* item) {
    items.push_back(item);
}

std::string Room::getName() const {
    return name;
}

void Room::printRoomState() const {
    std::cout << "Room: " << name << "\nDescription: " << description << "\n";
    for (const auto& wall : walls) {
        std::cout << wall.first << " Wall: " << (wall.second ? "Yes" : "No") << "\n";
    }
    for (const auto& door : doors) {
        std::cout << door.first << " Door: " << (door.second ? "Yes" : "No") << "\n";
    }
    std::cout << "NPCs in this room:\n";
    for (const auto& npc : npcs) {
        std::cout << npc->getName() << "\n";
    }
    std::cout << "Items in this room:\n";
    for (const auto& item : items) {
        std::cout << item->getName() << "\n";
    }
}

// EnvironmentManager Class Implementation
EnvironmentManager::EnvironmentManager()
    : playerRow(1), playerCol(1) {
    // Initialize a 3x3 grid of rooms
    grid.resize(3, std::vector<Room>(3, Room("Empty Room", "An empty room with nothing special.")));

    // Example: Customize some rooms
    grid[0][1] = Room("Entrance", "The entrance to the dungeon.");
    grid[2][1] = Room("Exit", "The way out to freedom.");
}

void EnvironmentManager::addNPCToRoom(int row, int col, NPC* npc) {
    grid[row][col].addNPC(npc);
}

void EnvironmentManager::addItemToRoom(int row, int col, Item* item) {
    grid[row][col].addItem(item);
}

bool EnvironmentManager::isValidMove(const std::string& direction) const {
    if (direction == "North" && playerRow > 0) return true;
    if (direction == "South" && playerRow < 2) return true;
    if (direction == "East" && playerCol < 2) return true;
    if (direction == "West" && playerCol > 0) return true;
    return false;
}

void EnvironmentManager::movePlayer(const std::string& direction) {
    if (isValidMove(direction)) {
        if (direction == "North") --playerRow;
        if (direction == "South") ++playerRow;
        if (direction == "East") ++playerCol;
        if (direction == "West") --playerCol;
        std::cout << "Moved to: " << grid[playerRow][playerCol].getName() << "\n";
    } else {
        std::cout << "Invalid move!\n";
    }
}

void EnvironmentManager::printEnvironmentState() const {
    for (const auto& row : grid) {
        for (const auto& room : row) {
            room.printRoomState();
            std::cout << "-------------------\n";
        }
    }
}
