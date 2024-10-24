#include "Player.h"
#include "usable_item.h"
#include <gtest/gtest.h>
#include <memory>
#include <fstream>

// Helper class: MockItem, used for testing UsableItem.
class MockItem : public UsableItem {
public:
    MockItem(const std::string& id, const std::string& name, const std::string& description)
        : UsableItem(id, name, description, []() { return "You used the item."; }) {}
};

// Test: Add item to the player's inventory and verify it was added successfully.
TEST(PlayerTest, AddItemToInventory) {
    // Create a player.
    Player player("Hero", "A brave adventurer.", nullptr);  // nullptr for starting room.

    // Create a mock item.
    auto item = std::make_shared<MockItem>("ITEM_ID", "Test Item", "A useful test item.");

    // Add the item to the player's inventory.
    player.addItemToInventory(item);

    // Capture the output of the inventory display.
    testing::internal::CaptureStdout();
    player.showInventory();
    std::string output = testing::internal::GetCapturedStdout();

    // Verify that the item is in the inventory.
    EXPECT_NE(output.find("Test Item"), std::string::npos);
    EXPECT_NE(output.find("A useful test item."), std::string::npos);
}

// Test: Verify multiple items are correctly displayed in the player's inventory.
TEST(PlayerTest, ShowInventoryWithMultipleItems) {
    // Create a player.
    Player player("Hero", "A brave adventurer.", nullptr);  // nullptr for starting room.

    // Create two mock items.
    auto item1 = std::make_shared<MockItem>("ITEM1", "Potion", "Restores health.");
    auto item2 = std::make_shared<MockItem>("ITEM2", "Key", "Opens a locked door.");

    // Add both items to the player's inventory.
    player.addItemToInventory(item1);
    player.addItemToInventory(item2);

    // Capture the output of the inventory display.
    testing::internal::CaptureStdout();
    player.showInventory();
    std::string output = testing::internal::GetCapturedStdout();

    // Verify both items are in the output.
    EXPECT_NE(output.find("Potion"), std::string::npos);
    EXPECT_NE(output.find("Restores health."), std::string::npos);
    EXPECT_NE(output.find("Key"), std::string::npos);
    EXPECT_NE(output.find("Opens a locked door."), std::string::npos);
}
