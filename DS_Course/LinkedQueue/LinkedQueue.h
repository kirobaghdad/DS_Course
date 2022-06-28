#pragma once

#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"


template <class T>
class LinkedQueue {
private:
	Node<T>* front;
	Node<T>* back;
	int count;
public:
	LinkedQueue() {
		front = NULL;
		back = NULL;
		count = 0;
	}

	//Checking if the queue is empty (Returns True if the queue is empty and false othersise
	bool isEmpty()const {
		return (count == 0);
	}
	//Enqueuing new Node
	void enqueue(T data) {

		Node<T>* newNode = new Node<T>;
		newNode->setData(data);
		newNode->setNext(NULL);
		if (isEmpty()) {
			front = newNode;
		}
		else {
			back->setNext(newNode);
		}
		back = newNode;
		count++;
	}

	void priorityEnqueue(T data, float p) {
		Node<T>* ptr = front;
		Node<T>* newNode = new Node<T>;
		newNode->setData(T);
		newNode->setPriority(p);


		while (ptr) {
			if (ptr->getPriority() < p && p > ptr->getNext()->getPriority())
			{
				newNode->setNext(ptr->getNext());
				ptr->setNext(newNode);
				return;
			}
		}
	}

	bool dequeue(T& data) {
		if (isEmpty())
			return false;

		Node<T>* ptr = front;
		data = front->getData();
		front = front->getNext();
		delete ptr;
		ptr = NULL;
		if (count == 1)
			back = NULL;
		count--;
		return true;
	}

	void print()const {
		Node<T>* ptr = front;
			for (int i = 0; i < count + 1; i++) {
				cout << "--------";
			}
			cout << endl;

		while (ptr) {
			cout << ptr->getData() << "  --->  ";
			ptr = ptr->getNext();
		}
		cout << "NULL" << endl;

			for (int i = 0; i < count + 1; i++) {
				cout << "--------";
			}
			cout << endl;

	}

};


