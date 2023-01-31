#include <stdio.h>
#include <stdlib.h>
int comparare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void CocktailSort(int vector[], int nr_elemente, int size, int(*comparare)(const void* a, const void* b))
{
	bool interschimbare;
	do
	{
		interschimbare = false;
		for (int i = 0; i <= nr_elemente - 2; i++)
		{
			void* vi = (char*)vector + size * i;
			void* vi1 = (char*)vector + size * (i + 1);
			if (comparare(vi, vi1) > 0)
			{
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				interschimbare = true;
			}
		}
		if (interschimbare == false)
		{
			break;
		}
		interschimbare = false;
		for (int i = nr_elemente - 2; i >= 0; i--)
		{
			void* vi = (char*)vector + size * i;
			void* vi1 = (char*)vector + size * (i + 1);
			if (comparare(vi, vi1)>0)
			{
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				interschimbare = true;
			}
		}
	} while (interschimbare == true);
}
int main()
{
	int vector[] = { 10, 9, 8, 7 ,6 };
	int nr_elemente = sizeof(vector) / sizeof(int);
	CocktailSort(vector, nr_elemente, sizeof(int), comparare);
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
int comparare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void SelectionSort(int vector[], int nr_elemente, int size, int (*comparare)(const void* a, const void* b))
{
	for (int i = 0; i < nr_elemente - 1; i++)
	{
		for (int j = i + 1; j < nr_elemente; j++)
		{
			void* vi = (char*)vector + size * i;
			void* vj = (char*)vector + size * j;

			if (comparare(vi, vj) > 0)
			{
				int aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}
}
int main()
{
	int vector[] = { 10, 9, 8, 7 ,6 };
	int nr_elemente = sizeof(vector) / sizeof(int);
	SelectionSort(vector, nr_elemente, sizeof(int), comparare);
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	return 0;
}