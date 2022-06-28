#include <iostream>
#include <limits.h>
#include <cstdlib>
#include "../Heap/Heap.h"
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


void bubbleSort0(int*& arr, int num)
{
	int newn;
	do {
		newn = 0;
		for (int i = 1; i < num; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				newn = i;
			}
		}
		num = newn;
	} while (num > 1);
}

//This is enhanced bubble sort
void bubbleSort1(int*& arr, int num) {
	bool swapped;
	do {
		swapped = 0;
		for (int i = 1; i < num; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
	} while (swapped);
}

//If random = 0 then the pivot is the last element and if random = 0 then pivot is random(Randomized-Partition)
int partition(int*& arr, int p, int r, bool random = 0) {
	int l;
	if (random) {
		l = rand() % (r - p + 1) + p;
		swap(arr[r], arr[l]);
	}
	int x = arr[r];
	int i = p - 1;

	for (int j = p; j < r ; j++) {
		if (arr[j] <= x) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}


void quickSort(int*& arr, int p, int r) {
	int q;
	if (p < r) {
		q = partition(arr, p, r, 1);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

//This functions if the given array is sorted in an increasing order
bool sorted(int* arr, int num) {
	for (int i = 1; i < num; i++) {
		if (arr[i - 1] > arr[i])
			return false;
	}
	return true;
}

void selectionSort(int*& arr, int num) {
	
	int j;
	int minj;

	for (int i = 0; i < num - 1; i++) {
		minj = i;
		for (j = i; j < num; j++) {
			if (arr[j] < arr[minj]) {
				minj = j;
			}
		}
		swap(arr[minj], arr[i]);
	}
}

template <class T>
void heapSort(T*& arr, int num) {
	Heap<T> heap(arr, num);
	for (int i = num - 1; i >= 0; i--) {
		heap.pop(arr[i]);
	}
}


//Insertion Sort implemented using two similar methods(both are stable)
void insertionSort(int*& arr, int num, int step = 1) {
	/*int i;
	int key;
	for (int j = 1; j < num; j = j + step)
	{
		key = arr[j];
		// Insert A[j] into the sorted sequence A[1..j-1]
		i = j - 1;
		while (i >= 0 && arr[i] >= key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
	*/
	//Another Correct Method
	int j;
	for (int i = step; i < num; i += step) {
		j = i;
		while (j >= 1 && arr[j - step] >= arr[j]) {
			swap(arr[j - step], arr[j]);
			j -= step;
		}
	}
}



void shellSort(int*& arr, int num) {
	int gaps[] = { 701, 301, 132, 57, 23, 10, 4, 1 };

	for (int i = 0; i < 8; i++) {
		insertionSort(arr, num, gaps[i]);
	}

}


void merge(int*& arr, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j;

	int* left  = new int[n1 + 1];
	int* right = new int[n2 + 1];

	for (i = 0; i < n1; i++)
		left[i] = arr[p + i];

	for (j = 0; j < n2; j++)
		right[j] = arr[q + j + 1];

	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (left[i] > right[j]) {
			arr[k] = right[j];
			j++;
		}
		else {
			arr[k] = left[i];
			i++;
		}
	}

	delete[]left;
	delete[]right;
}

void mergeSort(int*& arr, int p, int r) {
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

// //If random = 0 then the pivot is the last element and if random = 0 then pivot is random(Randomized-Partition)
// int partition(int*& arr, int p, int r, bool random = 0) {
// 	int l;
// 	if (random) {
// 		l = rand() % (r - p + 1) + p;
// 		swap(arr[r], arr[l]);
// 	}
// 	int x = arr[r];
// 	int i = p - 1;

// 	for (int j = p; j < r ; j++) {
// 		if (arr[j] <= x) {
// 			i = i + 1;
// 			swap(arr[i], arr[j]);
// 		}
// 	}
// 	swap(arr[i + 1], arr[r]);
// 	return i + 1;
// }


// void quickSort(int*& arr, int p, int r) {
// 	int q;
// 	if (p < r) {
// 		q = partition(arr, p, r, 1);
// 		quickSort(arr, p, q - 1);
// 		quickSort(arr, q + 1, r);
// 	}
// }

int main() {
	const int num = 10;
	int* arr = new int[num] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	//selectionSort(arr, num);
	//heapSort(arr, num);
	//bubbleSort0(arr, num);
	//mergeSort(arr, 0, num - 1);
	

	quickSort(arr, 0, num - 1);
	printArray(arr, num);
	delete[]arr;
	return 0;
}