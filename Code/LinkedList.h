#include "GroupIterator.h"
#include "CustomerGroup.h"
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
    void add(CustomerGroup* group) {
    }
    void remove(CustomerGroup* group) {
    }
};