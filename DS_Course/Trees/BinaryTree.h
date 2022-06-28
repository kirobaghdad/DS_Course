#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class BinaryTree {
private:
	Node<T>* root;
	int numOfNodes;
public:
	BinaryTree() {
		root = NULL;
		numOfNodes = 0;
	}

	//Setters
	void setRoot(Node<T>* ptr)
	{
		root = ptr;
	}
	//Getters
	int getNumOfNodes() const {
		return numOfNodes;
	}

	Node<T>* getRoot()const {
		return root;
	}

	bool addNode(T data, Node<T>* p) {

		bool nodeAdded = 0;
		//Adding first Node (root)
		if (isEmpty()) {
			Node<T>* newNode = new Node<T>(data);
			root = newNode;
			numOfNodes++;
			nodeAdded = 1;
		}
		else if (p->getLeft() == NULL || p->getRight() == NULL)
		{
			Node<T>* newNode = new Node<T>(data);
			if(p->getLeft() == NULL)
				p->setLeft(newNode);
			else
				p->setRight(newNode);
			numOfNodes++;
			nodeAdded = 1;
		}
		else
		{
			//Recursively calling addNode on the Left Branch
			nodeAdded = addNode(data, p->getLeft());
			
			//Recursively calling addNode on the Right Branch
			if(!nodeAdded)
			addNode(data, p->getRight());

		}
		return nodeAdded;

	}




	//Pre-Order Traversal Printing Function
	void printPreOrderTraversal(Node<T>* p)const {
		
		cout << p->getData() << "   ";

		if(p->getLeft())
		printPreOrderTraversal(p->getLeft());
		
		if(p->getRight())
		printPreOrderTraversal(p->getRight());
	}
	bool isEmpty()const {
		return (numOfNodes == 0);
	}
};
