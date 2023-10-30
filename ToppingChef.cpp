#include "ToppingChef.h"
#include "Veggies.h"
#include "Meat.h"
#include "Vegan.h"
#include "Nonvegan.h"

PizzaCreator* ToppingChef::createVeganPizza() {
    Veggies veggies;

    veggies.addVeggies();

    return new Vegan();
}

PizzaCreator* ToppingChef::createNonveganPizza() {
    Meat meat;

    meat.addMeat();

    return new Nonvegan();
}
