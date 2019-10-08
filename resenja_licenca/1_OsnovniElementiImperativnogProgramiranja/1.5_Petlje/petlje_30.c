/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int format, i;
  double sirina, duzina, nova_duzina;

  /* Ucitavanje formata papira. */
  printf("Unesite format papira: ");
  scanf("%d", &format);

  /* Provera ispravnosti ulaza. */
  if (format < 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* duzina/sirina = 1/sqrt(2) 
     duzina*sirina = 1000mm x 1000mm => 
     
     duzina = sirina/sqrt(2)
     duzina*sirina = 1000mm x 1000mm => 

     sirina*sirina/sqrt(2) = 1000*1000 
     sirina*sirina = sqrt(2) * 1000 * 1000
     sirina = sqrt(sqrt(2) * 1000 * 1000) =>
     
     duzina = sirina/sqrt(2) */
  sirina = sqrt(1000 * 1000 * sqrt(2));
  duzina = sirina / sqrt(2);

  /* Racunanje duzine i sirine za uneti format. */
  for (i = 1; i <= format; i++) {
    nova_duzina = sirina / 2;
    sirina = duzina;
    duzina = nova_duzina;
  }

  /* Ispis rezultata. Napomena: Duzina i sirina su celi brojevi. */
  printf("Dimenzije papira: %d %d\n", (int) duzina, (int) sirina);

  return 0;
}
