#include <iostream>
#include <cstdint>


typedef struct bst
{
    int val;
    struct bst *left;
    struct bst *right;
} bst;


void insertNode(int val);
int searchNode(int val);
int deleteNode(int val);


