#include "Testing.h"
#include<iostream> 
#include"DynamicArray.h" 
#include "Sequence.h" 
#include "ArraySequence.h" 
//#include "LinkedListSecuence.h"
//#include <assert.h>
//#include "LinkedList.h"
#include "menu.h"
//#include "Vector.h"
#include "tree.h"
#include "Sorters.h"
#include "Quick.h"
#include "Shell.h"
#include "Sprace_Vector.h"
#include "Dictionary.h"
#include "Gistog.h"
#include "Regular.h"
#include "HashTable.h"
#include "HashDictionary.h"
#include <list>
#include <stdlib.h>
#include <time.h>
//#include "Testing.h"
#include "Shared_Pointer.h"

using namespace std;
//template <typename T>
template <typename T>
int comp(T a, T b)
{
	return a - b;
}


class Data
{
private:
	double mass[100][100][100];
	double mass1[100][100][100];
	double mass2[100][100][100];
};


void test_regular_1()
{
	//тестируем DFA
	DFA testDFA(
		{ 0, 1, 2, 3, 4 },   		//состояния
		{ 0, 1 },            		//алфавит
		0,                 		//начальное состояние
		{ 1, 2 },            		//конечные состояния
		{                  		//функция переходов
			{1, 2},
			{1, 3},
			{4, 2},
			{1, 3},
			{4, 2}
		}
		);

	cout << "DFA:" << endl;
	testDFA.checkTest("0");
	testDFA.checkTest("111");
	testDFA.checkTest("10101");
	testDFA.checkTest("");
	testDFA.checkTest("01");
	testDFA.checkTest("101010");
	cout << endl;

}

void test_smart_ptr3()
{
	/*for (int i = 0; i < 100000; i++)
	{
		Data* obj = new Data();
		cout << i << endl;
	}*/

	for (int i = 0; i < 20000; i++)
	{
		//Data obj1();
		Data* obj = new Data();
		my_shared_ptr<Data> ptr(obj);
		cout << i << endl;
	}
}

int GetRandomNumber(int min, int max)
{
	// Установить генератор случайных чисел
	//srand(time(NULL));

	// Получить случайное число - формула
	int num = min + rand() % (max - min + 1);

	return num;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string dataddsd = "";
	dataddsd.append("12");
	cout << dataddsd << endl;
	

	//DynamicArray<int>* arr = new DynamicArray<int>(1000000);
	//arr->Set(500000, 12);
	//cout << arr->Get(500000);
	//test_vector(); 
	//test_tree();
	//test_smart_ptr(); 
	//menu();
	
	//test_sort_quick();
	//test_sort_shell();
	//test_smart_ptr1();
	//sort_menu();
	//cout << Cort(sequence, comp)[0];
	//test_tree();
	cout << "Обработка разряженных векторов" << endl;
	DynamicArray<double>* arr = new DynamicArray<double>(50);

	DynamicArray<double> arr2(50);
	arr2.Concat(arr);
	int* arr17 = new int[4];

	for (int i = 0; i < arr->GetSize(); i++)
	{
		if (i == 5 || i == 15 || i == 25) arr->Set(i,350);
		else if (i == 2 || i == 37 || i == 29) arr->Set(i, 120);
		else arr->Set(i,0);
	}


	DynamicArray<double>* arr1 = new DynamicArray<double>(70);

	for (int i = 0; i < arr1->GetSize(); i++)
	{
		if (i == 2 || i == 11 || i == 13) arr1->Set(i, 12);
		else if (i == 60 || i == 37 || i == 29) arr1->Set(i, 1);
		else arr1->Set(i, 0);
	}



	//print(arr->GetSize(), arr);

	Dictionary<double> dic = Solution_2_2(arr);
	cout << endl;
	Dictionary<double> dic1 = Solution_2_2(arr1);
	//cout << dic.Get(5) << "  ";
	//cout << dic.items->find(15) << "  ";
	//dic->GetPrint();
	//cout << " kf kkdvdvd";  
	//dic.GetPrint(); 
	cout << endl;
	//dic1.GetPrint();
	cout << endl;


	cout << "Гистограмма " << endl;
	Person per1(10);
	Person per2(35);
	Person per3(45);
	Person per4(65);
	Person per5(1);
	Person per6(85);
	Person per7(13);
	Person per8(74);

	// сделать рандомное получение возраста , например 30 челрвек молодые , 30 старые , 30 средние и тд
	DynamicArray<Person>* PersDataRand = new DynamicArray<Person>(30);
	for (int i = 0; i < 30; i++)
	{
		PersDataRand->Set(i, GetRandomNumber(0, 90));
	}
	Dictionary<int> dic3 = Solution_2_1(PersDataRand);

	DynamicArray<Person>* PersData = new DynamicArray<Person>(8);
	PersData->Set(0, per1);
	PersData->Set(1, per2);
	PersData->Set(2, per3);
	PersData->Set(3, per4);
	PersData->Set(4, per5);
	PersData->Set(5, per6);
	PersData->Set(6, per7);
	PersData->Set(7, per8);
	Dictionary<int> dic2 = Solution_2_1(PersData);

	//dic2.GetPrint();
	
	//test_regular_1();

	int key[] = {80, 2, 3, 40, 5, 6,18,22,11,19,20};
	int data[] = { 123, 432, 53, 43, 423, 111 ,120,1,4,234,1111};
	int n = sizeof(key) / sizeof(key[0]);

	HashTable<int> h(n);

	for (int i = 0; i < n; i++)
		h.insertItem(key[i], data[i]);
	cout << endl;
	//h.deleteItem(212);
	//h.deleteItem(321);
	//h.deleteItem(433);
	h.Print();
	//h.deleteItem(3);
	//h.Print();

	HashDictionary<int> di =  HashDictionary<int>(&h);

	//di.GetPrint();
	//cout << di.GetCount();

	//test_smart_ptr2();
	//test_tree();
	//Sequence<int> seq = ArraySequence<int>();
}







