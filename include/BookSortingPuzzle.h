#ifndef LIGHT_REFLECTION_PUZZLE_H
#define LIGHT_REFLECTION_PUZZLE_H

#include "Puzzle.h"
#include <vector>
#include <utility>

class LightReflectionPuzzle : public Puzzle {
public:
    LightReflectionPuzzle(const std::string& id, const std::string& description, 
                          const std::vector<std::pair<int, int>>& mirrorPositions,
                          const std::pair<int, int>& lightSource,
                          const std::pair<int, int>& target);

    virtual bool attemptSolve(const std::string& solution) override;
    std::string getCurrentState() const;

protected:
    virtual bool checkSolution(const std::string& solution) const override;

private:
    std::vector<std::pair<int, int>> m_mirrorPositions;
    std::pair<int, int> m_lightSource;
    std::pair<int, int> m_target;
    std::vector<std::pair<int, int>> m_currentPath;

    bool simulateLightPath();
    void resetSimulation();
    std::pair<int, int> getNextPosition(const std::pair<int, int>& current, const std::pair<int, int>& direction) const;
    std::pair<int, int> reflectLight(const std::pair<int, int>& direction) const;
};

#endif // LIGHT_REFLECTION_PUZZLE_H