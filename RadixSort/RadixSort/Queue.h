#pragma once
#ifndef _Queue_H
#define _Queue_H

#include "Node.h"

template <class T>
class Queue {
public:
	Queue() { cnt = 0; front = back = NULL; }
	Queue(Queue<T>& L);
	~Queue() { clear(); }

	// push an item onto the back of the queue
	void enqueue(T d);
	// pop an item off of the front of the queue
	T dequeue();

	// returns true if the list does not contain any data
	bool isEmpty() { return (cnt == 0); }
	// returns the number of nodes in the list
	unsigned int Length() { return cnt; }
	// returns the number of nodes in the list
	unsigned int Size() { return cnt; }
	// returns the number of nodes in the list
	unsigned int Count() { return cnt; }
	// returns the data at the head of the list
	T Front() { return front->data; }
	// returns the data at the tail of the list
	T Back() { return back->data; }
	// returns the data at the index
	T itemAtIndex(int i);

	// adds a queue to the back of this queue
	void append(Queue<T>& L);
	// clears the nodes from the list
	void clear() { while (!isEmpty()) { dequeue(); } }
	// displays the list in cout
	void display();

	// operators
	Queue<T>& operator=(Queue<T>& rh);
	Queue<T>& operator+=(Queue<T>& rh);
	Queue<T>& operator+(Queue<T>& rh);

	T operator[](int i) { return itemAtIndex(i); }

private:
	unsigned int cnt;
	Node<T>* front;
	Node<T>* back;
};

#endif