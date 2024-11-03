#ifndef GISTOG_H
#define GISTOG_H
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

class Person
{
public:
	int age;
	string name ="ivan";
	Person(int age)
	{
		this->age = age;
	}
	Person()
	{
		age = 0;
	}
};

template <typename T>
Dictionary<int> Solution_2_1(DynamicArray<T>* data)
{





	int para = 30;
	int young = 0;
	int old = 0;
	int middle = 0;
	binary_tree<int> tree;              
	Dictionary<int> dictionary(&tree);

	for (int i = 0; i < data->GetSize(); i++)
	{
		if((data->Get(i)).age <= para) young++;
		else if ((data->Get(i)).age > para * 2) old++;
		else middle++;
		Person chel = data->Get(i);
		//cout << chel.age << endl;
	}
	//cout << young << " " << old << " " << middle << " " << endl;
	dictionary.Add(30, young);
	dictionary.Add(60, middle);
	dictionary.Add(90, old);
	//cout << dictionary.ContainsKey(30) << endl;
	dictionary.GetPrintGis();
	return dictionary;
}
#endif
