#include<iostream> 
#include"DynamicArray.h" 
#include "Sequence.h" 
#include "ArraySequence.h" 
#include "LinkedListSecuence.h"
#include <assert.h>
using namespace std;

void test_dynamic_array()
{
	DynamicArray<int> items(10);
	for (int i = 0; i < 10; i++)
	{
		items.Set(i, i);
	}
	DynamicArray<int>* a = items.GetSubList(3, 7);
	for (int i = 0; i < 5; i++)
	{
		assert(items.Get(i) == a->Get(i));
	}
}

int main()
{
	test_dynamic_array();
}