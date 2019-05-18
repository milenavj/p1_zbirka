#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija od niza a formira dva niza: niz parnih elemenata
   niza a i niz neparnih elemenata niza a. Duzine rezultujucih
   nizova se upisuju na adrese np i nn. */
void par_nepar(int a[], int n, int parni[], int *np,
               int neparni[], int *nn) {
  int i, j, k;

  /* Promenljiva i je brojac u originalnom nizu i on se uvecava u
     svakoj iteraciji. Promenljiva j je projac za niz parnih
     brojeva i on treba da se uveca svaki put kada se naidje na
     novi element ovog niza. Promenljiva k je brojac za niz
     neparnih brojeva i on treba da se uveca sveki put kada se
     naidje na novi element ovog niza. */
  for (i = 0, j = 0, k = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      parni[j] = a[i];
      j++;
    } else {
      neparni[k] = a[i];
      k++;
    }
  }

  /* Na kraju petlje, u promenljivoj j se nalazi podatak o broju
     elementa niza parni[], a u promenljivoj k podatak o broju
     elementa niza neparni[]. Ove vrednosti se upisuju na adrese np 
     i nn. */
  *np = j;
  *nn = k;
}

/* Funkcija ispisuje elemente niza. */
void ispisi(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, n1, n2, i;
  int a[MAKS], parni[MAKS], neparni[MAKS];

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  /* Popunjavanje rezultujucih nizova odgovarajucim
     vrednostima. */
  par_nepar(a, n, parni, &n1, neparni, &n2);

  /* Ispis niza parni[] koji ima n1 elemenata. */
  printf("Niz parnih brojeva: ");
  ispisi(parni, n1);

  /* Ispis niza neparni[] koji ima n2 elemenata. */
  printf("Niz neparnih brojeva: ");
  ispisi(neparni, n2);

  exit(EXIT_SUCCESS);
}
