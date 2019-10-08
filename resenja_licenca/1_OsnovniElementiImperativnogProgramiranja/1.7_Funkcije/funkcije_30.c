/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Funkcija stampa n zvezdica za kojima sledi znak za novi red. */
void stampaj_zvezdice(int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("*");

  printf("\n");
}

/* Funkcija crta grafikon. */
void grafikon_h(int a, int b, int c, int d) {
  /* Prvo se ispisuje a zvezdica. */
  stampaj_zvezdice(a);

  /* Postupak se ponavlja za vrednosti b, c i d. */
  stampaj_zvezdice(b);
  stampaj_zvezdice(c);
  stampaj_zvezdice(d);
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, d;

  /* Ucitavanje vrednosti a,b,c,d. */
  printf("Unesite brojeve: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  /* Provera ispravnosti ulaza i ispis rezultata. */
  if (a < 0 || b < 0 || c < 0 || d < 0)
    printf("Greska: neispravan unos.\n");
  else
    grafikon_h(a, b, c, d);

  return 0;
}
