//vapoate. nume, culoare, an fabricatie, categorie(de croaziera=nr clase & de marfa=capacitate). 
//citire, afisare, cautare dupa capacitate, dupa an, dupa nume, sortare dupa nume, stergere dupa culoare, matrice dp an fab

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char nume[50], culoare[50], categorie[50];
	int an_fab, nr_clase, capac;
}vapoare;
void citire(vapoare *v, int *n)
{
	(*n)++;
	printf("nume: ");
	scanf("%s", (v + *n)->nume);
	printf("culoare: ");
	scanf("%s", (v + *n)->culoare);
	printf("anul fabricatiei: ");
	scanf("%d", &(v + *n)->an_fab);
	printf("categorie: ");
	scanf("%s", (v + *n)->categorie);
	if(strcmp((v + *n)->categorie, "croaziera") == 0)
	{
		printf("nr clase: ");
		scanf("%d", &(v + *n)->nr_clase);
	}
	else
		if(strcmp((v + *n)->categorie, "marfa") == 0)
		{
			printf("capacitate: ");
			scanf("%d", &(v + *n)->capac);
		}
}
void afisare(vapoare *v, int n)
{
	if(strcmp((v + n)->categorie, "croaziera") == 0)
		printf("%s %s %d %s %d\n", (v + n)->nume, (v + n)->culoare, (v + n)->an_fab, (v + n)->categorie, (v + n)->nr_clase);
	else
		if(strcmp((v + n)->categorie, "marfa") == 0)
			printf("%s %s %d %s %d\n", (v + n)->nume, (v + n)->culoare, (v + n)->an_fab, (v + n)->categorie, (v + n)->capac);
}
void cautare_capacitate(vapoare *v, int *n, int cap)
{
	int i;
	for(i=0; i<=*n; i++)
		if((v + i)->capac == cap)
			afisare(v, i);
}
void cautare_an_fab(vapoare *v, int *n, int an)
{
	int i;
	for(i=0; i<=*n; i++)
		if((v + i)->an_fab == an)
			afisare(v, i);
}
void cautare_nume(vapoare *v, int *n, char num[])
{
	int i;
	for(i=0; i<=*n; i++)
		if(strcmp((v + i)->nume, num) == 0)
			afisare(v, i);
}
void sortare(vapoare *v, int *n)
{
	int i=0, k=0;
	vapoare aux;
	do
	{
		k=1;
		for(i=0; i<=*n; i++)
		if(strcmp((v + i)->nume, (v + i + 1)->nume) > 0)
			{
				aux = *(v + i);
				*(v + i) = *(v + i + 1);
				*(v + i + 1) = aux;
				k=0;
			}
	}while(!k);
}
void steregere(vapoare *v, int *n, char c[])
{
	int i, j, k=0;
	for(i=0; i<= (*n-k); i++)
		if(strcmp((v + i)->culoare, c) == 0)
		{
			k++;
			for(j=i; j<=(*n-k); j++)
				*(v + j) = v[j+ 1];
			i--;
		}
		*n = *n - k;
}
void matrice(vapoare *v, int *n)
{
	int i, j, a[10][10];
	for(i=0; i<=*n; i++)
		for(j=0; j<=*n; j++)
		{
			if(i == j)
				a[i][j] = (v + i)->an_fab;
			else
				a[i][j] = 0;
		}
		for(i=0; i<=*n; i++)
		{
			for(j=0; j<=*n; j++)
				printf("%d", a[i][j]);
			printf("\n");
		}
}
int main ()
{
	vapoare v[50];
	char num[50], culoare[50], categorie[50];
	int optiune, i, n=-1, an, cap;
	do
	{
		printf("1. citire\n");
		printf("2. afisare\n");
		printf("3. cautare dupa capacitate\n");
		printf("4. cautare dupa anul fabricatiei\n");
		printf("5. cautare dupa nume\n");
		printf("6. sortare dupa nume\n");
		printf("7. stergere dupa culoare\n");
		printf("8. matricea cu anul fabricatie\n");
		printf("0. iesire\n");
		printf("optiunea dvs este: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 1: citire(&v[0], &n);
			break;
		case 2: for(i=0; i<=n; i++)
					afisare(v, i);
			break;
		case 3: printf("capacitatea: ");
			scanf("%d", &cap);
			cautare_capacitate(&v[0], &n, cap);
			break;
		case 4: printf("anul fabricatie: ");
			scanf("%d", &an);
			if(an > 2020)
				printf("anul cautat nu exista, mai asteptati!");
			else
			cautare_an_fab(&v[0], &n, an);
			break;
		case 5: printf("numele vaporului: ");
			scanf("%s", num);
			cautare_nume(&v[0], &n, num);
			break;
		case 6: sortare(&v[0], &n);
			for(i=0; i<=n; i++)
				afisare(v, i);
			break;
		case 7: printf("culoare: ");
			scanf("%s", culoare);
			steregere(&v[0], &n, culoare);
			for(i=0; i<=n; i++)
				afisare(v, i);
			break;
		case 8: matrice(&v[0], &n);
			break;
		case 0: exit(0);
			break;
		default: printf("optiune gresita!\n");
			break;
		}
	} while(optiune != 0);
	return 0;
}