#include <iostream>
#include "Room.h"

int main() {
    // Create a new Room object
    Room village("Village of Luminara", "A quaint village where your journey begins.");

    // Print room name and description
    std::cout << "Room Name: " << village.getName() << std::endl;
    std::cout << "Description: " << village.getDescription() << std::endl;

    // Set walls and doors
    village.setWall("North");
    village.setWall("South");
    village.setWall("West");
    village.setDoor("East");

    // Print the state of each wall and door
    std::cout << "\nWall and Door Configuration:" << std::endl;
    std::cout << "North Wall: " << (village.hasWall("North") ? "Yes" : "No") << std::endl;
    std::cout << "South Wall: " << (village.hasWall("South") ? "Yes" : "No") << std::endl;
    std::cout << "East Wall: " << (village.hasWall("East") ? "Yes" : "No") << std::endl;
    std::cout << "West Wall: " << (village.hasWall("West") ? "Yes" : "No") << std::endl;

    std::cout << "\nDoors:" << std::endl;
    std::cout << "North Door: " << (village.hasDoor("North") ? "Yes" : "No") << std::endl;
    std::cout << "South Door: " << (village.hasDoor("South") ? "Yes" : "No") << std::endl;
    std::cout << "East Door: " << (village.hasDoor("East") ? "Yes" : "No") << std::endl;
    std::cout << "West Door: " << (village.hasDoor("West") ? "Yes" : "No") << std::endl;

    return 0;
}
