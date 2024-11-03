#include "Testing.h"
#include<iostream> 
#include"DynamicArray.h" 
#include "Sequence.h" 
#include "ArraySequence.h" 
//#include "LinkedListSecuence.h"
#include <assert.h>
//#include "LinkedList.h"
#include "menu.h"
#include "Vector.h"
#include "tree.h"
#include "Smart_ptr.h"
#include "Sorters.h"
#include "Quick.h"
#include "Shell.h"
#include <time.h>
#include <cmath>
using namespace std;

template <typename T>
int comp1(T a, T b)
{
	return a - b;
}

template <typename T>
int comp2(T a, T b)
{
	return -(a - b);
}

void variant() {
	cout << "0: Print sequence" << endl;
	cout << "1: Get first element" << endl;
	cout << "2: Get last element" << endl;
	cout << "3: Get element by index" << endl;
	cout << "4: Set element (DynamicArray)" << endl;
	cout << "5: Append element" << endl;
	//cout << "6: Delete node by index (LinkedList)" << endl;
	cout << "7: Get size" << endl;
	cout << "8: GetSubList" << endl;
	cout << "9: Concat" << endl;
	cout << "10: Find index of element" << endl;
}

void print(int len, DynamicArray<double>* list)
{
	cout << "Result: ";
	for (int i = 0; i < len; i++)
	{
		cout << list->Get(i) << " ";
	}
	cout << endl;
}

/*void print_list(int len, LinkedList<double>* list)
{
	cout << "Result: ";
	for (int i = 0; i < len; i++)
	{
		cout << list->Get(i) << " ";
	}
}*/

void menu()
{


	cout << "Enter length of sequence" << "\n";
	int len;
	cin >> len;
	cout << "Enter elements of  sequence" << "\n";
	double* sequence = new double[len];
	for (int i = 0; i < len; i++)
	{
		cin >> sequence[i];
	}
	DynamicArray<double>* items1 = new DynamicArray<double>(sequence, len);
	SmartPtr<DynamicArray<double>> ptr(items1);

	variant();

	int go = 1;
	while (go == 1) {
		int choose1;
		cin >> choose1;

		if (choose1 == 1)
		{
			if (ptr->GetSize() == 0) cout << "Empty array" << endl;
			else {
				cout << ptr->GetFirst() << endl;

			}
		}

		else if (choose1 == 2)
		{
			if (ptr->GetSize() == 0) cout << "Empty array" << endl;
			else {
				cout << ptr->GetLast() << endl;
			}
		}

		else if (choose1 == 3)
		{
			if (ptr->GetSize() == 0) cout << "Empty array" << endl;
			else {
				cout << "Enter index" << endl;
				int i;
				cin >> i;
				while (i >= ptr->GetSize()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i;
				}
					cout << ptr->Get(i) << endl;
			}
		}

		else if (choose1 == 4)
		{
			cout << "Enter index" << endl;
			int i;
			cin >> i;
			while (i >= ptr->GetSize()) {
				cout << "Incorrect index , enter index" << endl;
				cin >> i;
			}
			cout << "Enter value" << endl;
			double v;
			cin >> v;
			ptr->Set(i, v);
		}
		else if (choose1 == 5)
		{
			cout << "Enter value" << endl;
			double v;
			cin >> v;
			
			ptr->Resize(ptr->GetSize() + 1);
			ptr->Set(ptr->GetSize()-1, v);
			
			
		}

		/*else if (choose1 == 6)
		{
			if (items1.GetSize() == 0) cout << "Empty array" << endl;
			else {
				cout << "Enter index" << endl;
				int i;
				cin >> i;
				while (i >= items2.GetLengh()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i;
				}
				items2.Delete(i);
			}
		}*/

		else if (choose1 == 7)
		{
			cout << ptr->GetSize() << endl;
			
		}

		else if (choose1 == 8)
		{
			if (ptr->GetSize() == 0) cout << "Empty array" << endl;
			else {
				cout << "Enter start index" << endl;
				int i1;
				cin >> i1;
				while (i1 >= ptr->GetSize()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i1;
				}
				cout << "Enter end index" << endl;
				int i2;
				cin >> i2;
				while (i2 >= ptr->GetSize()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i2;
				}

				DynamicArray<double>* m = ptr->GetSubList(i1, i2);
				SmartPtr<DynamicArray<double>> ptr1(m);
				print(ptr1->GetSize(), m);
				//cout << " point ";

			}
		}

		else if (choose1 == 9)
		{
			cout << "Enter length of 2 sequence" << "\n";
			int len2;
			cin >> len2;
			cout << "Enter elements of 2 sequence" << "\n";
			double* sequence2 = new double[len2];
			for (int i = 0; i < len2; i++)
			{
				cin >> sequence2[i];
			}
			DynamicArray<double> items3(sequence2, len2);
			//SmartPtr<DynamicArray<double>> ptr2(&items3);

			DynamicArray<double>* res = ptr->Concat(&items3);
			print(res->GetSize(), res);
			//cout << endl;

		}

		else if (choose1 == 10)
		{
			cout << "Enter value" << endl;
			double v;
			cin >> v;
			cout << ptr->Where(v);
		}

		else if (choose1 == 0)
		{
			print(ptr->GetSize(), items1);

			cout << endl;
		}

		cout << "1: Continue , 2: Finish" << " ";
		cin >> go;

	}




}

