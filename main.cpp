#include "Waiter.h"
#include "Menu.h"
#include "Order.h"
#include "Kitchen.h"
#include "Bill.h"
#include "CustomerComponent.h"
#include "RestaurantMediator.h"

int main() {
    // Create a new mediator
    std::shared_ptr<Mediator> mediator = std::make_shared<RestaurantMediator>();

    // Create a new menu and kitchen
    Menu* menu = new Menu();
    Kitchen* kitchen = new Kitchen();

    // Create a new waiter
    Waiter* waiter = new Waiter(mediator, menu, kitchen);

    // Create a new customer
    CustomerComponent* customer = new Customer("John Doe", 1);

    // Customer signals to order
    waiter->orderSignal(customer);

    // Customer signals for bill
    waiter->billSignal(customer);

    // Clean up
    delete waiter;
    delete menu;
    delete kitchen;
    delete customer;

    return 0;
}