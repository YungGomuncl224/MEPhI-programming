#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <iostream>
using namespace std;

template <typename T>
class SmartPtr
{
private:
    T* p; 
    int count; 

public:
 
    SmartPtr(T* _p = nullptr)
    {
        count = 0;
        p = _p;
    }


    SmartPtr operator=(const SmartPtr& obj)
    {

        p = obj.p;
        count++;
        return *this;
    }


    ~SmartPtr()
    {
 
        if ((p != nullptr) && (count == 0))
        {
           // cout << " (Delete object) " << endl;
            delete[] p;      
        }
        else 
        {
           // cout << " (Delete copy) " << endl;
            count--; 
        }
    }

    T* operator->()
    {
        return p;
    }
};

#endif;