#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>

void random_file_gen(int& n, int& r) {
	srand(time(0));
	int l = -r;
	std::string name = "Array" + std::to_string(n) + "_in_range" + std::to_string(r) + ".txt";
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

int MAX(std::vector<int>& arr)
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

void BitwiseSort(std::vector<int>& arr, int left_lim, int right_lim, int k)
{
	if (left_lim >= right_lim || k < 0)
		return;
	int i = left_lim, j = right_lim;
	int mask = 1 << k;
	while (i <= j)
	{
		while (i <= j && (arr[i] & mask) == 0)
			i++;
		while (i <= j && (arr[j] & mask) != 0)
			j--;
		if (i < j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	BitwiseSort(arr, left_lim, j, k - 1);
	BitwiseSort(arr, i, right_lim, k - 1);
}

void BitSort(std::vector<int>& arr)
{
	int max = MAX(arr);
	int k = 0;
	while (max)
	{
		max >>= 1;
		k++;
	}
	int i = 0, j = arr.size() - 1;
	while (i <= j)
	{
		while (arr[i] < 0)
			i++;
		while (arr[j] >= 0)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	BitwiseSort(arr, 0, j, k);
	BitwiseSort(arr, i, arr.size() - 1, k);
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

float ATW_bit_sort(const char* name)
{
	float average_time = 0;
	const int count = 3;
	std::vector<int> origin;
	file_in_array(name, origin);
	for (int i = 0; i <= count; i++)
	{
		std::vector<int> copy = origin;
		auto start = std::chrono::high_resolution_clock::now();
		BitSort(copy);
		auto end = std::chrono::high_resolution_clock::now();
		float time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		average_time += time1;
		if (!sort_check(copy))
			std::cout << "Try " << i << " .The array is not sorted" << std::endl;
	}
	average_time /= count;
	return average_time;
}

