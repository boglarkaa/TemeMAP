//Laboratorul 7

//ex1
#include <stdio.h>
#include <stdlib.h>
int alg_euclid(int numar1, int numar2)
{
	if (numar1 == numar2)
	{
		return numar1;
	}
	else if (numar1 > numar2)
	{
		numar1 -= numar2;
	}
	else
	{
		numar2 -= numar1;
	}
}
int main()
{
	int numar1, numar2;
	printf("Introduceti primul numar ");
	scanf_s("%d", &numar1);
	printf("Introduceti al doilea numar ");
	scanf_s("%d", &numar2);
	printf("Cel mai mare divizor comun pentru %d si %d este %d", numar1, numar2, alg_euclid(numar1, numar2));
	return 0;
}

//ex2

#include <stdio.h>
#include <stdlib.h>
int ridicare_la_putere(int numar, int putere)
{
	if (putere == 0)
	{
		return 1;
	}
	else
	{
		return numar * ridicare_la_putere(numar, putere-1);
	}
}
int main()
{
	int numar, putere;
	printf("Introduceti numarul ");
	scanf_s("%d", &numar);
	printf("Introduceti puterea la care trebuie ridicat ");
	scanf_s("%d", &putere);
	printf("%d la puterea %d este %d ", numar, putere, ridicare_la_putere(numar, putere));
	return 0;
}

//ex3

#include <stdio.h>
#include <stdlib.h>
int fact(int numar)
{
	if (numar == 0)
	{
		return 0;
	}
	else if (numar == 1)
	{
		return 1;
	}
	else
	{
		return numar * fact(numar - 1);
	}

}
int main()
{
	int numar; 
	int nr_combinatii;
	scanf_s("%d", &numar);
	scanf_s("%d", &nr_combinatii);
	printf("%d", fact(numar)/(fact(numar-nr_combinatii)*fact(nr_combinatii)));
}

//ex4

#include <stdio.h>
#include <stdlib.h>
int invers(int numar, int aux)
{
	if (numar == 0)
	{
		return aux;
	}
	else
	{
		return invers(numar/10, aux*10+numar%10);
	}
}
int main()
{
	int numar, aux=0;
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	printf("Inversul numarrului introdus este %d ", invers(numar, aux));
	return 0;
}

//ex5

#include <stdio.h>
#include <stdlib.h>

int hanoi(int n, int s, int d, int i) {
    if (n == 1) {
        printf("Mutati de pe %d pe %d\n", s, d);
    }
    else {
        hanoi(n - 1, s, i, d);
        printf("Mutati de pe %d pe %d\n", s, d);
        hanoi(n - 1, i, d, s);
    }
    return 0;
}

int main()
{
    int n, s, d, i;
    printf("Nr discuri ");
    scanf_s("%d", &n);
    printf("Sursa ");
    scanf_s("%d", &s);
    printf("Destinatie ");
    scanf_s("%d", &d);
    printf("Intermediar ");
    scanf_s("%d", &i);
    hanoi(n, s, d, i);
    return 0;
}

//ex6

#include <stdio.h>
#include <stdlib.h>
int maximum = 0;
int maxim(int* vector, int nr_elemente)
{
	if (nr_elemente < 0)
		return maximum;
	else 
	{
		if (vector[nr_elemente] > maximum)
		{
			maximum = vector[nr_elemente];
			return maxim(vector, nr_elemente-1);
		}
		else
		{
			return maxim(vector, nr_elemente - 1);
		}
	}
}
int main()
{
	int nr_elemente;
	printf("Introduceti nr de elemente ");
	scanf_s("%d", &nr_elemente);
	int* vector=(int*)calloc(nr_elemente, sizeof(int));
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % 101;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\nMaximul din vector este %d", maxim(vector, nr_elemente));
	return 0;
}

//ex7

