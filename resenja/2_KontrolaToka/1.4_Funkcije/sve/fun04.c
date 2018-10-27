#include <stdio.h>

/* Funkcija za dva neoznacena broja x i n utvrdjuje da li je
   x neki stepen broja n. Ukoliko jeste, funkcija vraca izlozilac
   stepena, a u suprotnom vraca -1. */
int je_stepen(unsigned int x, unsigned int n)
{
  /* Na pocetku, s = n^i = n^1 = n. */
  int i = 1;
  unsigned int s = n;

  /* U svakoj iteraciji petlje, s se azurira tako da ima
     vrednost n^i. Postupak se ponavlja dok je s manji od x. */
  while (s < x) {
    s = s * n;
    i++;
  }

  /* Kako s ima vrednost n^i, ako vazi da je s jednako x, onda
     je bas brojac i trazeni izlozilac. */
  if (s == x)
    return i;

  /* Ako nije, onda se vraca -1. */
  return -1;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int x, n;
  int st;

  /* Ucitavaju se vrednosti x i n. */
  printf("Unesite dva broja: ");
  scanf("%u%u", &x, &n);

  /* Poziva se napisana funkcija. */
  st = je_stepen(x, n);

  /* U zavisnosti od povratne vrednosti funkcije, vrsi se
     ispis rezultata. */
  if (st != -1)
    printf("%u=%u^%d\n", x, n, st);
  else
    printf("%u nije stepen broja %u\n", x, n);

  return 0;
}