/*void print(int len, Vector<double>* list)
{
	cout << "Result: ";
	cout << "{ ";
	for (int i = 0; i < len; i++)
	{
		cout << list->Get(i) << " ";
		//cout << ",";
	}
	cout << "} ";
	cout << endl;
}*/

void printm(int len, DiMatrix<double>* list)
{
	cout << "Result: ";
	cout << endl;
	for (int i = 0; i < len; i++) {
		for(int j = 0;j < len;j++)
		{
			if(j == i) cout << list->Get(i) << " ";
			else cout << "0" << " ";
			//cout << endl;
		}
		cout << endl;
	}
}

void variant2()
{
	cout << "1: Multiply by a number" << endl;
	cout << "2: Add with vector" << endl;
	cout << "3: Find the normal" << endl;
	cout << "4: Find the scalar multiplication(vector)" << endl;
	cout << "5: Get coordinate(vector)" << endl;
}

void variant1()
{
	cout << "1:Delete and Get element" << endl;
	cout << "2: Add element" << endl;
	cout << "3: Get size" << endl;
	cout << "4: Find index of element" << endl;
	cout << "5: Is  empty?" << endl;
	cout << "6: Is sequence in queue?" << endl;
}

/*void menu1()
{
	cout << "1: Queue, 2: Vector, 3: Diagonal matrix" << endl;
	int choose;
	cin >> choose;
	cout << "Enter length of origin queue or demension of a vector or a matrix" << "\n";
	int len;
	cin >> len;
	cout << "Enter elements of original queue or of a vector or a matrix" << "\n";
	double* sequence = new double[len];
	for (int i = 0; i < len; i++)
	{
		cin >> sequence[i];
	}
	DynamicArray<double> items1(sequence, len);
	DynamicArray<double>* arr = &items1;
	queue1<double> queue(arr);
	ArraySequence<double> seq(arr);
	Vector<double> vector(&seq);
	const int length = len;
	DiMatrix<double> matrix(&seq);
	if (choose == 1)
		variant1();

	if (choose == 2 || choose == 3)
		variant2();

	int go = 1;
	while (go == 1)
	{
		int choose1;
		cin >> choose1;
		if (choose1 == 1)
		{
			if (choose == 1)
				cout << queue.pop() << endl;
			if (choose == 2)
			{
				cout << "Enter number" << endl;
				double number;
				cin >> number;
				vector = *(vector.Mult(number));
				print(length, &vector);
			}
			if (choose == 3)
			{
				cout << "Enter number" << endl;
				double number;
				cin >> number;
				matrix = *(matrix.Mult(number));
				printm(length, &matrix);
			}
		}

		else if (choose1 == 2)
		{
			if (choose == 1)
			{
				int a;
				cout << "enter element" << endl;
				cin >> a;
				queue.push(a);
			}
			if (choose == 2)
			{
				cout << "Enter length of 2 sequence" << "\n";
				int len2;
				cin >> len2;
				cout << "Enter elements of 2 sequence" << "\n";
				double* sequence2 = new double[len2];
				for (int i = 0; i < len2; i++)
				{
					cin >> sequence2[i];
				}
				DynamicArray<double> items5(sequence2, len2);
				ArraySequence<double> seq2(&items5);
				Vector<double> v2(&seq2);
				vector = *(vector.Sum(&v2));
				print(length, &vector);
			}
			if (choose == 3)
			{
				cout << "Enter length of 2 sequence" << "\n";
				int len2;
				cin >> len2;
				cout << "Enter elements of 2 sequence" << "\n";
				double* sequence2 = new double[len2];
				for (int i = 0; i < len2; i++)
				{
					cin >> sequence2[i];
				}
				DynamicArray<double> items5(sequence2, len2);
				ArraySequence<double> seq2(&items5);
				DiMatrix<double> v2(&seq2);
				matrix = *(matrix.Sum(&v2));
				printm(length, &matrix);
			}
		}

		else if (choose1 == 3)
		{
			if (choose == 1)
				cout << queue.size();
			if (choose == 2)
			{
				Vector<double>* vec4 = vector.Normal();
				print(length, vec4);
			}
			if (choose == 3)
			{
				DiMatrix<double>* vec4 = matrix.Normal();
				printm(length, vec4);
			}
		}

		else if (choose1 == 4)
		{
			if (choose == 1)
			{
				int a;
				cout << "enter element" << endl;
				cin >> a;
				cout << queue.Where(a) << endl;
			}
			else
			{
				cout << "Enter length of 2 vector" << "\n";
				int len3;
				cin >> len3;
				cout << "Enter elements of 2 vector" << "\n";
				double* sequence3 = new double[len3];
				for (int i = 0; i < len3; i++)
				{
					cin >> sequence3[i];
				}
				DynamicArray<double> items6(sequence3, len3);
				ArraySequence<double> seq3(&items6);
				Vector<double> v5(&seq3);
				cout << vector.MultScal(&v5) << endl;
			}
		}

		else if (choose1 == 5)
		{
			if (choose == 1)
				cout << queue.isnt_place() << endl;
			else
			{
				cout << "Enter 1, 2 or 3... if you want to see x, y or z...appropriately" << endl;
				int i;
				cin >> i;
				cout << vector.Get(i) << endl;
			}
		}

		else if (choose1 == 6)
		{
			cout << "Enter length of  sequence" << "\n";
			int len2;
			cin >> len2;
			cout << "Enter elements of  sequence" << "\n";
			double* sequence2 = new double[len2];
			for (int i = 0; i < len2; i++)
			{
				cin >> sequence2[i];
			}
			DynamicArray<double> items3(sequence2, len2);
			cout << queue.is_sequence(&items3) << endl;
		}

		cout << "1: Continue , 2: Finish" << " ";
		cin >> go;
	}
}*/

