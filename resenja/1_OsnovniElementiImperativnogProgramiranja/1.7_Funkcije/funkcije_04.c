#include <stdio.h>

/* Funkcija za dva neoznacena broja x i n utvrdjuje da li je x neki 
   stepen broja n. Ukoliko jeste, funkcija vraca izlozilac stepena, 
   a u suprotnom vraca -1. */
int je_stepen(unsigned int x, unsigned int n) {
  /* Na pocetku, s = n^i = n^1 = n. */
  int i = 1;
  unsigned int s = n;

  /* U svakoj iteraciji petlje s se azurira tako da ima vrednost
     n^i. Postupak se ponavlja dok je s manji od x. */
  while (s < x) {
    s = s * n;
    i++;
  }

  /* Kako s ima vrednost n^i, ako vazi da je s jednako x, onda je
     bas brojac i trazeni izlozilac. */
  if (s == x)
    return i;

  /* Ako nije, onda se vraca -1. */
  return -1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int x, n;
  int stepen;

  /* Ucitavanje vrednosti x i n. */
  printf("Unesite dva broja: ");
  scanf("%u%u", &x, &n);

  /* Poziv funkcije. */
  stepen = je_stepen(x, n);

  /* U zavisnosti od povratne vrednosti funkcije, vrsi se ispis
     rezultata. */
  if (stepen != -1)
    printf("Jeste: %u=%u^%d\n", x, n, stepen);
  else
    printf("Broj %u nije stepen broja %u.\n", x, n);

  return 0;
}
