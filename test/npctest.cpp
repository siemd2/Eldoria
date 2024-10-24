#include "NPC.h"
#include <gtest/gtest.h>
#include <memory>
#include <fstream>

// Helper function to create a test dialogue file.
void createTestDialogueFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "hello=Hello, traveler!\n";
    file << "bye=Farewell, adventurer!\n";
    file.close();
}

// Test: Load dialogue from file.
TEST(NPCTest, LoadDialogueFromFile) {
    // Create a test dialogue file.
    const std::string filename = "test_dialogue.txt";
    createTestDialogueFile(filename);

    // Create an NPC and load dialogue from the file.
    auto npc = std::make_shared<NPC>("Test NPC", "A friendly NPC.");
    npc->loadDialogueFromFile(filename);

    // Verify loaded dialogues.
    EXPECT_EQ(npc->interactWithPlayer("hello"), "Hello, traveler!");
    EXPECT_EQ(npc->interactWithPlayer("bye"), "Farewell, adventurer!");
}

// Test: Default response for unknown input.
TEST(NPCTest, DefaultResponse) {
    // Create an NPC.
    auto npc = std::make_shared<NPC>("Test NPC", "A friendly NPC.");

    // Simulate dialogue loading with known inputs.
    npc->loadDialogueFromFile("test_dialogue.txt");

    // Check the NPC's response to an unknown input.
    EXPECT_EQ(npc->interactWithPlayer("unknown"), "I don't understand what you're saying.");
}
