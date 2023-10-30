#ifndef TOPPINGDECORATOR_H
#define TOPPINGDECORATOR_H

#include "Menu.h"

class ToppingDecorator : public Menu {
public:
    ToppingDecorator(Menu* foodItem);
    std::string getDescription() const override;
    double getCost() const override;

private:
    Menu* foodItem;
};

#endif // TOPPINGDECORATOR_H
