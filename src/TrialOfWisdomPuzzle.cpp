#include "TrialOfWisdomPuzzle.h"
#include <stdexcept>

TrialOfWisdomPuzzle::TrialOfWisdomPuzzle(const std::string& id, const std::string& description)
    : Puzzle(id, description), m_currentTrialIndex(0) {
    addHint("Each trial requires a different approach.");
    addHint("Consider the context and theme of each trial carefully.");
    addHint("Sometimes, the simplest answer is the correct one.");
}

void TrialOfWisdomPuzzle::addTrial(const std::string& trialDescription, 
                                   const std::function<bool(const std::string&)>& checkTrialSolution) {
    m_trials.emplace_back(trialDescription, checkTrialSolution);
}

bool TrialOfWisdomPuzzle::attemptSolve(const std::string& solution) {
    if (m_currentTrialIndex >= m_trials.size()) {
        return false;  // All trials completed
    }

    if (checkSolution(solution)) {
        m_trials[m_currentTrialIndex].solved = true;
        if (m_currentTrialIndex == m_trials.size() - 1) {
            setSolved(true);
            return true;
        }
        moveToNextTrial();
    }
    return false;
}

std::string TrialOfWisdomPuzzle::getCurrentTrialDescription() const {
    if (m_currentTrialIndex < m_trials.size()) {
        return m_trials[m_currentTrialIndex].description;
    }
    return "All trials completed.";
}

bool TrialOfWisdomPuzzle::moveToNextTrial() {
    if (m_currentTrialIndex < m_trials.size() - 1) {
        ++m_currentTrialIndex;
        return true;
    }
    return false;
}

size_t TrialOfWisdomPuzzle::getCurrentTrialIndex() const {
    return m_currentTrialIndex;
}

size_t TrialOfWisdomPuzzle::getTotalTrials() const {
    return m_trials.size();
}

bool TrialOfWisdomPuzzle::checkSolution(const std::string& solution) const {
    if (m_currentTrialIndex < m_trials.size()) {
        return m_trials[m_currentTrialIndex].checkSolution(solution);
    }
    return false;
}