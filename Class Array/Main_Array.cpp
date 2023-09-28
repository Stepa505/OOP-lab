#include <iostream>
#include <stdio.h>
#include "Array.h"

double calculateAvg(Array arr) {
	double avg = 0;
	
	if (arr.size() == 0) {
		return 0;
	}

	for (int i = 0; i < arr.size(); ++i) {
		avg += arr[i];
	}

	avg /= arr.size();
	return avg;

}

int main() {
	Array arr(10, 3);
	std::cout << arr[3] << ' ' << arr[9] << std::endl;

	std::cout << calculateAvg(arr) << "\n";

	arr.print();

	getchar();

	return 0;
}