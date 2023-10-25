#include <iostream>
#include <math.h>
#include <time.h>

void swap(int& a, int& b) {
	int c;
	c = b;
	b = a;
	a = c;
}

void rand_arr(int* arr, int& size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 100;
	}
}

bool sort_check(int* arr, int& size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}

void shell_sort(int* arr, int& size) {
	int d = size / 2;
	for (; d > 0; d /= 2) {
		for (int i = 0; i < size - d; i++) {
			for (int j = i; j >= 0 && arr[j] > arr[j + d]; j--) {
				swap(arr[j], arr[j + d]);
			}
		}
	}
}


void arr_out(int* a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}

int main() {
	int size;
	std::cout << "Enter the size of array: ";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << std::endl;
	//std::cout << "Enter the elements of array: ";
	//for (int i = 0; i < size; i++) {
	//	std::cin >> arr[i];
	//	std::cout << ", ";
	//}
	rand_arr(arr, size);
	std::cout << "Your array: ";
	arr_out(arr, size);
	std::cout << std::endl;
	shell_sort(arr, size);
	if (sort_check(arr, size)) {
		std::cout << "Sorted array: ";
		arr_out(arr, size);
	}
	else {
		std::cout << "Array is not sorted. ";
		arr_out(arr, size);
	}
}