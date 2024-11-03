#pragma once
#ifndef  ADAPTIVESEQUENCE_H
#define  ADAPTIVESEQUENCE_H
#include "LinkedList.h" 
#include "Sequence.h"

template <class T>
class AdaptiveSequence : Sequence<T>
{
private:
	DynamicArray<T>* buffer;
	size_t start;
	size_t end;
	size_t appendCount;
	size_t prependCount;
public:
	virtual T GetFirst() override
	{
		if (this->count)
			return this->buffer->Get(0);
		else
			throw new IndexOutOfRangeException();
	}

	virtual T Get(size_t index) override
	{
		if (this->start <= index && index <= this->end)
			return this->buffer->Get(index);
		else
			throw new IndexOutOfRangeException();
	}

	virtual void Append(T item) override
	{
		if (!(this->buffer->GetSize() > this->end))
		{
			this->buffer->Resize(this->buffer->GetSize() * 2); // разместить элементы в соотношении prependCount : appendCount
			appendCount = 0;
			prependCount = 0;
		}
		this->buffer->Set(count++, item);
		this->appendCount++;
	}
	virtual void Prepend(T item) override
	{
		if (!(0 > this->start))
		{
			this->buffer->Resize(this->buffer->GetSize() * 2); // разместить элементы в соотношении prependCount : appendCount
			appendCount = 0;
			prependCount = 0;
		}
		this->buffer->Set(count++, item);
		this->prependCount++;
	}
};

#endif