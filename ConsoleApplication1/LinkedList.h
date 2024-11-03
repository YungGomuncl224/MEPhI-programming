#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<cmath>
using  namespace std;

template<class T>
class LinkedList
{
	struct Node {
		T val;
		Node* next;
	};

private:
	Node* first;
	Node* last;
	int size;

public:
	LinkedList()
	{
		first = NULL;
		last = NULL;
	}

	bool is_empty() {
		return first == NULL;
	}
	
	LinkedList(T* items, int count)
	{
		for (int i = 0; i < count; i++)
		{
			Node* p = (Node*)malloc(sizeof(struct Node));
			p->val = items[i];
			if (is_empty()) {
				first = p;
				last = p;
				//return;
			}
			else
			{
				last->next = p;
				last = p;
			}
		}
		size = count;
	}

	int GetLengh()
	{
		return size;
	}

	T GetLast()
	{
		return last->val;
	}

	T GetFirst()
	{
		return first->val;
	}

	T Get (const int index) {
		if (is_empty()) return 1;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			int test = 1;
		}
		return p->val;
	}

	void Append(T item) {
		Node* p = (Node*)malloc(sizeof(struct Node));
		p->val = item;
		if (size == 0) {
			first = p;
			size++;
		}
		else {
			if (is_empty()) {
				this->first = p;
				this->last = p;
			}
			else
			{
				last->next = p;
				last = p;
			}
			size++;
		}
	}

	void Prepend(T item)
	{
		Node* p = new Node(item);
		if (is_empty())
		{
			first = p;
			last = p;
			return;
		}
		p->next = first;
		first = p;
	}

	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		LinkedList<T>* res = new LinkedList<T>;
		Node* pr = this->first;
		for (int i = 0; i < startIndex; i++)
		{
			pr = pr->next;
		}
		for (int i = 0; i <= endIndex - startIndex; i++)
		{
			res->Append(pr->val);
			pr = pr->next;
		}
		res->size = endIndex - startIndex;
		return res;
	}

	LinkedList<T>* Concat(LinkedList<T>* list)
	{
		LinkedList<T>* res = new LinkedList<T>;
		Node* pr = this->first;
		res->size = 0;
		for (int i = 0; i < this->size; i++)
		{
			res->Append(pr->val);
			pr = pr->next;
		}
		pr = list->first;
		for(int i = 0;i < list->size;i++)
		{
			res->Append(pr->val);
			pr = pr->next;
		}
		return res;
	}

	LinkedList<T>* Map(T(*function)(T item))
	{
		LinkedList<T>* res = new LinkedList<T>;
		res->size = this->size;
		Node* pr = this->first;
		for (int i = 0; i < this->size; i++)
		{
			res->Append(function(pr->val));
			pr = pr->next;
		}
		return res;
	}

	T Reduce(T(*function)(T item, T constant), T consta)
	{
		T res = function(this->first->val, consta);
		Node* pr = this->first;
		for (int i = 1; i < this->size; i++)
		{
			res = function(pr->val, consta);
			pr = pr->next;
		}
		return res;
	}

	size_t Where(T item)
	{
		Node* pr = this->first;
		for (int i = 0; i < this->size; i++)
		{
			if (pr->val == item)
			{
				return i;
			}
			pr = pr->next;
		}
	}

	T operator [] (int i)
	{
		Node* ptr = this->first;
		int j = 0;
		while (j != i)
		{
			ptr = ptr->next;
			j++;
		}
		return ptr->val;
	}

	void Delete(int index)
	{
		Node* p = first;
		if (index >= size)
		{
			throw;
		}
		if (index == 0)
		{
			this->first = p->next;
		}
		else {
			for (int i = 0; i < index - 1; i++) {
				p = p->next;
			}
			Node* buf = p->next;
			p->next = p->next->next;
			free(buf);
		}
		size--;
	}
};
#endif


