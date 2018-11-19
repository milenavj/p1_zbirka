#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAKS 500

/* Funkcija vraca 1 ukoliko broj x postoji u nizu, 0 inace. */
int postoji(int niz[], int n, int x)
{
  int i;
  for (i = 0; i < n; i++)
    if (niz[i] == x)
      return 1;

  return 0;
}

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int niz[], int n)
{
  int i, element;  
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &element);
    if(postoji(niz, i, element))
    {
      printf("Greska: skup ne moze imati duplikate.\n");
      exit(EXIT_FAILURE);
    }
    niz[i] = element;
  }
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS], unija[2 * MAKS], presek[MAKS],
      razlika[MAKS];
  int i, n_a, n_b, n_unija, n_presek, n_razlika;

  /* Ucitava se dimenzija prvog niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n_a);
  if (n_a <= 0 || n_a > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  ucitaj(a, n_a);
  
  /* Ucitava se dimenzija drugog niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n_b);
  if (n_b <= 0 || n_b > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  ucitaj(b, n_b);

  /* Brojaci elemenata u nizovima unija, presek i razlika. */
  n_unija = 0;
  n_presek = 0;
  n_razlika = 0;

  for (i = 0; i < n_a; i++) 
  {
    /* Svi elementi niza a se dodaju u uniju. */
      unija[n_unija] = a[i];
      n_unija++;

    /* Ukoliko se element a[i] nalazi u nizu b i ne postoji u nizu
       presek, dodaje se presek i povecava se brojac elemenata u
       nizu presek. */
    if (postoji(b, n_b, a[i]) == 1
        && postoji(presek, n_presek, a[i]) == 0) {
      presek[n_presek] = a[i];
      n_presek++;
    }

    /* Ukoliko element a[i] ne postoji u nizu b i ne postoji u nizu 
       razlika, dodaje se u razliku i povecava se brojac elemenata
       u nizu razlika. */
    if (postoji(b, n_b, a[i]) == 0
        && postoji(razlika, n_razlika, a[i]) == 0) {
      razlika[n_razlika] = a[i];
      n_razlika++;
    }
  }

  /* Elemente niza b koji nisu uneti u uniju dodaju se u uniju. */
  for (i = 0; i < n_b; i++)
  {
    if (postoji(unija, n_unija, b[i]) == 0) 
    {
      unija[n_unija] = b[i];
      n_unija++;
    }
  }
  /* Ispis rezultata. */
  printf("Unija: ");
  ispisi(unija, n_unija);
  
  printf("Presek: ");
  ispisi(presek, n_presek);
  
  printf("Razlika: ");
  ispisi(razlika, n_razlika);

  exit(EXIT_SUCCESS);
}
