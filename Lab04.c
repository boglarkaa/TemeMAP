//Lab 4

//ex 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cautare_secventiala(int * vector, int nr_cautat, int nr_elemente_vector)
{
	bool gasit = false;
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		if (nr_cautat == vector[i] && gasit == false)
		{
			return i;
			gasit = true;
		}
	}
	if (gasit == false)
	{
		printf("Elemenul nu a fost gasit\n");
	}
}
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
	if(gasit==false)
	{
		printf("Elementul nu a fost gasit\n");
		return -1;
	}
}
int sortare(const void* a, const void* b)
{
	int el = *(int*)a;
	int el2 = *(int*)b;
	return el - el2;
}
void generare_nr_random(int* vector, int nr_elemente_vector)
{
	for (int i = 0; i < nr_elemente_vector; i++)
	{
		vector[i] = (rand() % (100 + 1));
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
int main()
{
	int nr_elemente_vector = 10;
	int* vector = (int*)calloc(nr_elemente_vector, sizeof(int));
	generare_nr_random(vector, nr_elemente_vector);
	printf("Vectorul nesortat:\n");
	afisare(vector, nr_elemente_vector);
	int nr_cautat = 41; //(rand() % (100 + 1));
	printf("Elementul cautat este %d\n", nr_cautat);
	clock_t timp_initial, timp_final;
	timp_initial = clock();
	printf("Elementul a fost gasit pe pozitia %d\n", cautare_secventiala(vector, nr_cautat, nr_elemente_vector));
	timp_final = clock();
	double timp = (double)(timp_final-timp_initial)/CLOCKS_PER_SEC;
	printf("%.20lf\n", timp);
	qsort(vector, nr_elemente_vector, sizeof(int), sortare);
	printf("Vectorul sortat:\n");
	afisare(vector, nr_elemente_vector);
	timp_initial = clock();
	printf("Elementul a fost gasit pe pozitia %d\n", cautare_binara(vector, nr_cautat, nr_elemente_vector));
	timp_final = clock();
	timp = (double)(timp_final-timp_initial) / CLOCKS_PER_SEC;
	printf("%.20lf\n", timp);
	return 0;
}

//ex2

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
using namespace std;
int compara_int(const void* a, const void* b)
{
	//return ( *(int*)a - *(int*)b );
	if (*(int*)a < *(int*)b) return -1;
	else if (*(int*)a == *(int*)b) return 0;
	else return 1;
}
int compara_float(const void* a, const void* b)
{
	float dif = (*(float*)a - *(float*)b);
	if (dif > 0) return 1;
	else if (dif == 0) return 0;
	else return -1;

}
typedef int (*TIP_PF)(const void*, const void*);
void* cautareSecventiala(const void* adrCheie, const void* adrBaza, size_t nrel, size_t dimElement, TIP_PF functieComparare) {
	for (unsigned i = 0; i < nrel; ++i) {
		char* adrElement = (char*)adrBaza + dimElement * i;
		//adresa celui de al i-lea element
		if (functieComparare(adrCheie, adrElement) == 0)
			return adrElement;//exista si revin in main
	}
	return NULL;//nu exista
}
int main()
{
	int n;
	cout << "Fie un tablou de numere intregi: \n";
	cout << "Introduceti numarul de elemente ale tabloului: ";
	cin >> n;
	int* vector = new int[n];
	int cheie;
	for (int i = 0; i < n; i++)
	{
		vector[i] = (rand() % (100 + 1));
	}
	cout << "Introduceti valoarea cautata: ";
	cin >> cheie;
	clock_t timp_initial, timp_final;
	timp_initial = clock();
	int* adrElementGasit = (int*)cautareSecventiala(&cheie, vector, n, sizeof(int), compara_int);
	timp_final = clock();
	if (adrElementGasit == NULL) cout << "Elementul nu e in vector\n";
	else cout << "Pozitia elementului cautat : " << adrElementGasit - vector << endl;
	double timp = (double)(timp_final - timp_initial) / CLOCKS_PER_SEC;
	printf("%.20lf\n", timp);
	cout << endl;
	delete[] vector;
	_getch();
	return 0;
}

//ex3
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int compara_int(const void* a, const void* b)
{
	//return ( *(int*)a - *(int*)b );
	if (*(int*)a < *(int*)b) return -1;
	else if (*(int*)a == *(int*)b) return 0;
	else return 1;
}
int compara_float(const void* a, const void* b)
{
	float dif = (*(float*)a - *(float*)b);
	if (dif > 0) return 1;
	else if (dif == 0) return 0;
	else return -1;

}
typedef int (*TIP_PF)(const void*, const void*);
void* cautareBinaraGenerala(const void* adrCheie, const void* adrBaza, size_t nrel, size_t dimElement, TIP_PF functieComparare) {
	char* adrInc = (char*)adrBaza;//0x00001200
	char* adrSf = (char*)adrBaza + dimElement * nrel;//0x00001214
	char* adrMij;
	while (adrInc <= adrSf)
	{
		int dif = (adrSf - adrInc) / dimElement;//la primul pas n=5
		adrMij = adrInc + dif / 2 * dimElement;

		//if(v[mijl]==cheie) return mijl;
		if (functieComparare(adrCheie, adrMij) == 0)
			return adrMij;
		else
			//if(v[mij]>cheie) sf=mijl-1;
			if (functieComparare(adrCheie, adrMij) < 0)
				adrSf = adrMij - (1 * dimElement);
		//dimElement unitatea de masura a el. dat
			else //inc=mijl+1;
				adrInc = adrMij + (1 * dimElement);
	}
	return NULL;
}
int main()
{
	int n;
	cout << "Fie un tablou de numere intregi: \n";
	cout << "Introduceti numarul de elemente ale tabloului: ";
	cin >> n;
	int* vector = new int[n];
	int cheie;
	for (int i = 0; i < n; ++i) {
		cout << "vector[" << i << "]=";
		cin >> vector[i];
	}
	cout << "Introduceti valoarea cautata: ";
	cin >> cheie;

	int* adrElementGasit = (int*)cautareBinaraGenerala(&cheie, vector, n, sizeof(int), compara_int);
	if (adrElementGasit == NULL) cout << "Elementul nu e in vector\n";
	else cout << "Pozitia elementului cautat : " << adrElementGasit - vector << endl;

	cout << endl;
	delete[] vector;
	_getch();
	adrElementGasit = (int*) (bsearch(&cheie, vector, n, sizeof(int), compara_int));
	printf("Elementul a fost gasit la adresa %d", adrElementGasit-vector);
	return 0;
}