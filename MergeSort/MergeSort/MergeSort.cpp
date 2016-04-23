#include "MergeSort.h"
#include <iostream>

// sort an array using merge sort
template <class T>
void MergeSort<T>::Sort(T arr[], unsigned int size) {
	// put the array into a vector and sort it
	std::vector<T> vec = split(arrayToVector(arr, size));
	// put the vector back into the array
	for (int i = 0; i < size; i++) {
		arr[i] = vec[i];
	}
}

// sort a vector using merge sort
template <class T>
std::vector<T> MergeSort<T>::Sort(std::vector<T> vec) {
	return split(vec);
}

// put an array into a vector
template <class T>
std::vector<T> MergeSort<T>::arrayToVector(T arr[], int size) {
	std::vector<T> vec;
	for (int i = 0; i < size; i++) {
		vec.push_back(arr[i]);
	}
	return vec;
}

// perform a sorted merge on two vectors and return the result
template <class T>
std::vector<T> MergeSort<T>::merge(std::vector<T> L, std::vector<T> R) {
	std::vector<T> out;

	// while both sides have elements within them
	while (L.size() && R.size()) {
		// if the left side is smaller, append to output list
		if (L[0] <= R[0]) {
			out.push_back(L[0]);
			L.erase(L.begin());
		}
		// else the right side must be smaller, append to output
		else {
			out.push_back(R[0]);
			R.erase(R.begin());
		}
	}

	// if there are elements remaining in the left list append them
	for (int i = 0; i < L.size(); i++) {
		out.push_back(L[i]);
	}
	// if there are elements remaining in the right list append them
	for (int i = 0; i < R.size(); i++) {
		out.push_back(R[i]);
	}

	// return the merged list
	return out;
}

// recursively split and sorted merge an array
template <class T>
std::vector<T> MergeSort<T>::split(std::vector<T> v) {
	// if the list is less than 2 elements then it is already sorted
	if (v.size() < 2) {
		return v;
	}

	// create left and right vectors
	std::vector<T> L;
	std::vector<T> R;

	// split the array into 2 vectors
	for (int i = 0; i < v.size(); i++) {
		// odd indexes go left
		if (i % 2) {
			L.push_back(v[i]);
		}
		// even indexes go right
		else {
			R.push_back(v[i]);
		}
	}

	// sort each size recursively
	L = split(L);
	R = split(R);

	// return the merged sides
	return merge(L, R);
}



// explicit instantiations
template class MergeSort<int>;
template class MergeSort<char>;
template class MergeSort<long>;
template class MergeSort<float>;
template class MergeSort<double>;