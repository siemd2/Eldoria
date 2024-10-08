#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    Entity(const std::string& name, int id, const std::string& asciiArt);

    std::string getName() const;
    int getId() const;
    std::string getAsciiArt() const;

protected:
    std::string name;
    int id;
    std::string asciiArt;
};

#endif // ENTITY_H
