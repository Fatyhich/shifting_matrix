#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define COL 10

void init_matrix(int A[][COL], int n);
void print_matrix(int A[][COL], int n);
void function(int A[][COL], int str);


int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int str = 3;
	int A[str][COL];

	init_matrix(A, str);
	printf("Исходная матрица: \n");
	print_matrix(A, str);

	function(A, str);

	printf("\nИзмененная матрица: \n");
	print_matrix(A, str);

	return 0;
}

void init_matrix(int A[][COL], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			A[i][j] = rand() % 101 - 50;
		}
	}
}
void print_matrix(int A[][COL], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}
}

void function(int A[][COL], int str)
{
	int* temp = (int*)malloc(str * sizeof(int));
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < str; j++)
		{
			temp[j] = A[j][i];
		}

		printf("\nстрока :\n");
		for (int l = 0; l < str; l++)
			printf("%4d", temp[l]);

		int* B = (int*)malloc(str * sizeof(int));
		int k = 0;
		for (int m = 0; m < str; m++)
		{
			if ((i + m) < str)
				B[m] = temp[m + i];
			else
				B[m] = temp[k++];
		}
		printf("\nвидоизмененная строка :\n");
		for (int n = 0; n < str; n++)
		{
			printf("%4d", B[n]);
			A[n][i] = B[n];
		}
		free(B);
	}
	free(temp);
}