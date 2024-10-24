#pragma once
#include <string>
#include <vector>

class Character {
protected:
    std::string name;
    std::string description;
    std::vector<std::string> inventory;

public:
    // Constructor
    Character(const std::string& name, const std::string& description);

    // Virtual destructor for proper cleanup when using inheritance.
    virtual ~Character() = default;

    // Accessor functions.
    std::string getName() const;
    std::string getDescription() const;

    // Inventory management.
    void addItem(const std::string& item);
    void showInventory() const;

    // Pure virtual function: Forces derived classes to implement it.
    virtual void interact() const = 0;
};
