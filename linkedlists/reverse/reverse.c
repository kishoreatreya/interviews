#include "reverse.h"

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

node* reverse(node* list)
{
    // This function will reverse a singly linked list
    node* head = list;
    node* cur = head->next;
    node* last = head;
    
    while(last->next != NULL)
    {
        last->next = cur->next;
        cur->next = head;
        head = cur;
        cur = last->next;
    }
    
    return head;
}

int main (int argc, char* argv[])
{
    node* l0 = NULL;
    node* rl0 = NULL;
    
    l0 = buildListMult(4, 20);
    printf("forward: \n\n");
    printList(l0);

    rl0 = reverse(l0);
    
    printf("reverse: \n\n");
    printList(rl0);

    destroyList(rl0);
}
