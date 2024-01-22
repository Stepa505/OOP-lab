#include <iostream>
#include <string.h>
#include <time.h>
#include<chrono>

void RandomMatrix(int** matr, int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = 1 + rand() % 20;
}
void OutputMatrix(int** matr, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << matr[i][j] << " ";
		std::cout << std::endl;
	}
}
void OutputMas(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
		std::cout << *p << " ";
}
int AddMas(int* a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		k += a[i];
	return k;
}
int WeightWay(int* way, int** matr, int n)
{
	int min = 0;
	int i;
	for (i = 0; i < n - 1; i++)
		min += matr[way[i] - 1][way[i + 1] - 1];
	min += matr[way[i] - 1][way[0] - 1];
	return min;
}
void CopyMas(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++) b[i] = a[i];
}
void Swap(int& a, int& b)
{
	int x;
	x = a; a = b; b = x;
}
void SearchOptimalWeight(int* way, int** matr, int number_city, int* min_way, int* max_way, int starting_city)
{
	int first_way = 1;
	for (int k = 1; ; k++)
	{
		if (first_way == 1)//создаем первый путь
		{
			for (int i = 0, n = 1; i < number_city + 1; )
			{
				if (i == 0 || i == number_city)
					way[i++] = starting_city;
				else if (n != starting_city)
					way[i++] = n++;
				else if (++n == starting_city)//если n == стартовому городу, то нужно увеличить n и записать его, после этого увеличить n
					way[i++] = n++;
				first_way -= 1;
			}
			/*OutputMas(way, number_city + 1);
			std::cout << " weight " << WeightWay(way, matr, number_city) << std::endl;*/
			CopyMas(way, min_way, number_city + 1);//предполагаем, то что наш начальный путь может быть минимальным
			CopyMas(way, max_way, number_city + 1);//we assume that the initial path is the maximum
		}
		int max_i = -1, max_j;
		for (int i = 1; i < number_city - 1; i++)
		{
			if (way[i] < way[i + 1])
				max_i = i;
		}
		if (max_i == -1)
			break;
		for (int j = max_i + 1; j <= number_city - 1; j++)
		{
			if (way[j] > way[max_i])
				max_j = j;
		}
		Swap(way[max_i], way[max_j]);
		int j = number_city - 1;
		int i = max_i + 1;
		while (i < j)
		{
			Swap(way[i], way[j]);
			i++;
			j--;
		}
		if (WeightWay(way, matr, number_city) < WeightWay(min_way, matr, number_city))
			CopyMas(way, min_way, number_city + 1);
		if (WeightWay(way, matr, number_city) > WeightWay(max_way, matr, number_city))
			CopyMas(way, max_way, number_city + 1);
		//OutputMas(way, number_city + 1);
		//std::cout << " weight " << WeightWay(way, matr, number_city) << std::endl;
	}
}
int MinimalElement(int** matr, int number_city, int& i_min, int& j_min)
{
	int min_element = INT_MAX;
	for (int i = 0; i < number_city; i++)
	{
		for (int j = 0; j < number_city; j++)
		{
			if (matr[i][j] < min_element && matr[i][j] != 0)
			{
				min_element = matr[i][j];
				i_min = i;
				j_min = j;
			}
		}
	}
	return min_element;
}
void TransformMatrix(int** matr, int i_min, int j_min, int number_city)
{
	for (int i = 0, j = 0; i < number_city && j < number_city; i++, j++)
	{
		matr[i_min][j] = 0;
		matr[i][j_min] = 0;
	}
}
bool SearchCycle(int* way, int number_city, int i, int j)
{
	//we are looking for matching elements and if they are linked to the same element that this arc forms a cycle
	int ki = -2, kj = -1, k = 0, ki2;
	for (int i_way = 0, j_way = 1; i_way < (number_city * 2) - 1 && j_way < number_city * 2; i_way += 2, j_way += 2)
	{
		if (way[i_way] == way[j])
			ki = way[i_way + 1];
		if (way[j_way] == way[i])
			kj = way[j_way - 1];
		if (way[i_way] == way[j] && way[j_way] == way[i])//обратный путь
			k++;
	}
	ki2 = ki;
	for (int b = 0; b < number_city * 2; b++)//restoring the return path. if ki2 is equal to way[i] then adding this arc will result in a loop
	{
		for (int a = 0; a < (number_city * 2) - 1; a += 2)
		{
			if (way[a] == ki2 && a != i)
			{
				ki2 = way[a + 1];
				break;
			}
		}
	}
	if (ki == kj || k != 0 || ki2 == way[i])
		return true;
	else
		return false;
}
int Heuristics(int* way, int** matr_way_weight, int number_city, int& i_min, int& j_min, int min_element, int weight, int* heuristics_min_way, int starting_city)
{
	for (int i = 0, j = 1, k = 1;;)//подсчет веса
	{
		min_element = MinimalElement(matr_way_weight, number_city, i_min, j_min);
		if (min_element == INT_MAX)
			break;
		way[i] = i_min + 1;
		way[j] = j_min + 1;
		if (k != number_city)
		{
			if (SearchCycle(way, number_city, i, j) == true)
			{
				way[i] = 0;
				way[j] = 0;
				matr_way_weight[i_min][j_min] = 0;
			}
			else
			{
				weight += min_element;
				TransformMatrix(matr_way_weight, i_min, j_min, number_city);
				i += 2;
				j += 2;
				k++;
			}
		}
		else
		{
			weight += min_element;
			TransformMatrix(matr_way_weight, i_min, j_min, number_city);
			i += 2;
			j += 2;
		}
	}
	int k = 0, i;
	for (int j = 0; j < number_city + 1; j++)
	{
		for (i = 0; way[i] != starting_city; i += 2);

		heuristics_min_way[k++] = way[i];
		starting_city = way[i + 1];
	}
	return weight;
}
void CopyMatrix(int** matr, int** copy_matr, int number_city)
{
	for (int i = 0; i < number_city; i++)
	{
		for (int j = 0; j < number_city; j++)
			copy_matr[i][j] = matr[i][j];
	}
}