#include <stdio.h>
#include <stdlib.h>
int compar(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int CautareBinara(int* vector, int key, int left, int right)
{
	int middle = (left + right) / 2;
	if (key == vector[middle])
	{
		return middle;
	}
	else if (key < vector[middle])
	{
		return CautareBinara(vector,  key, left, middle - 1);
	}
	else if (key > vector[middle])
	{
		return CautareBinara(vector, key, middle + 1, right);
	}
}
int main()
{
	int nr_elemente;
	printf("Introduceti nr de elemente ");
	scanf_s("%d", &nr_elemente);
	int* vector = (int*)calloc(nr_elemente, sizeof(int));
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % 101;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
	qsort(vector, nr_elemente, sizeof(int), compar);
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	int key;
	printf("\nNr cautat = ");
	scanf_s("%d", &key);
	int left = 0;
	int right = nr_elemente;
	printf("Nr cautat a fost gasit pe poz %d ", CautareBinara(vector, key, left, right));
	return 0;
}

//ex8

#include <stdio.h>
#include <stdlib.h>
int CautareSecventiala(int* vector, int nr_elemente, int key)
{
	if (nr_elemente < 0)
	{
		printf("Nr nu a fost gasit");
		return 0;
	}
	if (vector[nr_elemente] == key)
	{
		return key;
	}
	else
	{
		return CautareSecventiala(vector, nr_elemente - 1, key);
	}
}
int main()
{
	int nr_elemente;
	printf("Introduceti nr de elemente ");
	scanf_s("%d", &nr_elemente);
	int* vector = (int*)calloc(nr_elemente, sizeof(int));
	for (int i = 0; i < nr_elemente; i++)
	{
		vector[i] = rand() % 101;
	}
	for (int i = 0; i < nr_elemente; i++)
	{
		printf("%d ", vector[i]);
	}
	int key;
	printf("\nNr cautat = ");
	scanf_s("%d", &key);
	if (CautareSecventiala(vector, nr_elemente, key) != 0)
	{
		printf("Nr a fost gasit");
	}
	return 0;
}

//ex9

#include <stdio.h>
#include <stdlib.h>
int ghicire_numar(int left, int right)
{
	char semn;
	int middle = (left + right) / 2;
	printf("%d a fost numarul dvs?\n Daca DA apasati =,\n daca e mai MIC apasati <,\n daca e mai MARE apasati >.\n", middle);
	scanf_s("%c", &semn);
	if (semn == '>')
	{
		scanf_s("%c", &semn);
		return ghicire_numar(middle + 1, right);

	}
	else if (semn == '<')
	{
		scanf_s("%c", &semn);
		return ghicire_numar(left, middle - 1);
	}
	else if (semn == '=')
	{
		return middle;
	}
}
int main()
{
	int left = 0;
	int right = 100;
	printf("\n%d a fost numarul dvs!", ghicire_numar(left, right));
	return 0;
}

//ex10

#include <stdio.h>
#include <stdlib.h>
int suma_v1_v2[20];
int r, s;
void suma(int* vector1, int* vector2, int lungime1, int lungime2, int lungime3)
{
	int i = lungime1 - 1, j = lungime2 - 1, k = lungime1 - 1;
	while (j >= 0)
	{
		s = vector1[i] + vector2[j] + r;
		suma_v1_v2[k] = s % 10;
		r = s / 10;
		suma(vector1, vector2, i--, j--, k--);
	}
	while (i >= 0)
	{
		s = vector1[i] + r;
		suma_v1_v2[k] = s % 10;
		r = s / 10;
		suma(vector1, vector2, i--, j, k);
	}
}

int main()
{
	int lungime_v1;
	int lungime_v2;
	printf("Lungimea primului vector ");
	scanf_s("%d", &lungime_v1);
	printf("Lungimea vectorului al doilea ");
	scanf_s("%d", &lungime_v2);
	int* vector1 = (int*)calloc(lungime_v1, sizeof(int));
	int* vector2 = (int*)calloc(lungime_v1, sizeof(int));
	printf("Cifrele primului vector ");
	for (int i = 0; i < lungime_v1; i++)
	{
		scanf_s("%d", &vector1[i]);
	}
	printf("Cifrele vectorului al doilea ");
	for (int i = 0; i < lungime_v2; i++)
	{
		scanf_s("%d", &vector2[i]);
	}
	if (lungime_v1 > lungime_v2)
	{
		suma(vector1, vector2, lungime_v1, lungime_v2, lungime_v1);
	}
	else if (lungime_v1 < lungime_v2)
	{
		suma(vector2, vector1, lungime_v2, lungime_v1, lungime_v2);
	}
	if (lungime_v1 > lungime_v2)
	{
		for (int i = 0; i <lungime_v1 ; i++)
		{
			printf("%d", suma_v1_v2[i]);
		}
	}
	else if (lungime_v1 < lungime_v2)
	{
		for (int i = 0; i <lungime_v2 ; i++)
		{
			printf("%d", suma_v1_v2[i]);
		}
	}
	return 0;
}

//ex11

#include <stdio.h>
#include <stdlib.h>
int citire_numere(int numar)
{
	if (numar % 2 == 0)
	{
		printf("%d ", numar);
	}
	if (numar == 0)
	{
		return 0;
	}
	else
	{
		scanf_s("%d", &numar);
		citire_numere(numar);
	}
	if (numar % 2 != 0)
	{
		printf("%d ", numar);
	}
}
int main()
{
	int numar;
	scanf_s("%d", &numar);
	citire_numere(numar);
	return 0;
}

//ex12

#include <stdio.h>
#include <stdlib.h>
int i, j;
int sort_insertie(int* vector, int lungime)
{
	if (i == lungime-1)
	{
		return 0;
	}
	else
	{
		i++;
		j = i - 1;
		int aux = vector[i];
		while (j >= 0 && aux < vector[j])
		{
			vector[j + 1] = vector[j];
			vector[j] = aux;
			j--;
		}
		sort_insertie(vector, lungime--);
	}

}
int main()
{
	int vector[] = { 5, 4, 3, 2 };
	int j = 0;
	int size = sizeof(vector) / sizeof(int);
	int n = sort_insertie(vector,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", vector[i]);
	}
}