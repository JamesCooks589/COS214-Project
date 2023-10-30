#ifndef CHEESEDECORATOR_H
#define CHEESEDECORATOR_H

#include "ToppingDecorator.h"

class CheeseDecorator : public ToppingDecorator {
public:
    CheeseDecorator(Menu* foodItem);
    std::string getDescription() const override;
    double getCost() const override;
};

#endif // CHEESEDECORATOR_H
