#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>
#include<cmath>

template<class T>
class DynamicArray
{
private:
	T* arr;
	int size;

public:
	DynamicArray(T* items, int count)
	{
		//int arr1[count];
		arr = new T[count];
		for (int i = 0; i < count; i++)
		{
			arr[i] = items[i];
		}
		size = count;
	}

	DynamicArray(){}

	DynamicArray(int size)
	{
		this->size = size;

		arr =  new T[size];
	}

	T Get(int index)
	{
		//if (index >= this->size || !arr[index])
			//return 0;
		//else
		return arr[index];
	}

	T GetFirst()
	{
		return arr[0];
	}

	T GetLast()
	{
		if (!arr)
			return 0;
		else
			return arr[size-1];
	}

	int GetSize()
	{
		//if (this == NULL) return 0;
		return this->size;
	}

	void Set(int index, T value)
	{
		arr[index] = value;
	}

	void Resize(int newSize)
	{
		size = newSize;
		T* temp = new T[newSize];
		for (int i = 0; i < newSize; i++)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
	}

	DynamicArray<T>* GetSubList(int startIndex, int endIndex)
	{
		DynamicArray<T>* subl = new DynamicArray<T>;
		subl->size = endIndex - startIndex+1;
		subl->arr = new T[subl->size];
		for (int i = startIndex; i <= endIndex; i++)
			subl->arr[i- startIndex] = this->arr[i];
		return subl;
	}

	void Pretend(T item)
	{
		T* temp = new T[size + 1];
		temp[0] = item;
		for (int i = 1; i <= size; i++)
			temp[i] = arr[i-1];
		delete[] arr;
		arr = temp;
		size++;
	}

	void InsertAt(T item, int index)
	{
		T* temp = new T[size+1];
		for (int i = 0; i < size; i++)
		{
			//temp[i] = arr[i];
			if (i == index)
			{
				temp[i] = item;
				i--;
			}
			else temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size++;
	}

	DynamicArray<T>* Concat(DynamicArray<T>* list)
	{
		DynamicArray<T>* temp = new DynamicArray<T>;
		temp->size = this->size + list->size;
		temp->arr = new T[temp->size];
		for (int i = 0; i < this->size; i++)
			temp->arr[i] = this->arr[i];
		for (int i = this->size; i < temp->size; i++)
			temp->arr[i] = list->arr[i - this->size];
		return temp;
	}

	DynamicArray<T>* Map(T (*function)(T item))
	{
		DynamicArray<T>* res = new DynamicArray<T>;
		res->size = this->size;
		res->arr = new T[res->size];
		for (int i = 0; i < this->size; i++)
		{
			res->arr[i] = function(this->arr[i]);
		}
		return res;
	}

	T Reduce(T(*function)(T item,T constant),T consta)
	{
		T res = function(this->arr[0],consta);
		for (int i = 1; i < this->size; i++)
		{
			res += function(this->arr[i], consta);
		}
		return res;
	}

	size_t Where(T item)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] == item)
			{
				return i;
			}
		}
	}

	void DeleteF() {
		//this->size = this->size - 1;
		T* temp = new T[size-1];
		for (int i = 1; i < size; i++)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
		this->size = this->size - 1;
	}

	T operator [] (int i) { return this->arr[i]; }


};
#endif
