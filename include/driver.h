#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include <utility>

/**
 * @brief Gets user input from the terminal.
 *
 * This function reads a line of input from the standard input (stdin) and validates it.
 * If the input is invalid, an error message is displayed, and an empty string is returned.
 *
 * @return A lowercase string containing the user input, or an empty string if invalid.
 */
std::string getInput();

/**
 * @brief Checks if the provided input is valid.
 *
 * Valid input is defined as containing only alphanumeric characters (letters and numbers).
 *
 * @param input The string to validate.
 * @return true if the input is valid, false otherwise.
 */
bool isValidInput(const std::string& input);

/**
 * @brief Converts a given string to lowercase.
 *
 * This function transforms all uppercase letters in the input string to their lowercase
 * equivalents while leaving other characters unchanged.
 *
 * @param input The string to convert.
 * @return A new string that is the lowercase version of the input.
 */
std::string toLowerCase(const std::string& input);

/**
 * @brief Processes the user input by splitting it into a command and arguments.
 *
 * This function takes a string input and separates it into the first word as the command
 * and the remaining words as arguments. The command and arguments are returned as a pair.
 *
 * @param input The input string to process.
 * @return A pair where the first element is the command and the second element is a vector
 *         of strings representing the arguments.
 */
std::pair<std::string, std::vector<std::string>> processInput(const std::string& input);

/**
 * @brief Handles user commands.
 *
 * This function processes the input command and executes the appropriate actions based on
 * the command received. Currently supports commands like "look", "move", and "quit".
 *
 * @param input The user command input.
 */
void handleInput(const std::string& input);

/**
 * @brief Runs the main game loop.
 *
 * This function initializes the game, displays a welcome message, and enters a loop where
 * it continuously prompts the user for input and processes it until the game is exited.
 */
void gameLoop();

#endif // DRIVER_H
