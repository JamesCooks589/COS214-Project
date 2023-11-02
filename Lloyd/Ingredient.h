#pragma once

#include <string>

class Ingredient {
public:
    Ingredient(const std::string& name, double price);
    const std::string& getName() const;
    double getPrice() const;

private:
    std::string name;
    double price;
};
