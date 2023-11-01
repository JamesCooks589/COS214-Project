#pragma once

#include "Waiter.h"
#include "Order.h"

class CustomerComponent{
    private:
        Waiter* waiter = nullptr;
        int id;

    protected:
        int tableID;
        
    public:
        CustomerComponent(int id);
        int getID();
        int getTableID();
        virtual void setTableID(int id) = 0;
        virtual Order* getOrder() = 0;
        virtual int getSize() = 0;
        void attachWaiter(Waiter* waiter);
        void detachWaiter();
        void signalToOrder();
        void signalForBill();
        virtual ~CustomerComponent();
};