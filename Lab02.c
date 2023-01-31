//Laboratorul 2
//ex 1

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct puncte {
	int x, y, z;
};
float distanta(struct puncte A1, struct puncte A0)
{
	int x = A1.x - A0.x;
	int y = A1.y - A0.y;
	int z = A1.z - A0.z;
	float distanta = sqrt(pow(A1.x - A0.x, 2) + pow(A1.y - A0.y, 2) + pow(A1.z - A0.z, 2));
	return distanta;
}
int main()
{
	puncte A0, A1;
	scanf("%d", &A0.x);
	scanf("%d", &A0.y);
	scanf("%d", &A0.z);
	scanf("%d", &A1.x);
	scanf("%d", &A1.y);
	scanf("%d", &A1.z);
	distanta(A1, A0);
	printf("%f", distanta(A1, A0));
	return 0;
}

//ex2
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Punct2D 
{
	int x, y;
};
Punct2D puncte[10];
Punct2D punct1, punct2, punct3;
float distanta(struct Punct2D punct1, struct Punct2D punct2)
{
	return sqrt(pow(punct2.x - punct1.x, 2) + pow(punct2.y - punct1.y, 2));
}
void centru_greutate_puncte(struct Punct2D punct1, struct Punct2D punct2, struct Punct2D punct3)
{
	float xG = (punct1.x + punct2.x + punct3.x) / 3;
	printf("xG= %f\n", xG);
	float yG = (punct1.y + punct2.y + punct3.y) / 3;
	printf("yG= %f\n", yG);
}
void citire_date(int nr_laturi)
{
	for (int i = 0; i < (nr_laturi + 1); i++)
	{
		printf("x.punct[%d]= ", i);
		scanf_s("%d", &puncte[i].x);
		printf("y.punct[%d]= ", i);
		scanf_s("%d", &puncte[i].y);
	}
}
void ordonare_puncte(int nr_laturi)
{
	Punct2D aux;
	for (int i = 0; i < (nr_laturi + 1); i++)
	{
		for (int j = i + 1; j < (nr_laturi + 1); j++)
		{
			if (puncte[i].x > puncte[j].x)           //ordonare dupa abcisa
			{
				aux = puncte[i];
				puncte[i] = puncte[j];
				puncte[j] = aux;
			}
			else if (puncte[i].x == puncte[j].x)   //daca abcisa e egala
			{
				if (puncte[i].y > puncte[j].y)     //ordonare dupa ordonata
				{
					aux = puncte[i];
					puncte[i] = puncte[j];
					puncte[j] = aux;
				}
			}
		}
	}
}
void afisare_puncte_ordonate(int nr_laturi)
{
	for (int i = 0; i < (nr_laturi + 1); i++)
	{
		printf("x.punct[%d]= %d\n", i, puncte[i].x);
		printf("y.punct[%d]= %d\n", i, puncte[i].y);

	}
}
int main()
{
	printf("x1= ");
	scanf("%d", &punct1.x);
	printf("y1= ");
	scanf("%d", &punct1.y);
	printf("x2= ");
	scanf("%d", &punct2.x);
	printf("y2= ");
	scanf("%d", &punct2.y);
	printf("x3= ");
	scanf("%d", &punct3.x);
	printf("y3= ");
	scanf("%d", &punct3.y);
	printf("Distanta dintre punct1 si punct2 este %f\n", distanta(punct1, punct2));
	printf("Distanta dintre punct2 si punct3 este %f\n", distanta(punct2, punct3));
	printf("Distanta dintre punct1 si punct3 este %f\n", distanta(punct1, punct3));
	printf("Centrul de greutate a punctelor se afla la coordonatele \n");
	centru_greutate_puncte(punct1, punct2, punct3);
	int nr_laturi;
	printf("Introduceti nr laturi a poligonului");
	scanf_s("%d", &nr_laturi);
	citire_date(nr_laturi);
	int suma_x = 0, suma_y = 0;
	for (int i = 0; i < (nr_laturi + 1); i++)
	{
		suma_x += puncte[i].x;
		suma_y += puncte[i].y;
	}
	float xG = suma_x / (nr_laturi + 1);
	float yG = suma_y / (nr_laturi + 1);
	printf("Coordonatele centrului de greutate a poligonului\n");
	printf("xG= %f\n", xG);
	printf("yG= %f\n", yG);
	ordonare_puncte(nr_laturi);
	printf("Punctele ordonate \n");
	afisare_puncte_ordonate(nr_laturi);
	return 0;
}

