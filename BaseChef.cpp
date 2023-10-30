#include "BaseChef.h"
#include "Veggies.h"
#include "Flour.h"
#include "Cheese.h"
#include "Vegan.h"
#include "Nonvegan.h"

PizzaCreator* BaseChef::createVeganPizza() {
    // Veggies veggies;
    Flour flour;

    // veggies.addVeggies();
    flour.prepareBase();

    return new Vegan();
}

PizzaCreator* BaseChef::createNonveganPizza() {
    Cheese cheese;
    // Flour flour;

    cheese.addCheese();
    // flour.prepareBase();

    return new Nonvegan();
}
