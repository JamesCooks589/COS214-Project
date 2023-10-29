#include "GroupIterator.h"
#include "CustomerComponent.h"
#include "Node.h"

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    GroupIterator getIterator() {
        return GroupIterator(head);
    }
    void add(CustomerComponent* group) {
    }
    void remove(CustomerComponent* group) {
    }
};