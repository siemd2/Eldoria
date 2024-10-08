#include "driver.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype> 

// Function to get user input from the terminal
std::string getInput() {
    std::string input;
    std::getline(std::cin, input);  // Read input from the user

    // Check if the input is valid
    if (!isValidInput(input)) {
        std::cout << "Invalid input! Only letters and numbers are allowed.\n";
        return "";
    }

    // Convert the input to lowercase
    return toLowerCase(input);
}

// Check if the input contains only letters and numbers
bool isValidInput(const std::string& input) {
    for (char ch : input) {
        if (!std::isalnum(ch)) {  // Check if each character is a letter or a number
            return false;
        }
    }
    return true;
}

// Convert a string to lowercase
std::string toLowerCase(const std::string& input) {
    std::string result = input;
    for (char& ch : result) {
        ch = std::tolower(ch);  // Convert each character to lowercase
    }
    return result;
}

// Process the input, potentially splitting it into command and arguments
std::pair<std::string, std::vector<std::string>> processInput(const std::string& input) {
    std::string command;
    std::vector<std::string> args;

    std::istringstream stream(input);
    stream >> command;  // The first word is the command

    std::string arg;
    while (stream >> arg) {  // The rest are arguments
        args.push_back(arg);
    }

    return {command, args};
}

// Function to handle different types of commands
// Placeholder for now
void handleInput(const std::string& input) {
    auto [command, args] = processInput(input);

    if (command == "look") {
        std::cout << "You look around the room.\n";
    } else if (command == "move") {
        if (args.size() < 1) {
            std::cout << "Where would you like to move?\n";
        } else {
            std::cout << "You move towards " << args[0] << ".\n";
        }
    } else if (command == "quit") {
        std::cout << "Exiting the game...\n";
        exit(0);
    } else {
        std::cout << "Unknown command: " << command << "\n";
    }
}

// Main game loop (Only the basic)
void gameLoop() {
    std::cout << "Welcome to the Eldoria!\n";

    while (true) {
        std::cout << "> ";
        std::string input = getInput();

        // Only process the input if it is valid
        if (!input.empty()) {
            handleInput(input);
        }
    }
}
