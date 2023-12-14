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

void file_in_array(const char* name, std::vector<int>& arr)
{
	std::ifstream fin(name);
	int n;
	if (!fin.good())
		std::cout << "File not found!" << std::endl;
	else
	{
		while (fin >> n)
			arr.push_back(n);
	}
	fin.close();
}

void hoar_sort(std::vector<int>& arr, const int l_lim, const int r_lim) {
	if (l_lim >= r_lim) return;
	int i = l_lim, j = r_lim, avg = arr[(l_lim + r_lim) / 2];
	while (i <= j) {
		while (arr[i] < avg)
			i++;
		while (arr[j] > avg)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	hoar_sort(arr, l_lim, j);
	hoar_sort(arr, i, r_lim);
}



int main() {
	for (int size = 10000; size <= 1000000; size *= 10) {
		for (int range = 10; range <= 100000; range *= 100) {
			std::string name = "Array" + std::to_string(size) + "_in_range" + std::to_string(range) + ".txt";
			random_file_gen(name.c_str(), range, size);
		}
	}
}