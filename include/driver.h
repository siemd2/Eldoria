#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include <utility>

std::string getInput();
bool isValidInput(const std::string& input);
std::string toLowerCase(const std::string& input);
std::pair<std::string, std::vector<std::string>> processInput(const std::string& input);
void handleInput(const std::string& input);
void gameLoop();

#endif // DRIVER_H
