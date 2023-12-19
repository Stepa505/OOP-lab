#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

int main() {
	BoolVector vector(true, 16);
	vector.Print();
	std::cout << std::endl;
	BoolVector vector1(vector);
	vector1.Print();
	std::cout << std::endl;
	vector.Set0(1, 5);
	vector.Print();
	std::cout << std::endl;
	vector.Swap(vector1);
	vector.Print();
	std::cout << " ";
	vector1.Print();
	std::cout << std::endl;
	vector1.Inverse();
	vector1.Print();
	std::cout << std::endl;
}