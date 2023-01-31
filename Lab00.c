//Laborator 0

//ex1
#include <stdio.h>
void afisare(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
}
int main()
{
	int numar;
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	afisare(numar);
	printf("Introduceti un alt numar ");
	scanf_s("%d", &numar);
	afisare(numar);
	printf("Introduceti un alt numar ");
	scanf_s("%d", &numar);
	afisare(numar);
	return 9;
}

//ex2
#include <stdio.h>
int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
	int numar, i;
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	for (i = 0; i < numar; i++)
	{
		printf("%d ", Fibonacci(i));
	}
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	for (i = 0; i < numar; i++)
	{
		printf("%d ", Fibonacci(i));
	}
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	for (i = 0; i < numar; i++)
	{
		printf("%d ", Fibonacci(i));
	}
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	for (i = 0; i <= numar; i++)
	{
		printf("%d ", Fibonacci(i));
	}
	return 0;
}

//ex3
#include <stdio.h>
void divizori (int n)
{
	int k=0, i;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			k++;
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("Numarul de divizori este %d", k);
}
int main()
{
	int numar;
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	divizori(numar);
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	divizori(numar);
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	divizori(numar);
	return 0;
}

//ex4
#include <stdio.h>
int invers(int n)
{
	int rev=0;
	while (n != 0)
	{
		rev = rev * 10 + n % 10;
		n = n / 10;
	}
	return rev;
}
int main()
{
	int numar;
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	printf("%d", invers(numar));
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	printf("%d", invers(numar));
	printf("\n");
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	printf("%d", invers(numar));
	return 0;
}

//ex5
#include <stdio.h>
int arie(int n)
{
	return n * n;
}
int main()
{
	int numar;
	printf("Introduceti latura patratului ");
	scanf_s("%d", &numar);
	printf("Aria patratului este %d", arie(numar));
	printf("\n");
	printf("Introduceti latura patratului ");
	scanf_s("%d", &numar);
	printf("Aria patratului este %d", arie(numar));
	printf("\n");
	printf("Introduceti latura patratului ");
	scanf_s("%d", &numar);
	printf("Aria patratului este %d", arie(numar));
	return 0;
}

//ex6
#include <stdio.h>
#include <math.h>
void ecuatie(int a, int b, int c)
{
	float delta, x1, x2;
	if (a == 0)
	{
		 printf("Nu este ecuatie de gradul 2");
	}
	else 
	{
		delta = b * b - 4 * a * c;
		if (delta == 0)
		{
			x1 = -b / 2 * a;
			printf("x = %f", x1);
		}
		else if (delta > 0)
		{
			x1 = (-b + sqrt(delta)) / 2 * a;
			x2 = (-b - sqrt(delta)) / 2 * a;
			printf("x1 = %f, x2 = %f", x1, x2);
		}
		else
			printf("x nu este numar real");
	}
}
int main()
{
	int a, b, c;
	printf("Introduceti coeficientii ecuatiei \n");
	printf("a= ");
	scanf_s("%d", &a);
	printf("b= ");
	scanf_s("%d", &b);
	printf("c= ");
	scanf_s("%d", &c);
	ecuatie(a, b, c);
	printf("\n");
	printf("Introduceti coeficientii ecuatiei \n");
	printf("a= ");
	scanf_s("%d", &a);
	printf("b= ");
	scanf_s("%d", &b);
	printf("c= ");
	scanf_s("%d", &c);
	ecuatie(a, b, c);
	printf("\n");
	printf("Introduceti coeficientii ecuatiei \n");
	printf("a= ");
	scanf_s("%d", &a);
	printf("b= ");
	scanf_s("%d", &b);
	printf("c= ");
	scanf_s("%d", &c);
	ecuatie(a, b, c);
	return 0;
}

//ex7
#include <stdio.h>
void triunghi(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d ", j);
		}
	printf("\n");
	}
}
int main()
{
	int numar;
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	triunghi(numar);
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	triunghi(numar);
	printf("Introduceti un numar ");
	scanf_s("%d", &numar);
	triunghi(numar);
	return 0;
}

