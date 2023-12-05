#include "Tree.h"

class Iterator {
private:
    friend class Tree;
    Node* ptr;
public:
    Iterator(Node* ptr_) : ptr(ptr_) {}
    int& operator*();

    Iterator& operator++() noexcept;
    Iterator operator++(int) noexcept;

    bool operator==(const Iterator& o) const { return this->ptr == o.ptr; }
    bool operator!=(const Iterator& o) const { return !(*this == o); }
};