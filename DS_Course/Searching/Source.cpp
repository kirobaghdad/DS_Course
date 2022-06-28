#include <iostream >
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

//This is the recurise binary search function.
//This function returns the indekey of the given key if found in the array or returns -1 if not found.
int recursiveBinarySearch(int arr[], int key, int l, int r)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		// If the element is present at the middle itself
		if (arr[mid] == key)
			return mid;
		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > key)
			return recursiveBinarySearch(arr, key, l, mid - 1);
		// Else the element can only be present
		// in right subarray
		return recursiveBinarySearch(arr, key, mid + 1, r);
	}
	// We reach here when element is not
	// present in array
	return -1;
}


//This is the iterative binary search function.
//This function returns the index of the given key if found in the array or returns -1 if not found.
int iterativeBinarySearch(int* arr, int key, int l, int r) {
	while (l <= r) {
		int m = l + (r - l) / 2;
		// Check if key is present at mid
		if (arr[m] == key)
			return m;
		// If key greater, ignore left half
		if (arr[m] < key)
			l = m + 1;
		// If key is smaller, ignore right half
		else
			r = m - 1;

	}
	// if we reach here, then element was
	// not present
	return -1;

}

int linearSearch(int* arr, int num, int key) {
	int index = -1;
	for (int i = 0; i < num; i++) {
		if (arr[i] == key)
			index = i;
	}

	return index;
}

int probabilitySearch(int*& arr, int num, int key) {
	int index = linearSearch(arr, num, key);

	if (index != -1) {
		if (index != 0) {
			swap(arr[index], arr[index - 1]);
		}
	}

	return index;
}

int sentinelSearch(int* arr,int num, int key) {
	int last = arr[num - 1];

	arr[num - 1] = key;

	int i = 0;
	while (arr[i] != key)
		i++;

	arr[num - 1] = last;

	return (i < num - 1 || arr[num - 1] == key) ? i : -1;
}


int main() {
	system("color 2");
	int* arr{ new int[5] {1, 2, 3, 4, 5} };


	int index = iterativeBinarySearch(arr, 1, 0, 4);

	if (index != -1)
		cout << "The key is found at index " << index << endl;
	else
		cout << "The key is not found in the matrix." << endl;

	delete []arr;

	return 0;
}