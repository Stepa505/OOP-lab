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
