#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>
#include <fstream>

void random_file_gen(int n, int l, int r) {
	srand(time(0));
	std::ofstream out;
	out.open("random_numbers.txt");
	if (out.is_open())
	{
		for (int i = 0; i < n; i++) {
			out << l + rand() % r;
		}
	}
	out.close();
}

void arr_out(std::vector<int> a, int l, int r) {
	std::cout << "[";
	for (int i = l; i <= r; i++)
		std::cout << a[i] << " ";
	std::cout << "]";
}

int max(std::vector<int>& arr)
{
	int max = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

bool sort_check(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}


