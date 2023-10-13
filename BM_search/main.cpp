#include <iostream>
#include <string.h>
#include "Array.h"

int BM_search(std::string text, std::string substring) {
	int len_t = size(text);
	int len_s = size(substring);
	int* shift1_array = new int[len_t];
	int* shift2_array = new int[len_s];
	shift2_array[len_s] = len_s;
	int n = len_s - 1;
	for (int i = 0; i < len_s - 1; i++) {
		shift2_array[i] = n;
		n--;
	}
	for (int i = 0; i < len_t; i++) {
		for (int j = 0; j < len_s; j++) {
			if (text[i] == substring[j]) {
				shift1_array[i] = shift2_array[j];
			}
		}
	}
		
}

int main() {
	int i;
	std::string text, substring;
	std::cout << "Enter the line with text: ";
	std::cin >> text;
	std::cout << std::endl;
	std::cout << "Enter the searched substring: ";
	std::cin >> substring;
}