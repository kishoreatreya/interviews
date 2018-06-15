#include <iostream>
#include <cstdint>
#include <time.h>
#include <cmath>

int* buildUnsortUniq(int numDigits)
{
    int *arr = new int[numDigits];
    int *tmp = new int[numDigits];

    // populate randomly from 0-numDigits unsorted
    srand(time(0));

    for(int i = 0; i < numDigits; i++)
    {
        tmp[i] = i;
    }
   
    int left = numDigits;
    while(left)
    {
        int search = rand() % numDigits;

        if(tmp[search] != -1)
        {
            arr[left-1] = tmp[search];
            tmp[search] = -1;
            left--;
        }
    }

    delete[] tmp;
    return arr;
}

void printArr(int *arr, int numDigits)
{
    for(int i = 0; i < numDigits; i++)
    {
        std::cout << "idx: " << i << ": " << arr[i] << std::endl;
    }
}

// partition picks pivots and moves smaller values to the left
// and larger values to the right of the pivot based on size of array
int partition(int *arr, int leftIdx, int rightIdx)
{
    int lo = leftIdx - 1;
    int pivot = arr[rightIdx];

    for(int i = leftIdx; i < rightIdx; i++)
    {
        // if current is less than pivot
        if(arr[i] < pivot)
        {
            // increment lo
            lo++;

            // swap new lo and i
            int tmp = arr[i];
            arr[i] = arr[lo];
            arr[lo] = tmp;
        }
    }

    // swap hi and lo + 1 to move pivot to the right place
    int tmp = arr[lo + 1];
    arr[lo + 1] = arr[rightIdx];
    arr[rightIdx] = tmp;

    return lo + 1;
}

// quick sort implementation pick pivot and shuffle, then for each half repeat
// until sub array size can't be divided further
// implement recursively
void sort(int *arr, int leftIdx, int rightIdx)
{
    if(leftIdx >= rightIdx)
    {
        return;
    }

    int pivot = partition(arr, leftIdx, rightIdx);

    // sort left
    sort(arr, leftIdx, pivot - 1);
    
    // sort right
    sort(arr, pivot + 1, rightIdx);
}

int main(void)
{
    int * arr = buildUnsortUniq(10);

    printArr(arr, 10);

    sort(arr, 0, 9);
    std::cout << "sort" << std::endl;
    printArr(arr, 10);
    

    delete [] arr;
    return 0;
}


