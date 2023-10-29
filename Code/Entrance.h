#include "LinkedList.h"
#include "CustomerComposite.h"

class Entrance {
private:
    LinkedList queue;
    
public:
    void addGroup(Group group);
    void removeGroup(Group group);
};