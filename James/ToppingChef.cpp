#include "ToppingChef.h"
#include "Veggies.h"
#include "Meat.h"
#include "Vegan.h"
#include "Nonvegan.h"

Chef* ToppingChef::createVeganPizza() {
    return new Veggies();
}

Chef* ToppingChef::createNonveganPizza() {
    return new Meat();
}
