#include "RiddlePuzzle.h"
#include <algorithm>

RiddlePuzzle::RiddlePuzzle(const std::string& id, const std::string& description, const std::string& riddle, const std::string& answer)
    : Puzzle(id, description), m_riddle(riddle), m_answer(answer) {
    addHint("Think carefully about the words in the riddle.");
    addHint("The answer is often a common object or concept.");
}

std::string RiddlePuzzle::getRiddle() const {
    return m_riddle;
}

bool RiddlePuzzle::attemptSolve(const std::string& solution) {
    if (checkSolution(solution)) {
        setSolved(true);
        return true;
    }
    return false;
}

bool RiddlePuzzle::checkSolution(const std::string& solution) const {
    // Convert both strings to lowercase for case-insensitive comparison
    std::string lowerSolution = solution;
    std::string lowerAnswer = m_answer;
    std::transform(lowerSolution.begin(), lowerSolution.end(), lowerSolution.begin(), ::tolower);
    std::transform(lowerAnswer.begin(), lowerAnswer.end(), lowerAnswer.begin(), ::tolower);
    
    return lowerSolution == lowerAnswer;
}