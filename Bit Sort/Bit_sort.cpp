#include<string>
#include<assert.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>

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

