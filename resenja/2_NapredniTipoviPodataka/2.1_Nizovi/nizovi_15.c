#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/* Funkcija razmenjuje najmanji i najveci element niza. */
void razmeni_min_max(int brojevi[], int n) {
  int i;
  /* Najvecim, kao i najmanjim elementom niza, proglasava se nulti
     element niza. Pozicije najveceg i najmanjeg elementa se
     postavljaju na 0. */
  int najveci = brojevi[0], najmanji = brojevi[0];
  int pozicija_najveceg = 0, pozicija_najmanjeg = 0;

  /* U prolazu kroz niz trazi se najveci i najmanji element i pamte 
     se njihove pozicije. */
  for (i = 1; i < n; i++) {
    if (brojevi[i] > najveci) {
      najveci = brojevi[i];
      pozicija_najveceg = i;
    }

    if (brojevi[i] < najmanji) {
      najmanji = brojevi[i];
      pozicija_najmanjeg = i;
    }
  }

  /* Zamenjuju se elementi na pozicijama pozicija_najmanjeg i
     pozicija_najveceg. */
  brojevi[pozicija_najveceg] = najmanji;
  brojevi[pozicija_najmanjeg] = najveci;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int brojevi[MAKS];
  int n;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(brojevi, n);

  /* Razmena najmanjeg i najveceg elementa. */
  razmeni_min_max(brojevi, n);

  /* Ispis rezultata. */
  printf("Rezultujuci niz:\n");
  ispisi(brojevi, n);

  exit(EXIT_SUCCESS);
}
