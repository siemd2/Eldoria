#ifndef ECHO_PUZZLE_H
#define ECHO_PUZZLE_H

#include "Puzzle.h"
#include <vector>
#include <utility>

class EchoPuzzle : public Puzzle {
public:
    EchoPuzzle(const std::string& id, const std::string& description, 
                const std::vector<std::pair<int, int>>& echoPoints,
                const std::pair<int, int>& playerPosition,
                const std::pair<int, int>& targetPosition);

    virtual bool attemptSolve(const std::string& solution) override;
    std::string getCurrentState() const;

protected:
    virtual bool checkSolution(const std::string& solution) const override;

private:
    std::vector<std::pair<int, int>> m_echoPoints;
    std::pair<int, int> m_playerPosition;
    std::pair<int, int> m_targetPosition;
    std::vector<std::pair<int, int>> m_currentPath;

    bool simulateEchoPath(const std::vector<std::string>& directions);
    std::pair<int, int> getNextPosition(const std::pair<int, int>& current, const std::string& direction) const;
    double calculateDistance(const std::pair<int, int>& p1, const std::pair<int, int>& p2) const;
};

#endif // ECHO_PUZZLE_H
