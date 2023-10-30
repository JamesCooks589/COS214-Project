/*Comment out the pizza we are not creating*/
#include "BaseChef.h"
#include "ToppingChef.h"

int main() {
    ChefCreator* baseChefFactory = new BaseChef();
    ChefCreator* toppingChefFactory = new ToppingChef();

    /*BaseChef: manages flour(vegan) and cheese(nonvegan)
      ToppingChef: manages meat(nonvegan) and veggies(vegan)
    */
    PizzaCreator* veganBasePizza = baseChefFactory->createVeganPizza();
    // PizzaCreator* nonveganBasePizza = baseChefFactory->createNonveganPizza();
    PizzaCreator* veganToppingPizza = toppingChefFactory->createVeganPizza();
    // PizzaCreator* nonveganToppingPizza = toppingChefFactory->createNonveganPizza();

    veganBasePizza->createPizza();
    // nonveganToppingPizza->createPizza();

    delete veganBasePizza;
    // delete nonveganBasePizza;
    delete veganToppingPizza;
    // delete nonveganToppingPizza;

    delete baseChefFactory;
    delete toppingChefFactory;

    return 0;
}
