#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
	Heap<int> heap(10);

	//add data to the heap
	heap.add(1);
	heap.add(9);
	heap.add(5);
	heap.add(4);
	heap.add(3);
	heap.add(30);
	heap.add(15);
	heap.add(22);
	heap.add(0);
	heap.add(52);

	heap.printHeap();

	heap.buildMaxHeap();


	heap.increaseKey(4, 55);

	heap.printHeap();


	//int x;
	//heap.pop(x);

	////Printing the array to check the haep
	//heap.printArray();
	//cout << endl << x << endl;

	//heap.pop(x);

	////Printing the array to check the haep
	//heap.printArray();
	//cout << endl << x << endl;

	//heap.pop(x);

	////Printing the array to check the haep
	//heap.printArray();
	//cout << endl << x << endl;
}