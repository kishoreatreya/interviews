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

    // left is inclusive of mid
    for(int i = 0; i < lsize; i++)
    {
        ltmp[i] = (*arr)[leftIdx + i];
    }
    for(int i = 0; i < rsize; i++)
    {
        rtmp[i] = (*arr)[mid + 1 + i];
    }

    int lIter = 0, rIter = 0;
    int arrIter = 0;
    while(lIter != lsize && rIter != rsize)
    {
        if(ltmp[lIter] < rtmp[rIter])
        {
            (*arr)[leftIdx + arrIter] = ltmp[lIter];
            lIter++;
        }
        else
        {
            (*arr)[leftIdx + arrIter] = rtmp[rIter];
            rIter++;
        }
        arrIter++;
    }

    // fill remaining left
    if(lIter < lsize)
    {
        for(int i = lIter; i < lsize; i++)
        {
            (*arr)[leftIdx + arrIter] = ltmp[i];
            arrIter++;
        }
    }
    else if(rIter < rsize)
    {
        for(int i = rIter; i < rsize; i++)
        {
            (*arr)[leftIdx + arrIter] = rtmp[i];
            arrIter++;
        }
    }

    delete [] ltmp;
    delete [] rtmp;
}

void sort(int *arr, int leftIdx, int rightIdx)
{
    int mid = (rightIdx + leftIdx) / 2;

    // Check if leftIdx >= rightIdx
    if(leftIdx >= rightIdx)
    {
        return;
    }
    else
    {
        // sort left
        sort(arr, leftIdx, mid);
        // sort right
        sort(arr, mid+1, rightIdx);
        merge(&arr, leftIdx, mid, rightIdx);
    }
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


