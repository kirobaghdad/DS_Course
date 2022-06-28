#include <iostream>
#include <Windows.h>
#include "LinkedQueue.h"

#include<memory.h>
using namespace std;

int main() {

	LinkedQueue<int>* queue = new LinkedQueue<int>;

	queue->enqueue(4);

	queue->print();
	
	cout << endl;

	int x; 
	queue->dequeue(x);

	queue->print();
	cout << endl << x;
}