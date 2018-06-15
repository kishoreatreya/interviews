#include "bst.h"

bst* allocNode(int val)
{
    bst* node = new(std::nothrow) bst();
    node->val = val;
    return node;
}

bst* insertNode(bst* tree, int val)
{
    if(tree == NULL)
    {
        // empty tree, create root node and return
        return allocNode(val);
    }

    // tree passed in, search for 
}

int searchNode(int val)
{
}

int deleteNode(int val)
{
}

int main(void)
{

    return 0;
}
