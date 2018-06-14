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
        std::cout << "idx: " << i << " " << arr[i] << std::endl;
    }
}

void merge(int **arr, int leftIdx, int mid, int rightIdx)
{
    // Built sub arrays
    int rsize = rightIdx - mid;
    int lsize = (mid - leftIdx) + 1;

    int *ltmp = new int[lsize];
    int *rtmp = new int[rsize];

    for(int i = 0; i < lsize; i++)
    {
        ltmp[i] = *arr[leftIdx + i];
    }
    for(int i = 0; i < rsize; i++)
    {
        rtmp[i] = *arr[mid + i];
    }

    printArr(rtmp, rsize);
    printArr(ltmp, lsize);
}

void sort(int *arr, int leftIdx, int rightIdx)
{
    merge(&arr, leftIdx, (rightIdx + leftIdx)/2, rightIdx);

    /*
    int mid

    // Check if leftIdx >= rightIdx
    if(leftIdx >= rightIdx)
    {
        return 
    }
    else
    {
        sort
    }*/
}

int main(void)
{
    int * arr = buildUnsortUniq(10);
    printArr(arr, 10);

    sort(arr, 0, 9);
    printArr(arr, 10);
    

    delete [] arr;
    return 0;
}


