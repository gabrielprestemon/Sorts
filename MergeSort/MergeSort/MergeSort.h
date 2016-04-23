#pragma once
#ifndef _MERGESORT_H
#define _MERGESORT_H

#include <vector>

template <class T>
class MergeSort {
public:
	// sort an array using merge sort
	static void Sort(T arr[], unsigned int size);
	// sort a vector using merge sort
	static std::vector<T> Sort(std::vector<T>);
private:
	// put an array into a vector
	static std::vector<T> arrayToVector(T arr[], int size);
	// recursively split and sorted merge an array
	static std::vector<T> split(std::vector<T>);
	// perform a sorted merge on two vectors and return the result
	static std::vector<T> merge(std::vector<T>, std::vector<T>);
};

#endif