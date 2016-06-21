#include <iostream>
#include <ctime>
#include "CocktailShaker.h"

// Prints the array
template <typename T>
void PrintArray(T arr[], int size);

// fills the array with random integer values between 0 and MAX_INT
void FillArray_int(int arr[], int size);

int main() {
	srand(time(NULL));
	int size = 50;
	int *arr;
	arr = new int[size];

	FillArray_int(arr, size);
	PrintArray(arr, size);
	std::cout << std::endl << std::endl;
	CocktailShaker<int>::sort(arr,size);
	PrintArray(arr, size);
	std::cout << std::endl << std::endl;

	delete[] arr;
	system("pause");
	return 0;
}

// Prints the array
template <typename T>
void PrintArray(T arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

// fills the array with random integer values between 0 and MAX_INT
void FillArray_int(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand();
	}
}