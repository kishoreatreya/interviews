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

    if(val == (*tree)->val)
    {
        // node already inserted
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
            if(node == node->parent->left)
            {
                std::cout << "left" << std::endl;
                node->parent->left = NULL;
                node->parent = NULL;
            }
            else
            {
                std::cout << "right" << std::endl;
                node->parent->right = NULL;
                node->parent = NULL;
            }
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
                node->parent->left = (node->left != NULL ? node->left : node->right);
                delete node;
            }
            else
            {
                // make child the right child of grand parent
                node->parent->right = (node->left != NULL ? node->left : node->right);
                delete node;
            }
            return;
        }
        
        // case 3: 2 children
        if(node->left != NULL && node->right != NULL)
        {
            // find the left most leaf of the right subtree and promote to child of grand parent
            bst* tmp = node->right;
            int count = 0;  // count the distance between the left most leaf of the right subtree and the node's parent
            while(tmp->left != NULL)
            {
                tmp = tmp->left;
                count++;
            }

            // tmp is the left most leaf of the right subtree
            // determine if current node is a left or right child of its parent
            if(node == node->parent->left)
            {
                // tmp must replace this position, so it's to become the left child of the grandparent
                if(count)
                {
                    // if the left most child of the right subtree is more than one level away from
                    // the node to be deleted's parent we need to update the left most child's current
                    // immediate parent's left child pointer to NULL and move the left most child's right
                    // pointer to the node to be deleted's right pointer
                    // 
                    //                  a
                    //              b        c
                    //          d      e         f
                    //
                    // if we're deleting c, f is the left most child of the right subtree and it's only
                    // one level away from the nodes parent, so this case we don't need to update f's
                    // right pointer and it's parent's left pointer, as it's parent is the node to be
                    // deleted
                    tmp->parent->left = NULL;
                    tmp->right = node->right;
                }
                tmp->parent = node->parent;
                tmp->parent->left = tmp;
                tmp->left = node->left;
                delete node;
            }
            else
            {
                // tmp must replace this position, so it's to become the left child of the grandparent
                if(count)
                {
                    // if the left most child of the right subtree is more than one level away from
                    // the node to be deleted's parent we need to update the left most child's current
                    // immediate parent's left child pointer to NULL and move the left most child's right
                    // pointer to the node to be deleted's right pointer
                    // 
                    //                  a
                    //              b        c
                    //          d      e         f
                    //
                    // if we're deleting c, f is the left most child of the right subtree and it's only
                    // one level away from the nodes parent, so this case we don't need to update f's
                    // right pointer and it's parent's left pointer, as it's parent is the node to be
                    // deleted
                    tmp->parent->left = NULL;
                    tmp->right = node->right;
                }
                tmp->parent = node->parent;
                tmp->parent->right = tmp;
                tmp->left = node->left;
                delete node;
            }
            return;
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
        node = bfq.front();
        std::cout << node->val << " " << std::endl;
        if(node->left != NULL)
        {
            bfq.push(node->left);
        }
        if(node->right != NULL)
        {
            bfq.push(node->right);
        }
        bfq.pop();
    }
}

// destroy tree using bfs traversal
void destroyTree(bst* tree)
{
    std::queue<bst*> bfq;

    bfq.push(tree);
    bst *node = tree;

    while(!bfq.empty())
    {
        node = bfq.front();
        if(node->left != NULL)
        {
            bfq.push(node->left);
        }
        if(node->right != NULL)
        {
            bfq.push(node->right);
        }
        bfq.pop();
        delete node;
    }
}

int main(void)
{
    int arr[11] = {4, 2, 8, 1, 3, 6, 5, 10, 7, 12, 9};

    bst *tree = NULL;

    for(int i = 0; i < 11; i++)
    {
        insertNode(&tree, arr[i], NULL);
    }

    std::cout << "print tree: " << std::endl;
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

    deleteNode(&tree, 8);
    printTree(tree);

    destroyTree(tree);

    return 0;
}


