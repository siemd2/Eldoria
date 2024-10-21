#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>

class Puzzle {
 public:
    Puzzle(const std::string& id, const std::string& description);
    virtual ~Puzzle() = default;

    std::string getId() const;
    std::string getDescription() const;
    bool isSolved() const;

    virtual bool attemptSolve(const std::string& solution) = 0;
    std::string getHint() const;

 protected:
    void setSolved(bool solved);
    void addHint(const std::string& hint);

 private:
    std::string m_id;
    std::string m_description;
    bool m_solved;
    std::vector<std::string> m_hints;
    size_t m_currentHintIndex;

    virtual bool checkSolution(const std::string& solution) const = 0;
};

#endif  // PUZZLE_H