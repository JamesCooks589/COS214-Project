#include "BaseChef.h"
#include "Veggies.h"
#include "Flour.h"
#include "Cheese.h"
#include "Vegan.h"
#include "Nonvegan.h"

Chef* BaseChef::createVeganPizza() {
    return new Flour();
}

Chef* BaseChef::createNonveganPizza() {
    return new Cheese();
}
