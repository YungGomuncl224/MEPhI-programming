#ifndef LINKEDLISTSEQUENCE_H 
#define LINKEDLISTSEQUENCE_H 
#include "LinkedList.h" 
#include "Sequence.h"

template <class T>
class LinkedListSequence : public Sequence<T>
{
private:

	LinkedList<T>* items;

public:
	LinkedListSequence(LinkedList<T>* items)
	{
		this->items = items;
	}

	virtual int GetLength() override
	{
		return this->items->GetLength();
	}

	virtual void Append(T item) override
	{
		this->items->Append(item);
	}

	virtual T Get(int index) override
	{
		return this->items->Get(index);
	}

	virtual T GetFirst(int index) override
	{
		return this->items->GetFirst(index);
	}

	virtual T GetLast() override
	{
		return this->items->GetLast();
	}

	virtual LinkedListSequence<T>* GetSubList(int startIndex, int endIndex) override
	{
		LinkedList<T>* buff = this->items->GetSubList(startIndex, endIndex);
		return new LinkedListSequence(buff);
	}

	virtual void Pretend(T item) override
	{
		this->items->Pretend(item);
	}

	virtual void InsertAt(T item, int index) override
	{
		this->items->InsertAt(item, index);
	}

	LinkedListSequence<T>* Concat(LinkedListSequence<T>* list)
	{
		LinkedListSequence<T>* buff = this->items->Concat(list);
		return LinkedListSequence(buff);
	}

	virtual LinkedListSequence<T>* Map(T(*function)(T item)) override
	{
		DynamicArray<T>* buff = this->items->Map(function);
		return new LinkedListSequence(buff);

	}

	virtual T Reduce(T(*function)(T item, T constant), T consta) override
	{
		T res = this->items->Reduce(function, consta);
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
