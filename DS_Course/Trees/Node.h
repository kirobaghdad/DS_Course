#pragma once

template<class T>
class Node {
private:
	Node<T>* left;
	Node<T>* right;

	T data;
public:
	Node() {
		left = right = NULL;
	}

	Node(T data)
	{
		left = right = NULL;
		this->data = data;
	}
	//Setters
	void setLeft(Node<T>* l) {
		left = l;
	}
	
	void setRight(Node<T>* r) {
		right = r;
	}

	void setData(T d) {
		data = d;
	}
	//Getters
	Node<T>* getLeft()const {
		return left;
	}
	Node<T>* getRight()const {
		return right;
	}

	T getData()const {
		return data;
	}
};