#include <iostream>
#include "MergeSort.h"
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	const int size = 100;
	int arr[size];

	for (int i = 0; i < size; i++) {
		arr[i] = rand();
		cout << arr[i] << " ";
	}

	cout << "\n\n\n\n";
	MergeSort<int>::Sort(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\n\n\n";
	system("pause");
	return 0;
}