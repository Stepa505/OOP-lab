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
		for (k = i, j = len_s - 1; j >= 0 && text[k] == substring[j];) {
			k--;
			j--;
		} 
		if (j < 0) return k + 1;
		if (k >= end) return -1;
	}
	if (i >= end && j < 0) return k + 1;
	else return -1;
}

std::vector<int> BM_search_in_range(std::string text, std::string substring, int* TAB, int start, int end) {
	std::vector<int> Entrance;
	int	entrance = BM_search(text, substring, TAB, start, end);
	if (entrance < 0) return Entrance;
	while (entrance >= 0)
	{
		Entrance.push_back(entrance);
		start = entrance + 1;
		entrance = BM_search(text, substring, TAB, start, end);
	}
	return Entrance;
}

std::vector<int> BM_search_all(std::string text, std::string substring, int* TAB) {
	return BM_search_in_range(text, substring, TAB, 0, text.length());
}

int main() {
	std::string text = "move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", substring = "tor";
	std::cout << "Text: " << text << ", substring: " << substring << std::endl;
	int* TAB = TAB_generate(text, substring);
	int first = BM_search(text, substring, TAB);
	if (first < 0) std::cout << "No entrance";
	else std::cout << "First entrance index: " << first << std::endl;
	int start, end;
	std::cout << "Enter the begining of search: ";
	std::cin >> start;
	std::cout << ". Enter the ending of search: ";
	std::cin >> end;
	std::vector<int> Entrance = BM_search_in_range(text, substring, TAB, start, end);
	if (Entrance.size() == 0) std::cout << "No entrance in range(" << start << ";" << end << ")." << std::endl;
	else{
		std::cout << "Indexes of all entrance in range(" << start << ";" << end << "): ";
		for (int el : Entrance)
			std::cout << el << " ";
		std::cout << "\n";
	}
	Entrance = BM_search_all(text, substring, TAB);
	if (Entrance.size() == 0) std::cout << "No entrance in al text";
	else {
		std::cout << "Indexes of all entrance: ";
		for (int el : Entrance)
			std::cout << el << " ";
		std::cout << "\n";
	}
	delete[] TAB;
}