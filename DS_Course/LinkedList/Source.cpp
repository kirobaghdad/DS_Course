#include<iostream>
#include "LinkedList.h"
#include"Node.h"
using namespace std;

template <class T>
void arrayToLinkedList(T* arr, int num, LinkedList<T>*& LL)
{
	for (int i = 0; i < num; i++)
		LL->add(arr[i], 1);
}


void printArray(int* arr, int num) {
	cout << "[  ";
	for (int i = 0; i < num; i++)
	{
		if (i > 0)
			cout << ",  ";
		cout << arr[i] << "  ";
	}

	cout << "]" << endl;

}


bool existInArray(int* arr, int num, int key) {
	for (int i = 0; i < num; i++) {
		if (arr[i] == key)
			return true;
	}
	return false;
}

void autoGenerateTestArray(int* arr, int num, bool repeat = 0, int start = 0, int end = -1) {
	if (end == -1)
		end = num * 2;

	int x;
	srand(time(0));
	for (int i = 0; i < num; i++) {
		x = rand() % (end - start + 1) + start;
		if (!repeat) {
			while (existInArray(arr, i, x))
				x = rand() % (end - start + 1);
		}
		arr[i] = x;
	}

}
int main() {
	const int num1 = 4;
	const int num2 = 5;
	const int num3 = 10;

	int arr1[num1];
	int arr2[num2];
	int arr3[num3];


	//Auto-Generate Random arrays
	autoGenerateTestArray(arr1, num1, 0, -5, 8);
	autoGenerateTestArray(arr2, num2, 0, -4, 6);
	autoGenerateTestArray(arr3, num3, 0, -4, 6);


	//First Test Case
	cout << "First Case" << endl;
	LinkedList<int>* LL = new LinkedList<int>;
	LinkedList<int>* LL1 = new LinkedList<int>;
	LinkedList<int>* LL2= new LinkedList<int>;

	arrayToLinkedList(arr1, num1,  LL);
	LL->print();

	LL->alternatingSplit(LL1, LL2);

	LL->print();
	LL1->print();
	LL2->print();
	delete LL;
	delete LL1;
	delete LL2;
	

	//Second Test Case
	cout << "Second Case" << endl;
	LL = new LinkedList<int>;
	LL1 = new LinkedList<int>;
	LL2 = new LinkedList<int>;
	arrayToLinkedList(arr2, num2,  LL);

	LL->print();

	LL->alternatingSplit(LL1, LL2);

	LL->print();
	LL1->print();
	LL2->print();
	delete LL;
	delete LL1;
	delete LL2;
	

	//Third Test Case
	cout << "Third Case" << endl;
	LL = new LinkedList<int>;
	LL1 = new LinkedList<int>;
	LL2 = new LinkedList<int>;
	arrayToLinkedList(arr3, num3,  LL);

	LL->print();

	LL->alternatingSplit(LL1, LL2);

	LL->print();
	LL1->print();
	LL2->print();
	delete LL;
	delete LL1;
	delete LL2;

	return 0;
}