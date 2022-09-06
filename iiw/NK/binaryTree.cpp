#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
struct Node
{
    T val;
    Node *Left;
    Node *Right;
};


template <typename T>
class BiTree
{
private:
    Node<T> root;
};