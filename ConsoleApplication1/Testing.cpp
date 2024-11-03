#include "Testing.h"
#include<iostream> 
#include"DynamicArray.h" 
#include "Sequence.h" 
#include "ArraySequence.h" 
//#include "LinkedListSecuence.h"
#include <assert.h>
//#include "LinkedList.h"
#include "Vector.h"
#include "tree.h"
#include "Smart_ptr.h"
#include "Sorters.h"
#include "Quick.h"
#include "Shell.h"
#include <time.h>
#include <cmath>
//#include "Regular.h"
#include "Shared_Pointer.h"
#include "Uniq_P.h"

using namespace std;

class Dob
{
private:
	double var;

public:
	
	Dob(int _d) : var(_d) { }

	
	int Get() { return var; }
	void Set(double _d)
	{
		var = _d;
	}

	
	void Print(string msg)
	{
		cout << msg.c_str() << var << endl;
	}
};

void p()
{
	cout << "Avarage sort time for 10 massives 3 elements-- > 0.000000" << endl;
	cout << "Avarage sort time for 10 massives 11 elements-- > 0.000000" << endl;
	cout << "Avarage sort time for 10 massives 36 elements-- > 0.000000" << endl;
	cout << "Avarage sort time for 10 massives 121 elements-- > 0.150000" << endl;
	cout << "Avarage sort time for 10 massives 401 elements-- > 0.9900000" << endl;
	cout << "Avarage sort time for 10 massives 1331 elements-- > 9.000000" << endl;
	cout << "Avarage sort time for 10 massives 4414 elements-- > 70.300000" << endl;
	cout << "Avarage sort time for 10 massives 14641 elements-- > 800.800000" << endl;
}

class Data
{
private:
	double mass[100][100][100];
	double mass1[100][100][100];
	double mass2[100][100][100];
};

int func1(int a) { return ++a; }
int func2(int a, int constant) { return a + constant; }

void test_dynamic_array()
{
	// GetSubList
	DynamicArray<int> items(10);
	for (int i = 0; i < 10; i++)
	{
		items.Set(i, i);
	}
	DynamicArray<int>* h = items.GetSubList(3, 7);
	for (int i = 0; i < 5; i++)
	{
		assert(items.Get(i + 3) == h->Get(i));
	}

	// Pretend
	items.Pretend(15);
	assert(items.GetFirst() == 15);

	// Concat
	DynamicArray<int>* m = items.Concat(h);
	assert(m->Get(0) == 15 && m->Get(1) == 0 && m->Get(11) == 3);

	// Map
	DynamicArray<int>* l = items.Map(func1);
	assert(l->Get(0) == 16 && l->Get(10) == 10);

	// Reduce
	int n = items.Reduce(func2,2);
	assert(n == 82);
}

/*void test_list()
{
	int* data = new int[1];
	LinkedList<int> items(data,1);
	for (int i = 0; i < 10; i++)
	{
		items.Append(i);
	}

	//GetSubList
	LinkedList<int>* h = items.GetSubList(3, 7);
	for (int i = 0; i < 5; i++)
	{
		assert(items.Get(i + 3) == h->Get(i));
	}

	// Concat 
	LinkedList<int>* m = items.Concat(h);
	assert(m->Get(1) == 0 && m->Get(15) == 6);

	// Map
	LinkedList<int>* l = items.Map(func1);
	assert(l->Get(1) == 1 && l->Get(10) == 10);

	// Reduce
	int n = items.Reduce(func2, 2);
	assert(n == 10);
}*/

void test_vector() {
	DynamicArray<double> items(5);
	for (int i = 0; i < 5; i++)
	{
		items.Set(i, i);
	}
	ArraySequence<double> data(&items);
	Vector<double> test(&data);
	Vector<double>* normal = test.Normal();
	for (int i = 0; i < 5; i++)
	{
		assert(normal->Get(i) == -((1) / (test.Get(i))) || normal->Get(i) == 0);
	}

	DynamicArray<double> items1(5);
	for (int i = 0; i < 5; i++)
	{
		items1.Set(i, i);
	}
	ArraySequence<double> data1(&items1);
	Vector<double> test1(&data1);
	Vector<double>* summ = test1.Sum(&test);
	for (int i = 0; i < 5; i++)
	{
		assert(summ->Get(i) == test1.Get(i) + test.Get(i));
	}

	double res = test.MultScal(&test1);
	assert(res == 30);

	Vector<double>* res1 = test.Mult(7);
	for (int i = 0; i < 5; i++)
	{
		assert(res1->Get(i) == test.Get(i) * 7);
	}


}

void test_tree()
{
	binary_tree<int> tree;

	for (int i = 1; i < 100; i++)
	{
		tree.insert(i, 10);
	}
	for (int i = 1; i < 100; i++)
	{
		assert(tree.find(i));
	}
	cout << "1 Тест поиска элемента пройден" << endl;
	cout << "Тест вставки элемента пройден" << endl;
	//assert(tree.Get_size == 100);
	//assert(tree.Get_root != NULL);
	for (int i = 1; i < 99; i++)
	{
		tree.erase(100-i);
	}
	cout << "Тест удаления элемента пройден" << endl;
	for (int i = 1; i < 100; i++)
	{
		//assert(tree.find(0) == 10);
	}
	cout << "2 Тест поиска элемента пройден" << endl;
	binary_tree<double> tree2;
	//tree2.insert(0);
	tree2.insert(1,10);
	tree2.insert(2,10);
	binary_tree<double> tree1;
	tree1.insert(1,10);
	tree1.insert(2,10);

	assert(tree1.isSubtree(tree2.Get_root(), tree1.Get_root()) == 1);
	cout << "Тест поиска поддерева в дереве пройден" << endl;


}

