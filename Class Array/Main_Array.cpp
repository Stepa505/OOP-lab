#include <iostream>
#include <stdio.h>
#include "Array.h"

int main() {
	Array arr(10, 0);
	std::cout << arr[3] << ' ' << arr[10] << std::endl;
}