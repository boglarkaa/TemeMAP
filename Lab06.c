//Laboratorul 6 

//ex1 - varianta Counting sort
#include <stdio.h>
#include <stdlib.h>
int maximum(int vector[], int nr_elemente)
{
	int maxim = vector[0];
	for (int i = 0; i < nr_elemente; i++)
	{
		if (maxim < vector[i])
		{
			maxim = vector[i];
		}
	}
	return maxim;
}
void CountingSort(int vector[], int nr_elemente)
{
	int  y[20];
	int maxim = maximum(vector, nr_elemente);
	int* vector_frecventa;
	vector_frecventa = (int*)calloc(maxim, sizeof(int));
	for (int i = 0; i <= maxim; i++)
	{
		vector_frecventa[i] = 0;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		vector_frecventa[vector[i]]++;
	}
	for (int i = 1; i <= maxim; i++)
	{
		vector_frecventa[i] = vector_frecventa[i - 1] + vector_frecventa[i];
	}
	for (int i = nr_elemente - 1; i >= 0; i--)
	{
		y[vector_frecventa[vector[i]] - 1] = vector[i];
		vector_frecventa[vector[i]]--;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = y[i];
	}
}
void afisare(int vector[], int nr_elemente)
{
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int main()
{
	int vector[] = { 10,9,8,7,6 };
	int nr_elemente = sizeof(vector) / sizeof(int);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente);
	CountingSort(vector, nr_elemente);
	printf("Vector sortat\n");
	afisare(vector, nr_elemente);
	return 0;
}

//ex1 varianta Radix sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void afisare(int vector[], int nr_elemente)
{
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int maximum(int vector[], int nr_elemente)
{
	int maxim = vector[0];
	for (int i = 0; i < nr_elemente; i++)
	{
		if (maxim < vector[i])
		{
			maxim = vector[i];
		}
	}
	int k = 0;
	while (maxim!=0)
	{
		k++;
		maxim /= 10;
	}
	return k;
}
void CountingSortCifra(int vector[], int nr_elemente, int pozcifra)
{
	int vector_frecventa[100], y[100];
	int cifra;
	int m = 9;
	for (int i = 1; i <= 9; i++)
	{
		vector_frecventa[i] = 0;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		int cifra =(int)((vector[i]) / pow(10, pozcifra)) % 10;
		vector_frecventa[cifra]++;
	}
	for (int i = 1; i <= m; i++)
	{
		vector_frecventa[i] = vector_frecventa[i - 1] + vector_frecventa[i];
	}
	for (int i = nr_elemente - 1; i >= 0; i--)
	{
		int cifra = (int)((vector[i]) / pow(10, pozcifra)) % 10;
		y[vector_frecventa[cifra] - 1] = vector[i];
		vector_frecventa[cifra]--;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = y[i];
	}
	afisare(vector, nr_elemente);
}
void RadixSort(int vector[], int nr_elemente)
{
	for (int pozcifra = 0; pozcifra < maximum(vector, nr_elemente); pozcifra++)
	{
		CountingSortCifra(vector, nr_elemente, pozcifra);
	}
}

int main()
{
	int vector[] = { 10,9,8,7,6 };
	int nr_elemente = sizeof(vector) / sizeof(int);
	afisare(vector, nr_elemente);
	RadixSort(vector, nr_elemente);
	return 0;
}

//ex2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int maximum(int* vector, int nr_elemente)
{
	int maxim = vector[0];
	for (int i = 0; i < nr_elemente; i++)
	{
		if (maxim < vector[i])
		{
			maxim = vector[i];
		}
	}
	return maxim;
}
void CountingSort(int* vector, int nr_elemente)
{
	int * y= (int*)calloc(nr_elemente, sizeof(int));
	int maxim = maximum(vector, nr_elemente);
	int* vector_frecventa;
	vector_frecventa = (int*)calloc(maxim, sizeof(int));
	for (int i = 0; i <= maxim; i++)
	{
		vector_frecventa[i] = 0;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		vector_frecventa[vector[i]]++;
	}
	for (int i = 1; i <= maxim; i++)
	{
		vector_frecventa[i] = vector_frecventa[i - 1] + vector_frecventa[i];
	}
	for (int i = nr_elemente - 1; i >= 0; i--)
	{
		y[vector_frecventa[vector[i]] - 1] = vector[i];
		vector_frecventa[vector[i]]--;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = y[i];
	}
}
int comparare(const void* a, const void* b)
{
	return*(int*)a - *(int*)b;
}
void afisare(int* vector, int nr_elemente)
{
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int main()
{
	int nr_elemente;
	time_t timp_initial, timp_final;
	printf("Nr elemente ");
	scanf_s("%d", &nr_elemente);
	int* vector=(int*)calloc(nr_elemente, sizeof(int));
	int* vector2 = (int*)calloc(nr_elemente, sizeof(int));
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % 101;
		vector2[i] = vector[i];
	}
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente);
	timp_initial = clock();
	CountingSort(vector, nr_elemente);
	timp_final = clock();
	printf("Vector sortat\n");
	afisare(vector, nr_elemente);
	double timp = (double)(timp_final - timp_initial)/CLOCKS_PER_SEC;
	printf("Timp de executie Counting sort %.20lf\n", timp);
	timp_initial = clock();
	qsort(vector2, nr_elemente, sizeof(int), comparare);
	timp_final = clock();
	timp = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Timp de executie  qsort %.20lf\n", timp);
	return 0;
}