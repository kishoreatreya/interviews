#include "bst.h"

bst* allocNode(int val)
{
    bst* node = new(std::nothrow) bst();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void insertNode(bst** tree, int val, bst* parent)
{
    if(*tree == NULL)
    {
        // empty tree, create root node and return
        *tree = allocNode(val);
        (*tree)->parent = parent;
        return;
    }

    // tree passed in, determine where to place node
    if(val < (*tree)->val)
    {
        insertNode(&((*tree)->left), val, *tree);
    }
    else
    {
        insertNode(&((*tree)->right), val, *tree);
    }
}

bst* searchNode(bst* tree, int val)
{
    if(tree->val == val)
    {
        return tree;
    }
    else
    {
        if(val < tree->val && tree->left != NULL)
        {
            // recurse to left subtree
            return searchNode(tree->left, val);
        }
        else if(val > tree->val && tree->right != NULL)
        {
            return searchNode(tree->right, val);
        }
        
        return NULL;
    }
}

void deleteNode(bst** tree, int val)
{
    // search for the node
    bst* node = searchNode(*tree, val);

    if(node == NULL)
    {
        // node not found, so just return
        return;
    }
    else
    {
        // case 1: no children
        if(node->left == NULL && node->right == NULL)
        {
            delete node;
            return;
        }
        
        // case 2: one child only
        if(node->left != NULL && node->right == NULL ||
           node->left == NULL && node->right != NULL)
        {
            // determine if the current node is a left or right child of its parent
            if(node == node->parent->left)
            {
                // make child the left child of grand parent
                node->parent->left = node->left;
                delete node;
            }
            else
            {
                // make child the right child of grand parent
                node->parent->right = node->left;
                delete node;
            }
        }
        
        // case 3: 2 children
        if(node->left != NULL && node->right != NULL)
        {
            // find the left most leaf of the right subtree and promote to child of grand parent
            bst* tmp = node->right;
            while(tmp->left != NULL)
            {
                tmp = tmp->left;
            }

            // tmp is the left most leaf of the right subtree
            // determine if current node is a left or right child of its parent
            if(node == node->parent->left)
            {
                node->parent->left = tmp;
                tmp->right = node->right;
                tmp->left = node->left;
                delete node;
            }
            else
            {
                node->parent->right = tmp;
                tmp->right = node->right;
                tmp->left = node->left;
                delete node;
            }
        }
    }
}

void printTree(bst* tree)
{
    // print tree nodes level by level
    std::queue<bst*> bfq;

    bfq.push(tree);
    bst *node = tree;

    while(!bfq.empty())
    {
        std::cout << node->val << " " << std::endl;
        if(node->left)
        {
            bfq.push(node->left);
        }
        if(node->right)
        {
            bfq.push(node->right);
        }
        node = bfq.front();
        bfq.pop();
    }
}


int main(void)
{
    int arr[5] = {4, 2, 5, 1, 3};

    bst *tree = NULL;

    for(int i = 0; i < 5; i++)
    {
        insertNode(&tree, arr[i], NULL);
    }

    printTree(tree);

    bst *search = searchNode(tree, 4);
    if(search != NULL)
    {
        std::cout << "node '" << 4 << "' found! " << search << std::endl;
    }
    else
    {
        std::cout << "node '" << 4 << "' not found! " << search << std::endl;
    }

    search = searchNode(tree, 20);
    if(search != NULL)
    {
        std::cout << "node '" << 20 << "' found! " << search << std::endl;
    }
    else
    {
        std::cout << "node '" << 20 << "' not found! " << search << std::endl;
    }

    deleteNode(&tree, 3);
    printTree(tree);
    
    return 0;
}

