#include <iostream>
#include <cstdint>
#include <queue>

typedef struct bst
{
    int val;
    struct bst *left;
    struct bst *right;
    struct bst *parent;
} bst;


void insertNode(bst** tree, int val, bst* parent);
bst* searchNode(bst* tree, int val);
void deleteNode(bst** tree, int val);
void printTree(bst* tree);

