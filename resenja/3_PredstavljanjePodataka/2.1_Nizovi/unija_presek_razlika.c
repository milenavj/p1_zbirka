#include <stdio.h>

#define MAX 500

/* Ucitavanje dimenzije i elemenata niza. */
int ucitavanje(int niz[])
{
	int i, n;

	printf("Unesite dimenziju niza: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		exit(EXIT_FAILURE);
	}

	printf("Unesite elemente niza: ");
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);

	return n;
}

/* Funkcija koja vraca 1 ukoliko broj x postoji u nizu, 0 inace. */
int postoji(int niz[], int n, int x)
{
  int i;

  for(i=0;i<n;i++)
    if(niz[i] == x)
      return 1;

  return 0;
}

int main()
{
  int a[MAX], b[MAX], unija[2*MAX], presek[MAX], razlika[MAX];
  int i, j, n_a, n_b, n_u, n_p, n_r, indikator;

  /* Unose se dva niza. */
  n_a = ucitavanje(a);
  n_b = ucitavanje(b);

  /* Brojaci elemenata u nizovima unija, presek i razlika. */
  n_u = 0;
  n_p = 0;
  n_r = 0;

  for(i=0;i<n_a;i++)
  {
    /*  Ukoliko se element a[i] ne nalazi u uniji, dodaje se u uniju i povecaca se brojac elemenata u nizu unija. */
    if(postoji(unija,n_u,a[i]) == 0)
    {
      unija[n_u] = a[i];
      n_u++;
    }

    /* Ukoliko se element a[i] nalazi u nizu b i ne postoji u nizu presek, dodaje se presek i povecava se brojac elemenata u nizu presek. */
    if(postoji(b, n_b, a[i])==1 && postoji(presek, n_p, a[i])==0)
    {
      presek[n_p] = a[i];
      n_p++;
    }

    /* Ukoliko element a[i] ne postoji u nizu b i ne postoji u nizu razlika, dodaje se u razliku i povecava se brojac elemenata u nizu razlika. */
    if(postoji(b, n_b, a[i])==0 && postoji(razlika, n_r, a[i])==0)
    {
      razlika[n_r] = a[i];
      n_r++;
    }
  }

  /* Elemente niza b koji nisu uneti u uniju dodaju se u uniju. */
  for(i=0;i<n_b;i++)
    if(postoji(unija, n_u, b[i]))
    {
      unija[n_u] = b[i];
      n_u++;
    }

  printf("Unija: ");
  for(i=0;i<n_u;i++)
    printf("%d ", unija[i]);

  printf("\nPresek: ");
  for(i=0;i<n_p;i++)
    printf("%d ", presek[i]);

  printf("\nRazlika: ");
  for(i=0;i<n_r;i++)
    printf("%d ", razlika[i]);

  return 0;
}
