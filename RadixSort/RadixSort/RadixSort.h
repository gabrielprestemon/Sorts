#ifndef _RADIXSORT_H
#define _RADIXSORT_H

#include "Queue.h"

template <class T>
class RadixSort {
public:
	//sorts the numbers in ascending order
	static void Sort(T arr[], unsigned int size);
	//sorts the numbers in ascending order
	static void SortAscending(T arr[], unsigned int size);
	//sorts the numbers in descending order
	static void SortDescending(T arr[], unsigned int size);

private:
	//positive order = ascedning, negative order = descending
	static void Sort(Queue<T>* q, int order);
	//put an array in a queue
	static void arrayToQueue(T arr[], unsigned int size, Queue<T>* q);
	//put a queue in an array
	static void queueToArray(Queue<T>* q, T arr[]);
	//find the largest element in the queue
	static T findMax(Queue<T>* q);
	//find the max passes for the sort
	static int maxDigits(T d);
	//isolate the digit to be used as the sorting key
	static int isolateDigit(T n, int d);
	//do a bucket sort on the list at the digit of the pass
	static void bucketSort(Queue<T>* q, int pass, int order);
};

#endif