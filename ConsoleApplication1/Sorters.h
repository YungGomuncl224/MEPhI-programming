
#ifndef SORTERS
#define SORTERS
#include "DynamicArray.h"
#include "Sequence.h"
#include <algorithm>
using namespace std;


template <typename T>
// –азделение
int partition(DynamicArray<T>* arr, int start, int end,int (*comp)(T,T))
{

    int pivot = arr->Get(end);


    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (comp(arr->Get(i), pivot) <= 0)
        {
           
            T buf = arr->Get(pIndex);
            arr->Set(pIndex, arr->Get(i));
            arr->Set(i, buf);
            pIndex++;
        }
    }

    // помен€ть местами `pIndex` с пивотом
   
    T buf = arr->Get(end);
    arr->Set(end, arr->Get(pIndex));
    arr->Set(pIndex, buf);

    return pIndex;
}



#endif
