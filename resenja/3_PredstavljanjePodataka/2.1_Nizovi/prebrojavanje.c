#include <stdio.h>
#include <stdlib.h>

#define BROJ_CIFARA 10
#define DUZINA_ALFABETA 26

/* Funkcija za ispis elemenata niza. */
void ispis(int niz[], int n, char c)
{
  int i;
  for (i = 0; i < n; i++) {
    if (niz[i] != 0)
      printf("Karakter %c se pojavljuje %d puta\n", c + i, niz[i]);
  }
}

int main()
{
  /* Niz u kojem ce se cuvati informacije o pojavljivanju cifara. */
  int cifre[BROJ_CIFARA];

  /* Niz u kojem ce se cuvati informacije o pojavljivanju malih
     slova. */
  int mala_slova[DUZINA_ALFABETA];

  /* Niz u kojem ce se cuvati informacije o pojavljivanju velikih
     slova. */
  int velika_slova[DUZINA_ALFABETA];

  int c, i;

  /* Brojaci se na pocetku inicijalizuju nulama. */
  for (i = 0; i < BROJ_CIFARA; i++) {
    cifre[i] = 0;
  }
  for (i = 0; i < DUZINA_ALFABETA; i++) {
    mala_slova[i] = 0;
    velika_slova[i] = 0;
  }

  /* Ucitavaju se karakteri sve do kraja ulaza. */
  while ((c = getchar()) != EOF) {
    /* Ako je procitani karakter veliko slovo uvecava se broj
       pojavljivanja odgovarajuceg velikog slova. Indeks velikog
       slova u nizu se odredjuje oduzimanjem slova A. 
       Na taj nacin slovo 'A' ce imati indeks 0, slovo 'B' indeks
       1, itd.*/
    if (c >= 'A' && c <= 'Z') {
      velika_slova[c - 'A']++;
    } 
    else if (c >= 'a' && c <= 'z') {
    /* Ako je procitani karakter malo slovo uvecava se broj
       pojavljivanja odgovarajuceg malog slova. */
      mala_slova[c - 'a']++;
    }
    else if (c >= '0' && c <= '9'){
    /* Ako je procitani karakter cifra uvecava se broj
       pojavljivanja odgovarajuce cifre. */
      cifre[c - '0']++;
    }  
  }

  /* Ispisuju se trazene informacije. */
  ispis(cifre, BROJ_CIFARA, '0');
  ispis(mala_slova, DUZINA_ALFABETA, 'a');
  ispis(velika_slova, DUZINA_ALFABETA, 'A');

  exit(EXIT_SUCCESS);
}
