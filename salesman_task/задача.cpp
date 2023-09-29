#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>

int way_weight(int* way, int** matr, int n) {
    int weight = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            weight += matr[way[i] - 1][way[0] - 1];
        }
        else {
            weight += matr[way[i] - 1][way[i + 1] - 1];
        }
    }
}

int fct(int n) {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        k *= i;
    }
}

int AddArr(int* a, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += a[i];
    }
    return k;
}

void Rand_Matr(int** matr, int m)
{
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
};

void Swap(int a, int b) {
    int c;
    c = a;
    a = b;
    b = c;
}

int display(int* a, int* arr, int n) {
    for (int x = 0; x < n; x++) {
        arr[x] = a[x];
    }
    return arr[n];
        //    printf("swapped (%d, %d)\n", j, i);
}

bool Permutations_2(int n, int* way) {
    int i = n - 2;
    while (i != 0 && way[i] >= way[i + 1]) i--;
    if (i == 0) return false;
    int j = n - 1;
    while (way[i] >= way[i + 1]) j--;
    Swap(way[i], way[j]);
    for (int k = i + 1, l = n - 1; i <= n / 2 && k < l; k++, l--) Swap(way[k], way[l]);
    return true;
}

void Permutations(int n) {
    int i, j, tmp, *a, *p, *paths_arr;
    a = new int[n];
    p = new int[n + 1];
    paths_arr = new int[fct(n - 1) * n];
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
        p[i] = i;
    }
    p[n] = n;
    display(a, paths_arr, n);
    i = 1;
    while (i < n) {
        p[i]--;
        j = i % 2 * p[i];
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
        
        i = 1;
        while (!p[i]) {
            p[i] = i;
            i++;
        }
    }
    delete[] a;
    delete[] p;
}

int path_weight(int** matr, int n) {
   int weight = 0;
   for (int i = 0; i < n-1; i++){
        weight += matr[i][i+1];
   }
   weight += matr[n - 1][1];
   return weight;
}


int main()
{
    int n, **a;
    std::cout << "enter the number of cities";
    std::cin >> n;
    a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    Rand_Matr(a, n);
    for (int i = 0; i < n; i++) {
        a[i][i] = 0;
    }
    Out_Matr(a, n);
    Permutations(n);
    std::cout << path_weight(a, n);
    
}
