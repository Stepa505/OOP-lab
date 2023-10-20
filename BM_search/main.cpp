#include <iostream>
#include <vector>

int* TAB_generate(std::string text, std::string substring) {
	int len_t = text.length(), len_s = substring.length();
	int* TAB = new int[256];
	for (int i = 0; i < len_t; i++) TAB[text[i]] = len_s;
	for (int i = 0; i < len_s; i++) TAB[substring[i]] = len_s - i - 1;
	return TAB;
}

int BM_search(std::string text, std::string substring, int *TAB, int start = 0, int end = -1) {
	if (end == -1) end = text.length();
	int len_s = substring.length();
	int i, j, k = 0;
	for (i = start + len_s - 1, j = len_s - 1; i <= end; i = k + TAB[text[k]]) {
		for (k = i; j = len_s; j >= 0 && text[k] == substring[j];) {
			k--;
			j--;
		} 
		if (j < 0) return k + 1;
		if (k >= end) return -1;
	}
	if (i >= end && j < 0) return k + 1;
	else return -1;
}



int main() {
	std::string text = ":move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", substring = "tor";

}