//ex8
#include <stdio.h>
#include <string.h>
int vocale(char s[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u')
		{
			k++;
		}
	}
	return k;
}
int main()
{
	char s[50];
	printf("Introduceti sirul de caractere ");
	fgets(s, sizeof(s), stdin);
	int n = strlen(s);
	printf("Numarul de vocale din sir este %d\n", vocale(s, n));
	printf("Introduceti sirul de caractere ");
	fgets(s, sizeof(s), stdin);
	n = strlen(s);
	printf("Numarul de vocale din sir este %d\n", vocale(s, n));
	printf("Introduceti sirul de caractere ");
	fgets(s, sizeof(s), stdin);
	n = strlen(s);
	printf("Numarul de vocale din sir este %d", vocale(s, n));
	return 0;
}

//ex9
#include <stdio.h>
#include <stdlib.h>
int matrice[20][20];
void citire(int matrice[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &matrice[i][j]);
		}
	}
}
void afisare(int matrice[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
int maxim(int n, int m, int* poz_rand, int* poz_col, int matrice[][20])
{
	int maxim = matrice[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrice[i][j] > maxim)
			{
				maxim = matrice[i][j];
				*poz_rand = i;
				*poz_col = j;

			}
		}
	}
	return maxim;
}
int main()
{
	int nr_randuri, nr_coloane;
	printf("Numarul de randuri ");
	scanf_s("%d", &nr_randuri);
	printf("Numarul de coloane ");
	scanf_s("%d ", &nr_coloane);
	citire(matrice, nr_randuri, nr_coloane);
	afisare(matrice, nr_randuri, nr_coloane);
	int poz_rand = -1, poz_col = -1;
	maxim(nr_randuri, nr_coloane, &poz_rand, &poz_col, matrice);
	printf("Maximul matricei este %d si se afla in randul %d, coloana %d ", maxim(nr_randuri, nr_coloane, &poz_rand, &poz_col, matrice), poz_rand, poz_col);
	return 0;
}

//ex9 alocare dinamica
#include <stdio.h>
#include <stdlib.h>
void citire(int** matrice, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &matrice[i][j]);
		}
	}
}
void afisare(int** matrice, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
int maxim(int n, int m, int*poz_rand, int *poz_col, int**matrice)
{
	int maxim = matrice[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrice[i][j] > maxim)
			{
				maxim = matrice[i][j];
				*poz_rand = i;
				*poz_col = j;

			}
		}
	}
	return maxim;
}
int main()
{
	int nr_randuri, nr_coloane;
	printf("Numarul de randuri ");
	scanf_s("%d", &nr_randuri);
	printf("Numarul de coloane ");
	scanf_s("%d ", &nr_coloane);
	int** matrice;
	matrice = (int**)calloc(nr_randuri, sizeof(int*));
	for (int i = 0; i < nr_randuri; i++)
	{
		matrice[i] = (int*)calloc(nr_randuri, sizeof(int));
	}
	citire(matrice, nr_randuri, nr_coloane);
	afisare(matrice, nr_randuri, nr_coloane);
	int poz_rand=-1, poz_col=-1;
	maxim(nr_randuri, nr_coloane, &poz_rand, &poz_col, matrice);
	printf("Maximul matricei este %d si se afla in randul %d, coloana %d ", maxim(nr_randuri, nr_coloane, &poz_rand, &poz_col, matrice), poz_rand, poz_col);
	for (int i = 0; i < nr_randuri; i++)
	{
		free(matrice[i]);
	}
	free(matrice);
	return 0;
}

//ex10 
#include <stdio.h>
int matrice1[20][20], matrice2[20][20], sum[20][20], dif[20][20], prod[20][20];
void citire(int matrice[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &matrice[i][j]);
		}
	}
}
void afisare(int matrice[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
void suma(int sum[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
}
void diferenta(int dif[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dif[i][j] = matrice1[i][j] - matrice2[i][j];
		}
	}
}
void produs(int prod[][20], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			prod[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				prod[i][j] = prod[i][j]+matrice1[i][k] * matrice2[k][j];
			}
		}
	}
}
int main()
{
	int row, col;
	printf("Nr randuri ");
	scanf_s("%d", &row);
	printf("Nr coloane ");
	scanf_s("%d", &col);
	printf("Prima matrice\n");
	citire(matrice1, row, col);
	printf("A doua matrice\n");
	citire(matrice2, row, col);
	printf("Prima matrice\n");
	afisare(matrice1, row, col);
	printf("A doua matrice\n");
	afisare(matrice2, row, col);
	suma(sum, row, col);
	printf("Suma este\n");
	afisare(sum, row, col);
	diferenta(dif, row, col);
	printf("Diferenta este\n");
	afisare(dif, row, col);
	produs(prod, row, col);
	printf("Produsul este\n");
	afisare(prod, row, col);
	return 0;
}

