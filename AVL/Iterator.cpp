#include "Iterator.h"

int& Iterator::operator*() { return ptr->data; }

Iterator& Iterator::operator++() noexcept {
	Node* p;
	if (ptr->right != nullptr) {
		ptr = ptr->right;
		while (ptr->left != nullptr) ptr = ptr->left;
	}
	else {
		p = ptr->parent;
		while (p != nullptr && ptr == ptr->right) {
			ptr = p;
			p = p->parent;
		}
		ptr = p;
	}
	return *this;
}

Iterator Iterator::operator++(int) noexcept {
	Iterator iterator = *this;
	++*this;
	return iterator;
}
