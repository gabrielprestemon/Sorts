#include "RadixSort.h"
#include <iostream>

template <class T>
void RadixSort<T>::Sort(T arr[], unsigned int size) {
	// create a queue
	Queue<T>* q = new Queue<T>;
	// put the array in a queue
	arrayToQueue(arr, size, q);
	// sort the queue
	Sort(q, 1);
	// put the queue back in the array
	queueToArray(q, arr);
	// release allocated memory
	delete q;
}

template <class T>
void RadixSort<T>::SortAscending(T arr[], unsigned int size) {
	// create a queue
	Queue<T>* q = new Queue<T>;
	// put the array in a queue
	arrayToQueue(arr, size, q);
	// sort the queue
	Sort(q, 1);
	// put the queue back in the array
	queueToArray(q, arr);
	// release allocated memory
	delete q;
}

template <class T>
void RadixSort<T>::SortDescending(T arr[], unsigned int size) {
	// create a queue
	Queue<T>* q = new Queue<T>;
	// put the array in a queue
	arrayToQueue(arr, size, q);
	// sort the queue
	Sort(q, -1);
	// put the queue back in the array
	queueToArray(q, arr);
	// release allocated memory
	delete q;
}

template <class T>
void RadixSort<T>::Sort(Queue<T>* q, int order) {
	// get the number of passes by finding the number of digits of the largest number
	int numPasses = maxDigits(findMax(q));
	// as long as there are passes, do the bucket sort
	for (int pass = 1; pass <= numPasses; pass++) {
		bucketSort(q, pass, order);
	}
}

// put an array in a queue
template <class T>
void RadixSort<T>::arrayToQueue(T arr[], unsigned int size, Queue<T>* q) {
	for (int i = 0; i < size; i++) {
		q->enqueue(arr[i]);
	}
}

// put a queue in an array
template <class T>
void RadixSort<T>::queueToArray(Queue<T>* q, T arr[]) {
	for (int i = 0; i < q->Length(); i++) {
		arr[i] = q->itemAtIndex(i);
	}
}

// find the largest element in the queue
template <class T>
T RadixSort<T>::findMax(Queue<T>* q) {
	// assume the first element is the largests
	T max = q->itemAtIndex(0);
	// if a larger element is found, set the max to that
	for (int i = 0; i < q->Length(); i++) {
		if (q->itemAtIndex(i) > max) {
			max = q->itemAtIndex(i);
		}
	}
	return max;
}

// find the max passes for the sort
template <class T>
int RadixSort<T>::maxDigits(T n) {
	int digits = 0;
	// as long as there are digits, divide by 10 to reduce digits by 1
	while (n > 0) {
		n /= 10;
		// keep track of how many digits
		digits++;
	}
	return digits;
}

// isolate the digit to be used as the sorting key
template <class T>
int RadixSort<T>::isolateDigit(T n, int d) {
	// remove everything left of the digit
	int modFactor = pow(10, d);
	n %= modFactor;
	// while there are digits to the right, move right and truncate
	while (--d > 0) {
		n /= 10;
	}
	return n;
}

// do a bucket sort on the list at the digit of the pass
template <class T>
void RadixSort<T>::bucketSort(Queue<T>* q, int pass, int order) {
	// create buckets
	Queue<T> buckets[10];
	// empty the queue into the buckets
	while (!q->isEmpty()) {
		int bucket = isolateDigit(q->itemAtIndex(0), pass);
		buckets[bucket].enqueue(q->dequeue());
	}
	// append the buckets back onto the main queue
	// positive order sorts ascending
	if (order > 0) {
		for (int i = 0; i < 10; i++) {
			q->append(buckets[i]);
		}
	}
	// negative order sorts descending
	else {
		for (int i = 9; i >= 0; i--) {
			q->append(buckets[i]);
		}
	}
}



// explicit instantiations
template class RadixSort<short>;
template class RadixSort<int>;
template class RadixSort<long>;
template class RadixSort<long long>;