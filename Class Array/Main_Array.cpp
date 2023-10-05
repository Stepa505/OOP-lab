#include <iostream>
#include <stdio.h>
#include "Array.h"

double calculateAvg(Array arr) {
	
	if (arr.size() == 0) {
		return 0;
	}

	double avg = 0;

	//for (int i = 0; i < arr.size(); ++i) {
	//	avg += arr[i];
	//}
	for (const int& element : arr) {
		avg += element;
	}

	avg /= arr.size();
	return avg;
}

int main() {
	Array arr(10, 0);
	std::cout << arr[3] << ' ' << arr[9] << std::endl;

	std::cout << calculateAvg(arr) << "\n";

	arr.print();

	getchar();

	return 0;
}