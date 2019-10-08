/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <string.h>

#define MAKS_IME 21
#define MAKS_VOCKI 50

/* Struktura koja opisuje vocku. */
typedef struct {
  char ime[MAKS_IME];
  float vitamin;
} Vocka;

/* Funkcija ucitava podatke o vockama u niz struktura. Kao
   povratnu vrednost vraca broj ucitanih vocki. */
int ucitaj(Vocka niz[]) {
  int i = 0;

  /* Ucitavanje vocki do kraja ulaza ili do popunjavanja niza. */
  do {
    printf("Unesite ime vocke i njenu kolicinu vitamina C: ");
    if(scanf("%s%f", niz[i].ime, &niz[i].vitamin) == EOF)
      break;
   
    i++;
  } while (i < MAKS_VOCKI);

  return i;
}

/* Funkcija pronalazi vocku sa najvise vitamina C. */
Vocka vocka_sa_najvise_vitamina(Vocka niz[], int n) {
  /* Pronalazak pozicije vocke sa najvise vitamina C. */
  int maks_i = 0, i;
  for (i = 1; i < n; i++)
    if (niz[i].vitamin > niz[maks_i].vitamin)
      maks_i = i;

  /* Kao povratna vrednost se vraca vocka na poziciji maks_i. */
  return niz[maks_i];
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  Vocka vocke[MAKS_VOCKI], najzdravija;
  int n;

  /* Ucitavanje ulaza. */
  n = ucitaj(vocke);

  /* Ispis rezultata. */
  najzdravija = vocka_sa_najvise_vitamina(vocke, n);
  printf("Voce sa najvise vitamina C je: %s\n", najzdravija.ime);

  return 0;
}
