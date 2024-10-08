#ifndef KEYITEM_H
#define KEYITEM_H

#include "Item.h"

class KeyItem : public Item
{
public:
    KeyItem(const std::string &name, const std::string &description, double weight);

    void use() override;
    void examine() const override;
    bool combineWith(std::shared_ptr<Item> otherItem) override;
};

#endif