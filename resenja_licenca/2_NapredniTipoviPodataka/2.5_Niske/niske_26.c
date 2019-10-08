/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija obrce nisku s. */
void obrni(char s[]) {
  int i, j;
  int n = strlen(s);
  char c;

  /* Brojac i ide od prvog karaktera niske s, a brojac j od
     poslednjeg i dok god se ne sretnu, vrsi se zamena karaktera
     koji se nalaze na njihovim pozicijama. */
  for (i = 0, j = n - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Racunanje i ispis rezultata. */
  obrni(s);
  printf("Rezultat: %s\n", s);

  exit(EXIT_SUCCESS);
}
