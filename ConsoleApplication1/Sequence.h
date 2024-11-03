#ifndef SEQUENCE_H 
#define SEQUENCE_H 

template <class T>
class Sequence
{

public:

	virtual void Append(T item) = 0;

	virtual int GetLength() = 0;

	virtual T GetFirst() = 0;

	virtual T GetLast() = 0;

	virtual T Get(int index) = 0;

	virtual Sequence<T>* GetSubList(int startIndex, int endIndex) = 0;

	virtual void Pretend(T item) = 0;

	virtual void InsertAt(T item, int index) = 0;

	virtual Sequence<T>* Map(T(*function)(T item)) = 0;

	virtual T Reduce(T(*function)(T item, T constant), T consta) = 0;

	virtual size_t Where(T item) = 0;

	virtual T operator [] (int i) = 0;

};

#endif
