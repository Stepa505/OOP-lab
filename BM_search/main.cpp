#include <iostream>
#include <string.h>

int BM_search(std::string text, std::string substring) {
	int len_t = size(text);
	int len_s = size(substring);
	int* shift1_array = new int[len_t];
	int* shift2_array = new int[len_s];
	shift2_array[len_s - 1] = len_s;
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
	int i = 0, j = 0, k = 0;
	for (; i < len_t; j++) {
		if (text[i] == substring[j]){
			if (j == len_s) {
				k = i - len_s - 1;
				break;
			}
			else i++;
		}
		else if (text[i] != substring[j]) {
			i += shift2_array[j];
			j = 0;
		}
		if (j == len_s) {
			j = 0;
		}
	}
	return k;
}

int main() {
	std::string text, substring;
	std::cout << "Enter the line with text: ";
	std::cin >> text;
	std::cout << std::endl;
	std::cout << "Enter the searched substring: ";
	std::cin >> substring;
	std::cout << BM_search(text, substring);
}