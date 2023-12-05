#include "Tree.h"

void Tree::makeEmpty(Node* t) {
    if (t == nullptr)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

Node* Tree::insert(int x, Node* t) {
    if (t == nullptr) {
        t = new Node;
        t->data = x;
        t->height = 0;
        t->left = t->right = nullptr;
    }
    else if (x < t->data) {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (x < t->left->data)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (x > t->data) {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (x > t->right->data)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = std::max(height(t->left), height(t->right)) + 1;
    return t;
}

Node* Tree::singleRightRotate(Node*& t) {
    Node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    u->height = std::max(height(u->left), t->height) + 1;
    return u;
}

Node* Tree::singleLeftRotate(Node*& t) {
    Node* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    u->height = std::max(height(t->right), t->height) + 1;
    return u;
}

Node* Tree::doubleLeftRotate(Node*& t) {
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

Node* Tree::doubleRightRotate(Node*& t) {
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

Node* Tree::findMin(Node* t) {
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}

Node* Tree::findMax(Node* t) {
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return findMax(t->right);
}

Node* Tree::remove(int x, Node* t) {
    Node* temp;

    if (t == nullptr)
        return nullptr;

    else if (x < t->data)
        t->left = remove(x, t->left);
    else if (x > t->data)
        t->right = remove(x, t->right);

    else if (t->left && t->right) {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else {
        temp = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }
    if (t == nullptr)
        return t;

    t->height = std::max(height(t->left), height(t->right)) + 1;

    if (height(t->left) - height(t->right) == 2) {
        if (height(t->left->left) - height(t->left->right) == 1)
            return singleLeftRotate(t);
        else
            return doubleLeftRotate(t);
    }
    else if (height(t->right) - height(t->left) == 2) {
        if (height(t->right->right) - height(t->right->left) == 1)
            return singleRightRotate(t);
        else
            return doubleRightRotate(t);
    }
    return t;
}

bool Tree::find(int x, Node* t) {
    if (t == nullptr)
        return false;
    else if (x == t->data) {
        return true;
    }
    else if (x <= t->data)
        find(x, root->left);
    else
        find(x, root->right);
}

int Tree::height(Node* t) {
    return (t == nullptr ? -1 : t->height);
}

int Tree::getBalance(Node* t) {
    if (t == nullptr)
        return 0;
    else
        return height(t->left) - height(t->right);
}

void Tree::inorder(Node* t) {
    if (t == nullptr)
        return;
    inorder(t->left);
    std::cout << t->data << " ";
    inorder(t->right);
}

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(int x) {
    root = insert(x, root);
}

void Tree::remove(int x) {
    root = remove(x, root);
}

void Tree::display() {
    if (root == nullptr) {
        std::cout << "Пусто" << std::endl;
    }

    inorder(root);
    std::cout << std::endl;
}

bool Tree::find(int x) {
    return find(x, root);
}

Node* Tree::getRoot() {
    return root;
}

void Tree::del() {
    makeEmpty(root);
    std::cout << "Удаление всех узлов." << std::endl;
}
