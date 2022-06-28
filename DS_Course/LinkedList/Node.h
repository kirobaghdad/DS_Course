#pragma once

template <class T>
class Node {
private:
	T data;
	Node* next;
	float priority;
public:
	Node() {
		next = NULL;
		priority = 0;
	}

	Node(const T& data) {
		this->data = data;
		next = NULL;
		priority = 0;
	}
	//Getters
	T getData()const {
		return data;
	}
	Node* getNext()const {
		return next;
	}

	float getPriority()const {
		return priority;
	}

	//Setters
	void setData(T data) {
		this->data = data;
	}
	void setNext(Node* next) {
		this->next = next;
	}

	void setPriority(float p)const {
		priority = p;
	}

	~Node() {
		delete next;
		next = NULL;
	}
};