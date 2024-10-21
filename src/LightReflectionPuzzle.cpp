#include "LightReflectionPuzzle.h"
#include <sstream>
#include <algorithm>

LightReflectionPuzzle::LightReflectionPuzzle(const std::string &id, const std::string &description,
                                             const std::vector<std::pair<int, int>> &mirrorPositions,
                                             const std::pair<int, int> &lightSource,
                                             const std::pair<int, int> &target)
    : Puzzle(id, description), m_mirrorPositions(mirrorPositions), m_lightSource(lightSource), m_target(target)
{
    addHint("Try to visualize the path of the light beam.");
    addHint("Remember, light reflects at the same angle it hits a mirror.");
    addHint("You may need to use multiple mirrors to reach the target.");
}

bool LightReflectionPuzzle::attemptSolve(const std::string &solution)
{
    resetSimulation();
    std::istringstream iss(solution);
    int x, y;
    char comma;
    while (iss >> x >> comma >> y)
    {
        m_mirrorPositions.push_back({x, y});
    }

    if (checkSolution(solution))
    {
        setSolved(true);
        return true;
    }
    return false;
}

bool LightReflectionPuzzle::checkSolution(const std::string &solution) const
{
    return simulateLightPath();
}

bool LightReflectionPuzzle::simulateLightPath()
{
    std::pair<int, int> currentPos = m_lightSource;
    std::pair<int, int> direction = {1, 0}; // Start moving right
    m_currentPath.clear();
    m_currentPath.push_back(currentPos);

    while (true)
    {
        currentPos = getNextPosition(currentPos, direction);
        m_currentPath.push_back(currentPos);

        if (currentPos == m_target)
        {
            return true;
        }

        auto it = std::find(m_mirrorPositions.begin(), m_mirrorPositions.end(), currentPos);
        if (it != m_mirrorPositions.end())
        {
            direction = reflectLight(direction);
        }

        // Check if out of bounds or stuck in a loop
        if (currentPos.first < 0 || currentPos.first > 10 ||
            currentPos.second < 0 || currentPos.second > 10 ||
            m_currentPath.size() > 100)
        {
            return false;
        }
    }
}

void LightReflectionPuzzle::resetSimulation()
{
    m_currentPath.clear();
}

std::pair<int, int> LightReflectionPuzzle::getNextPosition(const std::pair<int, int> &current,
                                                           const std::pair<int, int> &direction) const
{
    return {current.first + direction.first, current.second + direction.second};
}

std::pair<int, int> LightReflectionPuzzle::reflectLight(const std::pair<int, int> &direction) const
{
    return {direction.second, direction.first}; // Simple 90-degree reflection
}

std::string LightReflectionPuzzle::getCurrentState() const
{
    std::ostringstream oss;
    oss << "Light source: (" << m_lightSource.first << "," << m_lightSource.second << ")\n";
    oss << "Target: (" << m_target.first << "," << m_target.second << ")\n";
    oss << "Mirror positions:\n";
    for (const auto &pos : m_mirrorPositions)
    {
        oss << "(" << pos.first << "," << pos.second << ") ";
    }
    oss << "\nCurrent light path:\n";
    for (const auto &pos : m_currentPath)
    {
        oss << "(" << pos.first << "," << pos.second << ") ";
    }
    return oss.str();
}