//ex3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct persoana {
	char CNP[14];
	char nume[50];
	char prenume[50];
	char locnastere[100];
	char domiciliu[100];
};
persoana vpers[100];
void citire_date(int nr_persoane)
{
	for (int i = 0; i < nr_persoane; i++)
	{
		printf("CNP ");
		scanf("%s", &vpers[i].CNP);
		printf("Nume ");
		scanf("%s", &vpers[i].nume);
		printf("Prenume ");
		scanf("%s", &vpers[i].prenume);
		printf("Localitate nastere ");
		scanf("%s", &vpers[i].locnastere);
		printf("Domiciliu ");
		scanf("%s", &vpers[i].domiciliu);
	}
}
void sortare_alfabetica(int nr_persoane)
{
	persoana aux;
	for (int i = 0; i < nr_persoane - 1; i++)
	{
		for (int j = i + 1; j < nr_persoane; j++)
		{
			if (strcmp(vpers[i].nume, vpers[j].nume) > 0)
			{
				aux = vpers[i];
				vpers[i] = vpers[j];
				vpers[j] = aux;
			}
			if (strcmp(vpers[i].nume, vpers[j].nume) == 0)
			{
				if (strcmp(vpers[i].prenume, vpers[j].prenume) > 0)
				{
					aux = vpers[i];
					vpers[i] = vpers[j];
					vpers[j] = aux;
				}
			}
		}
	}
}
void afisare_sortat_alfabetic(int nr_persoane)
{ 
	printf("Persoanele sortate in ordine alfabetica dupa nume\n");
	for (int i = 0; i < nr_persoane; i++)
	{
		printf("%s %s\n", vpers[i].nume, vpers[i].prenume);
	}
}
void sortare_varsta_descrescator(int nr_persoane)
{
	persoana aux;
	for (int i = 0; i < nr_persoane; i++)
	{
		for (int j = i + 1; j < nr_persoane; j++)
		{
			if (vpers[i].CNP[0] == '3' || vpers[i].CNP[0] == '4' || vpers[i].CNP[0] == '7' || vpers[i].CNP[0] == '8' || vpers[i].CNP[0] == '9' || vpers[i].CNP[0] == '0')
			{
				printf("%s CNP invalid\n", vpers[i].CNP);
			}
			//daca ambele persoane sunt din 1900 
			else if ((vpers[i].CNP[0] == '1' || vpers[i].CNP[0] == '2') && (vpers[j].CNP[0] == '1' || vpers[j].CNP[0] == '2'))
			{
				if (vpers[i].CNP[1] < vpers[j].CNP[1])
				{
					aux = vpers[i];
					vpers[i] = vpers[j];
					vpers[j] = aux;
				}
				else if (vpers[i].CNP[1] == vpers[j].CNP[1])
				{
					if (vpers[i].CNP[2] < vpers[j].CNP[2])
					{
						aux = vpers[i];
						vpers[i] = vpers[j];
						vpers[j] = aux;
					}
				}

			}
			//daca ambele persoane sunt din 2000
			else if ((vpers[i].CNP[0] == '5' || vpers[i].CNP[0] == '6') && (vpers[j].CNP[0] == '5' || vpers[j].CNP[0] == '6'))
			{
				if (vpers[i].CNP[1] < vpers[j].CNP[1])
				{
					aux = vpers[i];
					vpers[i] = vpers[j];
					vpers[j] = aux;
				}
				else if (vpers[i].CNP[1] == vpers[j].CNP[1])
				{
					if (vpers[i].CNP[2] < vpers[j].CNP[2])
					{
						aux = vpers[i];
						vpers[i] = vpers[j];
						vpers[j] = aux;
					}
				}
			}
			//daca una e din 1900 si alta din 2000
			else if ((vpers[i].CNP[0] == '1' || vpers[i].CNP[0] == '2') && (vpers[j].CNP[0] == '5' || vpers[j].CNP[0] == '6'))
			{
				aux = vpers[i];
				vpers[i] = vpers[j];
				vpers[j] = aux;
			}
		}
	}
}
void afisare_sortat_varsta(int nr_persoane)
{
	printf("Persoanele sortate in ordine descrescatoare dupa varsta in functie de CNP\n");
	for (int i = 0; i < nr_persoane; i++)
	{
		printf("%s %s %s %s %s\n", vpers[i].CNP, vpers[i].nume, vpers[i].prenume, vpers[i].locnastere, vpers[i].domiciliu);
	}
}
int main()
{
	int nr_persoane;
	persoana aux;
	printf("Introduceti numarul de persoane care urmeaza sa fie citite ");
	scanf("%d", &nr_persoane);
	citire_date(nr_persoane);
	sortare_alfabetica(nr_persoane);
	afisare_sortat_alfabetic(nr_persoane);;
	sortare_varsta_descrescator(nr_persoane);
	afisare_sortat_varsta(nr_persoane);
	return 0;
}

