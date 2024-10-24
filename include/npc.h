#pragma once
#include "Character.h"
#include <map>
#include <string>

class NPC : public Character {
private:
    std::map<std::string, std::string> dialogues;

public:
    NPC(const std::string& name, const std::string& description);

    // Load dialogues from a file.
    void loadDialogueFromFile(const std::string& filename);

    // This is the key function the driver will use.
    std::string interactWithPlayer(const std::string& input);
};
