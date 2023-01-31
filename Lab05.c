//Laboratorul 5

//ex1 varianta Bubble sort
#include <stdio.h>
#include <stdlib.h>
int comparare(const void* a, const void* b)
{
	
	return *(int*)a - *(int*)b;
}
void BubbleSort(int vector[], int nr_elemente, int size, int(*comparare)(const void* a, const void* b))
{
	bool interschimbare;
	do
	{
		interschimbare = false;
		for (int i = 0; i <= nr_elemente - 2; i++)
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
void afisare(int vector[], int nr_elemente)
{
	for (int i = 0; i<nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int main()
{
	int vector[] = { 10, 9, 8, 7, 6 };
	int nr_elemente = sizeof(vector) / sizeof(int);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente);
	BubbleSort(vector, nr_elemente, sizeof(int), comparare);
	printf("Vector sortat\n");
	afisare(vector, nr_elemente);
	return 0;
}

//varianta Insertion sort - nu functioneaza corect - afiseaza 9 8 7 6 10
#include <stdio.h>
#include <stdlib.h>
void afisare(int vector[], int nr_elemente_vector)
{
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int comparare(const void* a, const void* b)
{
	int aux = *(int*)a;
	int vj = *(int*)b;
	if (aux < vj)
		return -1;
	else if (aux == vj)
		return 0;
	return 1;
}
void InsertionSort(int vector[], int nr_elemente, int size, int(*comparare)(const void* a, const void* b))
{
	for (int i = 1; i < nr_elemente; i++)
	{	
		int j = i - 1;
		int aux2 = vector[i];
		void* vj = (char*)vector + size * j;
		void* aux = (char*)vector + size * i;
		while (j >= 0 && comparare(aux, vj) < 0)
		{
			vector[j + 1] = vector[j];
			j -= 1;
		}
		vector[j + 1] = aux2;
	}
}
int main()
{
	int vector[] = { 10, 9, 8, 7, 6 };
	int n = sizeof(vector) / sizeof(int);
	printf("Vector nesortat\n");
	afisare(vector, n);
	InsertionSort(vector, n, sizeof(int), comparare);
	printf("Vector sortat\n");
	afisare(vector, n);
	return 0;
}

// varianta Shell sort - nu functioneaza corect - afiseaza 7 6 8 9 10
#include <stdio.h>
#include <stdlib.h>
int comparare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void ShellSort(int vector[], int nr_elemente, int size, int(*comparare)(const void* a, const void* b))
{
	for (int i_vector = nr_elemente / 2; i_vector > 0; i_vector /= 2)
	{
		int j;
		for (int i = i_vector; i < nr_elemente; i++)
		{
			j = i;
			int aux = vector[i];
			void* vji = (char*)vector + size * (j - i_vector);
			void* aux2 = (char*)vector + size * i;
			for (j = i; j >= i_vector && comparare(vji, aux2) > 0; j -= i_vector)
			{
				vector[j] = vector[j - i_vector];
			}
			vector[j] = aux;
		}
	}
}
void afisare(int vector[], int nr_elemente)
{
	for (int i = 0; i<nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int main()
{
	int vector[] = { 10, 9, 8, 7, 6 };
	int nr_elemente = sizeof(vector) / sizeof(int);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente);
	ShellSort(vector, nr_elemente, sizeof(int), comparare);
	printf("Vector sortat\n");
	afisare(vector, nr_elemente);
	return 0;
}

//ex2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generare_nr_random(int* vector_aux, int nr_elemente_vector)
{
	for (int i = 1; i < nr_elemente_vector; i++)
	{
		vector_aux[i] = (rand() % (100 + 1));
	}
}
void afisare(int* vector, int nr_elemente_vector)
{
	for (int i = 1; i < nr_elemente_vector; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
void copiere(int* vector, int* vector_aux, int nr_elemente_vector)
{
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		vector[i] = vector_aux[i];
	}
}
void insertion_sort(int* vector, int nr_elemente_vector)
{
	for (int i = 1; i <= nr_elemente_vector - 1; i++)
	{
		int j = i - 1;
		int aux = vector[i];
		while (j > -0 && aux < vector[j])
		{
			vector[j + 1] = vector[j];
			j = j - 1;
		}
		vector[j + 1] = aux;
	}
}
void shell_sort(int* vector, int nr_elemente_vector) 
{
	for (int i_vector = nr_elemente_vector / 2; i_vector > 0; i_vector /= 2)
	{
		int j;
		for (int i = i_vector; i < nr_elemente_vector; i++)
		{
			int aux = vector[i];
			for (j = i; j >= i_vector && vector[j - i_vector] > aux; j -= i_vector)
			{
				vector[j] = vector[j - i_vector];
			}
			vector[j] = aux;
		}
	}
}
void selection_sort(int* vector, int nr_elemente_vector)
{
	for (int i = 0; i <= nr_elemente_vector - 2; i++)
	{
		for (int j = i + 1; j <= nr_elemente_vector - 1; j++)
		{
			if (vector[i] > vector[j])
			{
				int aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}
}
void counting_sort(int* vector, int* dest, int*contor, int nr_elemente_vector)
{
	for (int i = 0; i <= nr_elemente_vector - 2; i++)
	{
		for (int j = i + 1; j <= nr_elemente_vector - 1; j++)
		{
			if (vector[i] > vector[j])
			{
				contor[i]++;
			}
			else
			{
				contor[j]++;
			}
		}
	}
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		dest[contor[i]] = vector[i];
	}
}
void bubble_sort(int* vector, int nr_elemente_vector)
{
	bool interschimbare;
	do {
		interschimbare = false;
		for (int i = 0; i <= nr_elemente_vector - 2; i++)
		{
			if (vector[i] > vector[i + 1])
			{
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				interschimbare = true;
			}
		}
	} while (interschimbare == true);
}
void cocktail_sort(int* vector, int nr_elemente_vector)
{
	bool interschimbare;
	do {
		interschimbare = false;
		for (int i = 0; i <= nr_elemente_vector - 2; i++)
		{
			if (vector[i] > vector[i + 1])
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
		for (int i = nr_elemente_vector - 2; i >= 0; i--)
		{
			if (vector[i] > vector[i + 1])
			{
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				interschimbare = true;
			}
		}
	} while (interschimbare == true);
}
void afisare_timp(double timp_insertion,double timp_shell, double timp_selection,double timp_counting, double timp_bubble, double timp_cocktail)
{
	printf("Timp pt insertion sort %.20lf\n", timp_insertion);
	printf("Timp pt shell sort %.20lf\n", timp_shell);
	printf("Timp pt selection sort %.20lf\n", timp_selection);
	printf("Timp pt counting sort %.20lf\n", timp_counting);
	printf("Timp pt bubble sort %.20lf\n", timp_bubble);
	printf("Timp pt cocktail sort %.20lf\n", timp_cocktail);

}
int main()
{
	int nr_elemente_vector;
	clock_t timp_initial, timp_final;
	printf("Introduceti nr elemente din vector ");
	scanf_s("%d", &nr_elemente_vector);
	int* vector = (int*)calloc(nr_elemente_vector, sizeof(int));
	int* vector_aux = (int*)calloc(nr_elemente_vector, sizeof(int));
	generare_nr_random(vector_aux, nr_elemente_vector);
	//Insertion sort
	copiere(vector, vector_aux, nr_elemente_vector);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente_vector);
	timp_initial = clock();
	insertion_sort(vector, nr_elemente_vector);
	timp_final = clock();
	double timp_insertion = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat\n");
	afisare(vector, nr_elemente_vector);
	//Shell sort
	copiere(vector, vector_aux, nr_elemente_vector);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente_vector);
	timp_initial = clock();
	shell_sort(vector, nr_elemente_vector);
	timp_final = clock();
	double timp_shell = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat\n");
	afisare(vector, nr_elemente_vector);
	//Selection sort
	copiere(vector, vector_aux, nr_elemente_vector);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente_vector);
	timp_initial = clock();
	selection_sort(vector, nr_elemente_vector);
	timp_final = clock();
	double timp_selection = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat\n");
	afisare(vector, nr_elemente_vector);
	//Counting sort
	copiere(vector, vector_aux, nr_elemente_vector);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente_vector);
	int* contor = (int*)calloc(nr_elemente_vector, sizeof(int));
	int* dest = (int*)calloc(nr_elemente_vector, sizeof(int));
	timp_initial = clock();
	counting_sort(vector, dest, contor, nr_elemente_vector);
	timp_final = clock();
	double timp_counting = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat\n");
	afisare(dest, nr_elemente_vector);
	//Bubble sort
	copiere(vector, vector_aux, nr_elemente_vector);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente_vector);
	timp_initial = clock();
	bubble_sort(vector, nr_elemente_vector);
	timp_final = clock();
	double timp_bubble = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat\n");
	afisare(vector, nr_elemente_vector);
	//Cocktail sort
	copiere(vector, vector_aux, nr_elemente_vector);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente_vector);
	timp_initial=clock();
	cocktail_sort(vector, nr_elemente_vector);
	timp_final = clock();
	double timp_cocktail = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat\n");
	afisare(vector, nr_elemente_vector);
	//Timp
	afisare_timp(timp_insertion, timp_shell, timp_selection, timp_counting, timp_bubble, timp_cocktail);
	return 0;
}

//ex3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initializare_vector(int nr_elemente, int* vector_pt_qsort, int* vector_pt_shellsort)
{
	for (int i = 0; i < nr_elemente; i++)
	{
		vector_pt_qsort[i] = rand() % (100 + 1);
		vector_pt_shellsort[i] = vector_pt_qsort[i];
	}
}
void shell_sort(int* vector, int nr_elemente_vector)
{
	for (int i_vector = nr_elemente_vector / 2; i_vector > 0; i_vector /= 2)
	{
		int j;
		for (int i = i_vector; i < nr_elemente_vector; i++)
		{
			int aux = vector[i];
			for (j = i; j >= i_vector && vector[j - i_vector] > aux; j -= i_vector)
			{
				vector[j] = vector[j - i_vector];
			}
			vector[j] = aux;
		}
	}
}
int comparare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void afisare(int* vector, int nr_elemente_vector)
{
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int main()
{
	int nr_elemente;
	clock_t timp_initial, timp_final;
	printf("Introduceti nr elemente din vector ");
	scanf_s("%d", &nr_elemente);
	int* vector_pt_qsort = (int*)calloc(nr_elemente, sizeof(int));
	int* vector_pt_shellsort = (int*)calloc(nr_elemente, sizeof(int));
	initializare_vector(nr_elemente, vector_pt_qsort, vector_pt_shellsort);
	printf("Vector nesortat\n");
	afisare(vector_pt_qsort, nr_elemente);
	timp_initial = clock();
	shell_sort(vector_pt_shellsort, nr_elemente);
	timp_final = clock();
	double timp_shell = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat prin shell sort\n");
	afisare(vector_pt_shellsort, nr_elemente);
	timp_initial = clock();
	qsort(vector_pt_qsort, nr_elemente, sizeof(int), comparare);
	timp_final = clock();
	double timp_qsort = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Vector sortat prin qsort sort\n");
	afisare(vector_pt_qsort, nr_elemente);
	printf("Timp pt shell sort %.25lf\n", timp_shell);
	printf("Timp pt qsort %.25lf\n", timp_qsort);
	return 0;
}

//ex4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initializare(int* vector, int nr_elemente)
{
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % (100 + 1);
	}
}
void insertion_sort(int* vector, int nr_elemente_vector)
{
	for (int i = 1; i <= nr_elemente_vector - 1; i++)
	{
		int j = i - 1;
		int aux = vector[i];
		while (j >= 0 && aux < vector[j])
		{
			vector[j + 1] = vector[j];
			j = j - 1;
		}
		vector[j + 1] = aux;
	}
}
int ord_cresc(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int ord_descresc(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
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
	clock_t timp_initial, timp_final;
	printf("Introduceti nr elemente din vector ");
	scanf_s("%d", &nr_elemente);
	int* vector = (int*)calloc(nr_elemente, sizeof(int));
	initializare(vector, nr_elemente);
	printf("Vector nesortat\n");
	afisare(vector, nr_elemente);
	timp_initial = clock();
	insertion_sort(vector, nr_elemente);
	timp_final = clock();
	double timp_random = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	qsort(vector, nr_elemente, sizeof(int), ord_cresc);
	timp_initial = clock();
	insertion_sort(vector,  nr_elemente);
	timp_final = clock();
	double timp_cresc = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	qsort(vector, nr_elemente, sizeof(int), ord_descresc);
	timp_initial = clock();
	insertion_sort(vector, nr_elemente);
	printf("Vector sortat\n");
	afisare(vector, nr_elemente);
	timp_final = clock();
	double timp_descresc = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("Timp caz favorabil %.20lf\nTimp caz nefavorabil %.20lf\nTimp caz random %.20lf", timp_cresc, timp_descresc, timp_random);
	return 0;
}

