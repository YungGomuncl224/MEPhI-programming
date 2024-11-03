#pragma once

#ifndef SHARED_H
#define SHARED_H


template <typename T>
class my_shared_ptr
{
private:
	T* ptr = nullptr;
	size_t counter = 0;

	void delete_ptr()
	{
		//if (!counter) return;

		-- counter;
		if (counter == 0)
		{
			delete ptr;
			counter == 0;
		}
	}

public:

	my_shared_ptr() :counter(0) {}

	my_shared_ptr(T* _ptr) :ptr(_ptr), counter(1) {}

	my_shared_ptr(const my_shared_ptr& another) :ptr(another.ptr), counter(another.counter)
	{
		if (counter > 0)
			++ counter;
	}



	T* operator->() const
	{
		return ptr;
	}

	my_shared_ptr& operator=(const my_shared_ptr& r)
	{
		delete_ptr();

		this->ptr = r.ptr;
		this->counter = r.counter;
		if (nullptr != r.ptr)
		{
			(this->counter)++;
		}
		return *this;
	}



	T& operator*() const
	{
		return *ptr;
	}

	T* get() const
	{
		return this->ptr;
	}


	~my_shared_ptr()
	{
		delete_ptr();
	}
};

#endif