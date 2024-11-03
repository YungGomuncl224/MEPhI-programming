#ifndef SHELL
#define SHELL
#include "DynamicArray.h"
#include "Sequence.h"
#include <algorithm>
#include "Sorters.h"
using namespace std;

template <typename T>
void shellSort(DynamicArray<T>* arr, int n,int (*comp)(T,T))
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            
            T temp = arr->Get(i);

            int j;
            for (j = i; j >= gap && comp(arr->Get(j - gap), temp) > 0 ; j -= gap)
                
                arr->Set(j, arr->Get(j - gap));
            
            arr->Set(j, temp);
        }
    }
}
#endif
