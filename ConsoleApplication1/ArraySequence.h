#ifndef ARRAYSEQUENCE_H 
#define ARRAYSEQUENCE_H 
#include"DynamicArray.h"
#include "Sequence.h"
#include <iostream>

using  namespace std;

template <class T>
class ArraySequence : public Sequence<T>
{
private:

	DynamicArray<T>* items;
	int capasity = 100;//capacity - емкость

public:
	ArraySequence(){}

	ArraySequence(DynamicArray<T>* items)
	{
		this->items = items;
	}

	virtual int GetLength() override
	{
		return this->items->GetSize();
	}

	virtual void Append(T item) override
	{
		if (this->items->GetSize() == 0){
			this->items->Set(0, item);
			//cout << " c  ";
			this->items->Resize(this->items->GetSize() + 1);
		}
		else {
			this->items->Resize(this->items->GetSize() + 1);
			this->items->Set(this->items->GetSize() - 1, item);
			//cout << " p  ";
		}
		if (items->GetSize() > 100)
		{
			capasity += 100;
			for (int i = capasity; i < capasity -100; i++) {
				items->Set(i, 0);
			}
		}
	}

	virtual T Get(int index) override
	{
		return this->items->Get(index);
	}

	virtual T GetFirst() override
	{
		return this->items->GetFirst();
	}

	virtual T GetLast() override
	{
		return this->items->GetLast();
	}

	virtual ArraySequence<T>* GetSubList(int startIndex, int endIndex) override
	{
		DynamicArray<T>* buff = this->items->GetSubList(startIndex, endIndex);
		return new ArraySequence(buff);
	}

	virtual void Pretend(T item) override
	{
		this->items->Pretend(item);
		if (items->GetSize() > 100)
		{
			capasity += 100;
			for (int i = capasity; i < capasity - 100; i++) {
				items->Set(i, 0);
			}
		}
	}

	virtual void InsertAt(T item, int index) override
	{
		this->items->InsertAt(item, index);
		if (this->items->GetSize() > 100)
		{
			capasity += 100;
			for (int i = capasity; i < capasity - 100; i++) {
				items->Set(i, 0);
			}
		}
	}

	ArraySequence<T>* Concat(ArraySequence<T>* list)
	{
		DynamicArray<T>* buff = this->items->Concat(list);
		return ArraySequence(buff);
	}

	virtual ArraySequence<T>* Map(T(*function)(T item)) override
	{
		DynamicArray<T>* buff = this->items->Map(function);
		return new ArraySequence(buff);

	}

	virtual T Reduce(T(*function)(T item, T constant), T consta) override
	{
		T res = this->items->Reduce(function,consta);
		return res;
	}

	virtual size_t Where(T item) override
	{
		return this->Where(item);
	}

	virtual T operator [] (int i) override
	{
		return this->items->operator[](i);
	}
};
#endif
