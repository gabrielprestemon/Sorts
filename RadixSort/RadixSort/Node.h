#pragma once
#ifndef _NODE_H
#define _NODE_H

#include <iostream>

template <class T>
class Node {
public:
	// members
	T data;
	Node* front;
	Node* back;

	// methods
	Node() { front = back = NULL; }
	Node(T d) { data = d; front = back = NULL; }
	~Node() {}
};

#endif // !_NODE_H
