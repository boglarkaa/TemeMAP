//Laborator01

//ex1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r"), *fisier_iesire=fopen("copie.txt", "w");
	if (fisier_iesire == NULL)
	{
		printf("Eroare de iesire");
		return -1;
	}
	if (fisier_intrare == NULL)
	{
		printf("Eroare de intrare");
		return -1;
	}
	//copiere caracter cu caracter
	/*while (!feof(fisier_intrare))
	{
		char caracter=fgetc(fisier_intrare);
		fputc(caracter, fisier_iesire);
	}*/
	//copiere linie cu linie
	char linii[20][255];
	int i = 0;
	while (fgets(linii[i], 255, fisier_intrare))
	{
		fputs(linii[i], fisier_iesire);
		i++;
	}
	fclose(fisier_iesire);
	fclose(fisier_intrare);
	return 0;
}

//ex1 varianta c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("Text.txt", ios::in);
	ofstream fout;
	fout.open("Copie.txt", ios::out);
	//citire caracter cu caracter
	/*
	char c;
	fin.get(c);
	while (!fin.eof())
	{
		fout.put(c);
		fin.get(c);
	}*/
	//copiere linie cu linie
	string linie;
	while (!fin.eof())
	{
		getline(fin, linie);
		fout << linie;
	}
	fin.close();
	fout.close();
	return 0;
}

//ex2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r");
	if (fisier_intrare == NULL)
	{
		printf("Eroare");
		return -1;
	}
	char linii[30][255];
	int nr_linii = 0;
	while (fgets(linii[nr_linii], 255, fisier_intrare))      
	{
		nr_linii++;
	}
	char cuvant_cautat[10];
	printf("Introduceti cuvatul cautat ");
	scanf("%s", &cuvant_cautat);
	cuvant_cautat[sizeof(cuvant_cautat) -1] = '\0';
	int contor=0;
	for (int i = 0; i < nr_linii; i++)
	{
		if (strstr(linii[i], cuvant_cautat)!=NULL)          
		{
			contor++;
		}
	}
	if (contor == 0)
	{
		printf("Cuvantul cautat nu a fost gasit");
	}
	else
	{
		printf("Cuvantul apare de %d ori in fisier", contor);
	}
	fclose(fisier_intrare);
	return 0;
}

//ex3
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r"), *fisier_iesire=fopen("sortat.txt", "w");
	char linii[20][255];
	int nr_linii = 0;
	while (fgets(linii[nr_linii], 255, fisier_intrare))
	{
		nr_linii++;
	}
	char aux[255];
	for(int j=0; j<nr_linii; j++)
	{
		for (int k = j+1; k < nr_linii; k++) 
		{
			if(linii[j][0]>linii[k][0])
			{
				strcpy(aux, linii[j]);
				strcpy(linii[j], linii[k]);
				strcpy(linii[k], aux);
			}
		}
	}
	for (int j = 0; j < nr_linii; j++)
	{
		fputs(linii[j], fisier_iesire);
	}
	fclose(fisier_iesire);
	fclose(fisier_intrare);
	return 0;
}

//ex4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* fisier = fopen("Text.txt", "w");
	if (fisier == NULL)
	{
		printf("Eroare");
		return -1;
	}
	char c;
	c = fgetc(stdin);
	while (c!=26)     // cod ascii pt ctrl+z; necesita apasare ENTER dupa ctrl+z
	{
		putc(c, fisier);
		c = fgetc(stdin);
	}
	fclose(fisier);
	return 0;
}

//ex5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r"), * fisier_iesire = fopen("Numerotat.txt", "w");
	if (fisier_iesire == NULL)
	{
		printf("Eroare iesire");
		return -1;
	}
	if (fisier_intrare == NULL)
	{
		printf("Eroare intrare");
		return -1;
	}
	char linii[20][255];
	int nr_linii = 0;
	while (fgets(linii[nr_linii], 255, fisier_intrare))
	{
		nr_linii++;
	}
	for (int i = 1; i <= nr_linii; i++)
	{ 
		char numar[10];
		_itoa(i, numar, 10);
		fprintf(fisier_iesire, numar);
		fprintf(fisier_iesire, ". ");
		fputs(linii[i - 1], fisier_iesire);
	}
	remove("Text.txt");
	rename("Numerotat.txt", "Text.txt");
	fclose(fisier_iesire);
	fclose(fisier_intrare);
	return 0;
}

