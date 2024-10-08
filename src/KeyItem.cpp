#include "KeyItem.h"
#include <iostream>

KeyItem::KeyItem(const std::string &name, const std::string &description, double weight)
    : Item(name, description, weight, true, true) {}

void KeyItem::use()
{
    std::cout << "You use the " << name_ << "to unlock a door." << std::endl;
}

void KeyItem::examine() const
{
    std::cout << description_ << std::endl;
}

bool KeyItem::combineWith(std::shared_ptr<Item> otherItem)
{
    std::cout << "The " << name_ << "can't be combined with " << otherItem->getName() << "." << std::endl;
}