#include <iostream>
#include <time.h>
#include <math.h>
#include <algorithm>

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

void arr_out(int* a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}

void mway_found(int** matr, int cities, int st_city, int* min_way, int* max_way, int& min_cost, int& max_cost) {
	int* path = new int[cities - 1];
	for (int i = 0; i < cities; ++i) {
		if (i != st_city) {
			path[i > st_city ? i - 1 : i] = i;
		}
	}

	int min = 10000;
	int max = -10000;
	int* min_cost_path = new int[cities];
	int* max_cost_path = new int[cities];

	do {
		int current_way = 0;
		int current_city = st_city;

		for (int i = 0; i < cities - 1; i++) {
			int next_city = path[i];
			current_way += matr[current_city][next_city];
			current_city = next_city;
		}

		current_way += matr[current_city][st_city];

		if (current_way < min) {
			min = current_way;
			for (int i = 0; i < cities - 1; i++) {
				min_cost_path[i] = path[i];
			}
		}

		if (current_way > max) {
			max = current_way;
			for (int i = 0; i < cities - 1; i++) {
				max_cost_path[i] = path[i];
			}
		}
	} while (std::next_permutation(path, path + cities - 1));

	max_cost = max;
	min_cost = min;

	min_way[0] = st_city + 1;
	for (int i = 0; i < cities - 1; i++) {
		min_way[i + 1] = min_cost_path[i] + 1;
	}

	max_way[0] = st_city + 1;
	for (int i = 0; i < cities - 1; i++) {
		max_way[i + 1] = max_cost_path[i] + 1;
	}

	delete[] min_cost_path;

	delete[] path;
}

int main(){
	int st_city, ** ways_matr, cities, * min_way, *max_way, min_cost, max_cost;
	std::cout << "Eneter the number of cities: ";
	std::cin >> cities;
	std::cout << std::endl;
	std::cout << "Eneter the number of start city: ";
	std::cin >> st_city;
	std::cout << std::endl;
	st_city--;
	ways_matr = new int* [cities];
	for (int i = 0; i < cities; i++) ways_matr[i] = new int[cities];
	Rand_Matr(ways_matr, cities);
	for (int i = 0; i < cities; i++) ways_matr[i][i] = 10000;
	min_way = new int[cities];
	max_way = new int[cities];
	mway_found(ways_matr, cities, st_city, min_way, max_way, min_cost, max_cost);
	for (int i = 0; i < cities; i++) ways_matr[i][i] = 0;
	std::cout << "The matrix of cost: " << std::endl;
	Out_Matr(ways_matr, cities);
	std::cout << "Minimal cost of sale's man way: " << min_cost << std::endl;
	std::cout << "Path of minimal cost: ";
	arr_out(min_way, cities);
	std::cout << std::endl;
	std::cout << "Maximum cost of sale's man way: " << max_cost << std::endl;
	std::cout << "Path of maximum cost: ";
	arr_out(max_way, cities);
	for (int i = 0; i < cities; i++) delete[] ways_matr[i];
	delete[] ways_matr;
	delete[] min_way, max_way;
}