#include "npc.h"

NPC::NPC(const std::string& name, int id, const std::string& asciiArt, const std::string& dialog)
    : Entity(name, id, asciiArt), dialog(dialog) {}

std::string NPC::getDialog() const {
    return dialog;
}

std::string NPC::getArt() const {
    return asciiArt;  // This uses the inherited asciiArt from the Entity class
}
