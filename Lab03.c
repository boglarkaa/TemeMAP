//Laboratorul 3
//ex1

#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<fstream>
using namespace std;
int nr_persoane;
struct persoana {
	char CNP[14];
	char nume[50];
	char prenume[50];
	char locnastere[100];
	char domiciliu[100];
};
persoana vpers[100];
int comparator_nume(const void* a, const void* b)
{
	persoana element1 = *(persoana*)a;
	persoana element2 = *(persoana*)b;
	if (strcmp(element1.nume, element2.nume) > 0)
	{
		return 1;
	}
	if (strcmp(element1.nume, element2.nume) == 0)
	{
		if (strcmp(element1.prenume, element2.prenume) > 0)
		{
			return 1;
		}
		else if (strcmp(element1.prenume, element2.prenume) == 0)
		{
			return 0;
		}
		else
		{
			return-1;
		}
	}
	return -1;
}
int comparator_CNP( const void*a, const void*b)
{
	persoana element1 = *(persoana*)a;
	persoana element2 = *(persoana*)b;
	if (strcmp(element1.CNP, element2.CNP) < 0)
	{
		return 1;
	}
	if (strcmp(element1.CNP, element2.CNP) == 0)
	{
		return 0;
	}
	return -1;
} 
void citire(ifstream& is)
{
	char nume[50];
	int contor = 0;
	int i = 0;
	while (is >> nume)
	{
		if (contor == 0)
		{
			strcpy(vpers[nr_persoane].CNP, nume);
		}
		if (contor == 1)
		{
			strcpy(vpers[nr_persoane].nume, nume);
		}
		if (contor == 2)
		{
			strcpy(vpers[nr_persoane].prenume, nume);
		}
		if (contor == 3)
		{
			strcpy(vpers[nr_persoane].locnastere, nume);
		}
		if (contor == 4)
		{
			strcpy(vpers[nr_persoane].domiciliu, nume);
		}
		contor++;
		if (contor == 5)
		{
			contor = 0;
			nr_persoane++;
		}
	}
	is.close();
}
void afisare(int nr_persoane)
{
	for (int i = 0; i < nr_persoane; i++)
	{
		printf("%s %s %s\n",vpers[i].CNP, vpers[i].nume, vpers[i].prenume);
	}
}
int main()
{
	ifstream is;
	is.open("Text.txt");
	citire(is);
	qsort(vpers, nr_persoane, sizeof(persoana), comparator_nume);
	printf("Ordonat alfabetic\n");
	afisare(nr_persoane);
	qsort(vpers, nr_persoane, sizeof(persoana), comparator_CNP);
	printf("Ordonat descrescator dupa CNP\n");
	afisare(nr_persoane);
	return 0;
}

//ex2
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
using namespace std;
int nr_produse;
struct produs{
	unsigned short ID;
	char denumire[50];
	unsigned short cantitate;
	float pret;
};
produs vprod[50];
int comparare_pret(const void* a, const void* b)
{
	produs pret1 = *(produs*)a;
	produs pret2 = *(produs*)b;
	if (pret1.pret > pret2.pret)
		return 1;
	else if (pret1.pret == pret2.pret)
		return 0;
	else return -1;
}
int comparare_cantitate (const void* a, const void*b)
{
	produs cant1 = *(produs*)a;
	produs cant2 = *(produs*)b;
	if (cant1.cantitate < cant2.cantitate)
		return 1;
	else if (cant1.cantitate == cant2.cantitate)
		return 0;
	else return -1;
}
void citire(ifstream& fisier_intrare)
{
	char aux_pt_citire[50];
	int contor = 0;
	while (fisier_intrare >> aux_pt_citire)
	{
		if (contor == 0)
		{
			vprod[nr_produse].ID = atoi(aux_pt_citire);
		}
		if (contor == 1)
		{
			strcpy(vprod[nr_produse].denumire, aux_pt_citire);
		}
		if (contor == 2)
		{
			vprod[nr_produse].cantitate = atoi(aux_pt_citire);
		}
		if (contor == 3)
		{
			vprod[nr_produse].pret = atof(aux_pt_citire);
		}
		contor++;
		if (contor == 4)
		{
			contor = 0;
			nr_produse++;
		}
	}
	fisier_intrare.close();
}
void afisare(int nr_produse)
{
	for (int i = 0; i < nr_produse; i++)
	{
		printf("%u %s %u %f \n", vprod[i].ID, vprod[i].denumire, vprod[i].cantitate, vprod[i].pret);
	}
}
int main()
{
	ifstream fisier_intrare;
	fisier_intrare.open("Text.txt");
	citire(fisier_intrare);
	qsort(vprod, nr_produse, sizeof(produs), comparare_pret);
	printf("Produse ordonate crescator dupa pret\n");
	afisare(nr_produse);
	qsort(vprod, nr_produse, sizeof(produs), comparare_cantitate);
	printf("Produse ordonate descrescator dupa cantitae\n");
	afisare(nr_produse);
	return 0;
}

