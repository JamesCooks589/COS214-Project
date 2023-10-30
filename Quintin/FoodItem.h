#ifndef FOODITEM_H
#define FOODITEM_H

#include "Menu.h"

class FoodItem : public Menu {
public:
    FoodItem(std::string description, double cost);
    std::string getDescription() const override;
    double getCost() const override;

private:
    std::string description;
    double cost;
};

#endif // FOODITEM_H
