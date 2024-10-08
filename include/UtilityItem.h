#ifndef UTILITYITEM_H
#define UTILITYITEM_H
#include "Item.h"

class UtilityItem : public Item
{
public:
    UtilityItem(const std::string &name, const std::string &description, double weight);

    void use() override;
    void examine() const override;
    bool combineWith(std::shared_ptr<Item> otherItem) override;
};

#endif