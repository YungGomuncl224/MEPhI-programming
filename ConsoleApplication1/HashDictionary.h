#pragma once
#ifndef HASHDICTIONARY_H
#define HASHDICTIONARY_H
//#include "tree.h"
#include "HashTable.h"
using namespace std;
template<class T>
class HashDictionary
{
	//private:

	//	binary_tree<T>* items;

public:

	HashTable<T>* items;


	HashDictionary(HashTable<T>* items)
	{
		this->items = items;
	}


	int GetCount()
	{
		return items->GetSize();
	}



	void Add(int k, T element)
	{
		items->insertItem(k,element);
	}

	void Remove(int key)
	{
		items->deleteItem(key);
	}

	void GetPrint()
	{
		items->Print();
	}

	/*void surrogat()
	{
		//	items->garbagge();
	}

	void GetPrintGis()
	{
		items->print_gis();
	}

	void show(int k)
	{
		items->show(k);
	}*/
};

#endif;
