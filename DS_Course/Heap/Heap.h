#pragma once
#include <iostream>
using namespace std;

template <class T>
class Heap {
private:
	const int MAX_COUNT;
	int currentCount;
	T* arr;

public:
	Heap(T*& arrIn, int maxCount):MAX_COUNT(maxCount > 0 ? maxCount : -1) {
		arr = new T[MAX_COUNT];
		for (int i = maxCount - 1; i >= 0; i--) {
			this->add(arrIn[i]);
		}
	}

	Heap(int maxCount): MAX_COUNT(maxCount > 0 ? maxCount : -1)
	{
		if (maxCount > 0)
		{
			arr = new T[MAX_COUNT];
		}
		currentCount = 0;
		arr = NULL;
	}



	//Index Getters
	int getLeftChildIndex(int parent)const {
		int rightChildIndex = parent * 2 + 1;
		return (rightChildIndex < currentCount ? rightChildIndex : -1);
	}

	int getRightChildIndex(int parent)const {

		int leftChildIndex = parent * 2 + 2;
		return (leftChildIndex < currentCount ? leftChildIndex : -1);
	}

	int getParentIndex(int child)const {
		return (child - 1) / 2;
	}


	///////////
	T getLeftChild(int parent)const {
		return arr[getLeftChildIndex(parent)];
	}
	
	T getRightChild(int parent)const {
		return arr[getRightChildIndex(parent)];
	}

	T getParent(int child)const {
		return arr[getParentIndex(child)];
	}



	bool hasParent(int index)const {
		return (getParent(index) != -1 ? 1 : 0);
	}

	bool hasLeftChild(int index)const {
		return (getLeftChildIndex(index) != -1 ? 1 : 0);
	}

	bool hasRightChild(int index)const {
		return (getRightChildIndex(index) != -1 ? 1 : 0);
	}


	bool isEmpty()const {
		return (currentCount == 0);
	}


	void maxHeapifyUp(int parent = 0) {

		if (getLeftChildIndex(parent) == -1)
			return;
		else maxHeapifyUp(getLeftChildIndex(parent));


		maxHeapifyUp(getRightChildIndex(parent));
		if (arr[parent] < getLeftChild(parent))
			swap(arr[parent], arr[getLeftChildIndex(parent)]);

		if (getRightChildIndex(parent) != -1 && arr[parent] < getRightChild(parent))
			swap(arr[parent], arr[getRightChildIndex(parent)]);


	}


	void maxHeapifyUpIterative() {
		int index = currentCount - 1;
		while (hasParent(index) && getParent(index) < arr[index]) {
			swap(arr[getParentIndex(index)], arr[index]);
			index = getParentIndex(index);
		}
	}

	void minHeapifyUpIterative() {
		int index = currentCount - 1;
		while (hasParent(index) && getParent(index) > arr[index]) {
			swap(arr[getParentIndex(index)], arr[index]);
			index = getParentIndex(index);
		}
	}

	void maxHeapifyDown(int parent = 0) {
		/*if (hasLeftChild(parent) && arr[parent] < getLeftChild(parent))
			swap(arr[parent], arr[getLeftChildIndex(parent)]);

		if (hasRightChild(parent) && arr[parent] < getRightChild(parent))
			swap(arr[parent], arr[getRightChildIndex(parent)]);
		*/
		if (hasLeftChild(parent)) {
			if (hasRightChild(parent)) {
				int maxIndex = arr[getLeftChildIndex(parent)] > arr[getRightChildIndex(parent)] ? getLeftChildIndex(parent) : getRightChildIndex(parent);

				if (arr[maxIndex] > arr[parent])
					swap(arr[maxIndex], arr[parent]);
				else return;
			}
			else {
				if (arr[getLeftChildIndex(parent)] > arr[parent]) {
					swap(arr[getLeftChildIndex(parent)], arr[parent]);
				}
				else
					return;
			}
		}
		else
			return;

		if (getLeftChildIndex(parent) == -1)
			return;
		else maxHeapifyDown(getLeftChildIndex(parent));
		
		if (getRightChildIndex(parent) == -1)
			return;
		else maxHeapifyDown(getRightChildIndex(parent));


	}

	void maxHeapifyDownIterative(int index = 0) {
		int largestChildIndex;
		while (hasLeftChild(index)) {
			largestChildIndex = getLeftChildIndex(index);

			if (hasRightChild(index) && arr[getRightChildIndex(index)] > arr[largestChildIndex]) {
				largestChildIndex = getRightChildIndex(index);
			}
			

			if (arr[index] > arr[largestChildIndex])
				break;
			else
				swap(arr[largestChildIndex], arr[index]);

			index = largestChildIndex;
		}

	}


	void minHeapifyDownIterative(int index = 0) {
		int largestChildIndex;
		while (hasLeftChild(index)) {
			largestChildIndex = getLeftChildIndex(index);

			if (hasRightChild(index) && arr[getRightChildIndex(index)] < arr[largestChildIndex]) {
				largestChildIndex = getRightChildIndex(index);
			}


			if (arr[index] < arr[largestChildIndex])
				break;
			else
				swap(arr[largestChildIndex], arr[index]);

			index = largestChildIndex;
		}

	}

	//This functions performs both addMaxHeapify(if max_or_min is ZERO) and addMinHeapify(if max_or_min is ONE)
	bool add(T data, bool max_or_min = 0) {
		if (currentCount >= MAX_COUNT)
			return false;

		arr[currentCount++] = data;
		if (!max_or_min)
			maxHeapifyUpIterative();
		else
			minHeapifyUpIterative();
		return true;
	}

	bool addWithOutHeapifying(T data) {
		if (currentCount >= MAX_COUNT)
			return false;

		arr[currentCount++] = data;
		return true;
	}

	bool peek(T& data)const {
		if (isEmpty())
			return false;
		data = arr[0];
		return true;
	}


	//This function returns the maximum of the heap if max_or_min is ZERO and the minimum of the heap if max_or_min is ONE
	bool pop(T& data, bool max_or_min = 0) {
		if (isEmpty()) {
			return false;
		}
		
		data = arr[0];

		arr[0] = arr[currentCount - 1];
		currentCount--;

		if (!max_or_min)
			maxHeapifyDown();
		else
			minHeapifyDownIterative();
		return true;
	}

	void buildMaxHeap() {
		for (int i = currentCount / 2 - 1; i >= 0; i--)
			maxHeapifyDown(i);
	}


	void printHeap() {
		cout << "[  ";
		for (int i = 0; i < currentCount; i++)
		{
			if (i > 0)
				cout << ",  ";
			cout << arr[i] << "  ";
		}

		cout << "]" << endl;
	}


	void increaseKey(int index, T key) {
		if (key < arr[index]) {
			cout << "The new key is smaller than the current key";
			return;
		}

		arr[index] = key;


		maxHeapifyUp();

		//Alternative Method
		/*while (index > 0 && arr[getParentIndex(index)] < arr[index])
		{
			swap(arr[index], arr[getParentIndex(index)]);
			index = getParentIndex(index);
		}*/
	}

	~Heap() {
		delete[]arr;
		arr = NULL;
	}
};