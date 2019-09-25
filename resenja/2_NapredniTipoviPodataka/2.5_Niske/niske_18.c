#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_NISKA 8

/* Funkcija racuna dekadnu vrednost jedne heksadekadne cifre. Ako
   je c dekadna cifra, vrednost se dobija oduzimanjem '0'. Ako je c 
   veliko slovo, vrednost se dobija oduzimanjem 'A' i dodavanjem 10 
   (npr. vrednost karaktera 'B' je 10 + 'B' - 'A' = 11). */
int vrednost_heksa_cifre(char c) {
  if (isdigit(c))
    return c - '0';
  else
    return 10 + toupper(c) - 'A';
}

/* Funkcija racuna dekadnu vrednost heksadekadnog broja. */
int dekadna_vrednost(char s[]) {
  int i, tezina_pozicije = 1, rezultat = 0;
  int n = strlen(s);

  /* Vrsi se prolazak kroz nisku sa desna na levo. Heksadekadna
     cifra najvece tezine se nalazi na poziciji n-1, a cifra najmanje
     tezine se nalazi na poziciji 2 (jer su prva dva karaktera 0x).

     U svakoj iteraciji, na rezultat se dodaje vrednost tekuce
     cifre pomnozene vrednoscu tezine njene pozicije. 
     Na primer, za s = "0x1a8e", n=6 
     i = 5, rezultat += vrednost('e')*1 => rezultat += 11*1 
     i = 4, rezultat += vrednost('8')*16 => rezultat += 8*16 
     i = 3, rezultat += vrednost('a')*256 => rezultat += 10*256 
     i = 2, rezultat += vrednost('1')*4096 => rezultat += 1*4096 */
  for (i = n - 1; i >= 2; i--) {
    rezultat += tezina_pozicije * vrednost_heksa_cifre(s[i]);
    tezina_pozicije *= 16;
  }
  
  /* II nacin: Koriscenjem Hornerove sheme.
  for (i = 2; i < n; i++)
    rezultat = rezultat * 16 + vrednost_heksa_cifre(s[i]); */

  return rezultat;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ispis rezultata. */
  printf("Rezultat: %d\n", dekadna_vrednost(s));

  exit(EXIT_SUCCESS);
}