//ex10 alocare dinamica
#include <stdio.h>
#include <stdlib.h>
void citire(int** matrice, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &matrice[i][j]);
		}
	}
}
void afisare(int** matrice, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
void suma(int** sum, int n, int m, int** matrice1, int** matrice2)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
}
void diferenta(int** dif, int n, int m, int** matrice1, int** matrice2)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dif[i][j] = matrice1[i][j] - matrice2[i][j];
		}
	}
}
void produs(int** prod, int n, int m, int** matrice1, int** matrice2)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			prod[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				prod[i][j] = prod[i][j] + matrice1[i][k] * matrice2[k][j];
			}
		}
	}
}
int main()
{
	int row, col;
	printf("Nr randuri ");
	scanf_s("%d", &row);
	printf("Nr coloane ");
	scanf_s("%d", &col);
	int** matrice1;
	matrice1 = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		matrice1[i] = (int*)calloc(row, sizeof(int));
	}
	int** matrice2;
	matrice2 = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		matrice2[i] = (int*)calloc(row, sizeof(int));
	}
	int** sum;
	sum = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		sum[i] = (int*)calloc(row, sizeof(int));
	}
	int** dif;
	dif = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		dif[i] = (int*)calloc(row, sizeof(int));
	}
	int** prod;
	prod = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		prod[i] = (int*)calloc(row, sizeof(int));
	}
	printf("Prima matrice\n");
	citire(matrice1, row, col);
	printf("A doua matrice\n");
	citire(matrice2, row, col);
	printf("Prima matrice\n");
	afisare(matrice1, row, col);
	printf("A doua matrice\n");
	afisare(matrice2, row, col);
	suma(sum, row, col, matrice1, matrice2);
	printf("Suma este\n");
	afisare(sum, row, col);
	diferenta(dif, row, col, matrice1, matrice2);
	printf("Diferenta este\n");
	afisare(dif, row, col);
	produs(prod, row, col, matrice1, matrice2);
	printf("Produsul este\n");
	afisare(prod, row, col);
	int i;
	for (i = 0; i < row; i++)
	{
		free(matrice1[i]);
	}
	free(matrice1);
	for (i = 0; i < row; i++)
	{
		free(matrice2[i]);
	}
	free(matrice2);
	for (i = 0; i < row; i++)
	{
		free(sum[i]);
	}
	free(sum);
	for (i = 0; i < row; i++)
	{
		free(dif[i]);
	}
	free(dif);
	for (i = 0; i < row; i++)
	{
		free(prod[i]);
	}
	free(prod);
	return 0;
}

//ex11
#include <stdio.h>
int matrice[20][20];
int diagonala[20];
void citire(int matrice[][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &matrice[i][j]);
		}
	}
}
void afisare(int matrice[][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
void diagonala_principala(int matrice[][20], int n, int diag[20])
{
	int k = 0, i;
	for ( i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				diag[k] = matrice[i][j];
				k++;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", diag[i]);
	}
}
void diagonala_secundara(int matrice[][20], int n, int diag[20])
{
	int k = 0, i;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == n- 1)
			{
				diag[k] = matrice[i][j];
				k++;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", diag[i]);
	}
}
int main()
{
	int n;
	printf("Nr randuri si coloane ");
	scanf_s("%d", &n);
	printf("Introduceti elementele matricei ");
	citire(matrice, n);
	printf("Matricea este\n");
	afisare(matrice, n);
	printf("Elementele de pe diagonala principala sunt ");
	diagonala_principala(matrice, n, diagonala);
	printf("Elementele de pe diagonala secundara sunt ");
	diagonala_secundara(matrice, n, diagonala);
	return 0;
}