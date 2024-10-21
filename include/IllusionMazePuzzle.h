// IllusionMazePuzzle.h
#ifndef ILLUSION_MAZE_PUZZLE_H
#define ILLUSION_MAZE_PUZZLE_H

#include "Puzzle.h"
#include <vector>
#include <map>

class IllusionMazePuzzle : public Puzzle {
public:
    IllusionMazePuzzle(const std::string& id, const std::string& description, 
                       const std::vector<std::vector<char>>& maze,
                       const std::pair<int, int>& startPosition,
                       const std::pair<int, int>& endPosition);

    virtual bool attemptSolve(const std::string& solution) override;
    std::string getCurrentState() const;

protected:
    virtual bool checkSolution(const std::string& solution) const override;

private:
    std::vector<std::vector<char>> m_maze;
    std::pair<int, int> m_startPosition;
    std::pair<int, int> m_endPosition;
    std::pair<int, int> m_currentPosition;
    std::map<char, std::pair<int, int>> m_illusionEffects;

    bool navigateMaze(const std::vector<char>& moves);
    std::pair<int, int> getNextPosition(const std::pair<int, int>& current, char move) const;
    bool isValidMove(const std::pair<int, int>& position) const;
    void applyIllusion(std::pair<int, int>& position);
};

#endif // ILLUSION_MAZE_PUZZLE_H