#pragma once

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    Node();
    Node(int data);
};