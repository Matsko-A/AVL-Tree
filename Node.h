#pragma once

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
    Node();
    Node(int data);
};
