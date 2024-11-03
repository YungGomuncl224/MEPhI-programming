#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream> 
#include"DynamicArray.h" 
#include "Sequence.h" 
#include "ArraySequence.h" 
//#include "LinkedListSecuence.h"
//#include "LinkedList.h"


#include<iostream>
#include<cmath>
using  namespace std;

template <class T> 
class Vector
{
private:
	Sequence<T>* data;
	size_t size;
public:

	Vector(){}

	Vector(Sequence<T>* items)
	{
		this->data = items;
		size = data->GetLength();
	}

	Vector<T>* Sum(Vector<T>* vector)
	{
		DynamicArray<T>* temp = new DynamicArray<T>(0);
		Vector<T>* buff = new Vector<T>;
		buff->data = new ArraySequence<T>(temp);
		buff->size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			buff->data->Append((this->data->Get(i)) + (vector->data->Get(i)));
		}
		return buff;
	}

	Vector<T>* Normal()
	{
		DynamicArray<T>* temp = new DynamicArray<T>(0);
		Vector<T>* buff = new Vector<T>;
		buff->data = new ArraySequence<T>(temp);
		buff->size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			if (this->data->Get(i) == 0) {
				buff->data->Append(0);
				//cout << " m  ";
				//cout << " b  ";
			}
			else {
				buff->data->Append(-((1) / (this->data->Get(i))));
				//cout << " l  ";
				
			}
			//cout << " n  ";
		}
		return buff;
	}

	T MultScal(Vector<T>* vector)
	{
		T res = 0;
		for (int i = 0; i < this->size; i++)
		{
			res += ((this->data->Get(i)) * (vector->data->Get(i)));
		}
		return res;
	}

	Vector<T>* Mult(T number)
	{
		DynamicArray<T>* temp = new DynamicArray<T>(0);
		Vector<T>* buff = new Vector<T>;
		buff->data = new ArraySequence<T>(temp);
		buff->size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			buff->data->Append((this->data->Get(i)) * number);
		}
		return buff;
	}

	T Get(int index)
	{
		return this->data->Get(index);
	}
};


template <class T>
class Complex
{
public:
	double real;
	double unreal;
	Complex() {
		real = 0;
		unreal = 0;
	}
	Complex operator + (Complex i1) {
		Complex res = new Complex();
		res.real = real + i1.real;
		res.unreal = unreal + i1.unreal;
		return res;
	}
};


template <class T>
class DiMatrix
{
private:
	Sequence<T>* data;
	size_t size;
public:

	DiMatrix(){}

	DiMatrix(Sequence<T>* items)
	{
		this->data = items;
		size = data->GetLength();
	}

	DiMatrix<T>* Mult(T number)
	{
		DynamicArray<T>* temp = new DynamicArray<T>(0);
		DiMatrix<T>* buff = new DiMatrix<T>;
		buff->data = new ArraySequence<T>(temp);
		buff->size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			buff->data->Append((this->data->Get(i)) * number);
		}
		return buff;
	}

	DiMatrix<T>* Sum(DiMatrix<T>* vector)
	{
		DynamicArray<T>* temp = new DynamicArray<T>(0);
		DiMatrix<T>* buff = new DiMatrix<T>;
		buff->data = new ArraySequence<T>(temp);
		buff->size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			buff->data->Append((this->data->Get(i)) + (vector->data->Get(i)));
		}
		return buff;
	}

	DiMatrix<T>* Normal()
	{
		DynamicArray<T>* temp = new DynamicArray<T>(0);
		DiMatrix<T>* buff = new DiMatrix<T>;
		buff->data = new ArraySequence<T>(temp);
		buff->size = this->size;
		for (int i = 0; i < this->size; i++)
		{
			if (this->data->Get(i) == 0) {
				buff->data->Append(0);
			}
			else {
				buff->data->Append(-((1) / (this->data->Get(i))));
			}
	
		}
		return buff;
	}

	T Get(int index)
	{
		return this->data->Get(index);
	}

};


template <class T>
class queue1
{
private:

	DynamicArray<T>* items;

public:

	queue1(DynamicArray<T>* item)
	{
		this->items = item;
	}

	bool isnt_place()
	{
		return items->GetSize() == 0;
	}

	void push(T x)
	{
		items->Resize(items->GetSize() + 1);
		items->Set(items->GetSize() - 1, x);
	}

	int size()
	{
		return items->GetSize();
	}

	T pop()
	{
		T x = items->GetFirst();
		items->DeleteF();
		return x;
	}

	queue1<T>* Map(T(*function)(T item))
	{
		DynamicArray<T>* buff = this->items->Map(function);
		return new queue1(buff);
	}

	T Reduce(T(*function)(T item, T constant), T consta)
	{
		T res = this->items->Reduce(function, consta);
		return res;
	}

	queue1<T>* GetSubList(int startIndex, int endIndex)
	{
		DynamicArray<T>* buff = this->items->GetSubList(startIndex, endIndex);
		return new queue1(buff);
	}

	queue1<T>* Concat(queue1<T>* list)
	{
		DynamicArray<T>* buff = this->items->Concat(list->items);
		return new queue1(buff);
	}

	T Where(T item)
	{
		return this->items->Where(item);
	}

	bool is_sequence(DynamicArray<T>* arr)
	{
		int index_seq1 = 0;
		int index_seq2 = 0;
		while (index_seq1 < arr->GetSize() and index_seq2 < items->GetSize())
		{
			if (arr->Get(index_seq1) == items->Get(index_seq2))
			{
				index_seq1 = index_seq1 + 1;
			}
			index_seq2 = index_seq2 + 1;
		}
		return index_seq1 == arr->GetSize();
	}

	void based_separation(T(*func)(T item), queue1<T>* list1, queue1<T>* list2)
	{
		while (list1->size() > 0)list1->pop();
		while (list2->size() > 0)list2->pop();
		for (int i = 0; i < size(); i++)
		{
			if (func(items->Get(i)))
				list1->push(items->Get(i));

			else
				list2->push(items->Get(i));
		}
	}
};


















#endif