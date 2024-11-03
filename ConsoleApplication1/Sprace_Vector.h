#ifndef SPRACE_VECTOR_H
#define SPRACE_VECTOR_H
#include<iostream> 
#include"DynamicArray.h" 
#include "Sequence.h" 
#include "ArraySequence.h" 
//#include "LinkedListSecuence.h"
#include <assert.h>
//#include "LinkedList.h"
#include "Vector.h"
#include "tree.h"
#include "Smart_ptr.h"
#include "Sorters.h"
#include "Quick.h"
#include "Shell.h"
#include <time.h>
#include <cmath>
#include "Sprace_Vector.h"
#include "Dictionary.h"
template<typename T>
Dictionary<T> Solution_2_2(DynamicArray<T>* data)
{
	binary_tree<T> tree;              //= new binary_tree<T>();
	Dictionary<T> dictionary(&tree);
	//int c = 0;
	for (int i = 0; i < data->GetSize(); i++)
	{
		if (data->Get(i) != 0)
		{
			dictionary.Add(i, data->Get(i));
			//cout << "added " << endl;
			//cout << dictionary.Get(i) << endl;
			//c++;
		}
	}
	//dictionary.GetPrint();
	//cout << dictionary.Get(5) << endl;
	//cout << dictionary.Get(15) << endl;
	dictionary.GetPrint();
	return dictionary;
}

#endif