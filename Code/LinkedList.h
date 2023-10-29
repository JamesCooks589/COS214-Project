#include "GroupIterator.h"
#include "CustomerComposite.h"
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
    void add(Group group) {
    }
    void remove(Group group) {
    }
};