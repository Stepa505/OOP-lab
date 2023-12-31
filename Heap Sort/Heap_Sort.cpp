#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//int max3(int& a, int& b, int& c) {
//	int max;
//	if (a >= b && a >= c) max = a;
//	else if (b >= a && b >= c) max = b;
//	else if (c >= b && c >= a) max = c;
//	return max;
//}

void rand_arr(int* arr, int& size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 100;
	}
}

void swap(int& a, int& b) {
	int c;
	c = b;
	b = a;
	a = c;
}

void arr_out(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		std::cout << a[i] << " ,";
	}
	std::cout << a[n - 1] << ".";
}

void Heap_Form(int* arr, int root, int bottom) {
	int max_child, done = 0;
	while (root * 2 <= bottom && done == 0) {
		if (root * 2 == bottom) 
			max_child = root * 2;
		else if (arr[root * 2] > arr[root * 2 + 1]) 
			max_child = root * 2;
		else 
			max_child = root * 2 + 1;
		if (arr[root] < arr[max_child]) {
			swap(arr[root], arr[max_child]);
			root = max_child;
		}
		else 
			done = 1;
	}
	/*arr_out(arr, size);*/
}

void Heap_Sort(int* arr, int size) {
	for (int i = size / 2; i >= 0; i--) 
		Heap_Form(arr, i, size - 1);
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		Heap_Form(arr, 0, i - 1);
	}
}

bool sort_check(int* arr, int& size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}

int main() {
	int* arr, size, choice;
	std::cout << "Enter size of the array: ";
	std::cin >> size;
	std::cout << std::endl;
	arr = new int[size];
	std::cout << "If you want to fell array with your numbers - type 1, if you want to fell array with random numbers - type 0: ";
	std::cin >> choice;
	std::cout << std::endl;
	if (choice == 0)
		rand_arr(arr, size);
	else if (choice == 1) {
		std::cout << "Enter array numbers: [ ";
		for (int i = 0; i < size; i++) {
			std::cin >> arr[i];
			if (i < size - 1)
				std::cout << ", ";
			else
				std::cout << " ].";
		}
	}
	std::cout << std::endl;
	arr_out(arr, size);
	std::cout << std::endl;
	Heap_Form(arr, 0, size - 1);
	Heap_Sort(arr, size);
	arr_out(arr, size);
	if (sort_check(arr, size)) {
		std::cout << "Array is sorted: ";
		arr_out(arr, size);
	}
	else
		std::cout << "Array is not sorted.";

}