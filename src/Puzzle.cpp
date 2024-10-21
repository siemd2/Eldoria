#include "Puzzle.h"
#include <stdexcept>

Puzzle::Puzzle(const std::string& id, const std::string& description)
    : m_id(id), m_description(description), m_solved(false), m_currentHintIndex(0) {}

std::string Puzzle::getId() const {
    return m_id;
}

std::string Puzzle::getDescription() const {
    return m_description;
}

bool Puzzle::isSolved() const {
    return m_solved;
}

std::string Puzzle::getHint() const {
    if (m_hints.empty()) {
        return "No hints available for this puzzle.";
    }
    
    std::string hint = m_hints[m_currentHintIndex];
    m_currentHintIndex = (m_currentHintIndex + 1) % m_hints.size();
    return hint;
}

void Puzzle::setSolved(bool solved) {
    m_solved = solved;
}

void Puzzle::addHint(const std::string& hint) {
    m_hints.push_back(hint);
}