//ex6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* fisier1 = fopen("fisier1.txt", "r"), *fisier2=fopen("fisier2.txt", "a");
	if (fisier1 == NULL)
	{
		printf("Eroare");
		return -1;
	}
	if (fisier2 == NULL)
	{
		printf("Eroare");
		return -1;
	}
	char linii[20][255];
	int i = 0;
	while (fgets(linii[i], 255, fisier1))
	{
		fputs(linii[i], fisier2);
		i++;
	}
	fclose(fisier1);
	fclose(fisier2);
	return 0;
}

//ex6 varianta c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("Text.txt", ios::in);
	ofstream fout;
	fout.open("Text2.txt", ios::app);
	string linie;
	while (!fin.eof())
	{
		getline(fin, linie);
		fout << linie << "\n";
	}
	fin.close();
	fout.close();
}

//ex7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r"), * fisier_iesire = fopen("Ordonat.txt", "w");
	if (fisier_iesire == NULL)
	{
		printf("Eroare iesire");
		return -1;
	}
	if (fisier_intrare == NULL)
	{
		printf("Eroare intrare");
		return -1;
	}
	char linii[30][255];
	int nr_linii = 0;
	while (fgets(linii[nr_linii], 255, fisier_intrare))
	{
		nr_linii++;
	}
	int nr_de_ordonat[100];
	int l = 0, j;
	int suma = 0, produs = 1;
	for (int i = 0; i < nr_linii; i++)                     //parcurge fiecare linie
	{
		char nr_din_text[50] = "\0";                       //creaza un array nou pt numerele din fiecare linie
		int k = 0;
		for (j = 0; j < strlen(linii[i]); j++)             //parcurge caracterele din fiecare linie
		{
			if ((linii[i][j] >= 48 && linii[i][j] <= 57))  //daca e cifra le pune in array
			{
				nr_din_text[k] = linii[i][j];
				k++;
			}
		}
		int  numar= atoi(nr_din_text);                      //transforma char in integer
		nr_de_ordonat[l] = numar;                           //le copiaza intr-un vector
		l++;
		suma = suma + numar;
		produs = produs * numar;
	}
	printf("Suma= %d\n", suma);
	printf("Produs= %d\n", produs);
	int aux;
	for (int i = 0; i < l; i++)
	{
		for (int j = i + 1; j < l; j++)
		{
			if (nr_de_ordonat[i] > nr_de_ordonat[j])    //metoda bubble sort pt sortare in ordine crescatoare
			{
				aux = nr_de_ordonat[i];
				nr_de_ordonat[i] = nr_de_ordonat[j];
				nr_de_ordonat[j] = aux;
			}
		}
	}
	for (int i = 0; i < l; i++)
	{
		char s[10];
		_itoa(nr_de_ordonat[i], s, 10);                  //transforma int in char si le pune in fisier
		fputs(s, fisier_iesire);
		fputs(" ", fisier_iesire);
	}
	printf("Verifica fisier pentru sirul crescator");
	fclose(fisier_iesire);
	fclose(fisier_intrare);
	return 0;
}

