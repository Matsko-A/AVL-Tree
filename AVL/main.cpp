#include "Tree.h"


int main(){
    Tree<int>* tree = new Tree<int>();
    tree->insert(10);
    tree->insert(15);
    tree->insert(5);
    tree->insert(12);
    tree->insert(55);

    std::cout << tree->display();

    tree->remove(15);

    std::cout << "\n" << tree->display();



    return 0;
}
