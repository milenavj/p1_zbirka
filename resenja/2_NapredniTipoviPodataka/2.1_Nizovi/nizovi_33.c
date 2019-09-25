#include <stdio.h>
#include <stdlib.h>

#define MAKS 700

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

/* Funkcija pomera za jedno mesto u levo elemente niza a pocevsi od 
   pozicije j. Element na poziciji j se brise i na njegovo mesto se 
   upisuje element na poziciji j+1, a u skladu sa tim svi ostali
   elementi posle njega u nizu se pomeraju. */
void pomeri_za_jedno_mesto(int a[], int n, int j) {
  int i;
  for (i = j; i < n - 1; i++)
    a[i] = a[i + 1];
}

/* Funkcija brise sve elemente niza koji nisu deljivi svojim
   indeksom. Povratna vrednost funkcije je broj elemenata
   rezultujuceg niza. */
int brisanje(int niz[], int n) {
  int i;

  /* Potrebno je krenuti od poslednjeg elementa niza i petljom ici
     ka pocetku niza (element na poziciji 0 se ne razmatra).
     Proverava se da li je element potrebno obrisati i ako jeste
     vrsi se pomeranje elemenata niza za jedno mesto u levo.
     Prednost ovog resenja u odnosu na resenje kada se krene od
     pocetka niza je u tome sto element koji se ispituje sigurno
     nije promenio svoju poziciju usled pomeranja zbog brisanja.
     Problem se moze resiti i koriscenjem pomocnog niza (uraditi za 
     vezbu). To resenje je efikasnije, ali trosi vise resursa. */
  for (i = n - 1; i > 0; i--)
    if (niz[i] % i != 0) {
      pomeri_za_jedno_mesto(niz, n, i);
      /* Nakon brisanja elementa, smanjuje se i dimenzija niza. */
      n--;
    }

  return n;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, niz[MAKS];

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(niz, n);

  /* Brisanje trazenih elemenata. */
  n = brisanje(niz, n);

  /* Ispis rezultujuceg niza. */
  printf("Rezultujuci niz:\n");
  ispisi(niz, n);

  exit(EXIT_SUCCESS);
}
