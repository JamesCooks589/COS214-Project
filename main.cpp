/*Comment out the pizza we are not creating*/
#include "BaseChef.h"
#include "ToppingChef.h"

int main() {
    //Create factories
    ChefCreator* baseChefFactory = new BaseChef();
    ChefCreator* toppingChefFactory = new ToppingChef();

    //Create chain of responsibility
    //Head of chain
    Chef* chefChain = baseChefFactory->createVeganPizza();
    //Add to chain
    chefChain->Add(toppingChefFactory->createVeganPizza());
    chefChain->Add(baseChefFactory->createNonveganPizza());
    chefChain->Add(toppingChefFactory->createNonveganPizza());

    //Create plate
    Plate* plate = new Plate();

    //Create order
    vector<string> orderDetails = vector<string>();

    //Add order details
    orderDetails.push_back("Flour");
    orderDetails.push_back("Cheese");
    orderDetails.push_back("Cheese");
    orderDetails.push_back("Meat");
    orderDetails.push_back("Meat");

    //Cook pizza
    chefChain->cookFood(orderDetails, plate);  

    //Delete chain
    delete chefChain;

    //Delete factories
    delete baseChefFactory;
    delete toppingChefFactory;
    

    return 0;
}
