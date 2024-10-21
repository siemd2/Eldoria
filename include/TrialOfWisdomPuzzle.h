// TrialOfWisdomPuzzle.h
#ifndef TRIAL_OF_WISDOM_PUZZLE_H
#define TRIAL_OF_WISDOM_PUZZLE_H

#include "Puzzle.h"
#include <vector>
#include <functional>

class TrialOfWisdomPuzzle : public Puzzle {
public:
    TrialOfWisdomPuzzle(const std::string& id, const std::string& description);

    void addTrial(const std::string& trialDescription, const std::function<bool(const std::string&)>& checkTrialSolution);
    virtual bool attemptSolve(const std::string& solution) override;
    std::string getCurrentTrialDescription() const;
    bool moveToNextTrial();
    size_t getCurrentTrialIndex() const;
    size_t getTotalTrials() const;

protected:
    virtual bool checkSolution(const std::string& solution) const override;

private:
    struct Trial {
        std::string description;
        std::function<bool(const std::string&)> checkSolution;
        bool solved;

        Trial(const std::string& desc, const std::function<bool(const std::string&)>& check)
            : description(desc), checkSolution(check), solved(false) {}
    };

    std::vector<Trial> m_trials;
    size_t m_currentTrialIndex;
};

#endif // TRIAL_OF_WISDOM_PUZZLE_H