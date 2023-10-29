#include "CustomerComposite.h"

class Node {

private:
    Group group;
    Node* next;
    
public:
    Node(Group group, Node* next = nullptr);
    ~Node();

    Group getGroup() const;

    Node* getNext() const;

    void setNext(Node* next);

};
