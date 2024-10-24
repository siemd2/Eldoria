#include "NPC.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor implementation.
NPC::NPC(const std::string& name, const std::string& description)
    : Character(name, description) {}

// Load dialogues from a file.
void NPC::loadDialogueFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string playerInput, npcResponse;

        if (std::getline(iss, playerInput, '=') && std::getline(iss, npcResponse)) {
            dialogues[playerInput] = npcResponse;
        }
    }
}

// Main interaction function for the driver to call.
std::string NPC::interactWithPlayer(const std::string& input) {
    // Check if the input matches any stored dialogue.
    auto it = dialogues.find(input);
    if (it != dialogues.end()) {
        return it->second;  // Return the corresponding NPC response.
    }
    return "I don't understand what you're saying.";  // Default response.
}
