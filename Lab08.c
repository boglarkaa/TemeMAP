//Lab08

//ex1
#include <stdio.h>
#include <stdlib.h>

void Interclasare(int inceput, int mijloc, int sfarsit, int* vector, int* temp)
{
	int i = inceput, j = mijloc + 1, k = 0;
	while (i <= mijloc && j <= sfarsit)
	{
		if (vector[i] < vector[j])
		{
			temp[k] = vector[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = vector[j];
			k++;
			j++;
		}
	}
	while (i <= mijloc)
	{
		temp[k] = vector[i];
		k++;
		i++;
	}
	while (j <= sfarsit)
	{
		temp[k] = vector[j];
		k++;
		j++;
	}
	for (int i = inceput; i <= sfarsit; i++)
	{
		vector[i] = temp[i - inceput];
	}
}
void MergeSort(int inceput, int sfarsit, int* vector, int* temp)
{
	if (inceput >= sfarsit) {
		return;
	}
	else
	{
		int mijloc = (inceput + sfarsit) / 2;
		//printf("mijloc %d ", mijloc);
		MergeSort(inceput, mijloc, vector, temp);
		MergeSort(mijloc + 1, sfarsit, vector, temp);
		Interclasare(inceput, mijloc, sfarsit, vector, temp);
	}
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
	printf("Nr elemente= ");
	scanf_s("%d", &nr_elemente);
	int* vector = (int*)calloc(nr_elemente, sizeof(int));
	int* temp = (int*)calloc(nr_elemente, sizeof(int));
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % 101;
	}
	afisare(vector, nr_elemente);
	int inceput = 0;
	int sfarsit = nr_elemente-1;
	int mijloc = (inceput + sfarsit) / 2;
	MergeSort(inceput, sfarsit, vector, temp);
	afisare(temp, nr_elemente);
	return 0;
}

//ex1.2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void interschimbare(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}
int comparare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int Partitionare(int inceput, int sfarsit, int* vector)
{
	int P = vector[inceput];
	int i = inceput + 1;
	int j = sfarsit;
	while (i <= j)
	{
		while (i <= j && vector[i] <= P)
		{
			i++;
		}
		while (i <= j && vector[j] >= P)
		{
			j--;
		}
		if (i < j)
		{
			interschimbare(&vector[i], &vector[j]);
		}
	}
	interschimbare(&vector[inceput], &vector[j]);
	return j;
}
void QuickSort(int inceput, int sfarsit, int* vector)
{
	if (inceput < sfarsit)
	{
		int pozPivot = Partitionare(inceput, sfarsit, vector);
		QuickSort(inceput, pozPivot - 1, vector);
		QuickSort(pozPivot + 1, sfarsit, vector);
	}
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
	printf("Nr elemente ");
	scanf_s("%d", &nr_elemente);
	int* vector = (int*)calloc(nr_elemente, sizeof(int));
	int* aux = (int*)calloc(nr_elemente, sizeof(int));
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % 101;
		aux[i] = vector[i];
	}
	//printf("Vector nesortat ");
	//afisare(vector, nr_elemente);
	clock_t initial, final;
	initial = clock();
	QuickSort(0, nr_elemente - 1, vector);
	final = clock();
	//printf("Vector sortat ");
	//afisare(vector, nr_elemente);
	printf("Timp sortare QuickSort %.20lf\n", (double)(final - initial) / CLOCKS_PER_SEC);  
	initial = clock();
	qsort(aux, nr_elemente, sizeof(int), comparare);
	final = clock();
	//printf("Vector sortat ");
	//afisare(aux, nr_elemente);
	printf("Timp sortare qsort %.20lf\n", (double)(final - initial) / CLOCKS_PER_SEC);  
	return 0;
}

