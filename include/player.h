#pragma once
#include "Character.h"
#include "Item.h"           // For managing inventory items.
#include "ReflectionPuzzle.h"
#include "BookSortingPuzzle.h"
#include "RiddlePuzzle.h"
#include <vector>            // To store inventory items.
#include <memory>            // For smart pointers.
#include <string>            // For item names.

class Player : public Character {
private:
    std::vector<std::shared_ptr<Item>> inventory;  // Player's inventory.

public:
    // Constructor to initialize the player with a name and description.
    Player(const std::string& name, const std::string& description);

    // Inventory Management:
    void addItem(std::shared_ptr<Item> item);  // Add an item to the inventory.
    void showInventory() const;                // Display all items in the inventory.
    bool hasItem(const std::string& itemName) const;  // Check if the player has a specific item.

    // Using Items:
    void useItem(const std::string& itemName);  // Use a general item from the inventory.
    void useItemForPuzzle(Puzzle& puzzle, const std::string& itemName);  // Use an item for a puzzle.

    // Puzzle Interactions:
    void solveReflectionPuzzle(ReflectionPuzzle& puzzle);  // Interact with Reflection Puzzle.
    void solveBookPuzzle(BookSortingPuzzle& puzzle);        // Interact with Book Sorting Puzzle.
    void solveRiddlePuzzle(RiddlePuzzle& puzzle);           // Interact with Riddle Puzzle.
};
