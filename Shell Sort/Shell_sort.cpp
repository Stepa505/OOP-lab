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

