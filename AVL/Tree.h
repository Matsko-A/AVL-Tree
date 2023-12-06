#pragma once

#include <iostream>
#include <iterator>
#include <cstddef>
#include <ostream>
#include "Node.h"
//#include "Iterator.h"


class Tree {
private:
    Node* root;

    //void makeEmpty(Node* t);
    Node* insert(int x, Node* t);
    Node* singleRightRotate(Node*& t);
    Node* singleLeftRotate(Node*& t);
    Node* doubleLeftRotate(Node*& t);
    Node* doubleRightRotate(Node*& t);
    Node* findMin(Node* t);
    Node* findMax(Node* t);
    Node* remove(int x, Node* t);
    bool find(int x, Node* t);
    int height(Node* t);
    int getBalance(Node* t);
    void inorder(Node* t);
    friend std::ostream& operator<< (std::ostream& os, const Node& node);

public:
    //Iterator begin() noexcept { return Iterator(findMin(root)); }
    //Iterator end() noexcept { return Iterator(nullptr); }

    Tree();
    void insert(int x);
    void remove(int x);
    void display();
    bool find(int x);
    Node* getRoot();
    void del();
};