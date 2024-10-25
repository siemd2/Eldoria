#include "../include/environment_manager.h"

int main() {
    EnvironmentManager env;

    // Add an NPC and item to rooms
    NPC* gorwin = new NPC("Gorwin", "A mysterious old man.");
    Item* lens = new Item("Crystal Lens", "Used to solve puzzles.");

    env.addNPCToRoom(0, 1, gorwin);
    env.addItemToRoom(2, 1, lens);

    env.printEnvironmentState();

    // Simulate player movement
    env.movePlayer("South");
    env.movePlayer("West");
    env.movePlayer("North");  // Invalid move

    return 0;
}
