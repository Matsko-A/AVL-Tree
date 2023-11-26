#pragma once

#include<iostream>
#include "Node.h"

class Tree
{
private:
    Node* root;

    void makeEmpty(Node* t);
    Node* insert(int x, Node* t);
    Node* singleRightRotate(Node* &t);
    Node* singleLeftRotate(Node* &t);
    Node* doubleLeftRotate(Node* &t);
    Node* doubleRightRotate(Node* &t);
    Node* findMin(Node* t);
    Node* findMax(Node* t);
    Node* remove(int x, Node* t);
    int height(Node* t);
    int getBalance(Node* t);
    void inorder(Node* t);
    

public:
    Tree();
    void insert(int x);
    void remove(int x);
    void display();
};
