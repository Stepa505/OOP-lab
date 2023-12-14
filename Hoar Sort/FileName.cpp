#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>
#include <random>

void random_file_gen(const char* name, int& lim, int& size) {
	int l_lim = -lim;
	int r_lim = lim;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(l_lim, r_lim);
	std::ofstream file(name);
	for (int i = 0; i < size; i++) {
		int x = dist(gen);
		file << x<< " ";
	}
	file.close();
}

bool sort_check(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

int main() {
	for (int size = 10000; size <= 1000000; size *= 10) {
		for (int range = 10; range <= 100000; range *= 100) {
			std::string name = "Array" + std::to_string(size) + "_in_range" + std::to_string(range) + ".txt";
			random_file_gen(name.c_str(), range, size);
		}
	}
}