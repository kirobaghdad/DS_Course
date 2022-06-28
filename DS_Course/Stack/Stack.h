#pragma once
#include <iostream>
#include "../LinkedList/Node.h"

using namespace std;

template<class T>
class Stack {
private:
	Node<T>* top;
	
	int count;
public:
	Stack() {
		count = 0;
		top = NULL;
	}

	bool isEmpty()const {
		return (count == 0);
	}

	//This function pushs a new node to the stack
	void Push(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		newNode->setNext(top);
		top = newNode;
		count++;
	}

	//This function pops the top node from the stack
	void Pop(T& data) {
		data = top->getData();
		Node<T>* ptr = top;
		top = top->getNext();
		ptr->setNext(NULL);
		delete ptr;
		count--;
	}

	//This function peeks the data from the top of the Stack
	void Peek(T& data)const {
		data = top->getData();
	}

	void Print()const {		
		Node<T>* ptr = top;

		while (ptr) {
			cout << "    | " << ptr->getData() << " |" << endl;
			ptr = ptr->getNext();
			if (ptr)
				cout << "    | " << " " << " |" << endl;
			else cout << "    |" << "___" << "|" << endl;
		}
		cout << endl;
	}
};