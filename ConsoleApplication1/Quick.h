#ifndef QUICK
#define QUICK
#include "DynamicArray.h"
#include "Sequence.h"
#include <algorithm>
#include "Sorters.h"
using namespace std;


template <typename T>

void quicksort(DynamicArray<T>* arr, int start, int end,int (*comp)(T,T))
{
 
    if (start >= end) {
        return;
    }

   
    int pivot = partition(arr, start, end,comp);

    
    quicksort(arr, start, pivot - 1, comp);

   
    quicksort(arr, pivot + 1, end, comp);
}

#endif