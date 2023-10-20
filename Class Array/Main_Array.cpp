#include <iostream>
#include <stdio.h>
#include "Array.h"

int main() {
	Array arr(10, 0);
	std::cin >> arr;
	std::cout << std::endl;
	std::cout << arr;

	return 0;
}