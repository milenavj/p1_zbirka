/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Funkcija racuna najveci od 4 prosledjena broja. */
int maksimum(int a, int b, int c, int d) {
  int maks;

  maks = a;
  if (b > maks)
    maks = b;
  if (c > maks)
    maks = c;
  if (d > maks)
    maks = d;

  return maks;
}

/* Pomocna funkcija za ispis beline ili zvezdice. */
void ispisi_znak(int polje, int granica) {
  if (polje < granica)
    printf(" ");
  else
    printf("*");
}

/* Funkcija iscrtava vertikalni grafikon. */
void grafikon_v(int a, int b, int c, int d) {
  int i, maks;

  /* Pronalazak najvece od zadate cetiri vrednosti. */
  maks = maksimum(a, b, c, d);

  /* Grafikon ukupno ima maks horizontalnih linija. */
  for (i = 0; i < maks; i++) {
    /* U svakoj od horizontalnih linija se nalazi po 4 polja: polje 
       za a, b, c i d uspravnu liniju. U svako od polja treba da se
       upise ili zvezdica ili praznina, u zavisnosti od vrednosti i
       toga koja linija se trenutno ispisuje. */

    /* Ispis znaka za polje a. */
    ispisi_znak(i, maks - a);

    /* Ispis znaka za polje b. */
    ispisi_znak(i, maks - b);

    /* Ispis znaka za polje c. */
    ispisi_znak(i, maks - c);

    /* Ispis znaka za polje d. */
    ispisi_znak(i, maks - d);

    /* Na kraju svake horizontalne linije stampa se novi red. */
    printf("\n");
  }
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, d;

  /* Ucitavanje vrednosti cetiri broja. */
  printf("Unesite brojeve: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  /* Provera ispravnosti ulaza i poziv funkcije za ispis
     grafikona. */
  if (a < 0 || b < 0 || c < 0 || d < 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  } else
    grafikon_v(a, b, c, d);

  return 0;
}
