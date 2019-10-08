/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Funkcija racuna presek pravih 
   y = k1 * x + n1 i y = k2 * x + n2. 
   Koordinate preseka (ako postoji) se upisuju na adrese px i 
   py. Kao povratna vrednost funkcije se vraca jedinica ukoliko
   presek postoji, a nula inace. */
int presek(float k1, float n1, float k2, float n2, float *px,
           float *py) {
  /* Ako je koeficijent pravca jednak, prave su paralelne. */
  if (k1 == k2)
    return 0;

  /* Koordinate preseka se upisuju na adrese (px, py). */
  *px = -(n1 - n2) / (k1 - k2);
  *py = k1 * (*px) + n1;

  /* Funkcija vraca 1 kao indikator da presek postoji. */
  return 1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float k1, k2, n1, n2;
  float x, y;

  /* Ucitavanje parametara za dve prave. */
  printf("Unesite k i n za prvu pravu: ");
  scanf("%f%f", &k1, &n1);
  printf("Unesite k i n za drugu pravu: ");
  scanf("%f%f", &k2, &n2);

  /* Ispis rezultata. */
  if (presek(k1, n1, k2, n2, &x, &y))
    printf("Prave se seku u tacki (%.2f, %.2f).\n", x, y);
  else
    printf("Prave su paralelne.\n");

  exit(EXIT_SUCCESS);
}
