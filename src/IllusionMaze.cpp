#include "IllusionMazePuzzle.h"
#include <sstream>
#include <algorithm>

IllusionMazePuzzle::IllusionMazePuzzle(const std::string& id, const std::string& description,
                                       const std::vector<std::vector<char>>& maze,
                                       const std::pair<int, int>& startPosition,
                                       const std::pair<int, int>& endPosition)
    : Puzzle(id, description), m_maze(maze), 
      m_startPosition(startPosition), m_endPosition(endPosition), m_currentPosition(startPosition) {
    addHint("Not all paths are as they seem. Watch out for illusions.");
    addHint("Some tiles may transport you to unexpected locations.");
    addHint("Remember your path, as backtracking might be necessary.");

    // Initialize illusion effects
    m_illusionEffects['A'] = {-1, -1};  // Teleport northwest
    m_illusionEffects['B'] = {1, 1};    // Teleport southeast
    m_illusionEffects['C'] = {-1, 1};   // Teleport southwest
    m_illusionEffects['D'] = {1, -1};   // Teleport northeast
}

bool IllusionMazePuzzle::attemptSolve(const std::string& solution) {
    m_currentPosition = m_startPosition;  // Reset position
    if (checkSolution(solution)) {
        setSolved(true);
        return true;
    }
    return false;
}

bool IllusionMazePuzzle::checkSolution(const std::string& solution) const {
    std::vector<char> moves(solution.begin(), solution.end());
    return navigateMaze(moves);
}

bool IllusionMazePuzzle::navigateMaze(const std::vector<char>& moves) {
    for (char move : moves) {
        m_currentPosition = getNextPosition(m_currentPosition, move);
        if (!isValidMove(m_currentPosition)) {
            return false;  // Hit a wall or out of bounds
        }
        applyIllusion(m_currentPosition);
        if (m_currentPosition == m_endPosition) {
            return true;  // Reached the end
        }
    }
    return false;  // Didn't reach the end
}

std::pair<int, int> IllusionMazePuzzle::getNextPosition(const std::pair<int, int>& current, char move) const {
    switch (move) {
        case 'N': return {current.first, current.second - 1};
        case 'S': return {current.first, current.second + 1};
        case 'E': return {current.first + 1, current.second};
        case 'W': return {current.first - 1, current.second};
        default: return current;  // Invalid move, don't change position
    }
}

bool IllusionMazePuzzle::isValidMove(const std::pair<int, int>& position) const {
    if (position.first < 0 || position.first >= m_maze[0].size() ||
        position.second < 0 || position.second >= m_maze.size()) {
        return false;  // Out of bounds
    }
    return m_maze[position.second][position.first] != '#';  // '#' represents a wall
}

void IllusionMazePuzzle::applyIllusion(std::pair<int, int>& position) {
    char currentTile = m_maze[position.second][position.first];
    auto it = m_illusionEffects.find(currentTile);
    if (it != m_illusionEffects.end()) {
        position.first += it->second.first;
        position.second += it->second.second;
        // Ensure we're still in bounds after applying the illusion
        position.first = std::max(0, std::min(static_cast<int>(m_maze[0].size()) - 1, position.first));
        position.second = std::max(0, std::min(static_cast<int>(m_maze.size()) - 1, position.second));
    }
}

std::string IllusionMazePuzzle::getCurrentState() const {
    std::ostringstream oss;
    oss << "Current position: (" << m_currentPosition.first << "," << m_currentPosition.second << ")\n";
    oss << "Maze state:\n";
    for (size_t i = 0; i < m_maze.size(); ++i) {
        for (size_t j = 0; j < m_maze[i].size(); ++j) {
            if (std::make_pair(j, i) == m_currentPosition) {
                oss << 'P';  // Player position
            } else if (std::make_pair(j, i) == m_startPosition) {
                oss << 'S';  // Start position
            } else if (std::make_pair(j, i) == m_endPosition) {
                oss << 'E';  // End position
            } else {
                oss << m_maze[i][j];
            }
        }
        oss << '\n';
    }
    return oss.str();
}