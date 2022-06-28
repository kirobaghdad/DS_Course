#include <Windows.h>
#include <iostream>
#include <math.h>
#include <ctime>
#include "../LinkedList/LinkedList.h"
using namespace std;


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


int sumOfCubes(int n) {
	if (n == 1)
		return 1;

	return sumOfCubes(n - 1) + pow(n, 3);
}

int arrayMinimum(int* arr, int first, int last) {
	if (first == last)
		return arr[first];
	int m = (last + first) / 2;
	int temp1 = arrayMinimum(arr, first, m);
	int temp2 = arrayMinimum(arr, m + 1, last);

	if (temp1 <= temp2)
		return temp1;
	else return temp2;
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

//If mode = 0 then the function prints the given data in a forward order, otherwise the data gets printed in a reverse order
void printKeyBoardInput(bool mode = 0, char in = '\0') {
	cout << "Please enter a character or S to stop the program!" << endl;
	cin >> in;

	if(in != 's' && in != 'S') {
		if (!mode) {
			system("color 2");
			cout << in << endl << endl;
			printKeyBoardInput(mode);
		}
		else {
			system("color 1");
			printKeyBoardInput(mode);
			cout << in << endl;
		}
	}
}

//If first_OR_last = 0 then the function returns the index of the first occurrence of the key in the array, otherwise it returns its last occurrence
int occurrenceIndex(int* arr, int num, int key, bool first_OR_last = 0, int index = 0) {

	if (!first_OR_last) {
		if (arr[index] == key)
			return index;

		index++;
		if (index < num) {
			return occurrenceIndex(arr, num, key, first_OR_last, index);
		}
		else return -1;

	}
	else 
	{

		if (num == 0) return -1;
		if (arr[num - 1] == key) return num - 1;
		else return occurrenceIndex(arr, num - 1, key, first_OR_last);
	}
}

int main() {

	//LinkedList<int> list1;
	//list1.add(16);
	//list1.add(15);
	//list1.add(14);
	//list1.add(14);
	//list1.add(12);
	//list1.add(10);

	/*if (list1.isSorted(list1.getHead()))
		cout << "The linked list is sorted!";
	else
		cout << "The linked list is not sorted!";*/

	/*//Print in a forward order
	printKeyBoardInput(0);
	cout << endl << endl;
	
	//Print in a reverse order
	printKeyBoardInput(1);*/

	//const int num = 7;
	//int arr[num] = { 1, 2, 5, 4, 5, 6, -50 };
	////cout << sumOfCubes(5);
	////cout << arrayMinimum(arr, 0, num - 1);
	const int num1 = 4;
	const int num2 = 5;
	const int num3 = 10;

	int arr1[num1];
	int arr2[num2];
	int arr3[num3];


	//Auto-Generate Random arrays
	autoGenerateTestArray(arr1, num1, 1, 4, 8); 
	autoGenerateTestArray(arr2, num2, 1, 2, 6); 
	autoGenerateTestArray(arr3, num3, 1, 1, 6); 


	//Printing the arrays
	printArray(arr1, num1);
	printArray(arr3, num3);

	cout << occurrenceIndex(arr1, num1, 5, 1)<<endl;
	cout << occurrenceIndex(arr2, num2, 3, 1)<<endl;
	cout << occurrenceIndex(arr3, num3, 4, 1)<<endl;


	//cout << endl;

	////Getting the minimum of each array
	//cout << arrayMinimum(arr1, 0, num1 - 1) << endl;
	//cout << arrayMinimum(arr2, 0, num2 - 1) << endl;
	//cout << arrayMinimum(arr3, 0, num3 - 1) << endl;

	return 0;
	system("color 2");
}