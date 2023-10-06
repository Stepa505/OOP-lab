#include <iostream>
#include <string.h>

int BM_search(std::string text, std::string substring) {
	int len_t = size(text);
	int len_s = size(substring);
	for (int i = 0; i < size(text);) {
		for (int j = 0; j < len_s; j++) {

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