void variant3()
{
	cout << "1: Insert element" << endl;
	cout << "2: Delete element" << endl;
	cout << "3: Get size" << endl;
	cout << "4: Is element in tree?" << endl;
	cout << "5: Is tree in tree?" << endl;
	cout << "6: Print tree" << endl;
	cout << "7: show children" << endl;
}

/*void menu2()
{
	cout << "Enter length of tree" << "\n";
	int len;
	cin >> len;
	cout << "Enter elements of tree" << "\n";
	binary_tree<double> tree;
	double o;
	int go = 1;
	for (int i = 0; i < len; i++)
	{
		cin >> o;
		tree.insert(o);
	}
	//tree.show(2);
	variant3();
	while (go == 1) {
		int choose;
		cin >> choose;
		if (choose == 1)
		{
			cout << "Element: ";
			double i;
			cin >> i;
			if (tree.Get_size() == 0) {
				binary_tree<double> tree1(i);
				tree = tree1; 
			}
			else tree.insert(i);
			tree.print();
		}
		if (choose == 2)
		{
			cout << "Element: ";
			double i;
			cin >> i;
			if (tree.Get_size() == 0) cout << "no elements" << endl;
			else tree.erase(i);
			if (tree.Get_size() == 0) cout << "empty tree" << endl;
			else tree.print();
		}
		if (choose == 4)
		{
			cout << "Element: ";
			double i;
			cin >> i;
			if (tree.find(i) == 1) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		if (choose == 5)
		{
			cout << "Length: " << endl;
			int len1;
			cin >> len1;
			cout << "Elements: ";
			binary_tree<double> tree1;
			for (int i = 0; i < len1; i++)
			{
				double j;
				cin >> j;
				tree1.insert(j);
			}
			if (tree.isSubtree(tree.Get_root(), tree1.Get_root()) == 1) cout << "yes";
			else cout << "no";
			cout << "\n";
		}
		if (choose == 6) tree.print();

		if (choose == 7)
		{
			cout << "Element: ";
			double i;
			cin >> i;
			tree.show(i);
		}

		cout << "1: Continue , 2: Finish" << " ";
		cin >> go;
		
	} 

}*/

