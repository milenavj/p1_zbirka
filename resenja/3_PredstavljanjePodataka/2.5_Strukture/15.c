#include <stdio.h>
#include <stdlib.h>

#define STEPEN 10
#define MAX_POLINOMA 100

typedef struct
{
	int  stepen;
	float koef[STEPEN+1];
}_polinom;

int ucitaj(_polinom* p)
{
	int i;

	printf("Uneti stepen: ");
	if (scanf("%d", &(p->stepen)) == EOF)
		return 0;

	if (p->stepen > STEPEN || p->stepen < 0)
	{
		printf("Greska u unosu stepena.\n");
		exit(EXIT_FAILURE);
	}

	printf("Uneti koeficijente polinoma:\n");
	for(i=0; i<=p->stepen; i++)
		scanf("%f", &(p->koef[i]));

	return 1;
}

int ispis_prvog_monoma(float koef, int stepen)
{
	if (koef != 0)
	{
		printf("%.2f", koef);
		
		if (stepen == 1)
			printf("*x ");
		else if (stepen > 1)
			printf("*x^%d ", stepen);

		return 1;
	}
	else
		return 0;
}

void ispis_monoma(float koef, int stepen)
{
	if (koef != 0)
	{
		if (koef > 0)
			printf("+ ");

		printf("%.2f", koef);
		
		if (stepen == 1)
			printf("*x ");
		else if (stepen > 1)
			printf("*x^%d ", stepen);
	}
}

void ispis(const _polinom *p)
{
	int prvi = 1;
	int i;

	for(i=0; i <= p->stepen; i++)
		if (prvi)
		{
			prvi = !ispis_prvog_monoma(p->koef[i], i);
		}
		else
			ispis_monoma(p->koef[i], i);

	printf("\n");
}

void integral(const _polinom* p, _polinom* integ)
{
	int i;

	integ->stepen = p->stepen + 1;

	integ->koef[0] = 0;

	for(i=1; i <= integ->stepen; i++)
		integ->koef[i] = (float)p->koef[i-1]/i;

}

int main()
{
	_polinom p[MAX_POLINOMA], integ;
	int i = 0, j;

	while(ucitaj(&p[i]))
		i++;

	printf("\n\nIntegrali su:\n");
	for(j=0; j<i; j++)
	{
		integral(&p[j], &integ);
		ispis(&integ);
	}

	return 0;
}
