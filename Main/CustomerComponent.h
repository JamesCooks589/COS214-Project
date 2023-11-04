#pragma once

#include "Waiter.h"
#include "Order.h"
#include "Plate.h"

class PrototypeWaiter;

class CustomerComponent{
    private:
        PrototypeWaiter* waiter = nullptr;
        int id;

    protected:
        int tableID;
        
    public:
        CustomerComponent(int id);
        int getID();
        int getTableID();
        virtual void setTableID(int id) = 0;
        virtual void givePlate(Plate* plate) = 0;
        virtual std::string getName();
        virtual Order* getOrder() = 0;
        virtual int getSize() = 0;
        virtual int getHappiness() = 0;
        void attachWaiter(PrototypeWaiter* waiter);
        void detachWaiter();
        void signalToOrder();
        void signalForBill();
        virtual void addToGroup(CustomerComponent* comp);
        virtual void payBill(double amount, bool split) = 0;
        virtual ~CustomerComponent();
        virtual void chefVisit() = 0;
};