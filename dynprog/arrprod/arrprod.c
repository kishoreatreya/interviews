#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define NUM_ELEMENTS 10 

int main(int argc, char *argv[])
{
    int elements = NUM_ELEMENTS;

    int *array = (int*)malloc(sizeof(int) * elements);
    memset(array, 0, sizeof(int) * elements);

    srand(time(0)); 

    for(int i = 0 ; i < elements ; i++)
    {
        array[i] = rand() % 9 + 1;
        printf("array[%d] = %d\n", i, array[i]);
    }

    // Implement dyn prog solution

    int *lparr = (int*)malloc(sizeof(int) * elements);
    int *rparr = (int*)malloc(sizeof(int) * elements);

    memset(lparr, 0, sizeof(int) * elements);
    memset(rparr, 0, sizeof(int) * elements);
    
    lparr[0] = 1;
    rparr[elements - 1] = 1;

    for(int i = 0, j = elements - 1; i < elements - 1; i++, j--)
    {
        rparr[j - 1] = rparr[j] * array[j];
        lparr[i + 1] = lparr[i] * array[i];
    }

    printf("\n\nprod array\n\n");
    for(int i = 0; i < elements; i++)
    {
        array[i] = lparr[i] * rparr[i];
        printf("array[%d] = %d; lparr[%d] = %d, rparr[%d] = %d\n", i, array[i], i, lparr[i], i, rparr[i]);
    }
    return 0;
}

