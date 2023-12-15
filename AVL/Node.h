#pragma once

template<typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;
    Node(T data) : data(data), left(nullptr), right(nullptr), parent(nullptr), height(0) {};
};
