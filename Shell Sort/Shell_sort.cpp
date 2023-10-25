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