//ex4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int  nota, nr_studenti;
float nr_discipline;
struct Disciplina {
	char denumire[100];
	int nota;
};
struct Student {
	char nume[50];
	char prenume[40];
	Disciplina d[10];
	float medie;
};
Student vectorStud[30];
void citire_date(int nr_studenti, int nr_discipline)
{
	for (int i = 0; i < nr_studenti; i++)
	{
		printf("Nume student ");
		scanf("%s", &vectorStud[i].nume);
		printf("Prenume student ");
		scanf("%s", &vectorStud[i].prenume);
		for (int j = 0; j < nr_discipline; j++)
		{
			printf("Denumire disciplina ");
			scanf("%s", &vectorStud[i].d[j].denumire);
			printf("Nota ");
			scanf("%d", &vectorStud[i].d[j].nota);
		}
	}
}
void calcul_medii(int nr_studenti, int nr_discipline)
{
	
	for (int i = 0; i < nr_studenti; i++)
	{
		float suma_note = 0;
		for (int j = 0; j < nr_discipline; j++)
		{
			suma_note += vectorStud[i].d[j].nota;
		}
		vectorStud[i].medie = suma_note / nr_discipline;

	}
}
void sortare_dupa_medii(int nr_studenti, int nr_discipline)
{
	Student aux;
	for (int i = 0; i < nr_studenti; i++)
	{
		for (int j = i + 1; j < nr_studenti; j++)
		{
			if (vectorStud[i].medie > vectorStud[j].medie)
			{
				aux = vectorStud[i];
				vectorStud[i] = vectorStud[j];
				vectorStud[j] = aux;
			}
		}
	}
}
void afisare_studenti_dupa_medie(int nr_studenti, int nr_discipline)
{
	for (int i = 0; i < nr_studenti; i++)
	{
		printf("Nume %s\n", vectorStud[i].nume);
		printf("Prenume %s\n", vectorStud[i].prenume);
		printf("Medie %f\n", vectorStud[i].medie);
	}
}
int main()
{
	printf("Introduceti numarul de studenti ");
	scanf("%d", &nr_studenti);
	printf("Nr discipline ");
	scanf("%f", &nr_discipline);
	citire_date(nr_studenti, nr_discipline);
	calcul_medii(nr_studenti, nr_discipline);
	sortare_dupa_medii(nr_studenti, nr_discipline);
	afisare_studenti_dupa_medie(nr_studenti, nr_discipline);
	return 0;
}


//ex5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int zi, luna, an;
struct Data_de_expirare {
	int zi;
	int luna;
	int an;
};
struct Alimente {
	char nume[20];
	int cod;
	char unitate_masura[3];
	int cantitate;
	Data_de_expirare data[100];
};
Alimente aliment[100];
void citire_data_de_azi()
{

	printf("Introduceti data de azi:\n");
	printf("Zi ");
	scanf("%d", &zi);
	printf("Luna ");
	scanf("%d", &luna);
	printf("An ");
	scanf("%d", &an);
}
void citire_date(int nr_alimente)
{
	for (int i = 0; i < nr_alimente; i++)
	{
		printf("Codul alimentului ");
		scanf("%d", &aliment[i].cod);
		printf("Numele alimentului ");
		scanf("%s", &aliment[i].nume);
		printf("Unitatea de masura a alimentului ");
		scanf("%s", &aliment[i].unitate_masura);
		printf("Cantitatea alimentului ");
		scanf("%d", &aliment[i].cantitate);
		printf("ZIua expirarii ");
		scanf("%d", &aliment[i].data[i].zi);
		printf("Luna expirarii ");
		scanf("%d", &aliment[i].data[i].luna);
		printf("Anul expirarii ");
		scanf("%d", &aliment[i].data[i].an);
	}
}
void afisare_date(int nr_alimente)
{
	for (int i = 0; i < nr_alimente; i++)
	{
		printf("%d %s %d %s\n", aliment[i].cod, aliment[i].nume, aliment[i].cantitate, aliment[i].unitate_masura);
	}
}
void verficare_expirat(int nr_alimente)
{

	for (int i = 0; i < nr_alimente; i++)
	{
		if (an > aliment[i].data[i].an)
		{
			printf("%d %s\n", aliment[i].cod, aliment[i].nume);
		}
		else if (an == aliment[i].data[i].an)
		{
			if (luna > aliment[i].data[i].luna)
			{
				printf("%d %s\n", aliment[i].cod, aliment[i].nume);
			}
			else if (luna == aliment[i].data[i].luna)
			{
				if (zi > aliment[i].data[i].zi)
				{
					printf("%d %s\n", aliment[i].cod, aliment[i].nume);
				}
			}
		}
	}
}
int main()
{
	int nr_alimente;
	printf("Introduceti nr de tipuri de alimente ");
	scanf("%d", &nr_alimente);
	citire_date(nr_alimente);
	printf("Stocul magazinului \n");
	afisare_date(nr_alimente);
	citire_data_de_azi();
	printf("Alimente expirate \n");
	verficare_expirat(nr_alimente);
	return 0;
}