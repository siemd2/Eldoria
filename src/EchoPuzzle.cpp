#include "EchoPuzzle.h"
#include <sstream>
#include <cmath>
#include <algorithm>

EchoPuzzle::EchoPuzzle(const std::string& id, const std::string& description,
                       const std::vector<std::pair<int, int>>& echoPoints,
                       const std::pair<int, int>& playerPosition,
                       const std::pair<int, int>& targetPosition)
    : Puzzle(id, description), m_echoPoints(echoPoints), 
      m_playerPosition(playerPosition), m_targetPosition(targetPosition) {
    addHint("Listen carefully to how the sound bounces off the walls.");
    addHint("The echo will travel in straight lines between reflection points.");
    addHint("Try to visualize the path of the sound to reach the target.");
}

bool EchoPuzzle::attemptSolve(const std::string& solution) {
    std::istringstream iss(solution);
    std::vector<std::string> directions;
    std::string direction;
    while (iss >> direction) {
        directions.push_back(direction);
    }
    
    if (checkSolution(solution)) {
        setSolved(true);
        return true;
    }
    return false;
}

bool EchoPuzzle::checkSolution(const std::string& solution) const {
    std::istringstream iss(solution);
    std::vector<std::string> directions;
    std::string direction;
    while (iss >> direction) {
        directions.push_back(direction);
    }
    return simulateEchoPath(directions);
}

bool EchoPuzzle::simulateEchoPath(const std::vector<std::string>& directions) {
    std::pair<int, int> currentPos = m_playerPosition;
    m_currentPath.clear();
    m_currentPath.push_back(currentPos);

    for (const auto& direction : directions) {
        currentPos = getNextPosition(currentPos, direction);
        m_currentPath.push_back(currentPos);

        auto it = std::find(m_echoPoints.begin(), m_echoPoints.end(), currentPos);
        if (it == m_echoPoints.end()) {
            // If we hit a non-echo point, the path is invalid
            return false;
        }

        if (currentPos == m_targetPosition) {
            return true;
        }
    }

    // If we've gone through all directions and haven't reached the target, it's not solved
    return false;
}

std::pair<int, int> EchoPuzzle::getNextPosition(const std::pair<int, int>& current, const std::string& direction) const {
    if (direction == "N") return {current.first, current.second + 1};
    if (direction == "S") return {current.first, current.second - 1};
    if (direction == "E") return {current.first + 1, current.second};
    if (direction == "W") return {current.first - 1, current.second};
    // If an invalid direction is given, return the current position
    return current;
}

double EchoPuzzle::calculateDistance(const std::pair<int, int>& p1, const std::pair<int, int>& p2) const {
    return std::sqrt(std::pow(p2.first - p1.first, 2) + std::pow(p2.second - p1.second, 2));
}

std::string EchoPuzzle::getCurrentState() const {
    std::ostringstream oss;
    oss << "Player position: (" << m_playerPosition.first << "," << m_playerPosition.second << ")\n";
    oss << "Target position: (" << m_targetPosition.first << "," << m_targetPosition.second << ")\n";
    oss << "Echo points:\n";
    for (const auto& point : m_echoPoints) {
        oss << "(" << point.first << "," << point.second << ") ";
    }
    oss << "\nCurrent path:\n";
    for (const auto& point : m_currentPath) {
        oss << "(" << point.first << "," << point.second << ") ";
    }
    return oss.str();
}