#pragma once

#include <iostream>
#include <sstream>
#include "Node.h"

template<typename T>
class Tree {

private:
    Node<T>* root;


    Node<T>* insert(T x, Node<T>* t){
    if (t == nullptr)
        t = new Node<T>(x);
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
};

    Node<T>* singleRightRotate(Node<T>*& t){
    Node<T>* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    u->height = std::max(height(u->left), t->height) + 1;
    return u;
};


    Node<T>* singleLeftRotate(Node<T>*& t){
    Node<T>* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    u->height = std::max(height(t->right), t->height) + 1;
    return u;
};


    Node<T>* doubleLeftRotate(Node<T>*& t){
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
};


    Node<T>* doubleRightRotate(Node<T>*& t){
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
};


    Node<T>* findMin(Node<T>* t){
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
};


    Node<T>* findMax(Node<T>* t){
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return findMax(t->right);
};


    Node<T>* remove(T x, Node<T>* t){
    Node<T>* temp;

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
};


    bool find(T x, Node<T>* t){
    if (t == nullptr)
        return false;
    else if (x == t->data)
        return true;
    else if (x <= t->data)
        find(x, root->left);
    else
        find(x, root->right);
};


    int height(Node<T>* t){
    return (t == nullptr ? -1 : t->height);
};


    int getBalance(Node<T>* t){
    if (t == nullptr)
        return 0;
    else
        return height(t->left) - height(t->right);
};


    std::string inorder(Node<T>* t, std::ostringstream& out){
    if (t != nullptr) {
        inorder(t->left, out);
        out << t->data << " ";
        inorder(t->right, out);

    }
    return out.str();
};

public:

    Tree(){ root = nullptr; };


    void insert(T x){ root = insert(x, root); };


    void remove(T x){ root = remove(x, root); };


    std::string display(){
      std::ostringstream buffer{};
      inorder(root, buffer);
      return buffer.str();
    };


    bool find(T x){ return find(x, root); };
};
