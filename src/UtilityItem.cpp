#include "UtilityItem.h"
#include <iostream>

UtilityItem::UtilityItem(const std::string &name, const std::string &description, double weight)
    : Item(name, description, weight, true, true) {}
