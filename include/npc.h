#ifndef NPC_H
#define NPC_H

#include "entity.h"
#include <string>

class NPC : public Entity {
public:
    NPC(const std::string& name, int id, const std::string& asciiArt, const std::string& dialog);

    std::string getDialog() const;
    std::string getArt() const;

private:
    std::string dialog;
};

#endif // NPC_H
