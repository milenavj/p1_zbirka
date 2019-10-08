/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Funkcija ucitava karakter po karakter sa ulaza i prebrojava
   koliko puta se pojavio karakter '.' i koliko puta se pojavio
   karakter ','. */
void interpunkcija(int *br_tacaka, int *br_zareza) {
  int tacke = 0, zarezi = 0;
  char c;

  /* Ucitavanje i prebrojavanje trazenih karaktera. */
  while ((c = getchar()) != EOF) {
    if (c == '.')
      tacke++;

    if (c == ',')
      zarezi++;
  }

  /* Smestanje rezultata na prosledjene adrese. */
  *br_tacaka = tacke;
  *br_zareza = zarezi;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int br_tacaka, br_zareza;

  /* Ucitavanje i obrada teksta. */
  printf("Unesite tekst: \n");
  interpunkcija(&br_tacaka, &br_zareza);

  /* Ispis rezultata. */
  printf("Broj tacaka: %d\n", br_tacaka);
  printf("Broj zareza: %d\n", br_zareza);

  exit(EXIT_SUCCESS);
}
