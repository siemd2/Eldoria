#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

class Item
{
public:
    Item(const std::string &name, const std::string &description, double weight, bool isCollectible, bool isUsable);

    virtual ~Item();

    virtual void use() = 0;
    virtual void examine() const = 0;
    virtual bool combineWith(std::shared_ptr<Item> otherItem) = 0;

    std::string getName() const;
    std::string getDescription() const;
    double getWeight() const;
    bool isItemCollectible() const;
    bool isItemUsable() const;

protected:
    std::string name_;
    std::string description_;
    double weight_;
    bool isCollectible_;
    bool isUsable_;
};

#endif