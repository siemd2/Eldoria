#include "Player.h"
#include <iostream>

// Constructor initializes the player with a name and description.
Player::Player(const std::string& name, const std::string& description)
    : Character(name, description) {}

// Add an item to the player's inventory.
void Player::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
    std::cout << "Added " << item->getName() << " to your inventory." << std::endl;
}

// Display all items currently in the inventory.
void Player::showInventory() const {
    std::cout << "Inventory:" << std::endl;
    if (inventory.empty()) {
        std::cout << "  (Empty)" << std::endl;
    } else {
        for (const auto& item : inventory) {
            std::cout << "  - " << item->getName() << std::endl;
        }
    }
}

// Check if the player has a specific item in their inventory.
bool Player::hasItem(const std::string& itemName) const {
    for (const auto& item : inventory) {
        if (item->getName() == itemName) {
            return true;
        }
    }
    return false;
}

// Use a general item from the inventory.
void Player::useItem(const std::string& itemName) {
    for (const auto& item : inventory) {
        if (item->getName() == itemName) {
            std::cout << item->Use() << std::endl;  // Call the item's use effect.
            return;
        }
    }
    std::cout << "You don't have a " << itemName << " in your inventory." << std::endl;
}

// Use an item specifically for a puzzle (like the Crystal Lens for Reflection Puzzle).
void Player::useItemForPuzzle(Puzzle& puzzle, const std::string& itemName) {
    for (const auto& item : inventory) {
        if (item->getName() == itemName) {
            std::cout << item->Use() << std::endl;

            // Special logic: Activate the Reflection Puzzle with the Crystal Lens.
            if (itemName == "Crystal Lens") {
                auto* reflectionPuzzle = dynamic_cast<ReflectionPuzzle*>(&puzzle);
                if (reflectionPuzzle) {
                    reflectionPuzzle->SetHasLens(true);
                    std::cout << "The Crystal Lens activates the reflection puzzle!" << std::endl;
                }
            }
            return;
        }
    }
    std::cout << "You don't have the " << itemName << " required for this puzzle." << std::endl;
}

// Handle Reflection Puzzle interactions, including placing mirrors and attempting solutions.
void Player::solveReflectionPuzzle(ReflectionPuzzle& puzzle) {
    std::cout << "You encounter a reflection puzzle!" << std::endl;
    std::string input;

    while (true) {
        std::cout << "Enter a command (place, attempt, quit): ";
        std::getline(std::cin, input);

        if (input == "place") {
            int x, y, rotation;
            std::cout << "Enter x, y, and rotation: ";
            std::cin >> x >> y >> rotation;
            std::cin.ignore();  // Clear input buffer.

            if (puzzle.PlaceMirror(x, y, rotation)) {
                std::cout << "Placed a mirror at (" << x << ", " << y << ") with rotation " 
                          << rotation << " degrees." << std::endl;
            } else {
                std::cout << "Failed to place the mirror. Try again." << std::endl;
            }
        } else if (input == "attempt") {
            if (puzzle.AttemptSolution("")) {
                std::cout << "You solved the reflection puzzle!" << std::endl;
                break;
            } else {
                std::cout << "The beam did not reach the target. Try again!" << std::endl;
            }
        } else if (input == "quit") {
            std::cout << "Exiting the puzzle." << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Try 'place', 'attempt', or 'quit'." << std::endl;
        }
    }
}

// Handle Book Sorting Puzzle interactions.
void Player::solveBookPuzzle(BookSortingPuzzle& puzzle) {
    std::cout << "You encounter a bookshelf with empty slots." << std::endl;
    std::string input;
    while (true) {
        std::cout << "Enter a command (place, remove, attempt, quit): ";
        std::getline(std::cin, input);

        if (input == "place") {
            int bookIndex, position;
            std::cout << "Enter book index and position: ";
            std::cin >> bookIndex >> position;
            std::cin.ignore();

            if (puzzle.PlaceBook(std::to_string(bookIndex), position)) {
                std::cout << "Placed book " << bookIndex << " at position " << position << "." << std::endl;
            } else {
                std::cout << "Failed to place the book. Try again." << std::endl;
            }
        } else if (input == "remove") {
            int position;
            std::cout << "Enter position to remove book from: ";
            std::cin >> position;
            std::cin.ignore();

            std::string removedBook = puzzle.RemoveBook(position);
            if (!removedBook.empty()) {
                std::cout << "Removed book from position " << position << "." << std::endl;
            } else {
                std::cout << "No book found at that position." << std::endl;
            }
        } else if (input == "attempt") {
            if (puzzle.AttemptSolution("")) {
                std::cout << "You solved the book puzzle!" << std::endl;
                break;
            } else {
                std::cout << "Incorrect arrangement. Try again." << std::endl;
            }
        } else if (input == "quit") {
            std::cout << "Exiting the puzzle." << std::endl;
            break;
        }
    }
}

// Handle Riddle Puzzle interactions.
void Player::solveRiddlePuzzle(RiddlePuzzle& puzzle) {
     std::string input;
    while (true) {
        std::cout << "Enter your answer or type 'hint' for a clue, 'quit' to exit: ";
        std::getline(std::cin, input);

        if (input == "hint") {
            std::cout << puzzle.GetHint() << std::endl;
        } else if (input == "quit") {
            std::cout << "Exiting the puzzle." << std::endl;
            break;
        } else {
            if (puzzle.AttemptSolution(input)) {
                std::cout << "Correct! You solved the riddle!" << std::endl;
                break;
            } else {
                std::cout << "Wrong answer. Try again." << std::endl;
            }
        }
    }
}
