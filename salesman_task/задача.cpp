#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>

int AddArr(int* a, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += a[i];
    }
    return k;
}

void Rand_Matr(int** matr, int m)
{
	srand(time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = rand() % 101;
}

void Out_Matr(int matr[][100], int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) printf("%4d", matr[i][j]);
		printf("\n");
	}
};

void Swap(int a, int b) {
    int c;
    c = a;
    a = b;
    b = c;
}


void display(int* a, int j, int i, int n) {
    for (int x = 0; x < n; x++) {
        printf("%d ", a[x]);
    }
    //    printf("swapped (%d, %d)\n", j, i);
}

void Permutations(int n) {
    int a[n], p[n + 1];
    int i, j, tmp;
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
        p[i] = i;
    }
    p[n] = n;
    display(a, 0, 0, n);
    i = 1;
    while (i < n) {
        p[i]--;
        j = i % 2 * p[i];
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
        display(a, j, i, n);
        i = 1;
        while (!p[i]) {
            p[i] = i;
            i++;
        }
    }
}


//int path(int n, ){

//int path_weight(int** matr[][]){
//   int weight;
//   for (int i = 0; i < n; i++){
//        weight += matr[i][i+1];
//   }
//}


int main()
{
    int n = 6;
    Permutations(n);
}
