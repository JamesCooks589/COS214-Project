#include <iostream>
#include "Waiter.h"

class RestaurantMediator : public Mediator {
public:
    void communicate(std::string message, Waiter* waiter) override {
        // Implement the communication logic here
        if (message == "take order") {
            std::cout << "Mediator: Waiter " << waiter << " is taking the order." << std::endl;
        } else if (message == "deliver bill") {
            std::cout << "Mediator: Waiter " << waiter << " is delivering the bill." << std::endl;
        } else if (message == "deliver food") {
            std::cout << "Mediator: Waiter " << waiter << " is delivering the food." << std::endl;
        } else {
            std::cout << "Mediator: Unknown message." << std::endl;
        }
    }
};