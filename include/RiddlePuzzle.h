#ifndef RIDDLE_PUZZLE_H
#define RIDDLE_PUZZLE_H

#include "Puzzle.h"

class RiddlePuzzle : public Puzzle {
public:
    RiddlePuzzle(const std::string& id, const std::string& description, const std::string& riddle, const std::string& answer);

    std::string getRiddle() const;
    virtual bool attemptSolve(const std::string& solution) override;

protected:
    virtual bool checkSolution(const std::string& solution) const override;

private:
    std::string m_riddle;
    std::string m_answer;
};

#endif // RIDDLE_PUZZLE_H