/*void menu()
{

	cout << "1: DynamicArray, 2: LinkedList" << endl;
	int choose;
	cin >> choose;
	cout << "Enter length of sequence" << "\n";
	int len;
	cin >> len;
	cout << "Enter elements of  sequence" << "\n";
	double* sequence = new double[len];
	for (int i = 0; i < len; i++)
	{
		cin >> sequence[i];
	}
	DynamicArray<double> items1(sequence, len);;
	LinkedList<double> items2(sequence, len);

	variant();

	int go = 1;
	while (go == 1) {
		int choose1;
		cin >> choose1;

		if (choose1 == 1)
		{
			if (items1.GetSize() == 0 || items2.GetLengh() == 0) cout << "Empty array" << endl;
			else {
				if (choose == 1) cout << items1.GetFirst() << endl;
				else cout << items2.GetFirst() << endl;
			}
		}

		else if (choose1 == 2)
		{
			if (items1.GetSize() == 0 || items2.GetLengh() == 0) cout << "Empty array" << endl;
			else {
				if (choose == 1) cout << items1.GetLast() << endl;
				else cout << items2.GetLast() << endl;
			}
		}

		else if (choose1 == 3)
		{
			if (items1.GetSize() == 0 || items2.GetLengh() == 0) cout << "Empty array" << endl;
			else {
				cout << "Enter index" << endl;
				int i;
				cin >> i;
				while (i >= items2.GetLengh()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i;
				}
				if (choose == 1) cout << items1.Get(i) << endl;
				else cout << items2.Get(i) << endl;
			}
		}

		else if (choose1 == 4)
		{
			cout << "Enter index" << endl;
			int i;
			cin >> i;
			while (i >= items2.GetLengh()) {
				cout << "Incorrect index , enter index" << endl;
				cin >> i;
			}
			cout << "Enter value" << endl;
			double v;
			cin >> v;
			items1.Set(i, v);
		}
		else if (choose1 == 5)
		{
			cout << "Enter value" << endl;
			double v;
			cin >> v;
			if (choose == 1) {
				items1.Resize(items1.GetSize() + 1);
				items1.Set(items1.GetSize() - 1, v);
			}
			else items2.Append(v);
		}

		else if (choose1 == 6)
		{
			if (items1.GetSize() == 0 || items2.GetLengh() == 0) cout << "Empty array" << endl;
			else {
				cout << "Enter index" << endl;
				int i;
				cin >> i;
				while (i >= items2.GetLengh()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i;
				}
				items2.Delete(i);
			}
		}

		else if (choose1 == 7)
		{
			if (choose == 1) cout << items1.GetSize() << endl;
			else cout << items2.GetLengh() << endl;
		}

		else if (choose1 == 8)
		{
			if (items1.GetSize() == 0 || items2.GetLengh() == 0) cout << "Empty array" << endl;
			else {
				cout << "Enter start index" << endl;
				int i1;
				cin >> i1;
				while (i1 >= items2.GetLengh()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i1;
				}
				cout << "Enter end index" << endl;
				int i2;
				cin >> i2;
				while (i2 >= items2.GetLengh()) {
					cout << "Incorrect index , enter index" << endl;
					cin >> i2;
				}
				if (choose == 1) {
					DynamicArray<double>* m = items1.GetSubList(i1, i2);
					print(m->GetSize(), m);
				}
				else {
					LinkedList<double>* m = items2.GetSubList(i1, i2);
					print_list(m->GetLengh(), m);
				}
			}
		}

		else if (choose1 == 9)
		{
			cout << "Enter length of 2 sequence" << "\n";
			int len2;
			cin >> len2;
			cout << "Enter elements of 2 sequence" << "\n";
			double* sequence2 = new double[len2];
			for (int i = 0; i < len2; i++)
			{
				cin >> sequence2[i];
			}
			DynamicArray<double> items3(sequence2, len2);
			LinkedList<double> items4(sequence2, len2);
			if (choose == 1)
			{
				DynamicArray<double>* m = items1.Concat(&items3);
				print(m->GetSize(), m);
			}
			else
			{
				LinkedList<double>* m = items2.Concat(&items4);
				print_list(m->GetLengh(), m);
			}
		}

		else if (choose1 == 10)
		{
			cout << "Enter value" << endl;
			double v;
			cin >> v;
			if (choose == 1) cout << items1.Where(v);
			else cout << items2.Where(v);
		}

		else if (choose1 == 0)
		{
			if (choose == 1) print(items1.GetSize(), &items1);
			else print_list(items2.GetLengh(), &items2);
			cout << endl;
		}

		cout << "1: Continue , 2: Finish" << " ";
		cin >> go;

	}




} */

void sort_menu() 
{
	int c = 1;
	while (c == 1) {
		cout << "Enter length of sequence" << "\n";
		int len;
		cin >> len;
		cout << "Enter elements of  sequence" << "\n";
		double* sequence = new double[len];
		for (int i = 0; i < len; i++)
		{
			cin >> sequence[i];
		}
		DynamicArray<double>* items1 = new DynamicArray<double>(sequence, len);

		clock_t start = 0, end = 0;
		start = clock();
		quicksort(items1,0,len-1, comp1);
		end = clock();
		print(len, items1);
		cout << "sorting time --> " << (double)(end - start) << endl;

		start = 0;
		end = 0;
		start = clock();
		quicksort(items1,0, len-1, comp2);
		end = clock();
		print(len, items1);
		cout << "sorting time reversed --> " << (double)(end - start) << endl;


		cout << "0 for end" << endl;
		cin >> c;
	}
}

