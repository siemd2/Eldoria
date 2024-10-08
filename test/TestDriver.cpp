#include "driver.h"
#include <gtest/gtest.h>

// Test for isValidInput
TEST(InputValidationTests, ValidInput) {
    EXPECT_TRUE(isValidInput("move"));
    EXPECT_TRUE(isValidInput("12345"));
    EXPECT_TRUE(isValidInput("look123"));
    EXPECT_TRUE(isValidInput("north"));
}

TEST(InputValidationTests, InvalidInput) {
    EXPECT_FALSE(isValidInput("move north@"));
    EXPECT_FALSE(isValidInput("12345#"));
    EXPECT_FALSE(isValidInput("!look"));
    EXPECT_FALSE(isValidInput("quit$"));
}

// Test for toLowerCase
TEST(ToLowerCaseTests, ConvertsInputToLowercase) {
    EXPECT_EQ(toLowerCase("HELLO"), "hello");
    EXPECT_EQ(toLowerCase("TeSt123"), "test123");
    EXPECT_EQ(toLowerCase("LooK!"), "look!");
}

// Test for processInput
TEST(ProcessInputTests, ProcessesValidInput) {
    auto [command, args] = processInput("move north");
    EXPECT_EQ(command, "move");
    EXPECT_EQ(args.size(), 1);
    EXPECT_EQ(args[0], "north");

    auto [command2, args2] = processInput("look");
    EXPECT_EQ(command2, "look");
    EXPECT_EQ(args2.size(), 0);
}

TEST(HandleInputTests, HandlesUnknownCommand) {
    testing::internal::CaptureStdout();
    handleInput("unknowncommand");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Unknown command: unknowncommand\n");
}

