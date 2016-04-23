#pragma once
#ifndef _QUICKSORT_H
#define _QUICKSORT_H

template<class T>
class QuickSort {
public:
	// Sorts the array in increasing order using a quicksort
	// arr is the array to be sorted
	// a is the starting index, b is the ending index
	static void Sort(T arr[], int a, int b);

private:
	// Partitions the array for use in quicksort
	// arr is the array to be partitioned
	// a is the starting index, b is the ending index
	static int Partition(T arr[], int a, int b);

	// Swaps values of a and b
	static void Swap(T *a, T *b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};

#endif