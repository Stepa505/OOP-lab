#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

int main() {
	BoolVector vector(1, 14);
	vector.Print();
	puts("");
	BoolVector vec(vector);
	vec.Print();
	puts("");
	BoolVector vec2("10010101001001");
	vec2.Print();
	puts("");
	std::cout << vector.Lenght();
	puts("");
	vector.Inverse();
	vector.Print();
	puts("");
	vector.Inverse();
	vector.Set0(0, 3);
	vector.Print();
	puts("");
	vector.Swap(vec2);
	vector.Print();
	puts("");
	vec2.InverseIndex(13);
	vec2.Print();
	puts("");
	vec2.Set0InRange(2, 11);
	vec2.Print();
}