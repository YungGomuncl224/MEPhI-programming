#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <list>
using namespace std;



template<class T>
class HashTable
{
    int capacity;
    list<T>* table;

public:

    int GetSize()
    {
        return capacity;
    }

    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }

    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key)
    {
        return (key % capacity);
    }
   

    HashTable(int c)
    {
        int size = getPrime(c);
        this->capacity = size;
        table = new list<T>[capacity];
    }

    void insertItem(int key, T data)
    {
        int index = hashFunction(key);
        table[index].push_back(data);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);

        list<int>::iterator i;
        for (i = table[index].begin();
            i != table[index].end(); i++)
        {
            //cout << *i << endl;

            if (*i == table[index].front())
                break;
        }

        if (i != table[index].end())
            table[index].erase(i);
    }

    void Print()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "table[" << i << "]";
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
        cout << endl;
    }
};






#endif