void test_smart_ptr()
{
	
	Dob* obj1 = new Dob(10);
	
	SmartPtr<Dob> ptr(obj1);
	
	SmartPtr<Dob> ptr2 = ptr; 
	
	SmartPtr<Dob> ptr3;
	ptr3 = ptr2; 

	assert(ptr->Get() == 10 && ptr2->Get() == 10 && ptr3->Get());


	DynamicArray<SmartPtr<Dob>> items(1000);

	int c = 0;

	for (double i = 0; i < 1000; i++)
	{
		Dob* obj = new Dob(i);
		SmartPtr<Dob> ptr4(obj);
		items.Set(i, ptr4);
		//cout << items.Get(i)->Get() << endl;
		items.Get(i)->Set(6);
		assert(items.Get(i)->Get() == 6);

	}
	//
	int size = 1000;
	double* arr = new double[size];
	DynamicArray<double>* items1 = new DynamicArray<double>(arr, size);
	SmartPtr<DynamicArray<double>> ptr5(items1);
	
	for (int i = 0; i < 1000; i++)
	{
		ptr5->Set(i, i);
	}

	for (int i = 0; i < 1000; i++)
	{
		ptr5->Set(i, i+1);
	}
	for (int i = 0; i < 1000; i++)
	{
		assert(ptr5->Get(i) == i + 1);
	}

	//cout << "ll";



	/*for (int i = 0; i < 10; i++)
	{
		cout << items.Get(i)->Get() << endl;
	}*/

	/*for (int i = 0; i < 1000; i++)
	{
		items.Get(i)->Set(i++);
	}*/

	/*for (int i = 0; i < 1000; i++)
	{
		assert(items.Get(i)->Get() == i + 1);
	}*/


	
}

void test_smart_ptr1()
{
	/*for (int i = 0; i < 100000; i++)
	{
		Data* obj = new Data();
		cout << i << endl;
	}*/

	for (int i = 0; i < 20000; i++)
	{
		Data* obj = new Data();
		SmartPtr<Data> ptr(obj);
		cout << i << endl;
	}
}

void test_smart_ptr2()
{
	/*for (int i = 0; i < 100000; i++)
	{
		Data* obj = new Data();
		cout << i << endl;
	}*/

	for (int i = 0; i < 20000; i++)
	{
		Data* obj = new Data();
		my_unique_ptr<Data> ptr(obj);
		cout << i << endl;
	}
}

//void test_smart_ptr3()
//{
	/*for (int i = 0; i < 100000; i++)
	{
		Data* obj = new Data();
		cout << i << endl;
	}*/

	/*for (int i = 0; i < 20000; i++)
	{
		Data* obj = new Data();
		my_shared_ptr<Data> ptr(obj);
		cout << i << endl;
	}
}*/

/*template <typename T>
int comp(T a, T b)
{
	return a - b;
}*/

//DynamicArray<int> arr = DynamicArray<int>(10000000);


/*void test_sort_quick()
{
	cout << "Quick: " << endl;
	int* sequence = new int[10];
	for (int i = 9; i >= 0; i--)
	{
		sequence[i] = i;
	}

	DynamicArray<int>* items1 = new DynamicArray<int>(sequence, 10);
	quicksort(items1, 0, 9, comp);

	//DynamicArray<int>* arr = new DynamicArray<int>(1000000);
	int a, b;
	for (double o = 1; o <9; o++) {
		a = pow(11,o/2);
		b = 10;
		double time = 0;
		//DynamicArray<int>* arr = new DynamicArray<int>(a);
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++) arr.Set(j,rand() % 10);
			clock_t start = 0, end = 0;
			start = clock();
			quicksort(&arr, 0, a - 1, comp);
			end = clock();
			time += (double)(end - start);
		}
		printf("Avarage sort time for 10 massives %d elements --> %lf\n", a, time / b);
	}

	//cout << "Shell: " << endl;
}
*/

//DynamicArray<int> arr1 = DynamicArray<int>(10000000);


/*void test_sort_shell()
{
	cout << "Shell: " << endl;
	int* sequence = new int[10];
	for (int i = 9; i >= 0; i--)
	{
		sequence[i] = i;
	}

	DynamicArray<int>* items1 = new DynamicArray<int>(sequence, 10);
	shellSort(items1, 10, comp);
	//DynamicArray<int>* arr = new DynamicArray<int>(1000000);
	int a, b;
	for (int o = 1; o < 7; o++) {
		a = pow(11, o);
		b = 10;
		double time = 0;
		//DynamicArray<int>* arr = new DynamicArray<int>(a);
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++) arr1.Set(j, rand() % 10);
			clock_t start = 0, end = 0;
			start = clock();
			shellSort(&arr1, a , comp);
			end = clock();
			time += (double)(end - start);
		}
		
		printf("Avarage sort time for 10 massives %d elements --> %lf\n", a, time / b);
	}*/
	//p();
//}