int main()
{
	srand(time(0));
	int** matr_way_weight, number_city, starting_city, * way, * min_way, * max_way, min_weight_exact, max_way_exact;
	int min_element = 0, heuristics_weight = 0, ix = 0, jx = 0, * way_heuristics, ** heuristics_matr_way_weight, * heuristics_min_way;
	int& i_min = ix, & j_min = jx;
	std::cout << "enter the number of cities: ";
	std::cin >> number_city;
	std::cout << std::endl << "enter the number of starting city: ";
	std::cin >> starting_city;
	//создаем матрицу стоимостей маршрутов
	matr_way_weight = new int* [number_city];//выделяем память под массив указателей
	for (int i = 0; i < number_city; i++)//выделяем память под каждую "строку"
		matr_way_weight[i] = new int[number_city];
	RandomMatrix(matr_way_weight, number_city);
	for (int i = 0; i < number_city; i++)//зануляем диагонали матрицы
		matr_way_weight[i][i] = 0;
	OutputMatrix(matr_way_weight, number_city);

	//create matrix weight for Heuristics(copy matrix for exact algorithm)
	heuristics_matr_way_weight = new int* [number_city];//выделяем память под массив указателей
	for (int i = 0; i < number_city; i++)//выделяем память под каждую "строку"
		heuristics_matr_way_weight[i] = new int[number_city];
	CopyMatrix(matr_way_weight, heuristics_matr_way_weight, number_city);

	way = new int[number_city + 1];//создаем массив, в котором будут храниться пути
	min_way = new int[number_city + 1];
	max_way = new int[number_city + 1];

	auto start = std::chrono::high_resolution_clock::now();
	SearchOptimalWeight(way, matr_way_weight, number_city, min_way, max_way, starting_city);
	auto end = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	min_weight_exact = WeightWay(min_way, matr_way_weight, number_city);
	max_way_exact = WeightWay(max_way, matr_way_weight, number_city);

	std::cout << "The exact algorithm: minimum weight path ";
	OutputMas(min_way, number_city + 1);
	std::cout << "his minimal weight " << min_weight_exact << std::endl;
	std::cout << "The exact algorithm: maximal weight path ";
	OutputMas(max_way, number_city + 1);
	std::cout << "his maximal weight " << max_way_exact << std::endl;
	std::cout << "Working time of the exact algorithm " << time << " nanoseconds" << std::endl;

	//heuristics
	heuristics_min_way = new int[number_city + 1];
	way_heuristics = new int[number_city * 2];//make an array, when we keep way
	for (int i = 0; i < number_city * 2; i++)//let 's take an array 0
		way_heuristics[i] = 0;
	OutputMatrix(heuristics_matr_way_weight, number_city);
	start = std::chrono::high_resolution_clock::now();
	heuristics_weight = Heuristics(way_heuristics, heuristics_matr_way_weight, number_city, i_min, j_min, min_element, heuristics_weight, heuristics_min_way, starting_city);
	end = std::chrono::high_resolution_clock::now();
	float time_h = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	std::cout << "Heuristics: ";
	OutputMas(heuristics_min_way, number_city + 1);
	std::cout << "his weight of min way = " << heuristics_weight << std::endl;
	std::cout << "Working time of heuristics " << time_h << " nanoseconds" << std::endl;

	//quality
	float percent_quality = 100 - ((float)(heuristics_weight - min_weight_exact) / (float)(max_way_exact - min_weight_exact)) * 100;
	std::cout << "The quality of the heuristic algorithm " << percent_quality << "%" << std::endl;
	//speed
	float percent_speed = (time / time_h) * 100;
	std::cout << "The speed of the heuristic algorithm " << percent_speed << "%" << std::endl;

	//удаляем память, выделенную под матрицу
	for (int i = 0; i < number_city; i++)
		delete[] matr_way_weight[i];
	delete[] matr_way_weight;
	for (int i = 0; i < number_city; i++)
		delete[] heuristics_matr_way_weight[i];
	delete[] heuristics_matr_way_weight;
	//удаляем память, выделенную под массив
	delete[] way;
	delete[] min_way;
	delete[] way_heuristics;
	delete[] heuristics_min_way;
	delete[] max_way;
}