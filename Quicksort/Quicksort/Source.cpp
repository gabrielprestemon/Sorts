#include <iostream>
#include <ctime>

// Sorts the array in increasing order using a quicksort
// arr is the array to be sorted
// a is the starting index, b is the ending index
template <typename T>
void Quicksort(T arr[], int a, int b);

// Partitions the array for use in quicksort
// arr is the array to be partitioned
// a is the starting index, b is the ending index
template <typename T>
int Partition(T arr[], int a, int b);

// Prints the array
template <typename T>
void PrintArray(T arr[], int size);

// fills the array with random integer values between 0 and MAX_INT
void FillArray_int(int arr[], int size);

// Swaps values of a and b
template <typename T>
void Swap(T *a, T *b);

int main() {
	srand(time(NULL));
	int size = 50;
	int *arr;
	arr = new int[size];

	FillArray_int(arr, size);
	PrintArray(arr, size);
	std::cout << std::endl << std::endl;
	Quicksort(arr, 0, size - 1);
	PrintArray(arr, size);
	std::cout << std::endl << std::endl;

	delete[] arr;
	system("pause");
	return 0;
}

// Sorts the array in increasing order using a quicksort
// arr is the array to be sorted
// a is the starting index (0), b is the ending index (size - 1)
template <typename T>
void Quicksort(T arr[], int a, int b) {
	// if partitioning is possible
	if (a < b) {
		// find an index to partition at
		int partitionIndex = Partition(arr, a, b);
		// perform a quicksort on the partitions
		Quicksort(arr, a, partitionIndex - 1);
		Quicksort(arr, partitionIndex + 1, b);
	}
}

// Partitions the array for use in quicksort
// arr is the array to be partitioned
// a is the starting index (0), b is the ending index (size - 1)
template <typename T>
int Partition(T arr[], int a, int b) {
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

// Swaps values of a and b
template <typename T>
void Swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}