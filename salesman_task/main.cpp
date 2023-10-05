#include <iostream>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <cstdlib>

void Rand_Matr(int** matr, int m) {
	srand(time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = 1 + rand() % 20;

}

void Out_Matr(int** matr, int m)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) printf("%4d", matr[i][j]);
		printf("\n");
	}
}

void Swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}

void arr_out(int* a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}

int mway_found(int** matr, int cities, int st_city, int* min_way) {
	int* path = new int[cities - 1];
	for (int i = 0; i < cities; ++i) {
		if (i != st_city) {
			path[i > st_city ? i - 1 : i] = i;
		}
	}

	int min_cost = 10000;
	int* min_cost_path = new int[cities];

	do {
		int current_way = 0;
		int current_city = st_city;

		for (int i = 0; i < cities - 1; ++i) {
			int next_city = path[i];
			current_way += matr[current_city][next_city];
			current_city = next_city;
		}

		current_way += matr[current_city][st_city]; // Вернуться в начальный город

		if (current_way < min_cost) {
			min_cost = current_way;
			for (int i = 0; i < cities - 1; ++i) {
				min_cost_path[i] = path[i];
			}

		}
	}

	while (std::next_permutation(cities, cities + cities - 1));

	min_way[0] = st_city;
	for (int i = 0; i < cities - 1; ++i) {
		path[i + 1] = min_cost_path[i];
	}

	delete[] min_cost_path;

	delete[] path;

	return min_cost;
}

int main(){
	int st_city, ** ways_matr, cities, *min_way;
	std::cout << "Eneter the number of cities: ";
	std::cin >> cities;
	std::cout << std::endl;
	std::cout << "Eneter the number of start city: ";
	std::cin >> st_city;
	std::cout << std::endl;
	ways_matr = new int* [cities];
	for (int i = 0; i < cities; i++) ways_matr[i] = new int[cities];
	Rand_Matr(ways_matr, cities);
	for (int i = 0; i < cities; i++) ways_matr[i][i] = 10000;
	min_way = new int[cities];
	int answer = mway_found(ways_matr, cities, st_city, min_way);
	for (int i = 0; i < cities; i++) ways_matr[i][i] = 0;
	std::cout << "The matrix of cost: " << std::endl;
	Out_Matr(ways_matr, cities);
	std::cout << "Minimal cost of sale's man way: " << answer << std::endl;
	std::cout << "Path of minimal cost: ";
	arr_out(min_way, cities);
	for (int i = 0; i < cities; i++) delete[] ways_matr[i];
	delete[] ways_matr;
}