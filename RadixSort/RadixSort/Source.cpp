#include <iostream>
#include "RadixSort.h"
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	int size = 100;
	long* list = new long[size];
	for (int i = 0; i < size; i++) {
		list[i] = rand() % 10000;
		cout << list[i] << " ";
	}

	RadixSort<long>::SortAscending(list, size);

	cout << "\n\n\n";

	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}

	RadixSort<long>::SortDescending(list, size);

	cout << "\n\n\n";

	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}


	delete[] list;
	system("pause");
	return 0;
}