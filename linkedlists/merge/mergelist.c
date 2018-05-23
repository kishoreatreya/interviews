#include "mergelist.h"

node* allocNode()
{
    node* link = (node*) malloc(sizeof(node));
    return link;
}

void destroyList(node* list)
{
    node* cur = list;
    
    while(cur != NULL)
    {
        node *tmp = cur;
        cur = cur->next;
        
        free(tmp);
    }
}

void printList(node * list)
{
    node* cur = list;
    while(cur != NULL)
    {
        printf("data: %d\n", cur->data);
        cur = cur->next;
    }
}

node* buildListMult(uint32_t mux, uint32_t numNodes)
{
    // Builds a sorted list of numNodes with a skip of mux
    node* root = NULL;
    node* cur = NULL;
        
    root = allocNode();
    root->data = mux;
    cur = root;
    
    for(uint32_t i = 1; i <= numNodes; i++)
    {
        cur->next = allocNode();
        cur = cur->next;
        cur->data = (mux * (i+1));
    }
    cur->next = NULL;
    
    return root;
}

/**
 * // Merges two lists into one and returns a head pointer to the singly linked list
 */
node* mergeLists(node* l0, node* l1)
{
    node* l0_cur = l0, *l1_cur = l1;
    node* head = NULL, *tmp = NULL;
    
    if(l0_cur->data < l1_cur->data)
    {
        head = l0_cur;
        l0_cur = l0_cur->next;
    }
    else
    {
        head = l1_cur;
        l1_cur = l1_cur->next;
    }
    
    tmp = head;
    
    while(l0_cur != NULL && l1_cur != NULL)
    {
        if(l0_cur->data < l1_cur->data)
        {
            tmp->next = l0_cur;
            l0_cur = l0_cur->next;
        }
        else
        {
            tmp->next = l1_cur;
            l1_cur = l1_cur->next;
        }
        tmp = tmp->next;
    }
    
    if(l0_cur != NULL)
    {
        while(l0_cur != NULL)
        {
            tmp->next = l0_cur;
            tmp = tmp->next;
            l0_cur = l0_cur->next;
        }
    }
    else if(l1_cur != NULL)
    {
        while(l1_cur != NULL)
        {
            tmp->next = l1_cur;
            tmp = tmp->next;
            l1_cur = l1_cur->next;
        }
    }

    return head;
}

int main(int argc, char* argv[])
{
    node* l0 = NULL;
    node* l1 = NULL;
    
    l0 = buildListMult(3, 10);
    l1 = buildListMult(5, 3);
    
    printf("list 0: \n\n");
    printList(l0);
    
    printf("list 1: \n\n");
    printList(l1);
    
    printf("merged: \n\n");
    node* merged = mergeLists(l0, l1);
    printList(merged);
    
    destroyList(merged);
    
    return 0;
}
