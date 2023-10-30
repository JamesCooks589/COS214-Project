#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
    virtual ~Menu() {}
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

#endif // MENU_H
