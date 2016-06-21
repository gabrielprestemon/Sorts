#pragma once
#ifndef _COCKTAILSHAKER_H
#define _COCKTAILSHAKER_H

template <class T>
class CocktailShaker {
public:
	static void sort(T arr[], int size) {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 0; i < size - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					swap(&arr[i], &arr[i + 1]);
					sorted = false;
				}
			}
			if (sorted) {
				break;
			}
			sorted = true;
			for (int i = size - 1; i > 0; i--) {
				if (arr[i] < arr[i - 1]) {
					swap(&arr[i], &arr[i - 1]);
					sorted = false;
				}
			}
		}
	}

	// Swaps values of a and b
	static void swap(T *a, T *b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};

#endif