#include "Command.cpp"

class RequestBill : public Command {
private:
    CustomerComponent& CustomerComponent;

public:
    RequestBill(CustomerComponent& t) : CustomerComponent(t) {}

    void execute() override {
        table.requestBill();
    }
};