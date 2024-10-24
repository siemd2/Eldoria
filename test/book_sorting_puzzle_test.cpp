#include <gtest/gtest.h>
#include "book_sorting_puzzle.h"

class BookSortingPuzzleTest : public ::testing::Test {
 protected:
    void SetUp() override {
        // Create test books
        books_ = {
            std::make_shared<Book>("B1", "Book 1", "First inscription", "Theme A"),
            std::make_shared<Book>("B2", "Book 2", "Second inscription", "Theme A"),
            std::make_shared<Book>("B3", "Book 3", "Third inscription", "Theme B")
        };

        // Define valid sequences
        valid_sequences_ = {
            {"B1", "B2", "B3"},
            {"B2", "B1", "B3"}
        };

        // Create puzzle
        puzzle_ = std::make_unique<BookSortingPuzzle>(
            "Test Puzzle",
            "Arrange the books correctly",
            books_,
            valid_sequences_,
            "Try arranging by theme",
            3  // max attempts
        );
    }

    std::vector<std::shared_ptr<Book>> books_;
    std::vector<std::vector<std::string>> valid_sequences_;
    std::unique_ptr<BookSortingPuzzle> puzzle_;
};

TEST_F(BookSortingPuzzleTest, InitialStateIsEmpty) {
    auto arrangement = puzzle_->GetCurrentArrangement();
    EXPECT_EQ(arrangement.size(), 3);
    for (const auto& slot : arrangement) {
        EXPECT_TRUE(slot.empty());
    }
}

TEST_F(BookSortingPuzzleTest, PlaceBookValidPosition) {
    EXPECT_TRUE(puzzle_->PlaceBook("B1", 0));
    auto book = puzzle_->GetBookAt(0);
    ASSERT_NE(book, nullptr);
    EXPECT_EQ(book->GetId(), "B1");
}

TEST_F(BookSortingPuzzleTest, PreventsDuplicateBookPlacement) {
    EXPECT_TRUE(puzzle_->PlaceBook("B1", 0));
    EXPECT_FALSE(puzzle_->PlaceBook("B1", 1));
}

TEST_F(BookSortingPuzzleTest, RemoveBook) {
    puzzle_->PlaceBook("B1", 0);
    EXPECT_EQ(puzzle_->RemoveBook(0), "B1");
    EXPECT_EQ(puzzle_->GetBookAt(0), nullptr);
}

TEST_F(BookSortingPuzzleTest, CorrectSolutionSolvesPuzzle) {
    puzzle_->PlaceBook("B1", 0);
    puzzle_->PlaceBook("B2", 1);
    puzzle_->PlaceBook("B3", 2);
    EXPECT_TRUE(puzzle_->AttemptSolution(""));
    EXPECT_TRUE(puzzle_->IsSolved());
}

TEST_F(BookSortingPuzzleTest, IncorrectSolutionFails) {
    puzzle_->PlaceBook("B3", 0);
    puzzle_->PlaceBook("B2", 1);
    puzzle_->PlaceBook("B1", 2);
    EXPECT_FALSE(puzzle_->AttemptSolution(""));
    EXPECT_FALSE(puzzle_->IsSolved());
}

TEST_F(BookSortingPuzzleTest, ResetClearsArrangement) {
    puzzle_->PlaceBook("B1", 0);
    puzzle_->Reset();
    EXPECT_EQ(puzzle_->GetBookAt(0), nullptr);
}

TEST_F(BookSortingPuzzleTest, MaxAttemptsEnforced) {
    for (int i = 0; i < 3; ++i) {
        EXPECT_FALSE(puzzle_->AttemptSolution(""));
    }
    EXPECT_THROW(puzzle_->AttemptSolution(""), PuzzleException);
}