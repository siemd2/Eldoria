#ifndef ENVIRONMENT_MANAGER_H
#define ENVIRONMENT_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// classes
#include "character.h"
#include "npc.h"
#include "item.h"
#include "player.h"
#include "usable_item.h"

class Room {
public:
    Room(std::string name, std::string description);

    void setWall(const std::string& direction);
    void setDoor(const std::string& direction);
    bool hasWall(const std::string& direction) const;
    bool hasDoor(const std::string& direction) const;

    void addNPC(NPC* npc);
    void addItem(Item* item);

    std::string getName() const;
    void printRoomState() const;

private:
    std::string name;
    std::string description;
    std::unordered_map<std::string, bool> walls;
    std::unordered_map<std::string, bool> doors;
    std::vector<NPC*> npcs;
    std::vector<Item*> items;
};

class EnvironmentManager {
public:
    EnvironmentManager();
    void addNPCToRoom(int row, int col, NPC* npc);
    void addItemToRoom(int row, int col, Item* item);
    void movePlayer(const std::string& direction);
    void printEnvironmentState() const;

private:
    std::vector<std::vector<Room>> grid;
    int playerRow, playerCol;

    bool isValidMove(const std::string& direction) const;
};

#endif  // ENVIRONMENT_MANAGER_H
