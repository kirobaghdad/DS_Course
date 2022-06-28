#pragma once
#include <iostream>
#include <Windows.h>
#include"Node.h"
using namespace std;

template<class T>
class LinkedList {
private:
	Node<T>* head;
	int count;

public:
	LinkedList() {
		head = NULL;
		count = 0;
	}

	//Setters
	void setHead(Node<T>* ptr) {
		head = ptr;
	}

	//Getters
	Node<T>* getHead()const {
		return head;
	}
	int getCount()const {
		return count;
	}


	void addFront(T data) {
		Node<T>* newNode = new Node<T>;
		
		newNode->setData(data);
		if (!count) {
			newNode->setNext(NULL);
			head = newNode;
		}
		else {
			newNode->setNext(head);
			head = newNode;
		}
		count++;
	}

	//If mode = 0 then data is added to the front, otherwise it is added to the back
	void add(T data, bool mode = 0) {
		Node<T>* newNode = new Node<T>;
		Node<T>* ptr = head;
		newNode->setData(data);

		if (!count) {
			newNode->setNext(NULL);
			head = newNode;
		}

		else if (mode) {
			while (ptr && ptr->getNext()) {
				ptr = ptr->getNext();
			}

			ptr->setNext(newNode);
			newNode->setNext(NULL);
			
		}
		else {
			newNode->setNext(head);
			head = newNode;
		}

		count++;

	}



	bool isSorted(Node<T>* ptr) {
		if (ptr && ptr->getNext()) 
		{
			if (ptr->getNext()->getData() < ptr->getData())
			{
				return false;
			}
			
			isSorted(ptr->getNext());
		}
		else
			return true;
	}

	void alternatingSplit(LinkedList<T>*& L1, LinkedList<T>*& L2) {
		int count = 0;
		Node<T>* orgPtr = head;
		Node<T>* L1_Ptr = NULL;
		Node<T>* L2_Ptr = NULL;

		while (orgPtr) {
			orgPtr = orgPtr->getNext();
			if (count % 2 == 0) {
				popNode(L1_Ptr);
				L1->addNode(L1_Ptr);
				L1_Ptr = L1_Ptr->getNext();
			}
			else {
				popNode(L2_Ptr);
				L2->addNode(L2_Ptr);
				L2_Ptr = L2_Ptr->getNext();
			}
			count++;
		}
	}


	void print()const {
		Node<T>* ptr = head;

		int count = 0;
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);

		int P = 1;
		while (ptr) {
			if(count % 2 == 0)
				SetConsoleTextAttribute(console_color, P++);
			else
				SetConsoleTextAttribute(console_color, P--);


			cout << ptr->getData() << "  -->>  ";
			ptr = ptr->getNext();
			count++;


		}

		SetConsoleTextAttribute(console_color, P++);
		cout << "NULL" << endl<<endl;
		SetConsoleTextAttribute(console_color, 15);
	}

	bool deleteNode(T data) {
		Node<T>* ptr = head;
		Node<T>* prev = NULL;
		while (ptr) {
			if (ptr->getData() == data) {
				if (ptr == head) {
					head = ptr->getNext();
					ptr->setNext(NULL);
					delete ptr;
					ptr = head;
				}
				else {
					prev->setNext(ptr->getNext());
					ptr->setNext(NULL);
					delete ptr;
				}
				count--;
				return true;
			}
			prev = ptr;
			ptr = ptr->getNext();
		}
		return false;
	}


	void addNode(Node<T>*& newPtr) {
		if (!count)
		{
			head = newPtr;
			head->setNext(NULL);
		}
		else {
			Node<T>* ptr = head;
			while (ptr && ptr->getNext()) {
				ptr = ptr->getNext();
			}

			ptr->setNext(newPtr);
			newPtr->setNext(NULL);
		}
		count++;
	}

	void popNode(Node<T>*& ptr) {
		ptr = head;
		head = head->getNext();
	}


	void deleteNegatives() {
		//Recursive Solution
		/*if (ptr->getData() < 0) {
			Node<T>* temp = ptr;
			ptr = ptr->getNext();
			deleteNode(temp->getData());
		}

		if (ptr->getNext()) {
			deleteNegatives(ptr, ptr->getNext());
		}*/


		//Iterative Solution
		Node<T>* prev = NULL;
		Node<T>* ptr = head;
		while (ptr) {
			if (ptr->getData() < 0) {
				Node<T>* temp = ptr;
				if (ptr != head)
					ptr = prev;
				else
					ptr = ptr->getNext();
				deleteNode(temp->getData());
			}
			prev = ptr;
			ptr = ptr->getNext();
		}
	}


	void duplicate() {
		Node<T>* ptr = head;
		int oldCount = count;

		for (int i = 0; i < oldCount; i++) {
			add(ptr->getData(), 1);
			ptr = ptr->getNext();
		}
	}

};