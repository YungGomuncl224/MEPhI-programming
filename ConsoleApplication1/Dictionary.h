#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "tree.h"

template<class T>
class Dictionary
{
//private:

//	binary_tree<T>* items;

public:

	binary_tree<T>* items; 


	Dictionary(binary_tree<T>* items)
	{
		this->items = items;
	}


	int GetCount()
	{
		return items->Get_size();
	}

	T Get(int key)
	{
		return items->find(key);
	}

	bool ContainsKey(int key)
	{
		return items->InTree(key);
	}

	void Add(int k, T element)
	{
		items->insert(k, element);
	}

	void Remove(int key)
	{
		items->erase(key);
	}

	void GetPrint() 
	{
		items->print();
	}

	void surrogat()
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
	}
};

#endif;
