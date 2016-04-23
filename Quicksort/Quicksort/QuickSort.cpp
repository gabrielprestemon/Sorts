#include "QuickSort.h"
#include <iostream>

// Sorts the array in increasing order using a quicksort
// arr is the array to be sorted
// a is the starting index (0), b is the ending index (size - 1)
template <class T>
static void QuickSort::Sort(T arr[], int a, int b) {
	// if partitioning is possible
	if (a < b) {
		// find an index to partition at
		int partitionIndex = Partition(arr, a, b);
		// perform a quicksort on the partitions
		Sort(arr, a, partitionIndex - 1);
		Sort(arr, partitionIndex + 1, b);
	}
}

// Partitions the array for use in quicksort
// arr is the array to be partitioned
// a is the starting index (0), b is the ending index (size - 1)
template <class T>
static int QuickSort::Partition(T arr[], int a, int b) {
	// find a pivot (pick the last index)
	T pivot = arr[b];
	// swap position
	int swapPos = a;
	// loop through the array
	for (int i = a; i < b; i++) {
		// if the element is less than the pivot, swap and increment swap index
		if (arr[i] <= pivot) {
			Swap(&arr[i], &arr[swapPos++]);
		}
	}
	Swap(&arr[b], &arr[swapPos]);
	// return the swap position, new location to partition
	return swapPos;
}
