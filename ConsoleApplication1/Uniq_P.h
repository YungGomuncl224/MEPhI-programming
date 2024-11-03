#pragma once
#ifndef UNI_H
#define UNI_H

template <class T>
class my_unique_ptr
{

private:
	T* ptr = nullptr;

public:

	my_unique_ptr() {}

	my_unique_ptr(T* ptr) : ptr(ptr) {}

	my_unique_ptr(const my_unique_ptr&) = delete;

	my_unique_ptr& operator = (const my_unique_ptr&) = delete;



	T& operator*() const
	{
		return *ptr;
	}

	T* operator->() const
	{
		return ptr;
	}

	T* get() const
	{
		return this->ptr;
	}

	~my_unique_ptr()
	{
		delete ptr;
	}
};



#endif