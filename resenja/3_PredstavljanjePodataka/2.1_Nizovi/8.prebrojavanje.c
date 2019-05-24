#include <stdio.h>
#include <stdlib.h>

#define BROJ_CIFARA 10
#define DUZINA_ALFABETA 26

/* Pomocna funkcija za ispis elemenata niza.
   Vrednost n oznacava broj elemenata niza 
   (ima vrednost 10 ili 26).
   Karakter c oznacava prvi karakter za datu kategoriju
   ('a' za mala slova, 'A' za velika i '0' za cifre). */
void ispisi(int niz[], int n, char c) {
  int i;
  for (i = 0; i < n; i++) 
    if (niz[i] != 0)
      printf("Karakter %c se pojavljuje %d puta\n", c + i, niz[i]);
}

/* Funkcija inicijalizuje niz postavljajuci vrednosti svih
   elemenata na nulu. */
void inicijalizuj(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    niz[i] = 0;
}

int main() {
  /* Deklaracije nizova brojaca za cifre, mala i velika slova. */
  int cifre[BROJ_CIFARA];
  int mala_slova[DUZINA_ALFABETA];
  int velika_slova[DUZINA_ALFABETA];
  
  /* Deklaracije pomocnih promenljivih. */
  int c;
  
  /* Inicijalizacije brojaca nulama. */
  inicijalizuj(cifre, BROJ_CIFARA);
  inicijalizuj(mala_slova, DUZINA_ALFABETA);
  inicijalizuj(velika_slova, DUZINA_ALFABETA);
  
  /* Ucitavanje karaktera sve do kraja ulaza. */
  printf("Unesite tekst:\n");
  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z') {
      /* Ako je procitani karakter veliko slovo uvecava se broj
       pojavljivanja odgovarajuceg velikog slova. Indeks velikog
       slova u nizu se odredjuje oduzimanjem slova A. 
       Na taj nacin slovo 'A' ce imati indeks 0, slovo 'B' indeks
       1, itd.*/
      velika_slova[c - 'A']++;
    } else if (c >= 'a' && c <= 'z') {
    /* Ako je procitani karakter malo slovo uvecava se broj
       pojavljivanja odgovarajuceg malog slova. */
      mala_slova[c - 'a']++;
    } else if (c >= '0' && c <= '9') {
    /* Ako je procitani karakter cifra uvecava se broj
       pojavljivanja odgovarajuce cifre. */
      cifre[c - '0']++;
    }  
  }

  /* Ispis trazenih informacija. */
  ispisi(cifre, BROJ_CIFARA, '0');
  ispisi(mala_slova, DUZINA_ALFABETA, 'a');
  ispisi(velika_slova, DUZINA_ALFABETA, 'A');

  exit(EXIT_SUCCESS);
}
