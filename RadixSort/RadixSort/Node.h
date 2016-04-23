#pragma once
#ifndef _NODE_H
#define _NODE_H

//#define NULL 0
#include <iostream>

template <class T>
class Node {
public:
	//members
	T data;
	Node* front;
	Node* back;

	//methods
	Node() { data = 0; front = back = NULL; }
	Node(T d) { data = d; front = back = NULL; }
	~Node() {}
};

#endif // !_NODE_H
