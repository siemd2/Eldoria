#include "Item.h"

Item::Item(const std::string &name, const std::string &description, double weight, bool isCollectible, bool isUsable)
    : name_(name), description_(description), weight_(weight), isCollectible_(isCollectible), isUsable_(isUsable) {}

Item::~Item() {}

std::string Item::getName() const { return name_; }
std::string Item::getDescription() const { return description_; }
double Item::getWeight() const { return weight_; }
bool Item::isItemCollectible() const { return isCollectible_; }
bool Item::isItemUsable() const { return isUsable_; }