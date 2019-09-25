#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

/* Funkcija formira niz c ukrstanjem nizova a i b. */
void ukrsti(int a[], int b[], int n, int c[]) {
  int i, j;
  /* Formira se treci niz. Koriste se dva indeksa: indeks i
     pomocu kojeg se pristupa elementima nizova a i b i koji treba
     uvecati za 1 nakon svake iteracije i indeks j pomocu kojeg se
     pristupa elementima rezultujuceg niza c; s obzirom da se u
     svakoj iteraciji u niz c smestaju dva elementa, jedan iz niza
     a i jedan iz niza b, indeks j se uvecava za 2 nakon svake
     iteracije. */
  for (i = 0, j = 0; i < n; i++, j += 2) {
    c[j] = a[i];
    c[j + 1] = b[i];
  }
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS], c[2 * MAKS];
  int n;

  /* Ucitavanje dimenzije nizova i provera ispravnosti ulaza. */
  printf("Unesite dimenziju nizova: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata nizova. */
  printf("Unesite elemente niza a: ");
  ucitaj(a, n);
  printf("Unesite elemente niza b: ");
  ucitaj(b, n);

  /* Formiranje niza c. */
  ukrsti(a, b, n, c);

  /* Ispis elemenata rezultujuceg niza. */
  printf("Rezultujuci niz:\n");
  ispisi(c, 2 * n);

  exit(EXIT_SUCCESS);
}