//ex3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int comparare(const void* a, const void* b)
{
	char** adrlinie1 =(char**)(a);
	char** adrlinie2 = (char**)(b);
	char* linie1 = *(adrlinie1);
	char* linie2 = *(adrlinie2);
	if (strcmp(linie1, linie2) < 0)
	{
		return 1;
	}
	else if (strcmp(linie1,linie2)==0)
	{
		return 0;
	}
	return -1;
}
int main()
{
	ifstream fisier_intrare;
	fisier_intrare.open("Text.txt");
	int nr_linii;
	fisier_intrare >> nr_linii;
	char** linii = (char**)malloc(nr_linii * sizeof(char*));
	for (int i = 1; i <= nr_linii; i++)
	{
		linii[i] = (char*)malloc(255 * sizeof(char));
	}
	for (int i = 1; i <= nr_linii; i++)
	{
		getline(fisier_intrare, linii[i]);						//getline nu functioneaza
	}
	qsort(linii, nr_linii, sizeof(char*), comparare);
	for (int i = 0; i < nr_linii; i++)
	{
		printf("%s", linii[i]);
	}

	return 0;
}


//ex4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
int compar(const void* a, const void* b)
{
	int** adresalinie1 = (int**)a;
	int** adresalinie2 = (int**)b;
	int* el1 = *(adresalinie1);
	int* el2 = *(adresalinie2);

	if (el1 > el2)
	{
		return 1;
	}
	else if (el1 == el2)
	{
		return 0;
	}
	return -1;
}
int main()
{
	ifstream fisier_intrare;
	fisier_intrare.open("Text.txt");
	int nr_linii, nr_coloane;
	fisier_intrare >> nr_linii;
	fisier_intrare >> nr_coloane;
	int** matrice=(int**)calloc(nr_linii, sizeof(int*));
	for (int i = 0; i < nr_linii; i++)
	{
		matrice[i] = (int*)calloc(nr_coloane, sizeof(int));
	}
	for (int i = 0; i < nr_linii; i++)
	{
		for (int j = 0; j < nr_coloane; j++)
		{
			fisier_intrare >> matrice[i][j];
		}
	}
	printf("Matricea originala\n");
	for (int i = 0; i < nr_linii; i++)
	{
		for (int j = 0; j < nr_coloane; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < nr_coloane; i++)
	{
		qsort(matrice, nr_coloane, sizeof(int), compar);
	}
	printf("Matricea sortata dupa prima coloana\n");
	for (int i = 0; i < nr_linii; i++)
	{
		for (int j = 0; j < nr_coloane; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//ex5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void ordine_crescatoare(int nr_numere, ...)
{
	int* vector=(int*)calloc(nr_numere, sizeof(int));
	
	for (int i = 1; i <= nr_numere; i++)
	{
		vector[i] = *(&nr_numere + i);
	}
	printf("Vector original ");
	for (int i = 1; i <= nr_numere; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
	int aux;
	for (int i = 1; i <= nr_numere; i++)
	{
		for (int j = i + 1; j <= nr_numere; j++)
		{
			if (vector[i] > vector[j])
			{
				aux = vector[j];
				vector[j] = vector[i];
				vector[i] = aux;
			}
		}
	}
	printf("Vector sortat ");
	for (int i = 1; i <= nr_numere; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}
int main()
{
	ordine_crescatoare(3, 4, 7, 6);
	ordine_crescatoare(10, 2, 6, 7, 9, 0, -2, 4, 6, 10, -9);
	ordine_crescatoare(5, 8, 7, 6, 5, 4);
	return 0;
}

//ex8
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	printf("Numele programului este: %s\n", argv[0]);
	printf("Argumentele sunt: ");
	for (int i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	int lungime = 0;
	for (int i = 1; i < argc; i++)
	{
		lungime += strlen(argv[i]);
	}
	printf("Lungime %d", lungime);
	return 0;
}
