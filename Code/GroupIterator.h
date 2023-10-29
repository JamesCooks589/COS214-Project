#include "CustomerComposite.h"
#include "Node.h"

class GroupIterator {
    
private:
    Node* current;

public:
    GroupIterator(Node* head);
    ~GroupIterator();

    bool hasNext();

    Group getCurrent();

    void next();
};