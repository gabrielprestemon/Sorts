#include "Queue.h"
#include <iostream>
#include <cassert>

//copy constructor
template <class T>
Queue<T>::Queue(Queue<T>& q) {
	this->append(q);
}


//push an item onto the back of the queue
template <class T>
void Queue<T>::enqueue(T d) {
	//create space for the new data
	Node<T>* n = new Node<T>(d);
	//empty case
	if (isEmpty()) {
		this->front = this->back = n;
	}
	//not empty case
	else {
		n->front = this->back;
		this->back->back = n;
		this->back = n;
	}
	//increment count
	cnt++;
}

//pop an item off of the front of the queue
template <class T>
T Queue<T>::dequeue() {
	//ensure there is an item to pop
	assert(!isEmpty());

	T d = this->front->data;
	//last item
	if (cnt == 1) {
		delete this->front;
		this->front = this->back = NULL;
	}
	//more than 1 item remaining
	else {
		this->front = this->front->back;
		delete this->front->front;
		this->front->front = NULL;
	}
	//decrement count
	cnt--;
	//return the information
	return d;
}

//returns the data at the index
template <class T>
T Queue<T>::itemAtIndex(int i) {
	//make sure i is within bounds and the list is not empty
	assert(i >= 0 && i < cnt && !isEmpty());
	Node<T>* n = this->front;
	for (int a = 0; a < i; a++, n = n->back);
	return n->data;
}

//adds a list to the back of this list
template <class T>
void Queue<T>::append(Queue<T>& q) {
	Node<T>* n = q.front;
	while (n != NULL) {
		this->enqueue(n->data);
		n = n->back;
	}
}

//displays the list in cout
template <class T>
void Queue<T>::display() {
	Node<T>* n = this->front;
	while (n != NULL) {
		std::cout << n->data << " ";
		n = n->back;
	}
}

template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>& rh) {
	this->clear();
	this->append(rh);
	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator+=(Queue<T>& rh) {
	this->append(rh);
	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator+(Queue<T>& rh) {
	Queue<T>* Q = new Queue(*this);
	Q->append(rh);
	return *Q;
}


//explicit instantiations
template class Queue<short>;
template class Queue<int>;
template class Queue<long>;
template class Queue<long long>;