#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS_STEPEN 10
#define MAKS_POLINOMA 100

typedef struct {
  int stepen;
  float koef[MAKS_STEPEN + 1];
} Polinom;

/* Funkcija ucitava podatke o polinomima. */
int ucitaj(Polinom niz[]) {
  int i = 0, j;

  while (i < MAKS_POLINOMA) {
    printf("Unesite stepen: ");
    if (scanf("%d", &(niz[i].stepen)) == EOF)
      break;

    if (niz[i].stepen > MAKS_STEPEN || niz[i].stepen < 0) {
      printf("Greska: neispravan unos stepena.\n");
      exit(EXIT_FAILURE);
    }

    printf("Unesite koeficijente polinoma:\n");
    for (j = 0; j <= niz[i].stepen; j++)
      scanf("%f", &(niz[i].koef[j]));

    i++;
  }
  
  return i;
}

/* Prvi monom je specijalan jer se ispred njega ne vrsi eksplicitan 
   ispis znaka. Na primer, za polinom x + 3*x^2, prvi monom je x.
   Svakom sledecem monomu (u ovom slucaju samo 3*x^2) u ispisu
   prethodi znak (+ ili -). Funkcija ispisuje prvi monom. */
void ispis_prvog_monoma(float koef, int stepen) {
  printf("%.2f", koef);

  if (stepen == 1)
    printf("*x ");
  else if (stepen > 1)
    printf("*x^%d ", stepen);
}

/* Funkcija ispisuje monom koji nije prvi. */
void ispis_monoma(float koef, int stepen) {
  /* Monomi ciji je koeficijent nula se ne ispisuju. */
  if (koef != 0) {
    /* Ispis znaka. */
    if (koef > 0)
      printf("+ ");
    else
      printf("- ");

    /* Ispis koeficijenta. */
    printf("%.2f", fabs(koef));

    /* Ispis ostatka. */
    if (stepen == 1)
      printf("*x ");
    else if (stepen > 1)
      printf("*x^%d ", stepen);
  }
}

/* Funkcija ispisuje ceo polinom p. */
void ispis(const Polinom *p) {
  int i;

  /* Vrsi se ispis prvog monoma. Posto je moguce da prvi monom ima
     koeficijent 0, trazi se prvi monom sa koeficijentom razlicitim
     od nule. */
  for (i = 0; i <= p->stepen; i++)
    if (p->koef[i] != 0) {
      ispis_prvog_monoma(p->koef[i], i);
      i++;
      break;
    }

  /* Ispis ostalih monoma. Nastavlja se od mesta gde se stalo u
     prethodnoj petlji i iz tog razloga je preskocen korak
     inicijalizacije brojaca i. */
  for (; i <= p->stepen; i++)
    ispis_monoma(p->koef[i], i);

  printf("\n");
}

/* Funkcija racuna integral polinoma p. */
void integral(const Polinom *p, Polinom *tekuci_integral) {
  int i;

  tekuci_integral->stepen = p->stepen + 1;
  tekuci_integral->koef[0] = 0;

  for (i = 1; i <= tekuci_integral->stepen; i++)
    tekuci_integral->koef[i] = (float) p->koef[i - 1] / i;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  Polinom polinomi[MAKS_POLINOMA], tekuci_integral;
  int n, i;

  /* Ucitavanje polinoma. */
  n = ucitaj(polinomi);

  /* Ispis integrala. */
  printf("\n\nIntegrali su:\n");
  for (i = 0; i < n; i++) {
    integral(&polinomi[i], &tekuci_integral);
    ispis(&tekuci_integral);
  }

  return 0;
}
