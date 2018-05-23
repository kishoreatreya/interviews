#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>


/**
 * \brief linked list node
 */
typedef struct _node 
{
    uint32_t data;
    struct _node *next;
} node;

