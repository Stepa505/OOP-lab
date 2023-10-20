#include <iostream>
#include <vector>

int* TAB_generate(std::string text, std::string substring) {
	int len_t = text.length(), len_s = substring.length();
	int* TAB = new int[256];
	for (int i = 0; i < len_t; i++) TAB[text[i]] = len_s;
	for (int i = 0; i < len_s; i++) TAB[substring[i]] = len_s - i - 1;
	return TAB;
}

int BM_search() {

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