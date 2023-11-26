#include "tree.h"


using namespace std;


int main()
{
    Tree t;
    t.insert(20);
    t.insert(1);
    t.insert(123);
    t.insert(2);
    t.insert(500);
    t.insert(501);
    t.display();
    t.remove(123);
    t.display();
}