//ex2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cautare_binara(int* vector, int nr_cautat, int nr_elemente_vector)
{
	int left = 0;
	int right = nr_elemente_vector;
	int mijloc;
	int poz_gasit;
	bool gasit = false;
	while (left <= right)
	{
		mijloc = (left + right) / 2;
		if (nr_cautat == vector[mijloc])
		{
			return mijloc;
		}
		else if (nr_cautat < vector[mijloc])
		{
			right = mijloc - 1;
		}
		else if (nr_cautat > vector[mijloc])
		{
			left = mijloc + 1;
		}
	}
	if (gasit == false)
	{
		printf("Elementul nu a fost gasit\n");
		return -1;
	}
}
int CautareBinara_recursiv(int* vector, int key, int left, int right)
{
	int middle = (left + right) / 2;
	if (key == vector[middle])
	{
		return middle;
	}
	else if (key < vector[middle])
	{
		return CautareBinara_recursiv(vector, key, left, middle - 1);
	}
	else if (key > vector[middle])
	{
		return CautareBinara_recursiv(vector, key, middle + 1, right);
	}
}
void generare_nr_random(int* vector, int nr_elemente_vector)
{
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		vector[i] = (rand() % (1000 + 1));
	}
}
void afisare(int* vector, int nr_elemente_vector)
{
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int sortare(const void* a, const void* b)
{
	int el = *(int*)a;
	int el2 = *(int*)b;
	return el - el2;
}
int main()
{
	long int nr_elemente_vector = 10000000;
	int* vector = (int*)calloc(nr_elemente_vector, sizeof(int));
	generare_nr_random(vector, nr_elemente_vector);
	//printf("Vectorul nesortat:\n");
	//afisare(vector, nr_elemente_vector);
	qsort(vector, nr_elemente_vector, sizeof(int), sortare);
	//afisare(vector, nr_elemente_vector);
	int nr_cautat = 41; //rand() % 101;
	clock_t initial, final;
	initial = clock();
	printf("%lf\n", (double)initial);
	printf("Elementul a fost gasit pe pozitia %d\n", cautare_binara(vector, nr_cautat, nr_elemente_vector));
	final = clock();
	printf("%lf\n", (double)final);
	printf("Timp cautare cautare binara %.100lf\n", (double)(final - initial) / CLOCKS_PER_SEC);
	initial = clock();
	printf("Nr cautat a fost gasit pe poz %d\n", CautareBinara_recursiv(vector, nr_cautat, 0, nr_elemente_vector ));
	final = clock();
	printf("Timp cautare binara recursiva %.100lf\n", (double)(final - initial) / CLOCKS_PER_SEC);
	initial = clock();
	int* key = (int*)bsearch(&nr_cautat, vector, nr_elemente_vector, sizeof(int), sortare);
	final = clock();
	printf("Elementul a fost gasit la adresa %d\n", key - vector);
	printf("Timp cautare bsearch %.100lf\n", (double)(final - initial) / CLOCKS_PER_SEC);
	return 0;
}

//ex3


//ex4
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
int n;
struct Gaura {
	int x, y;
};
Gaura g[50];
struct Dreptunghi {
	int x, y, h, l;
}DrMax;
bool esteDreptunghiMaxim(int x, int y, int L, int H)
{
	return ((L * H) > (DrMax.h * DrMax.l));
}
int gasire_gaura(int x, int y, int l, int h)
{
	for (int i = 0; i <= n; i++)
	{
		if (g[i].x > x && g[i].y > y && g[i].x < x + l && g[i].y < y + h)
		{
			return i;
		}
	}
	return -1;
}

void taieturi(int x, int y, int l, int h)
{
	int indexGaura = gasire_gaura(x, y, l, h);
	if (gasire_gaura(x, y, l, h) == -1)
	{
		if (esteDreptunghiMaxim(x, y, l, h))
		{
			DrMax.x = x;
			DrMax.y = y;
			DrMax.h = h;
			DrMax.l = l;
		}
	}
	else 
	{
		
		taieturi(x, y, l, g[indexGaura].y - y);
		taieturi(x, g[indexGaura].y, l, h - g[indexGaura].y + y);
		taieturi(x, y, g[indexGaura].x - x, h);
		taieturi(g[indexGaura].x, y, l - g[indexGaura].x + x, h);
	}
}
int main()
{
	int h, l;
	ifstream fisier("Text.txt");
	fisier >> h >> l>>n;
	for (int i = 0; i < n; i++)
	{
		fisier >> g[i].x >> g[i].y;
	}
	fisier.close();
	taieturi(0, 0, 0 + l, 0 + h);
	printf("Aria maximua este %d\nCoordonatele tablei %d %d %d %d", DrMax.h * DrMax.l, DrMax.x, DrMax.y, DrMax.h, DrMax.l);
	return 0;
}

//ex5

#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
struct Punct {
	int x, y;
}*drum;
int n, m, xo, yo, xi, yi;
int** a;
void afisareDrum(int nrpasi) {
	cout << "Lungimea dr.: " << nrpasi + 1 << " trece prin:";
	for (int i = 0; i < nrpasi; ++i)
		cout << "(" << drum[i].x << "," << drum[i].y << "), ";
	cout << "(" << xi << "," << yi << ")" << endl << endl;

}
void labirint(int x, int y, int nrpasi) {
	if (x == xi && y == yi) afisareDrum(nrpasi);
	else if (a[x][y] == -1 || a[x][y] == 1);//zid
	else//if(a[x][y]==0)
	{
		drum[nrpasi].x = x;//adaugare la drum
		drum[nrpasi].y = y;
		a[x][y] = 1;//zidire camera vizitata
		labirint(x + 1, y, nrpasi + 1);
		labirint(x, y + 1, nrpasi + 1);
		labirint(x - 1, y, nrpasi + 1);
		labirint(x, y - 1, nrpasi + 1);
		a[x][y] = 0;//desfiintare zid
	}
}
int main() {
	ifstream f("Labirint.txt");
	f >> n >> m >> xo >> yo >> xi >> yi;
	drum = new Punct[n * m];
	a = new int* [n + 2];
	for (int i = 0; i < n + 2; ++i) a[i] = new int[m + 2];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) f >> a[i][j];
	f.close();
	for (int i = 0; i < n + 2; ++i) a[i][0] = a[i][m + 1] = -1;
	for (int j = 0; j < m + 2; ++j) a[0][j] = a[n + 1][j] = -1;
	labirint(xo, yo, 0);
	delete[] drum;
	for (int i = 0; i < n + 2; ++i) delete[] a[i];
	delete[] a;
	_getch();
	return 0;
}