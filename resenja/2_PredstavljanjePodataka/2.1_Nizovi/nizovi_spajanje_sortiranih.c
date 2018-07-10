#include <stdio.h>

#define DIMENZIJA 100

/* Funkcija za ucitavanje niza. */
void unos(int niz[], int n)
{
	int i;

	printf("Uneti elemente sortiranog niza:\n");
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);
}

/* Funkcija za ispis niza. */
void ispis(int niz[], int n)
{
	int i;

	for(i=0; i<n; i++)
		printf("%d ", niz[i]);

	printf("\n");
}

int main()
{
	int a[DIMENZIJA], b[DIMENZIJA];
	/* Niz c moze biti duplo veci od nizova a i b, pa za njega treba odvojiti dupli prostor. */
	int c[2*DIMENZIJA];
	int m, n;
    /* Brojac u petlji za elemente niza a. */
	int i = 0;
    /* Brojac u petlji za elemente niza b. */
	int j = 0;
	/* Brojac u petlji za elemente niza c. */
	int k = 0;

	printf("Uneti broj elemenata niza: ");
	scanf("%d", &n);

	unos(a, n);
	unos(b, n);

	while(i<n && j<n)
	{
		/* Porede se elementi nizova a i b i u niz c upisuje se samo onaj koji je manji. */
	    if (a[i] < b[j])
		{
			c[k] = a[i];
			/* Kako element niza a je upisan u niz c, uvecava se brojac niza a.
               Eelement niza b nije upisan u niz c, te brojac za niz b ne treba uvecavati. */
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}

		/* U nizu c na poziciju k je upisan ili a[i] ili b[j].
           Brojac k se uvecava. */
		k++;
	}

	/* Ukoliko je ostalo elemenata u nizu a, upisuju se u niz c. */
	while(i < n)
	{
		c[k] = a[i];
		k++;
		i++;
	}

    /* Ukoliko je ostalo elemenata u nizu b, upisuju se u niz c. */
	while(j < n)
	{
		c[k] = b[j];
		k++;
		j++;
	}

	/* Ispis elemenata niza c cija dimenzija je zbir dimenzija nizova a i b. */
	ispis(c, 2*n);

	return 0;
}