//ex8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r");
	if (fisier_intrare == NULL)
	{
		printf("Eroare intrare");
		return -1;
	}
	char linii[30][255];
	int nr_linii = 0;
	while (fgets(linii[nr_linii], 255, fisier_intrare))         
	{
		nr_linii++;
	}
	char* token;
	char cuvinte[50][100];
	int nr_cuvinte = 0;
	for (int i = 0; i < nr_linii; i++)				
	{
		token=strtok(linii[i], " .,?!\n");
		while (token != NULL)
		{
			strcpy(cuvinte[nr_cuvinte], token);		
			nr_cuvinte++;
			token = strtok(NULL, " .,?!\n");
		}
	}
	int max_lungime = strlen(cuvinte[0]);			
	int min_lungime = strlen(cuvinte[0]);
	char cuvant_cel_mai_lung[100]="\0";
	char cuvant_cel_mai_scurt[100]="\0";
	for (int i = 0; i < nr_cuvinte; i++)
	{
		if (strlen(cuvinte[i]) > max_lungime)
		{
			max_lungime = strlen(cuvinte[i]);
			strcpy(cuvant_cel_mai_lung, cuvinte[i]);
		}
		if (strlen(cuvinte[i]) < min_lungime)
		{
			printf("M");
			min_lungime = strlen(cuvinte[i]);
			strcpy(cuvant_cel_mai_scurt, cuvinte[i]);
		}
	}
	printf("Cel mai lung cuvant din fisier este \"%s\"\n", cuvant_cel_mai_lung);
	printf("Cel mai scurt cuvant din fisier este \"%s\"", cuvant_cel_mai_scurt);
	fclose(fisier_intrare);
	return 0;
}

//ex9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int verificare_fisier(FILE * fisier_intrare, FILE * fisier_iesire)
{
	if (fisier_iesire == NULL)
	{
		printf("Eroare iesire");
		return -1;
	}
	if (fisier_intrare == NULL)
	{
		printf("Eroare intrare");
		return -1;
	}
}
struct Angajat
{
	char nume[30], prenume[30];
	unsigned salariu;
};
float calcul_medii(int nr_angajati, float suma_salarii)
{
	return suma_salarii / nr_angajati;
}
int main()
{
	FILE* fisier_intrare = fopen("Text.txt", "r"), *fisier_iesire=fopen("Angajati.txt", "w");
	Angajat angajat;
	verificare_fisier(fisier_intrare, fisier_iesire);
	int nr_linii=1;
	char linii[20][255];
	char nr_elemente[3];
	fgets(nr_elemente, 3, fisier_intrare);                    //extrage nr de elemente din prima linie
	while (fgets(linii[nr_linii], 255, fisier_intrare))       //extrage restul liniilor
	{
		nr_linii++;
	}
	char* token;
	int nr_cuvinte = 0;
	char cuvinte[50][255];
	for (int i = 1; i < nr_linii; i++)                       //descompune liniile in cuvinte 
	{
		token = strtok(linii[i], " .,?!\n");                 
		while (token != NULL)
		{
			strcpy(cuvinte[nr_cuvinte], token);
			nr_cuvinte++;
			token = strtok(NULL, " .,?!");
		}
	}
	float salariu_dim;
	float salariu_pre_dim=0, salariu_post_dim=0;
	for (int i = 0; i < nr_cuvinte; i++)
	{
		strcpy(angajat.nume, cuvinte[i]);						  //copiaza datele din fisier in structura angajat
		i++;
		strcpy(angajat.prenume, cuvinte[i]);
		i++;;
		angajat.salariu = atoi(cuvinte[i]);
		printf("%s ", angajat.nume);							  //afiseaza datele pe ecran
		printf("%s ", angajat.prenume);
		printf("%d\n", angajat.salariu);
		fputs(angajat.nume, fisier_iesire);						  //pune numele angajatilor in fisier
		fputs(" ", fisier_iesire);
		fputs(angajat.prenume, fisier_iesire);
		fputs(" ", fisier_iesire);
		salariu_dim = angajat.salariu-angajat.salariu*25/100;   
		char salariu_nou[5];
		fputs(_itoa(salariu_dim, salariu_nou, 10), fisier_iesire); //si salariul diminuat
		fputs("\n", fisier_iesire);
		salariu_post_dim += salariu_dim;						   //calculeaza suma salariilor pre si post diminuare
		salariu_pre_dim += angajat.salariu;
	}
	int nr_angajati = atoi(nr_elemente);
	printf("Media salariilor inainte de diminuare este %lf\n", calcul_medii(nr_angajati, salariu_pre_dim));
	printf("Media salariilor dupa de diminuare este %lf\n", calcul_medii(nr_angajati,salariu_post_dim));
	printf("Diferenta dintre cele doua procente este %lf", calcul_medii(nr_angajati, salariu_pre_dim) / calcul_medii(nr_angajati, salariu_post_dim));
	fclose(fisier_intrare);
	fclose(fisier_iesire);
	return 0;
}